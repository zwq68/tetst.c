#pragma once
#include<cstdlib>
#include<cstdio>
#include<mysql/mysql.h>
#include<jsoncpp/json/json.h> // 借助第三方库json  操作和解析json
// 一个类  json ::Value  非常类似于 std::map
//   两个重要方法   1   Reader::parse  把一个json格式 字符转成 json ::Value 对象 -----反序列化
//   两个重要方法   2   Write::write 把一个json::Value对象转成字符串-----序列化

namespace image_system{



  static MYSQL *MySQLInit(){

    // 1  创建句柄  
    MYSQL*mysql=mysql_init(NULL);
    // 2 拿着句柄和数据库建立连接
    if(mysql_real_connect(mysql,"127.0.0.1","root","1","image_system",3306,NULL,0)==NULL){
      // 数据库连接失败
      printf("数据库连接失败!%s\n",mysql_error(mysql));
      return NULL;
    }
    // 3  设置编码格式
    mysql_set_character_set(mysql,"utf8");
    return mysql;
  }



  static void MySQLRelease(MYSQL*mysql){
    mysql_close(mysql);
  }

  //   这个类是用来操作数据库 的image_table 这个表.
  //   此处使用json   参数  (为了 参数太多)
  class ImageTable{
    public:
      //构造函数
      ImageTable(MYSQL*mysql):mysql_(mysql){}
      // image 就形如一下形势:
      //{
      //image_name: "test.png",
      //size: 1024,
      //upload_time:"2019/9/1"
      //.....
      //.....
      //path:"data/test.png"
      //}
      //  使用json的原因: 1 扩展方便 2 方便和服务器接收到的数据打通
      //    上传图片---输入数据
      bool Insert(const Json::Value& image ){
        // 拼装字符串(mysql语句)
        char sql[4*1024]={0};
        sprintf(sql,"insert into image_table values(null,'%s',%d,'%s','%s','%s','%s')",image["image_name"].asCString(),
            image["size"].asInt(),image["upload_time"].asCString(),
            image["md5"].asCString(),image["type"].asCString(),
            image["path"].asCString());
        printf("[Insert sql]%s\n",sql);// 打印出来看看  可视化 利于纠错

        // 执行sql 语句
        int ret=mysql_query(mysql_,sql);
        if(ret!=0){
          printf("Insert 执行 SQL 失败! %s\n",mysql_error(mysql_));
          return false;
        }
        return true;
      }


      //查所有图片内容
      bool SelectAll(Json::Value*images){
        char sql[1024*4]={0};
        sprintf(sql,"select * from image_table");
        int ret=mysql_query(mysql_,sql);
        if(ret!=0){
          printf("SelectAll 指向 SQL 失败! %s\n",mysql_error(mysql_));
          return false;
        }

        // 走到这说明执行成功
        // 遍历结果集合 ,并把结果集合写到images 参数之中
        MYSQL_RES* result=mysql_store_result(mysql_);
        int rows =mysql_num_rows(result);
        for(int i=0;i<rows;++i){
          MYSQL_ROW row=mysql_fetch_row(result);
          // 数据库查出的每条记录都相当于是一个图片的信息
          // 需要把这个信息转换成Json 格式
          Json::Value image; //  创建一个对象出来
          image["image_id"]=atoi(row[0]);
          image["image_name"]=row[1];
          image["size"]=atoi(row[2]);
          image["upload_time"]=row[3];
          image["md5"]=row[4];
          image["type"]=row[5];
          image["path"]=row[6];
          images->append(image);
        }
        //  忘记会导致内存泄漏
        mysql_free_result(result);

        return true;
      }

      // 查指定图片内容
      bool SelectOne(int image_id,Json::Value*image_ptr){
        char sql[1024*4]={0};
        // 拼接SQL语句
        sprintf(sql,"select * from image_table where image_id=%d",image_id);
        int ret=mysql_query(mysql_,sql);
        if(ret!=0){
          printf("SelectOne  执行失败! %s\n",mysql_error(mysql_));
          return false;
        }
        // 走到这里说明SQL语句执行成功
        // 遍历结果集合
        MYSQL_RES* result=mysql_store_result(mysql_);// 获取结果集
        int rows=mysql_num_rows(result);// 获取一行数据 将行数保存在rows
        // 进行结果校验  rows  预期结果应该为1 
        if(rows !=1){
          printf("SelectOne 查询结果 不是一条记录! 实际查到%d 条!\n",rows);
          return false;
        }
        MYSQL_ROW row= mysql_fetch_row(result);
        Json::Value image; //  创建一个对象出来 
        image["image_id"]=atoi(row[0]);
        image["image_name"]=row[1];
        image["size"]=atoi(row[2]);
        image["upload_time"]=row[3];
        image["md5"]=row[4];
        image["type"]=row[5];
        image["path"]=row[6];
        *image_ptr=image;
        // 释放结果集合
        mysql_free_result(result);
        return true;
      }


      // 删除图片
      bool Delete(int image_id){
        char sql[1024*4]={0};
        sprintf(sql,"delete from image_table where image_id=%d",image_id);
        int ret=mysql_query(mysql_,sql);
        if(ret!=0){                                                         
          printf("Delete  执行失败! %s\n",mysql_error(mysql_));
          return false;
        }
        return true;
      }

    private: 
      MYSQL*mysql_;
  };
}// end image_system





