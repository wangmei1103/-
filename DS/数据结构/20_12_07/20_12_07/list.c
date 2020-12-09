#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//#include"list.h"

#define SLTDateType int
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
// ��̬����һ���ڵ�
SListNode* BySListNode(SLTDateType x)
{
	SListNode* Node = (SListNode*)malloc(sizeof(SListNode));
	Node->data = x;
	Node->next = NULL;
	return Node;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* p=plist;
	while(p != NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf(".\n");
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	//assert(*pplist != NULL);
}


// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestory(SListNode* plist);
 

int main()
{
	return 0;
}






//typedef int LDataType;
//typedef struct listNode
//{
//	LDataType _data;
//	struct listNode*_next;
//}listNode;
//listNode* creatListNode(int val){
//}
//typedef struct list
//{
//	listNode* _head;
//}list;
//void listInit(list* lst)
//{
//	//��ʼ��Ϊ��
//	if(lst==NULL)
//		return;
//	lst->_head=NULL;
//}
//void listPushBack(list* lst,LDataType val)
//{
//	if(lst->_head=NULL)
//	{
//		lst->_head=creatListNode(val);
//	}
//	else{
//		listNode* tail=lst->_head;
//		while(tail->_next!=NULL)
//		{
//			tail=tail->_next;
//		}
//		tail->_next=creatListNode(val);
//	}
//}
///*
//void listPopBack(list* lst)
//{
//	if(lst==NULL||lst->_head==NULL)
//		return;
//	listNode* prev=NULL;
//	listNode* tail=lst->_head;
//	while(tail->_next!=NULL)
//	{
//		prev=tail;
//		tail=tail->_next;
//	}
//	free(tail);
//	if(prev==NULL)
//		lst->_head=NULL;
//	else
//		prev->_next=NULL;
//}
//*/
//void listPushFront(list* lst,LDataType val)
//{
//	if (lst==NULL)
//		return;
//	//�����ڵ�
//	listNode* node=creatListNode(val);
//	node->_next=lst->_head;
//	lst->_head=node;
//}
//
//void listPopBack(list* lst,LDataType val)
//{
//	if(lst==NULL||lst->_head==NULL)
//		return;
//	listNode* next=lst->_head->_next;
//	free(lst->_head);
//	lst->_head=next;
//}
//
//void insertAfter(listNode* node,LDataType val)
//{
//	if (node==NULL)
//		return;
//	listNode* newNode=creatListNode(val);
//	listNode* next=node->_next;
//	node->_next=newNode;
//	newNode->_next=next;
//}
//
//void listEraseAfter(listNode* node)
//{
//	if(node==NULL||node->_next==NULL)
//		return;
//	listNode* next=node->_next;
//	listNode* nextnext=next->_next;
//	free(next);
//	node->_next=nextnext;
//}
//
//
//listNode* listFind(list* lst,LDataType val)
//{
//	if(lst==NULL||lst->_head==NULL)
//		return NULL;
//	listNode
//
//	return NULL;
//}
//
//void listDestory(listNode* lst)
//{
//	if(lst==NULL||lst->_head==NULL)
//		return;
//	listNode* next=lst->_head->_next;
//	listNode* cur=next->_next;
//	while(next!=NULL)
//	{
//		free(next);
//		next=cur;
//		cur=cur->_next;
//	}
//	free(lst->_head);
//	lst->_head=NULL;
//}
//
//void listErase(listNode* node)
//{
//	if(node==NULL)
//		return;
//	listNode* prev;
//	listNode* next=node->_next;
//	
//}