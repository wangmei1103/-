#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QNode
{ 
 struct QNode* _pNext; 
 QDataType _data; 
}QNode; 
// 队列的结构
typedef struct Queue
{ 
	//头尾指针
	QNode* _head; 
	QNode* _tail; 
}Queue;
 
//初始化
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
	//遍历
}