#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

QNode*BuyQueueNode(QDataType Data){
	QNode*pNewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == pNewNode){
		assert(0);
		return;
	}
	pNewNode->_data = Data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void QueueInit(Queue*q){
	assert(q);
	q->_front = q->_back = NULL;
}
void QueuePush(Queue*q, QDataType data){
	assert(q);
	QNode*pNewNode = BuyQueueNode(data);
	if (QueueEmpty(q)){
		q->_front = q->_back = pNewNode;
	}
	else{
		q->_back->_pNext = pNewNode;
		q->_back = pNewNode;
	}
}
void QueuePop(Queue*q){
	assert(q);

	if (QueueEmpty(q)){
		return ;
	}
	QNode*pDelNode = q->_front;
	if (NULL == pDelNode->_pNext){
		q->_front = q->_back = NULL;
	}
	else{
		q->_front = pDelNode->_pNext;
	}
	free(pDelNode);
}
QDataType QueueFront(Queue*q){
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue*q){
	assert(q);
	return q->_back->_data;
}
int QueueSize(Queue*q){
	int count = 0;
	QNode*pcur = q->_front;
	while (pcur){
		count++;
		pcur = pcur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue*q){
	assert(q);
	return NULL == q->_front;
}
void QueueDestory(Queue*q){
	QNode*pcur = q->_front;
	while (pcur){
		q->_front = pcur->_pNext;
		free(pcur);
		pcur = q->_front;
	}
	q->_front = q->_back = NULL;
}

void TestQueue(){
	Queue  q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("front=%d\n", QueueFront(&q));
	printf("back=%d\n", QueueBack(&q));
	printf("size=%d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front=%d\n", QueueFront(&q));
	printf("back=%d\n", QueueBack(&q));
	printf("size=%d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("front=%d\n", QueueFront(&q));
	printf("back=%d\n", QueueBack(&q));
	printf("size=%d\n", QueueSize(&q));

	QueuePop(&q);
	
	printf("size=%d\n", QueueSize(&q));








	QueueDestory(&q);
}