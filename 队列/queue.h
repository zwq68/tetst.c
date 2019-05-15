#pragma once

typedef int QDataType;
//定义节点的结构
typedef struct  QNode{
	struct	QNode *_pNext;
	QDataType _data;
}QNode;
//定义队列
typedef  struct	Queue{
	QNode* _front;//指向队头元素
	QNode*_back;//指向队尾元素
}Queue;

void QueueInit(Queue*q);
void QueuePush(Queue*q, QDataType data);
void QueuePop(Queue*q);
QDataType QueueFront(Queue*q);
QDataType QueueBack(Queue*q);
int QueueSize(Queue*q);
int QueueEmpty(Queue*q);
void QueueDestory(Queue*q);

void TestQueue();