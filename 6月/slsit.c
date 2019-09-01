#include<stdlib.h>
#include<stdio.h>
#include"slist.h"
#include<assert.h>




//  ��ʼ������
void slistinit(slist *s){
	assert(s);
	s->_Phead = NULL;
}
//  �ݻ�����
//void slistdestory(slist *s);

PNode BuyNode( SDataType data){
	
	PNode newNode = malloc(sizeof(Node));
	if (newNode == NULL){
		assert(0);
		return NULL;
	}
	newNode->_data = data;
	newNode->PNext = NULL;
	//����ڵ�ɹ�֮�󽫽ڵ㷵��
	return newNode;
}

// �����β��
void slistpushback(slist *s, SDataType data){
	assert(s);
	PNode newNode = BuyNode(data);
	//	���1 ����Ϊ��
	if (s->_Phead == NULL){
		s->_Phead = newNode;
	}
	// ���2 ����ǿ�  �����������һ���ڵ�
	PNode cur = s->_Phead;
	while (cur->PNext){
		cur = cur->PNext;
	}
	cur->PNext = newNode;
}
// �����βɾ
void slistpopback(slist*s){
	assert(s);
	// ���1 ������
	if (s->_Phead == NULL){
		return;
	}
	// ���2 ����ֻ��һ���ڵ�
	else if (s->_Phead->PNext == NULL){
		s->_Phead=NULL;
	}
	// ���3 �����ж���ڵ�   �ҵ����һ���ڵ�
	else{
		PNode cur = s->_Phead;
		PNode pre = NULL;
		
		while (cur->PNext){
			pre = cur;
			cur = cur->PNext;
		}
		free(cur);
		pre->PNext = NULL;
	}

}

// �����ͷ��
void slistpushfront(slist *s, SDataType data){
	assert(s);
	PNode newNode = BuyNode(data);
	newNode->PNext = s->_Phead;
	s->_Phead = newNode;

}
//  �����ͷɾ
void slistpopfront(slist *s){
	assert(s);

	// 1 ����Ϊ��
	if (s->_Phead == NULL){
		return;
	}
	PNode	pDelNode = NULL;
	//  �ҵ���ɾ���ڵ�
	pDelNode = s->_Phead;
	s->_Phead = pDelNode->PNext;
	free(pDelNode);
}

// ����λ�ò�������
  void slistinsert(PNode  pos,SDataType data){
	  PNode newNode = NULL;
	  if (pos = NULL){
		  return;
	  }
	  newNode->PNext = pos->PNext;
	  pos->PNext= newNode;

  }
// ���� λ�� ɾ��
  void slisterase(slist *s,PNode pos){
	  assert(s);
	  if (pos == NULL || s->_Phead == NULL){
		  return;
	  }
	

  }

  PNode slistfind(slist *s, SDataType data){
	  assert(s);
	  PNode pcur = s->_Phead;
	  while (pcur){
		  if (data = pcur->_data){
			  return pcur;
		  }
		  pcur = pcur->PNext;
	  }
	  return  NULL;
  }

// ɾ�������һ��ֵΪdata��Ԫ�� 
  void slistremovoe(slist *s, SDataType data){
	  assert(s);
	// ���1 : ����Ϊ��
	  if (s->_Phead == NULL){
		  return;
	  }
	  //   1 �ҵ��ýڵ��λ��
	  PNode pPre = NULL;
	  PNode pcur = s->_Phead;
	  while (pcur){
		  if (pcur->_data == data){
			  // ɾ���ڵ�
			  if (pcur == s->_Phead){
				  s->_Phead = pcur->PNext;
				  //free(pcur);
			  }
			  else{
				  pPre->PNext = pcur->PNext;
				 // free(pcur);
			  }
			  free(pcur);
			  return;
		  }
		  else{
			  pPre = pcur;
			  pcur = pcur->PNext;
		  }
	  }
	  
  }
// ɾ����������ֵΪdata��Ԫ��
  void slistremoveall(slist *s, SDataType data){

  }

// �������
int slistclear(slist *s);
//  ��ǰ�����еĽڵ����
int slistsize(slist *s);

// ��ӡ����
void print_slist(slist*s){
	assert(s);
   PNode pcur = s->_Phead;
	while (pcur){
		printf("%d-->", pcur->_data);
		pcur = pcur->PNext;
	}
	printf("NULL\n");

}


void testlist(){
	slist s;

	slistinit(&s);
	slistpushfront(&s, 1);
	slistpushfront(&s, 2);
	slistpushfront(&s, 3);
	slistpushfront(&s, 4);
	slistpushfront(&s, 5);


	slistpopfront(&s);
	
	slistpopback(&s);
	print_slist(&s);


}