#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QNode
{ 
 struct QNode* _pNext; 
 QDataType _data; 
}QNode; 
// ���еĽṹ
typedef struct Queue
{ 
	//ͷβָ��
	QNode* _head; 
	QNode* _tail; 
}Queue;
 
//��ʼ��
void initQueue(Queue* q)
{

}


void queuePush(Queue* q,QDataType val)
{

}


void queuePop(Queue* q)
{

}

QDataType queueFront(Queue* q)
{

}

QDataType queueBack(Queue* q)
{

}

int queueSize(Queue* q)
{
	//����
}