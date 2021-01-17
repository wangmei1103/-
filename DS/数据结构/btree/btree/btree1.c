
#include<stdlib.h>
#include<stdio.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;//空树
	}
	//当前树的根结点
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a,n,pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// 二叉树销毁
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
// 二叉树节点个数  左子树个数+右子树个数+当前结点
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//空树
	if (root == NULL)
		return 0;
	//叶子结点
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	//非叶子
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数 左右子树k-1层结点个数之和
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//空树
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
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
// 二叉树前序遍历  根 左子树  右子树
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// 二叉树中序遍历  左子树  根  右子树
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
// 二叉树后序遍历  左子树  右子树  根
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//队尾入队，队头出队

typedef QDataType;

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
struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}
//初始化
void initQueue(Queue* q)
{
	//空队列
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
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	//Queue q;
	//BTNode* node;
	//initQueue(&q);
	//queuePush(&q, root);
	//while (!queueEmpty(&q))
	//{
	//	//获取队头元素
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
// 判断二叉树是否是完全二叉树
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
		//获取队头元素
		BTNode* node = queueFront(&q);
		queuePop(&q);
		//左右孩子入队
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