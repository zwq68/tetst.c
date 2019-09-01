#include<fstream>  //c++ 提供文件读写操作
#include"httplib.h"
#include"db.hpp"
#include<signal.h>
#include<sys/stat.h>

class FileUtil{
  public:
    // 向文件写入的方法
    static bool Write(const std::string& file_name,const std:: string& content){
      std::ofstream file(file_name.c_str());// 创建一个文件对象
      if(!file.is_open()){
        return false; // 打开失败
      }
      file.write(content.c_str(),content.length());// 文件写入操作
      file.close();// 关闭文件
      return true ;
    }

    // 将文件中的内容读取到字符串content 中
    static bool Read(const std::string& file_name,std::string*content){
      std::ifstream file(file_name.c_str());
      if(!file.is_open()){
        return false;
      }
      // 走到这里可以读文件了
      //   一口气把整个文件读完
      //   需要先获取文件大小
      struct stat st;
      stat(file_name.c_str(),&st);
      // 将content 字符串大小设置为和文件大小一样
      content->resize(st.st_size);
      // char* 缓冲区长度
      // // int 读取多长

      file.read((char*)content->c_str(),content->size());
      file.close();
      return true;
    }


};


// 回调函数
MYSQL*mysql=NULL;  // 操作句柄全局使用
int main(){
  using namespace httplib;
  //  服务器启动时 先连接数据库

  mysql=image_system::MySQLInit();
  image_system::ImageTable image_table(mysql);  //  创建一个数据库对象(操作数据库)

  // 由于程序泡在服务器上,因此  不能在程序中释放,可通过 Ctrl  C  手动释放
  signal(SIGINT,[](int){
      image_system:: MySQLRelease(mysql);
      exit(0);
      });

  Server server; //  创建一个对象
  // 客户端请求 /hello 路径的时候 ,执行一个特定的函数
  // 指定不同的路径对应到不同的函数上  这个过程叫做  设置路由
  //  服务器中有两个特别重要的概念:
  //  1 requst :请求
  //  2 response: 响应
  //  [&image_table]  这是lambda 的重要特性  用来捕获变量
  //  本来 lambda 内部是不能直接访问image_table  的
  // 捕获之后 就在lambda 内部就可以访问了 (相当于强制捕获传参), 其中&  的含义是 相当于按引用捕获
  server.Post("/image",[&image_table](const Request& req,Response& resp){
      Json::FastWriter writer;
      Json::Value resp_json;//搞一个json对象
      printf("上传图片\n");
      // 1 先对参数进行校验
      // auto size = req.files.size();// 图片个数
      auto ret = req.has_file("upload");
      if(!ret){
      printf("文件上传出错!\n");
      resp.status=404;
      // 使用json 格式组织一个返回结果
      resp_json["ok"]=false;
      resp_json["reason"]="上传文件出错,没有需要的upload字段";
      resp.set_content(writer.write(resp_json),"application/json");// 将错误描述放到响应中
      return;
      } 
      // 2 根据文件名获取到文件数据,数据在 file 对象中
      const auto& file = req.get_file_value("upload");
      //  file.filename;
      // file.content_type;
      // body : 图片内容

      //  auto body = req.body.substr(file.offset, file.length);//offset  起始位置  length截取长度   提取图片内容    通过将图片内容写入文件来校验图片内容
      //  3将图片属性信息插入到数据库中 (以json格式组织数据)

      Json::Value image;
      image["image_name"]=file.filename;
      image["size"]=(int)file.length;
      image["upload_time"]="208/08/29"; //  暂时写死(此时是固定时间) //   to do (这里还没有写完呢)  !!!
      image["md5"]="aaaaaaa" ;  // 同上  暂时写死
      image["type"]=file.content_type;
      image["path"]="./data/"+file.filename;

      ret= image_table.Insert(image);// 以json数据包插入到数据库中
      if(!ret){
        printf("image_table Insert faile!\n");
        resp_json["ok"]=false;
        resp_json["reason"]="数据库插入失败!";
        // 返回状态码
        resp.status=500; //   这是服务器的锅
        resp.set_content(writer.write(resp_json),"application/json");
        return ;

      }

      //  4把图片保存到指定的磁盘目录中
      auto body = req.body.substr(file.offset, file.length);
      FileUtil::Write(image["path"].asString(),body);   
      //  5构造一个响应数据通知客户端上传成功
      resp_json["ok"]=true;
      resp.status =200;
      resp.set_content(writer.write(resp_json),"application/json");
      return ;     
  });





  server.Get("/image",[&image_table](const Request& req,Response& resp){    
      printf("获取所有图片的信息");
      (void)req;   // 没有实际的效果  显示告诉编译器  这个你不要管
      Json::Value resp_json;
      Json::FastWriter writer;
      // 1 调用数据库接口来获取数据
      bool ret=image_table.SelectAll(&resp_json);
      if(!ret){
      printf("查询数据库失败!\n");
      resp_json["ok"]=false;
      resp_json["reason"]="查询数据库失败!";
      resp.status=500;
      resp.set_content(writer.write(resp_json),"application/json");

      return ;
      }
      // 2 构造响应结果 返回给客户端
      resp.status=200;
      resp.set_content(writer.write(resp_json),"application/json");
      });




  // 正则表达式
  // 原始字符串(raw string)
  server.Get(R"(/image/(\d+))",[&image_table](const Request& req,Response& resp){
      Json::FastWriter writer;
      Json::Value resp_json;
      // 1 先获取到图片id
      int image_id=std::stoi(req.matches[1]);
      printf("获取ID 为 %d的图片信息!\n",image_id);
      // 2 再来根据图片ID查询数据库
      bool ret=image_table.SelectOne(image_id,&resp_json);
      if(!ret){
      printf("数据库查询出错!\n");
      resp_json["ok"]=false;
      resp_json["reson"]="数据库查询出错";
      resp.status=404;
      resp.set_content(writer.write(resp_json),"application/json");
      return ;
      }
      // 3 把查询结果返回给客户端

      resp_json["ok"]=true;
      resp.set_content(writer.write(resp_json),"application/json");
      return ;    
  });



  // 获取图片详细内容
  server.Get(R"(/show/(\d+))",[&image_table](const Request& req,Response& resp){
      Json::FastWriter writer;
      Json::Value resp_json;

      // 1 根据图片ID去数据库中查到对应的目录
      int image_id=std::stoi(req.matches[1]);      
      printf("获取ID 为 %d的图片内容!\n",image_id);
      Json:: Value image;
      bool ret=image_table.SelectOne(image_id,&image);         
      if(!ret){
      printf("读取数据库出错!\n");
      resp_json["ok"]=false;
      resp_json["reson"]="数据库查询出错";
      resp.status=404;
      resp.set_content(writer.write(resp_json),"application/json");
      return ;

      }
      // 2 根据目录找到文件内容,读取文件内容
      std::string image_body ; // image_body 是文件内容
      printf("%s\n",image["path"].asCString());
      ret=FileUtil::Read(image["path"].asString(),&image_body);// 读取文件并做校验
      if(!ret){
        printf("读取文件失败!\n");
        resp_json["ok"]=false;
        resp_json["reson"]="读取文件失败";
        resp.status=500;
        resp.set_content(writer.write(resp_json),"application/json");
        return ;
      }
      // 3 把文件内容构造成响应,返回给客户端
      resp.status=200;
      // 不同的图片 ,设置的content type是不一样的
      // 如果是 png 应该设置为image/png
      // 如果是 jpg应该设为image/jpg
      resp.set_content(image_body,image["type"].asCString());

  });



  // 删除图片
  server.Delete(R"(/image/(\d+))",[&image_table](const Request& req,Response& resp){
      Json::FastWriter writer; 
      Json::Value resp_json;

      //  1  根据图片id  去数据库中查到对应的目录
      int image_id=std::stoi(req.matches[1]);                  
      printf("删除ID 为 %d的图片内容!\n",image_id);
      //  2 查找对应文件的路径
        Json:: Value image;
        bool ret=image_table.SelectOne(image_id,&image);
        if(!ret){
        printf("删除图片文件失败!\n");
        resp_json["ok"]=false;                                       
        resp_json["reson"]="删除图片取文件失败";                     
        resp.status=404;                                             
        resp.set_content(writer.write(resp_json),"application/json");
        }

      //3 调用数据库操作进行删除
       ret=image_table.Delete(image_id);
      if(!ret){                                                      
      printf("删除图片文件失败!\n");
      resp_json["ok"]=false;
      resp_json["reson"]="删除图片取文件失败";
      resp.status=404;
      resp.set_content(writer.write(resp_json),"application/json");
      return ;
      }
      // 4  删除磁盘上文件
      // C++标准库中,没有删除文件的方法
      //  可以使用操作系统提供的方法
      unlink(image["path"].asCString());

      // 5  构造响应
      resp_json["ok"]=true;
      resp.status=200;
      resp.set_content(writer.write(resp_json),"application/json");

      });


  server.set_base_dir("./wwwroot");
  server.listen("0.0.0.0",9094);  // 启动服务器

  return 0;

}





















