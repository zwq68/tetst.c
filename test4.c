#include<stdio.h>
#include<stdlib.h>
#if 0
struct  student {
	char name[10];
	int age;
};//定义结构体类型
int main(){
	struct student s = { "zhangsan", 10 };//定义结构体变量
	struct student*p = &s; //定义结构体指针变量
	printf("%d\n", (*p).age);
	printf("%d\n", p->age);
	printf("%s\n", s.name);
	printf("%s\n", p->name);

	system("pause");
	return 0;
}
#endif
//结构体传参时,如果直接把结构体作为参数传过去的话,拷贝量太大,读取数据效率太低(形参是实参的拷贝)
//所以我们一般使用结构体指针来传参数
//定义结构体类型
struct  student {
	char name[1024];
	int age;
};
//  1 结构体作为参数
void print(struct student s){
	printf("%d\n", s.age);
}
// 2 结构体指针作为参数
void print2(struct student *p ) {
	printf("%d\n", p->age);
}

int main(){
	struct student s = { "wangkaixing", 10 };
	struct student *p = &s;
	print(s);
	print2(&s);

	system("pause");
	return 0;
}