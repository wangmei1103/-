#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

void listInsert(ListNode* node,LDataType val);

typedef int LDataType;
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

typedef struct List
{
	struct ListNode* _head;
}List;

//��ʼ��
void initList(List* lst)
{
	lst->_head=(struct ListNode*) malloc (sizeof (struct ListNode));	
	lst->_head->_prev = lst->_head->_next = lst->_head;
}

//��������
struct ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode* ) malloc (sizeof(struct ListNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}

//β��
void listPushBack(List* lst,LDataType val)
{
	struct ListNode* tail = lst->_head->_prev;
	struct ListNode* newNode = creatNode(val);
	tail->_next = newNode;
	newNode->_prev = tail;
	lst->_head->_prev = newNode;
	newNode->_next = lst->_head;
	//listInsert(lst->_head,val);
}

//ͷ��
void listPushFront(List* lst,LDataType val)
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* next = lst->_head->_next;
	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;
	next->_prev = newNode;
	newNode->_next = next;
	//listInsert(lst->_head->_next,val);
}

//�����
void listInsert(ListNode* node,LDataType val)
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* prev = node->_prev;
	//prev newnode node
	node->_prev=newNode;
	newNode->_next=node->_next;
	newNode->_prev=prev;
	prev->_next=newNode;
}

//βɾ
void listPopBack(List* lst,LDataType val)
{
	if(lst->_head->_prev == lst->_head)
		return;//������
	struct ListNode* tail = lst->_head->_prev;
	struct ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = lst->_head;
	lst->_head->_prev = prev;
	//listErase(lst->_head->_prev);
}

//ͷɾ
void listPopFront(List* lst)
{
	if(lst->_head->_prev == lst->_head)
		return;
	struct ListNode* prev = lst->_head->_next;
	struct ListNode* next = prev->_next;
	free(prev);
	lst->_head->_next = next;
	next->_prev = lst->_head;
	//listErase(lst->_head->_next);
}


//����ɾ
void listErase(ListNode* node)
{
	//prev node next
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;
	free(node);
	prev->_next = next;
	next->_prev = prev;
}

void printList(List* lst)
{
	struct ListNode* cur;
	while(cur != lst->_head)
	{
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void listDestroy(List* lst)
{
	struct ListNode* cur = lst->_head->_next;
	while(cur != lst->_head)
	{
		struct ListNode* next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	free(lst->_head);
	lst->_head = NULL;
}

int main()
{
	system("pause");
	return 0;
}