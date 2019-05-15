#pragma once

typedef int QDataType;
//����ڵ�Ľṹ
typedef struct  QNode{
	struct	QNode *_pNext;
	QDataType _data;
}QNode;
//�������
typedef  struct	Queue{
	QNode* _front;//ָ���ͷԪ��
	QNode*_back;//ָ���βԪ��
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