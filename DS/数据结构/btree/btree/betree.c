/*
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
//�������Ľ�㣺������
typedef struct BNode
{
	struct BNode* _left;
	struct BNode* _right;
	DataType _data;
}Node;

typedef struct BTree
{
	//�������ĸ��ڵ�
	Node* _root;
}BTree;

//void createBinaryTree(BTree* bt)
//{
//	//����һ������
//	bt->_root = NULL;
//}
//����һ�������������ض�����
//�����˳��Ϊǰ�����
//ǰ�����������ABD##E#H##CF##G##

Node* createBinaryTree(DataType arr[],int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;//����
	}
	//��ǰ���ĸ����
	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[*idx];
	(*idx)++;
	root->_left = createBinaryTree(arr, idx);
	root->_right = createBinaryTree(arr, idx);
	return root;
}

//ǰ�����   ��  ������  ������
void preOrder(Node* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}
//�������  ������  ��  ������
void inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//�������  ������  ������  ��
void postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}
//������+������+�����ĸ�����
int bTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

//�Ե�ǰ���Ϊ�������ĸ߶ȣ�max�����������ĸ߶ȣ�+1
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
}

//������Ҷ�ӽ��ĸ���
int bTreeLeafSize(Node* root)
{
	//����
	if (root == NULL)
		return 0;
	//Ҷ�ӽ��
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	//��Ҷ��
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}
//��K��Ľ������������Ϊ��һ��
//��������k-1���������
int bTreeKSize(Node* root,int k)
{
	//����
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//����
Node* bTreeFind(Node* root, char ch)
{
	if (root)
	{
		Node* node;
		if (root->_data == ch)
			return root;
		node = bTreeFind(root->_left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->_right, ch);
	}
	else
		return NULL;
}

void bTreeDestroy(Node** root)
{
	if (*root)
	{
		bTreeDestroy(&(*root)->_left);
		bTreeDestroy(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}
//��β��ӣ���ͷ����

typedef Node* QDataType;

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
struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}
//��ʼ��
void initQueue(Queue* q)
{
	//�ն���
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}
void queuePush(Queue* q, QDataType val)
{
	struct	QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else {
		q->_tail->_next = node;
		q->_tail = node;
	}
	++q->_size;
}
void queuePop(Queue* q)
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	if (q->_head == NULL)
		q->_tail = NULL;
	--q->_size;
}
QDataType queueFront(Queue* q)
{
	//if (q == NULL)
	//	return NULL;
	return q->_head->_data;
}
int queueEmpty(Queue* q)
{
	return q->_head == NULL;
}

void queueDestroy(Queue* q)
{
	QNode* cur = q->_head;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = q->_head;
	}
}

void bTreeLevelOrder(Node* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q,root);
	while (!queueEmpty(&q))
	{
		Node* node = queueFront(&q);
		queuePop(&q);
		printf("%c ", node->_data);
		if (node->_left)
			queuePush(&q,node->_left);
		if (node->_right)
			queuePush(&q, node->_right);
	}
	printf("\n");
}
//��ȫ������
int isCompleteBtree(Node* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		Node* node = queueFront(&q);
		queuePop(&q);
		//���Һ������
		if (node)
		{
			queuePush(&q, node->_left);
			queuePush(&q, node->_right);
		}
		else
			break;
	}
	while (!queueEmpty(&q))
	{
		Node* node = queueFront(&q);
		if (node)
			return 0;
	}
	return 1;
}

////�����ж�
//void push_back(list*, Node*);
//void pop_front(list*);
//Node* head(list*);
//int listEmpty(list*);
//int isCompleteBtree(Node* root)
//{
//	list* p;
//	if (root)
//		push_back(&p, root);
//	while (!listEmpty(&p))
//	{
//		Node* node = head(&p);
//		pop_front(&p);
//		if (node)
//		{
//			push_back(&p, node->_left);
//			push_back(&p, node->_right);
//		}
//		else
//			break;
//	}
//	while (!listEmpty(&p))
//	{
//		Node* node = head(&p);
//		pop_front(&p);
//		if (node)
//			return 0;
//	}
//	return 1;
//}
void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	Node* root = createBinaryTree(arr, &idx);
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	printf("%d ", bTreeSize(root));
	printf("\n");
	printf("Height:%d\n", bTreeHeight(root));
	printf("leafSize:%d\n", bTreeLeafSize(root));
	printf("kSize:k-->%d: %d\n", 4, bTreeKSize(root, 4));
	printf("kSize:k-->%d: %d\n", 3, bTreeKSize(root, 3));
	printf("kSize:k-->%d: %d\n", 2, bTreeKSize(root, 2));
	printf("kSize:k-->%d: %d\n", 1, bTreeKSize(root, 1));
	Node* node;
	node = bTreeFind(root, 'G');

	bTreeDestroy(&root);
}
int main()
{
	test();
	return 0;
}*/