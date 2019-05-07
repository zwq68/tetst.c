#include"slist.h"
#include<stdlib.h>
#include<stdio.h>
#include"assert.h"


void SListInit(Slist* s) {
	assert(s);
	s->_pHead = NULL;
}
//新建节点
   PNode BuySlistNode(SDataType data){
	PNode pNewNode = malloc(sizeof(Node));
	if (NULL == pNewNode){
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
void SListPushBack(Slist*s, SDataType data){
	assert(s);
	PNode pNewNode = BuySlistNode(data);
	if (NULL == s->_pHead){
		//空链表情况
		s->_pHead = pNewNode;
	}
	else {
		//找链表最后一个节点
		PNode pcur = s->_pHead;
		while (pcur->_pNext){
			pcur = pcur->_pNext;
			//pcur->_pNext = pNewNode;
		}
		pcur->_pNext = pNewNode;
	}
}
void SListPopBack(Slist*s){
	//考虑空链表，直接返回
	assert(s);
	if (NULL == s->_pHead){
		return;
	}
	//只有一个节点
	else if (NULL == s->_pHead->_pNext){
		free(s->_pHead);
		s->_pHead = NULL;
	}
	//两个节点及以上
	else{
		PNode pPre = NULL;
		PNode pcur = s->_pHead;
	while (pcur->_pNext){
			pPre = pcur;//用pPre记录pcur
			pcur = pcur->_pNext;
		}
		free(pcur);
		pPre->_pNext = NULL;
	}
}
void SListPushFront(Slist*s, SDataType data){
	assert(s);
	PNode pNewNode = BuySlistNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}
void SListPopFront(Slist*s){
	PNode pDelNode = NULL;
	assert(s);
	//链表为空和只有一个节点情况
	if(NULL == s->_pHead){
		return;
	}
   //找到待删除的节点
	 pDelNode = s->_pHead;
	 s->_pHead=pDelNode->_pNext;
	free(pDelNode);
}
void SListInsert(PNode pos, SDataType data){
	if (NULL == pos){
		return;
	}
	PNode pNewNode = BuySlistNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
void SListErase(Slist*s, PNode pos){
	assert(s);
	if (NULL == pos || NULL == s->_pHead){
		return;
		if (pos == s->_pHead){
			s->_pHead == pos->_pNext;
			free(pos);
		}
		else{//多节点
			PNode pPrepos = s->_pHead;
			while (pPrepos&&pPrepos->_pNext != pos){
				pPrepos = pPrepos->_pNext;

			}
			if (pPrepos){
				pPrepos->_pNext = pos->_pNext;
			}
			pPrepos->_pNext = pos->_pNext;
			free(pos);
				
		}
	}
}


PNode SListFind(Slist*s, SDataType data){
	assert(s);
	PNode pcur = s->_pHead;
	while (pcur){
		if (pcur->_data = data){
			return pcur;
		}
		pcur = pcur->_pNext;
	}
	return NULL;
}
//当前链表有多少个节点
size_t SListSize(Slist*s){
	assert(s);
	PNode pcur = s->_pHead;
	size_t count = 0;
	while (pcur){
		count ++;
		pcur = pcur->_pNext;
	}
	return count;
}
int SListEmpty(Slist*s){
	assert(s);
	if (s->_pHead == NULL){
		return NULL;
	}
}//移除链表中第一个值为data的元素
void SListRemove(Slist*s, SDataType data){
	//1 找到该节点 的位置
	//情况1 位置是第一个元素
	//情况2  位置不是第一个元素
	   assert(s);
	if (NULL == s->_pHead){
		return ;
	}
	PNode pPre = NULL;
	PNode pcur = s->_pHead;
	while (pcur){
		if (pcur->_data == data){
			if (pcur == s->_pHead){
				s->_pHead = pcur->_pNext;
			
			}
			else{
				pPre->_pNext = pcur->_pNext;
				
			}
			free(pcur);
			return;
		}
		else{
			pPre = pcur;
			pcur = pcur->_pNext;
		}
	}
}
void SListRemoveAll(Slist*s, SDataType data){
	assert(s);
	if (NULL == s->_pHead){
		return NULL;
	}
	PNode pPre = NULL;
	PNode pcur = s->_pHead;
	while (pcur){
		if (data == pcur->_data){
			if (pPre == NULL){
				//第一个节点
				s->_pHead = pcur->_pNext;
				free(pcur);
				pcur = s->_pHead;
			}
			else{
				//非第一个节点
				pPre->_pNext = pcur->_pNext;
				free(pcur);
				pcur = pPre->_pNext;

			}
		}
		else{
			pPre = pcur;
			pcur = pcur->_pNext;

		}
	}
	return s->_pHead;
}

void printSlist(Slist*s){
	assert(s);
	PNode pcur = s->_pHead;
	while (pcur){
		printf("%d---->", pcur->_data);
		pcur = pcur->_pNext;
	}
	printf("NULL\n");
}

	void TestSlist1(){
		Slist s;
		SListInit(&s);
		SListPushBack(&s, 1);
		SListPushBack(&s, 2);
		SListPushBack(&s, 3);
		SListPushBack(&s, 4);
		SListPushBack(&s, 5);
		SListPopBack(&s);
		SListPopBack(&s);
		SListPopBack(&s);
		
	
	
		

		printSlist(&s);

	}
	void TestSlist2(){
		Slist s;
		SListInit(&s);
		SListPushFront(&s, 1);
		SListPushFront(&s, 2);
		SListPushFront(&s, 3);
		SListPushFront(&s, 4);
		SListPushFront(&s, 5);
		printSlist(&s);

		SListPopFront(&s);
		printSlist(&s);

		SListPopFront(&s);
		SListPopFront(&s);
		SListPopFront(&s); 
		SListPopFront(&s);
		SListPopFront(&s);
		printSlist(&s);
	}
	void TestSlist(){
		//TestSlist1();
		TestSlist2();
	}



	

