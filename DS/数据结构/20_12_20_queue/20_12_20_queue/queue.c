#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QNode
{ 
	struct QNode* _next; 
	QDataType _data; 
}QNode; 

// ���еĽṹ
typedef struct Queue
{ 
	//ͷβָ��
	QNode* _head; 
	QNode* _tail; 
	int _size;
}Queue;
 
//��ʼ��
void initQueue(Queue* q)
{
	if(q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}

//β��
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

struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}

//ͷɾ
void queuePop(Queue* q)
{
	if(q==NULL || q->_head ==NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head=next;
	--q->_size;
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
int queueSize(Queue* q)
{
	//����
	if(q == NULL)
		return;
	return q->_size;
}
void queueDeatroy(Queue* q)
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
	return 0;
}