#include"slist.h"
#include<stdlib.h>
#include<stdio.h>
#include"assert.h"


void SListInit(Slist* s) {
	assert(s);
	s->_pHead = NULL;
}
//�½��ڵ�
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
		//���������
		s->_pHead = pNewNode;
	}
	else {
		//���������һ���ڵ�
		PNode pcur = s->_pHead;
		while (pcur->_pNext){
			pcur = pcur->_pNext;
			//pcur->_pNext = pNewNode;
		}
		pcur->_pNext = pNewNode;
	}
}
void SListPopBack(Slist*s){
	//���ǿ�����ֱ�ӷ���
	assert(s);
	if (NULL == s->_pHead){
		return;
	}
	//ֻ��һ���ڵ�
	else if (NULL == s->_pHead->_pNext){
		free(s->_pHead);
		s->_pHead = NULL;
	}
	//�����ڵ㼰����
	else{
		PNode pPre = NULL;
		PNode pcur = s->_pHead;
	while (pcur->_pNext){
			pPre = pcur;//��pPre��¼pcur
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
	//����Ϊ�պ�ֻ��һ���ڵ����
	if(NULL == s->_pHead){
		return;
	}
   //�ҵ���ɾ���Ľڵ�
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
		else{//��ڵ�
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
//��ǰ�����ж��ٸ��ڵ�
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
}//�Ƴ������е�һ��ֵΪdata��Ԫ��
void SListRemove(Slist*s, SDataType data){
	//1 �ҵ��ýڵ� ��λ��
	//���1 λ���ǵ�һ��Ԫ��
	//���2  λ�ò��ǵ�һ��Ԫ��
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
				//��һ���ڵ�
				s->_pHead = pcur->_pNext;
				free(pcur);
				pcur = s->_pHead;
			}
			else{
				//�ǵ�һ���ڵ�
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



	

