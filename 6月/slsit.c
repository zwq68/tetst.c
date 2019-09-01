#include<stdlib.h>
#include<stdio.h>
#include"slist.h"
#include<assert.h>




//  初始化链表
void slistinit(slist *s){
	assert(s);
	s->_Phead = NULL;
}
//  摧毁链表
//void slistdestory(slist *s);

PNode BuyNode( SDataType data){
	
	PNode newNode = malloc(sizeof(Node));
	if (newNode == NULL){
		assert(0);
		return NULL;
	}
	newNode->_data = data;
	newNode->PNext = NULL;
	//申请节点成功之后将节点返回
	return newNode;
}

// 链表的尾插
void slistpushback(slist *s, SDataType data){
	assert(s);
	PNode newNode = BuyNode(data);
	//	情况1 链表为空
	if (s->_Phead == NULL){
		s->_Phead = newNode;
	}
	// 情况2 链表非空  找链表中最后一个节点
	PNode cur = s->_Phead;
	while (cur->PNext){
		cur = cur->PNext;
	}
	cur->PNext = newNode;
}
// 链表的尾删
void slistpopback(slist*s){
	assert(s);
	// 情况1 空链表
	if (s->_Phead == NULL){
		return;
	}
	// 情况2 链表只有一个节点
	else if (s->_Phead->PNext == NULL){
		s->_Phead=NULL;
	}
	// 情况3 链表有多个节点   找到最后一个节点
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

// 链表的头插
void slistpushfront(slist *s, SDataType data){
	assert(s);
	PNode newNode = BuyNode(data);
	newNode->PNext = s->_Phead;
	s->_Phead = newNode;

}
//  链表的头删
void slistpopfront(slist *s){
	assert(s);

	// 1 链表为空
	if (s->_Phead == NULL){
		return;
	}
	PNode	pDelNode = NULL;
	//  找到待删除节点
	pDelNode = s->_Phead;
	s->_Phead = pDelNode->PNext;
	free(pDelNode);
}

// 任意位置插入数据
  void slistinsert(PNode  pos,SDataType data){
	  PNode newNode = NULL;
	  if (pos = NULL){
		  return;
	  }
	  newNode->PNext = pos->PNext;
	  pos->PNext= newNode;

  }
// 任意 位置 删除
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

// 删除链表第一个值为data的元素 
  void slistremovoe(slist *s, SDataType data){
	  assert(s);
	// 情况1 : 链表为空
	  if (s->_Phead == NULL){
		  return;
	  }
	  //   1 找到该节点的位置
	  PNode pPre = NULL;
	  PNode pcur = s->_Phead;
	  while (pcur){
		  if (pcur->_data == data){
			  // 删除节点
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
// 删除链表所有值为data的元素
  void slistremoveall(slist *s, SDataType data){

  }

// 清空链表
int slistclear(slist *s);
//  求当前链表中的节点个数
int slistsize(slist *s);

// 打印链表
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