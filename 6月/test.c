// 实现一个通讯录程序
//1 新增联系人
//2 删除联系人
//3修改联系人
//4查找记录
//5 打印全部记录
//6 排序记录
//7 清空全部记录
//管理
//1 把基本信息抽象并描述出来(结构体）
//2  需要管理很多数据，就需要把数据组织起来（数据结构）

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_personinfo_size 300
    typedef struct personinfo {
	char name[1024];
	char phone[1024];
}personinfo;
	typedef struct addressbook {
		personinfo persons[MAX_personinfo_size];
		//[0,size]
		int size;
	} addressbook;
	addressbook g_address_book;//定义全局变量
	int menu() {
		printf("========\n");
		printf("1.新增联系人\n");
		printf("2.删除联系人\n");
		printf("3.查找联系人\n");
		printf("4.修改联系人\n");
		printf("5.打印全部联系人\n");
		printf("6.排序联系人\n");
		printf("7.清空联系人\n");
		printf("0.退出\n");
		printf("========\n");
		printf("请输入您的选择\n");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
	}
	void init() {
		g_address_book.size = 0;
		for (int i = 0; i < MAX_personinfo_size; ++i) {
			g_address_book.persons[i].name[0] = '\0';
			g_address_book.persons[i].phone[0] = '\0';
		}
	}
	void empty() {
    }
	void addpersoninfo() {
		printf("新增联系人\n");
		if (g_address_book.size>= MAX_personinfo_size) {
			printf("新增联系人失败！\n");
			return;
		}
		personinfo*person_info = &g_address_book.persons[g_address_book.size];
		printf("请输入联系人姓名\n");
		scanf("%s", person_info->name);
		printf("请输入联系人电话:\n");
		scanf("%s", person_info->phone);
		++g_address_book.size;
		printf("新增联系人成功！\n");
	}
	void delpersoninfo() {
		printf("删除联系人！\n");
		if (g_address_book.size <=0) {
			printf("删除失败，通讯录为空！");
		}
		printf("请输入要删除的序号:");
		int id = 0;
		scanf("%d", &id);
		if (id < 0 || id >= g_address_book.size) {
			printf("删除失败！，输入的序号有误！\n");
			return;
		}
		g_address_book.persons[id]
			= g_address_book.persons[g_address_book.size - 1];
		--g_address_book.size;
		printf("删除联系人成功！\n");

	}
	void findpersoninfo() {
		printf("查找联系人\n");
		if (g_address_book.size <= 0) {
			printf("修改失败，通讯录为空！\n");
			return;
		}
		//根据姓名查找电话
		printf("请输入要查找的姓名:");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < g_address_book.size; ++i) {
			personinfo*info = &g_address_book.persons[i];
			if (strcmp(info->name, name) == 0) {
				printf("[%d] %s\t%s\n", i, info->name, info->phone);
			}
		}
		printf("查找联系人成功！\n");
	}
	void updatepersoninfo() {
		printf("更新联系人！\n");
		if (g_address_book.size <0) {
			printf("修改失败，通讯录为空！\n");
			return;
		}
		printf("请输入要修改的序号:");
		int id = 0;
		scanf("%d", &id);
		if (id<0 || id>g_address_book.size) {
			printf("修改失败，输入的序号有误！\n");
			return;
		}
		personinfo*info = &g_address_book.persons[id];
		printf("请输入新的姓名:(%s)\n",info->name);
		char name[1024] = { 0 };
		scanf("%s", name);
		if (strcmp(name, "*") != 0) {
			strcpy(info->name,name);
		}
		printf("请输入新的电话:(%s)\n", info->phone);
		char phone[1024] = { 0 };
		scanf("%s", phone);
		if (strcmp(phone, "*") != 0) {
			strcpy(info->phone, phone);
		}
		printf("更新联系人成功！\n");
	}
	void printallpersoninfo() {
		printf("打印全部联系人\n");
		for (int i = 0; i < g_address_book.size; ++i) {
			personinfo*info = &g_address_book.persons[i];
			printf("[%d] %s\t%s\n", i,info->name, info->phone);
		}
		printf("共打印了%d条数据\n",g_address_book.size);
		printf("打印全部联系人成功！\n");

	}
	void sortpersoninfo() {

	}
	void clearallpersoninfo() {
		printf("清空全部数据\n");
		printf("您真的要清空全部数据吗？Y/N\n");
		char choice[1024] = { 0 };
		scanf("%s", choice);
		if (strcmp(choice, "y") == 0) {
			g_address_book.size = 0;
			printf("清空全部数据成功！\n");
		}
		else {
			printf("清空操作取消！\n");
		}
	}
	typedef void(*func)();
	int main(){
		func arr[] = {
			empty,
			addpersoninfo,
			delpersoninfo,
			findpersoninfo,
			updatepersoninfo,
			printallpersoninfo,
			sortpersoninfo,
			clearallpersoninfo
		};
		init();
		while (1) {
			int choice = menu();
			if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
				printf("您的输入有误！\n");
				continue;
			}
			if (choice == 0) {
				printf("goodbye\n");
				break;
			}
			arr[choice]();
			
		}
		system("pause");
		return 0;
	}

