#pragma once//�ļ�ֻ������һ��
typedef int SDataType;
//����Ľڵ�
typedef struct SlistNode{
	SDataType  _data;
	struct SlistNode* _pNext; 
}Node, *  PNode;
//����Ľṹ(����ͷ���ĵ�����)
typedef struct Slist
{
	PNode  _pHead;//��һ�� ָ�������еĵ�һ���ڵ��ָ��
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