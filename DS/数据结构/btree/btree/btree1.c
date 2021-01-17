
#include<stdlib.h>
#include<stdio.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;//����
	}
	//��ǰ���ĸ����
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a,n,pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}
// �������ڵ����  ����������+����������+��ǰ���
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	//����
	if (root == NULL)
		return 0;
	//Ҷ�ӽ��
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	//��Ҷ��
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ���� ��������k-1�������֮��
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//����
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root)
	{
		BTNode* node;
		if (root->_data == x)
			return root;
		node = BinaryTreeFind(root->_left, x);
		if (node)
			return node;
		else
			return BinaryTreeFind(root->_right, x);
	}
	else
		return NULL;
}
// ������ǰ�����  �� ������  ������
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// �������������  ������  ��  ������
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
// �������������  ������  ������  ��
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//��β��ӣ���ͷ����

typedef QDataType;

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
	if (q == NULL)
		return NULL;
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
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//Queue q;
	//BTNode* node;
	//initQueue(&q);
	//queuePush(&q, root);
	//while (!queueEmpty(&q))
	//{
	//	//��ȡ��ͷԪ��
	//	node = queueFront(&q);
	//	printf("%c ", node->_data);
	//	if (node->_left)
	//	{
	//		queuePush(&q, node->_left);
	//	}
	//	if (node->_right)
	//	{
	//		queuePush(&q, node->_right);
	//	}
	//	queuePop(&q);
	//}
	//queueDestroy(&q);
	//printf("\n");
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		BTNode* node = queueFront(&q);
		queuePop(&q);
		printf("%c ", node->_data);
		if (node->_left)
			queuePush(&q, node->_left);
		if (node->_right)
			queuePush(&q, node->_right);
	}
	printf("\n");
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//Queue q;
	//BTNode* node;
	//int tag = 0;
	//initQueue(&q);
	//queuePush(&q, root);
	//while (!queueEmpty(&q))
	//{
	//	node = queueFront(&q);
	//	if (node->_right && !node->_left)
	//		return 0;
	//	if (tag && (node->_right || node->_left))
	//		return 0;
	//	if (node->_left)
	//	{
	//		queuePush(&q, node->_left);
	//	}
	//	if (node->_right)
	//	{
	//		queuePush(&q, node->_right);
	//	}
	//	else
	//		tag = 1;
	//	queuePop(&q);
	//}
	//queueDestroy(&q);
	//return 1;
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		BTNode* node = queueFront(&q);
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
		BTNode* node = queueFront(&q);
		if (node)
			return 0;
	}
	return 1;
}

void test()
{
	char a[] = "ABD##E#H##CF##G##";
	int pi = 0;
	int n = sizeof(a) / sizeof(a[0]);
	BTNode* root = BinaryTreeCreate(a, n, &pi);
	printf("size:%d\n", BinaryTreeSize(root));
	printf("leafsize:%d\n",BinaryTreeLeafSize(root));
	printf("ksize:k=%d: %d\n", 5, BinaryTreeLevelKSize(root, 5));
	printf("ksize:k=%d: %d\n", 4, BinaryTreeLevelKSize(root, 4));
	printf("ksize:k=%d: %d\n", 3, BinaryTreeLevelKSize(root, 3));
	printf("ksize:k=%d: %d\n", 2, BinaryTreeLevelKSize(root, 2));
	printf("ksize:k=%d: %d\n", 1, BinaryTreeLevelKSize(root, 1));
	BTNode* node;
	node = BinaryTreeFind(root, 'E');

	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	BinaryTreeComplete(root);
	BinaryTreeDestory(&root);
}
int main()
{
	test();
	return 0;
}