#include<stdio.h>
#include<string.h>
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate(LTDataType x)
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->_data = x;
	head->_next = head->_prev = NULL;
	return head;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	struct ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		struct ListNode* next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	free(pHead);
	pHead = NULL;
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	struct ListNode* cur = pHead->_next;
	while (cur!=pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// ˫������β��
//tail  node  pHead
void ListPushBack(ListNode* pHead, LTDataType x)
{
	struct ListNode* tail = pHead->_prev;
	struct ListNode* node = ListCreate(x);
	tail->_next = node;
	node->_prev = tail;
	pHead->_prev = node;
	node->_next = pHead;
}
// ˫������βɾ
//prev tail pHead
void ListPopBack(ListNode* pHead)
{
	if (pHead->_prev == pHead)
		return;
	struct ListNode* tail = pHead->_prev;
	struct ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = pHead;
	pHead->_prev = prev;
}
// ˫������ͷ��
// pHead node next
void ListPushFront(ListNode* pHead, LTDataType x)
{
	struct ListNode* node = ListCreate(x);
	struct ListNode* next = pHead->_next;
	pHead->_next = node;
	node->_prev = pHead;
	next->_prev = node;
	node->_next = next;
}
// ˫������ͷɾ
//pHead prev next
void ListPopFront(ListNode* pHead)
{
	if (pHead->_prev == pHead)
		return;
	struct ListNode* prev = pHead->_next;
	struct ListNode* next = prev->_next;
	free(prev);
	pHead->_next = next;
	next->_prev = pHead;
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	if (pHead->_prev == pHead)
		return;
	struct ListNode* head = pHead;
	while (pHead->_data != x)
	{
		pHead = pHead->_next;
		if (pHead->_next = head)
			return NULL;
	}
	return pHead;
}
// ˫��������pos��ǰ����в���
//prev node pos
void ListInsert(ListNode* pos, LTDataType x)
{
	struct ListNode* node = ListCreate(x);
	struct ListNode* prev = pos->_prev;
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}
// ˫������ɾ��posλ�õĽڵ�
//prev pos next
void ListErase(ListNode* pos)
{
	struct ListNode* prev = pos->_prev;
	struct ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

int main()
{
	return 0;
}