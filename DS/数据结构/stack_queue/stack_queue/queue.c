
#include<stdio.h>
#include<string.h>
typedef int QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	if (q == NULL)
		return;
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
QNode* createNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	QNode* node = createNode(data);
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else 
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	q->_size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return;
	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;
	if (q->_front == NULL)
		q->_rear = NULL;
	q->_size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->_size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return 1;
	else
		return 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	QNode* node = q->_front;
	while (node)
	{
		QNode* next = node->_next;
		free(node);
		node = q->_front;
	}
}
int main()
{
	return 0;
}
