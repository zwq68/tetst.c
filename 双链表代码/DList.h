#pragma once

typedef int DLDataType;


typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType _data;
}DLNode, *PDLNode;


void DListInit(PDLNode* pHead);
void DListPushBack(PDLNode pHead, DLDataType data);
void DListPopBack(PDLNode pHead);
void DListPushFront(PDLNode pHead, DLDataType data);
void DListPopFront(PDLNode pHead);
void DListInsert(PDLNode pos, DLDataType data);
void DListErase(PDLNode pos);
void DListClear(PDLNode pHead);
void DListDestroy(PDLNode* pHead);

void TestDList();
