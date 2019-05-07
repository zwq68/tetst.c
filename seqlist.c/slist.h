#pragma once//文件只被包含一次
typedef int SDataType;
//链表的节点
typedef struct SlistNode{
	SDataType  _data;
	struct SlistNode* _pNext; 
}Node, *  PNode;
//链表的结构(不带头结点的单链表)
typedef struct Slist
{
	PNode  _pHead;//给一个 指向链表中的第一个节点的指针
}Slist;
void SListInit(Slist*s);
void SListPushBack(Slist*s, SDataType data);
void SListPopBack(Slist*s);
void SListPushFront(Slist*s, SDataType data);
void SListPopFront(Slist*s);
void SListInsert(PNode pos,SDataType data);
void SListErase(Slist*s,PNode pos);
PNode SListFind(Slist*s);
int  SListSize(Slist*s);
int SListEmpty(Slist*s);
void SListRemove(Slist*s, SDataType data);
void SListRemoveAll(Slist*s, SDataType data);

void TestSlist();