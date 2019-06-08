// ʵ��һ��ͨѶ¼����
//1 ������ϵ��
//2 ɾ����ϵ��
//3�޸���ϵ��
//4���Ҽ�¼
//5 ��ӡȫ����¼
//6 �����¼
//7 ���ȫ����¼
//����
//1 �ѻ�����Ϣ������������(�ṹ�壩
//2  ��Ҫ����ܶ����ݣ�����Ҫ��������֯���������ݽṹ��

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
	addressbook g_address_book;//����ȫ�ֱ���
	int menu() {
		printf("========\n");
		printf("1.������ϵ��\n");
		printf("2.ɾ����ϵ��\n");
		printf("3.������ϵ��\n");
		printf("4.�޸���ϵ��\n");
		printf("5.��ӡȫ����ϵ��\n");
		printf("6.������ϵ��\n");
		printf("7.�����ϵ��\n");
		printf("0.�˳�\n");
		printf("========\n");
		printf("����������ѡ��\n");
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
		printf("������ϵ��\n");
		if (g_address_book.size>= MAX_personinfo_size) {
			printf("������ϵ��ʧ�ܣ�\n");
			return;
		}
		personinfo*person_info = &g_address_book.persons[g_address_book.size];
		printf("��������ϵ������\n");
		scanf("%s", person_info->name);
		printf("��������ϵ�˵绰:\n");
		scanf("%s", person_info->phone);
		++g_address_book.size;
		printf("������ϵ�˳ɹ���\n");
	}
	void delpersoninfo() {
		printf("ɾ����ϵ�ˣ�\n");
		if (g_address_book.size <=0) {
			printf("ɾ��ʧ�ܣ�ͨѶ¼Ϊ�գ�");
		}
		printf("������Ҫɾ�������:");
		int id = 0;
		scanf("%d", &id);
		if (id < 0 || id >= g_address_book.size) {
			printf("ɾ��ʧ�ܣ���������������\n");
			return;
		}
		g_address_book.persons[id]
			= g_address_book.persons[g_address_book.size - 1];
		--g_address_book.size;
		printf("ɾ����ϵ�˳ɹ���\n");

	}
	void findpersoninfo() {
		printf("������ϵ��\n");
		if (g_address_book.size <= 0) {
			printf("�޸�ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
			return;
		}
		//�����������ҵ绰
		printf("������Ҫ���ҵ�����:");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < g_address_book.size; ++i) {
			personinfo*info = &g_address_book.persons[i];
			if (strcmp(info->name, name) == 0) {
				printf("[%d] %s\t%s\n", i, info->name, info->phone);
			}
		}
		printf("������ϵ�˳ɹ���\n");
	}
	void updatepersoninfo() {
		printf("������ϵ�ˣ�\n");
		if (g_address_book.size <0) {
			printf("�޸�ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
			return;
		}
		printf("������Ҫ�޸ĵ����:");
		int id = 0;
		scanf("%d", &id);
		if (id<0 || id>g_address_book.size) {
			printf("�޸�ʧ�ܣ�������������\n");
			return;
		}
		personinfo*info = &g_address_book.persons[id];
		printf("�������µ�����:(%s)\n",info->name);
		char name[1024] = { 0 };
		scanf("%s", name);
		if (strcmp(name, "*") != 0) {
			strcpy(info->name,name);
		}
		printf("�������µĵ绰:(%s)\n", info->phone);
		char phone[1024] = { 0 };
		scanf("%s", phone);
		if (strcmp(phone, "*") != 0) {
			strcpy(info->phone, phone);
		}
		printf("������ϵ�˳ɹ���\n");
	}
	void printallpersoninfo() {
		printf("��ӡȫ����ϵ��\n");
		for (int i = 0; i < g_address_book.size; ++i) {
			personinfo*info = &g_address_book.persons[i];
			printf("[%d] %s\t%s\n", i,info->name, info->phone);
		}
		printf("����ӡ��%d������\n",g_address_book.size);
		printf("��ӡȫ����ϵ�˳ɹ���\n");

	}
	void sortpersoninfo() {

	}
	void clearallpersoninfo() {
		printf("���ȫ������\n");
		printf("�����Ҫ���ȫ��������Y/N\n");
		char choice[1024] = { 0 };
		scanf("%s", choice);
		if (strcmp(choice, "y") == 0) {
			g_address_book.size = 0;
			printf("���ȫ�����ݳɹ���\n");
		}
		else {
			printf("��ղ���ȡ����\n");
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
				printf("������������\n");
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

