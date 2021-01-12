
#include<stdio.h>
#include<string.h>
typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;

// ��ʼ������ 
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
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->_size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q == NULL || q->_front == NULL)
		return 1;
	else
		return 0;
}
// ���ٶ��� 
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
