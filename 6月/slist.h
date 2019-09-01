#pragma once 

typedef int SDataType;

// 定义链表节点
typedef struct slistnode{
	SDataType _data;
	struct slistnode *PNext;
}Node,* PNode;


//定义链表结构
typedef struct slist{
	PNode _Phead;// 对于链表只需要存储头结点
}slist;// 给链表类型取别名

//  初始化链表
void slistinit(slist *s);


// 链表的尾插
void slistpushback(slist *s,  SDataType data);
// 链表的尾删
void slistpopback(slist*s);

// 链表的头插
void slistpushfront(slist *s, SDataType data);
//  链表的头删
void slistpopfront(slist *s);


// 任意位置插入数据
void slistinsert(PNode  pos, SDataType data);
// 任意 位置 删除
void slisterase(slist *s,PNode pos);


// 删除链表第一个值为data的元素 
void slistremovoe(slist *s, SDataType data);
// 删除链表所有值为data的元素
void slistremoveall(slist *s, SDataType data);

// 清空链表
int slistclear(slist *s);
//  求当前链表中的节点个数
int slistsize(slist *s);



