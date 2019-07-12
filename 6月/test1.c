#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

#if 0
int main(){
	//sizeof(运算符)求占内存大小,占多少字节

	printf("%d\n", sizeof(char));//1
	printf("%d\n", sizeof(short));//2
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(long));//4
	printf("%d\n", sizeof(long long));//8
	printf("%d\n", sizeof(float));//4
	printf("%d\n", sizeof(double));//8
	printf("%d\n", sizeof(long double));//8
	system("pause");
	return 0;
# endif
#if 0	
	int main(){
		printf("hello world!\n");
		system("pause");
		return 0;
	}
#endif
#if 0
	//局部变量(函数内部)    和全局变量(函数外部)
	//当局部变量和全局变量同名时,局部变量优先使用
	//推荐使用局部变量
	int global = 2019;
	int main(){
		int local = 2018;//局部
		int global = 2020;//局部变量
		printf("global=%d\n", global);
		system("pause");
		return 0;
	}
#endif

#if 0  
	int main(){
		int num1 = 0;
		int num2 = 0;
		int sum = 0;
		printf("please enter two number:\n");
		scanf("%d %d", &num1, &num2);
		sum = num1 + num2;
		printf("%d\n", sum);
		system("pause");
		return 0;

	}
#endif

#if 0
	//转义字符
	int main(){
		printf("c:\code\test.c\n");//"\t"  是一个转义字符  :水平制表符 
		system("pause");
		return 0;
	}
#endif
#if 0
	int main(){
		printf("%d\n", strlen("abcdef"));//6
		printf("%d\n", sizeof("abcdef"));//7
		
		printf("%d\n", strlen("c:\test\328test.c"));//14   "\+数字" :表ASCII代码值
		printf("%d\n", strlen("\32"));
		system("pause");
		return 0;
	}
#endif

#if 0
	int main(){
		printf("你觉得赵文强帅吗?   输入1 表示帅   输入2表示不帅\n");
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 1){
			printf("你可真有眼光!");
		}
		else{
			printf("你的眼睛瞎了吗!");
			}
		system("pause");
		return 0;
		}

	int main(){
		printf("加入比特\n");
		int line = 0;
		while (line <= 2000){
			line++;
			printf("我要继续努力敲代码!\n");

		}
		if (line > 2000){
			printf("走向人生巅峰");
		}
		system("pause");
		return 0;
	}

	//输出1  到100
	int main(){
		for (int i = 1; i <=100; ++i){
			printf("%d\n", i);
		}
		system("pause");
	}
	int main(){
		int i = 1;
		while (i <= 100){
		
			printf("%d\n",i);
			i++;
		}
		system("pause");
		return 0;
	}

	//函数 码复用
	int Add(int x,int y){
		
		int sum= x + y;
	}
	int main(){
		int sum = 0;
		int a = 100;
		int b = 10000;
		sum = Add(a, b);
		printf("%d\n", sum);
		system("pause");
		return 0;
	}

	int main(){
		int a = 10;
		
		printf("%p", &a);
		system("pause");
		return 0;
	}
	int main(){
		char ch = 'w';
		char*pc = &ch;
		//*pc = 'q';
		printf("%p\n", pc);
		printf("%c\n", ch);
		printf("%c\n",*pc);
		system("pause");
		return 0;
	}

	//指针变量的大小
	//指针型变量在32位平台是4个字节  ,在64位平台是8个字节
	int main(){
		printf("%d\n", sizeof(char*));
		printf("%d\n", sizeof(int*));
		printf("%d\n", sizeof(double*));
		printf("%d\n", sizeof(float*));
		system("pause");
		return 0;
	}


	
	int main(){
		int day=0;
		printf("请输入数字!\n");
		
		scanf("%d", &day);

		switch (day){
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n"); 
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		
		case 6:
			printf("星期六\n"); 
			break;
		case 7:
			printf("星期七\n");
			break;
			//特殊情况
		default:
			printf("你是傻逼吗\n");
			break;
		}
		system("pause");
		return 0;
	}
	//switch语句注意事项:
	//1  break 不能省
	//2  最好加上  default
	// 3 switch 中判定的变量必须是整数常量,不能写表达式
	// 4case 语句中只能写一个整数常量
	//因此它的应用场景大大的收到限制(不推荐使用)

	//while 中的break和continue
	int main(){
		int i = 1;
	}

	int main(){
		int num = 1;
		while (num <= 10){
			printf("%d\n", num);
			num++;
			
		}
		system("pause");
		return 0;
	}

	//循环 1--10 这10个整数,遇到第一个三的倍数就停止循环
	int main(){
		int num = 1;
		while (num <= 10){
			printf("%d\n", num);
		if (num % 3 == 0){
			break;
			}
		num++;
		}
		system("pause");
		return 0;
	}

	//循环 1--10 这10个整数,遇到三的倍数就不打印
	int main(){
		int num = 1;
		while (num <= 10){
			if (num % 3 == 0){
				num++;
				continue;
			}
			else{
				printf("%d\n", num);
				//num++; 放这里也可以
			}
			num++;
		}
		system("pause");
		return 0;
	}

	int main(){
		for (int num = 1; num <= 10; num++){

			if (num % 3 == 0){
				continue;
			}
			else{
				printf("%d\n", num);
			}
		}
		system("pause");
		return 0;
	}

	//如果遇到小写字母就不输出,否则就输出
	int main(){
		char ch = 0;
		while ((ch = getchar()) != EOF){
			if (ch >='a'&&ch <='z'){
				continue;
			}
			else {
				putchar(ch);
			}
		
		}
		system("pause");
		return 0;

	}

	//自增运算符
	//   num++   vs   ++num
	// 1  num++:  
	//   num++  相当于 int tmp=num;     num=num+1;    return tmp;
	//2   ++num
	//++num    相当于 num=num+1;  return num;

	//  面试题   问 :  循环执行多少次   答案:   0次  
	int main(){
		int i = 0;
		int  k = 0;
		for (i = 0, k = 0; k == 0;i++,k++){
			k++;
			printf("hehe\n");
		}
		system("pause");
		return 0;
	}

	//小差别  天壤之别    执行一次
	int main(){
		int i = 0;
		int  k = 0;
		for (i = 0, k = 0; k == 0; i++, k++){
			k++;
			printf("hehe\n");
		}
		system("pause");
		return 0;
	}

	//求N的阶乘
	int Factor(int n){
		int ret = 1;
		for (int i = 1; i <= n; ++i){
			ret = ret*i;
		}
		return ret;
	}
	int main(){
		printf("%d\n", Factor(5));
		system("pause");
		return 0;

//求  1!+2!+......+10!
		int Factor(int n){
			int ret = 1;
			for (int i = 1; i <= n; ++i){
				ret = ret*i;
			}
			return ret;
		}

		int main(){
			int sum = 0;
			for (int i = 1; i <= 10; ++i){
				sum = sum + Factor(i);
			}
			printf("%d\n", sum);
			system("pause");
			return 0;
		}

		int main(){
			char  str1[] = "welcome to bite!";
			char str2[] = "***************";
			int left = 0;
			int right = strlen(str2) - 1;//获取最后一个元素的下标
			while (left <= right){
				printf("%s\n", str2);
				str2[left] = str1[left];
				str2[right] = str1[right];
				++left;
				--right;
				Sleep(100); // 加上以后会有动态效果
				//system("cls");
				
			}
			system("pause");
			return 0;
		}

		


#endif
#if 0


		int main(){
			//char password[10] = { 0 };
			//scanf("%s", password);
			int i = 0;
			for (; i < 3; ++i){
				printf("请输入密码:\n");
				char password[10] = { 0 };
				scanf("%s", password);
				if (strcmp(password, "20190504") == 0){
					break;
				}
			}
			if (i < 3){
				printf("恭喜你登陆成功!\n");
			}
			else{
				printf("您的输入次数已经超过3次,登录失败!\n");
			}
			system("pause");
			return 0;
		}
	//函数版本
		void menu(){
			printf("##############\n");
			printf("请输入您的密码\n");
			printf("##############\n");
           }

		int main(){
			menu();
			int i = 0;
			for (; i < 3; ++i){
				char  password[10] = { 0 };
				scanf("%s", password);
				if (strcmp(password, "20190504") == 0){
					printf("登录成功!\n");
					break;
				}

			}
			if (i < 3){
				printf("登录成功!\n");
			}
			else{
				printf("你是猪吗");
			}

			system("pause");
			return 0;
		}



		int main(){
			int arr[4] = { 9, 5, 2, 7 };
			int to_find = 10;
			int i = 0;
			for (; i <= 3; ++i){
				if (to_find == arr[i]){
					break;
					//printf("在呢!\n");
				}
			}
			if (  i <= 3){
				printf("在呢!\n");
			}
			else{
				printf("不在!\n");
			}
			system("pause");
			return 0;
		}

		//二分查找(有序数列)
#include<stdlib.h>
#include<stdio.h>
		int main(){
			int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int size = sizeof(arr) / sizeof(arr[0]) - 1;
			int left = 0;
			int right = size - 1;
			//[left,right]
			while (left <= right){
				int to_find = 3;
				int mid = (left + right) / 2;
				if (arr[mid] > to_find){
					right = mid - 1;
				}
				else if (arr[mid] < to_find){
					left = mid + 1;
				}
				else{
					//printf("找到了!\n");
					break;
				}

			}
			if (left <= right){
				printf("找到了!\n");
			}
			else{
				printf("没找到!\n");
			}
			system("pause");
			return 0
		//二分查找(函数版本)
#include<stdlib.h>
#include<stdio.h>
			, int to_fint BinaryReserch(int arr[], int to_find){
				int left = 0;
				int right = size - 1;
				while (left <= right){
					int mid = (left + right) / 2;
					if (arr[mid] > to_find){
						right = mid - 1;
					}
					else if (arr[mid] < to_find){
						left = mid + 1;
					}
					else{

						return mid;
					}
				}
				return -1;
			}
			int main(){
				int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				int size = sizeof(arr) / sizeof(arr[0]);
				//printf("%d\n", size);

				int ret = BinaryReserch(arr, size, 9);
				printf("%d\n", ret);

				system("pause");
				return 0;
			}


		
		//猜数字游戏
			int Menu(){
				printf("*********************\n");
				printf("1 开始游戏 2 结束游戏\n");
				printf("********************\n");
				printf("请输入您的选项!\n");
				int choice = 0;
				scanf("%d", &choice);
				return choice;//必须返回
			}
			int Game(){
				//计算机 自动生成一个随机数字(1到100)
				int to_Guess = rand() % 100 + 1;
				//让用户猜这个数字
				int i = 0;
				while (i<5){
					int num = 0;
					printf("输入你要猜的数字:");
					scanf("%d", &num);
					//将用户猜的数字和生成的数字进行比较,然后根据实际相互大小,输出"高了"  或者   "低了"     
					if (num > to_Guess){
						printf("高了!");
					}
					else if (num < to_Guess){
						printf("低了!");
					}
					else{
						printf("恭喜你猜对了!");
						break;
					}
					++i;
				}
				if (i < 5){
					printf("恭喜你猜对了!\n");
				}
				else{
					printf("我给过你机会了可你没有把握住！\n");
				}
				}
				
			int main(){
				//时间戳
				srand(( unsigned int)time(0));
				while (1){
					int choice = Menu();
					if (choice == 1){
						Game();
					}
					else if (choice == 2){
						printf("goodbye!\n");
					}
					else{
						printf("您的输入有误!\n");
					}
				}
				system("pause");
				return 0;
			}
	
//打印100到200之间的素数(除了1和它本身之外不能被其他数整除)
			int main(){
				int n;
				int i;
			
				for (n= 100; n < 201; n++){
					for (i= 2; i<n; i++){
						if (n%i == 0){
						break;
						}
						
					}
					if (i == n){
						printf("%d\n", n);
					}
					
					}
				
				system("pause");
				
//求两个数的最大值
int Max(int x, int y){
	if (x > y){
		return x;
	}
	else{
	return y;
	}
	
}
	int main(){
					int a = 10;
					int b = 20;
					Max(a, b);
					printf("%d\n", Max(a, b));
					system("pause");
					return 0;
				}

	void swap(int x, int y){
		int tmp = x;
		x = y;
	    y = tmp;
	}
	int main(){
		int a = 100;
		int b = 123;
		//以下代码等同于  swap(a,b)
		int x = a;//对x初始化
		int y = b;//对y初始化
		int tmp = x;
		x = y;
		y = tmp;


		//swap(a, b);
		printf("%d %d\n",a,b );
		system("pause");
		return 0;
	}

	void swap(int*x, int*y){
		int tmp = *x;//  相当于  int tmp=a;
		 *x = *y;//相当于  a=b;
		 *y = tmp;//相当于  b=tmp;
	}
	int main(){
		int a = 10;
		int b = 20;
		swap(&a,&b);
		printf("%d %d\n", a, b);
		system("pause");
		return 0;
	}
	//约定 返回1 表示  是素数   返回 0 表示 不是素数
	int Issushu(int x){
		//考虑非法情况的意识
		if (x ==1){
			return 0;
		}
		else if (x <= 0){
			return 0;
		}
	for (int i = 2; i < x; ++i){
			if (x%i == 0){
				return 0;
			}
		}
	return 1;
		
	}
	int main(){
			int ret = Issushu(11);
		printf("%d\n", ret);
		system("pause");
		return 0;

	}

	//约定 返回1 表示  是润年        0 表示 不是闰年
	int Isrunnian(int x)
	{
		//闰年分为普通闰年和世纪闰年
		if (x % 100 == 0){
			if (x % 400){
				return 1;
			}
			else {
				return 0;
			}
		}
		else{
			if (x % 4 == 0){
				return 1;
			}
			else{
				return 0;
			}

		}
	}
	int main(){
		int ret = Isrunnian(2020);
		printf("%d\n", ret);
		system("pause");
		return 0;
	}

	//写一个函数  每调用一次使得num的值+1
	void  func(int*x){
		*x += 1;
	}
	int main(){
		int a = 4;
		func(&a);
		printf("%d\n", a);
		system("pause");
		return 0;
	}

	void  func(x){
		x += 1;
	}
	int main(){
		int a = 4;
		func(a);
		printf("%d\n", a);
		system("pause");
		return 0;
	}

#include<stdio.h>
#include<stdlib.h>

	void swap(int*x, int*y) {
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
	typedef int(*Cmp)(int x, int y);
	void Bubblesort(int arr[], int size, Cmp cmp) {
		int bound = 0;
		for (; bound < size; ++bound){
			for (int cur = size - 1; cur > bound; --cur) {
				if (!cmp(arr[cur - 1], arr[cur])) {
					swap(&arr[cur - 1], &arr[cur]);
				}
			}
		}
	}
	int less(int x, int y) {
		if (x < y) {
			return 1;
		}
		return 0;
	}
	/*int greater(int x, int y) {
	if (x > y) {
	return 1;
	}
	return 0;
	}*/
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		Bubblesort(arr, 4, less/*greater*/);
		for (int i = 0; i < 4; ++i) {
			printf("%d\n", arr[i]);
		}
		system("pause");
		return 0;
	}
	//数组
	int main(){
		int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		//如果在数组名前加了  const  关键字就只能对数组进行读不能写
		//const  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		//  1   对数组进行"写入"操作
		for (int i = 0; i < 10; ++i){
			arr[i] = 100 + i;
		}//  2    对数组进行"读取"操作
		for (int i = 0; i < 10; ++i){
			printf("%d\n", arr[i]);
			
		}
     //访问越界,此时访问的是非法内存,产生的值是随机值;
		//printf("%d\n", arr[16]);//黄赌毒
		system("pause");
		return 0;
	
	//二维数组
	int main(){
		//  1,2  逗号表达式  表示的是逗号后面的值
		int arr[3][4] = { (1, 2), (3, 4), (5, 6) };
		system("pause");
		return 0;
	}

	//二维数组
	int main(){
		int arr[3][4] = { 0 };
		for (int row = 0; row < 3; ++row){
			for (int col = 0; col < 4; ++col){
				printf("%d ", arr[row][col]);
			}
			printf("\n");
		}
		system("pause");
		return 0;
	}

	//冒泡排序(升序版本)
	void  swap(int *x, int *y){
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
	void BubbleSort(int arr[], int size){
         //已排序区间[0,bound)     未排序区间[bound,size)
		int bound = 0;
		for (int bound = 0; bound < size; ++bound){
			for (int cur = size -1; cur >bound; --cur){
				if (arr[cur - 1]>arr[cur]){
					swap(&arr[cur - 1], &arr[cur]);
				}
			}
		}
	}
	int main(){
		int arr[4] = { 9,5,2,7 };
		int size = sizeof(arr) / sizeof(arr[0]) ;
		 BubbleSort(arr, size);
		 for (int i = 0; i < 4; ++i){
			 printf("%d\n", arr[i]);
		 }
		 system("pause");
		 return 0;
	
	int main(){
		//int ret = 1 / 2;//结果为0
		//double ret = 1 / 2;//结果为0.00000000
		//double ret = 1.0 / 2.0;//结果为0.500000
		int ret = 1.0 / 2;// 1.0/2=>  1.0/2.0 =>0.5000=>  0
		printf("%d\n", ret);
		system("pause");
		return 0;
	}

// 操作符
	// 1  左移一个数,左移一位乘以2
	// 2 右移一个数.右移一位除以2
	// 与操作  两个数 都为1  结果为1   否则结果为0;
	// 或操作  两个数都为 0  结果为0  否则 结果为1
	// 异或操作   相同为0  相反为1
	// 取反操作   0 =>1 ;1=> 0

	//不用临时变量  交换了两个数

	int main(){
		int a = 10;
		int b = 20;
	    //a = a + b;
		//b = a - b;
		//a = a - b;
		a = a^b;
		b = a^b;
		a = a^b;

		printf("%d %d\n", a, b);
		system("pause");
		return 0;
	}

	int main(){
	
		int x = 10;
		int* p;
		p = &x;
		printf("%d\n", sizeof(p));
		printf("%p\n", p);
		printf("%d\n", *p);
		system("pause");
			return 0;
	}

	int  main(){
		int n = 10;
		int *p = &n;
		int n2 = 10;
		int *p2 = &n2;
		printf("%p\n", p);
		printf("%p\n", p2);
		if (p == p2){//指针比较的时候比较的是地址   看地址是否相同
			printf("hehe\n");
		}
		else{
			printf("haha\n");
		}

		system("pause");
		return 0;
	
	void  func(int *p){
		printf("%d\n", *p);//输出  1
			printf("%d\n", *(p + 1));//输出 2
	}
	int main(){
		int arr[4] = { 1, 2, 3, 4 };
		func(arr);
		system("pause");
		return 0;
	
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		printf("%p\n", arr);
		printf("%p\n", &arr[0]);
		system("pause");
		return 0;
	
	
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		int *p = arr;
		int size = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < size; ++i){

//	printf("%d\n", arr[i]);
			
	printf("%d\n", *(p + i));
		}
		system("pause");
		return 0;
	
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		printf("%p\n", arr);
		
	printf("%p\n",&arr[0]);
		printf("%p\n", &arr);
		system("pause");
		return 0;

	}


// 定义结构体类型
		struct student {
			char name[20];
			int  id;
		};
		int main(){
			struct student s = { "wangkaixin", 10 };//定义结构体变量 s 并对他进行初始化;
 		//	s.id = 20;   修改值;
			//strcpy(s.name, "lisi");  修改值;
			printf("%d\n", s.id);
			printf("%s\n", s.name);
			system("pause");
			return 0;

		}
		//GBK  用两个字节表示一个汉字;
		//UTF-8  用三个字节表示  一个汉字;

		//小练习:  定义一个结构体类型,并对其进行初始化;
//#endif
		struct  student{
			int number;
			char name[1024];
			char sex[1024];
			char address[1024];
			int scores ;
		};
		int main(){
			struct student s = { 9,5,2,7, "王开心", "man", "安康",100 };
			printf("NO=%d\n", s.number);
			printf("name=%s\n", s.name);
			printf("sex=%s\n", s.sex);
			printf("address=%s\n",s.address);
			printf("成绩=%d\n", s.scores);
			system("pause");
			return 0;

		}


		int  menu(){
			printf("*********************************************\n");
			printf("你愿意继续敲代码吗, 1表示愿意  2表示 不愿意\n");
			printf("*********************************************\n");
			printf("请输入您的选项:");
			int choice = 0;
			scanf("%d", &choice);
			return choice;
          }
		int main1(){
			int choice = 0;
			choice = menu();
			if (choice == 1){
				printf("加油明天会更好!");
			}
			else{
				printf("rubbsh!");
			}
			system("pause");
			return 0;
		}
#endif
		


			

		
	
		

	
		

	
