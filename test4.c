#include<stdio.h>
#include<stdlib.h>
#if 0
struct  student {
	char name[10];
	int age;
};//����ṹ������
int main(){
	struct student s = { "zhangsan", 10 };//����ṹ�����
	struct student*p = &s; //����ṹ��ָ�����
	printf("%d\n", (*p).age);
	printf("%d\n", p->age);
	printf("%s\n", s.name);
	printf("%s\n", p->name);

	system("pause");
	return 0;
}
#endif
//�ṹ�崫��ʱ,���ֱ�Ӱѽṹ����Ϊ��������ȥ�Ļ�,������̫��,��ȡ����Ч��̫��(�β���ʵ�εĿ���)
//��������һ��ʹ�ýṹ��ָ����������
//����ṹ������
struct  student {
	char name[1024];
	int age;
};
//  1 �ṹ����Ϊ����
void print(struct student s){
	printf("%d\n", s.age);
}
// 2 �ṹ��ָ����Ϊ����
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