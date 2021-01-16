#include<stdio.h>
#include<stdlib.h>

//队尾入队，队头出队

typedef int QDataType;

typedef struct QNode
{ 
	struct QNode* _next; 
	QDataType _data; 
}QNode; 

// 队列的结构
typedef struct Queue
{ 
	//头尾指针
	QNode* _head; 
	QNode* _tail; 
	int _size;
}Queue;
 
//初始化
void initQueue(Queue* q)
{
	//空队列
	if(q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}

struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}

//尾插
void queuePush(Queue* q,QDataType val)
{
	struct	QNode* node = creatNode(val);
	if(q->_head == NULL)
		q->_head = q->_tail = node;
	else{
		q->_tail->_next = node;
		q->_tail=node;
	}
	++q->_size;
}


//头删
void queuePop(Queue* q)
{
	if(q == NULL || q->_head == NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	if (q->_head == NULL)
		q->_tail = NULL;
	--q->_size;
}

int queueSize(Queue* q)
{
	//遍历
	if(q == NULL)
		return 0;
	return q->_size;
}

QDataType queueFront(Queue* q)
{
	return q->_head->_data;
}

QDataType queueBack(Queue* q)
{
	return q->_tail->_data;
}


int queueEmpty(Queue* q)
{
	return q->_head == NULL;
}

void queueDestroy(Queue* q)
{
	QNode* cur = q->_head;
	while(cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur=q->_head;
	}
}

int main()
{
	system("pause");
	return 0;
}