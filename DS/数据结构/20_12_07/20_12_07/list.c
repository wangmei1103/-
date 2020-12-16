#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#define SLTDateType int  
typedef struct ListNode
{
	SLTDateType data;
	struct ListNode* next;
}SListNode;


struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow=head;
	struct ListNode* fast=head;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

struct ListNode* reverse(ListNode* head)
{
	if(head==NULL||head->next==NULL)
		return head;
	struct ListNode* newhead,*cur,*next;
	newhead=NULL;
	cur=head;
	while(cur)
	{
		next=cur->next;
		cur->next=newhead;
		newhead=cur;
		cur=next;
	}
	return newhead;
}
bool chkPalindrome(ListNode* A)
{
	if(A==NULL||A->next=NULL)
		return true;
	ListNode* middleNode(A);

	ListNode* reverse(slow);
}



struct ListNode* List(struct ListNode* phead,int x)
{
	if(phead==NULL)
		return phead;
	struct ListNode* lessHead,*lessTail,*greaterHead,*greaterTail;
	lessHead=lessTail=greaterHead=greaterTail=NULL;
	struct ListNode* cur=phead
;	while(cur)
	{
		if(cur->data<x){
			if(lessTail==NULL)
			{
				lessHead=lessTail=NULL;
			}
			else{
				lessTail->next=cur;
				lessTail=lessTail->next;
			}
			cur=cur->next;
		}
		else
		{
			if(greaterTail==NULL)
			{
				greaterHead=greaterTail=NULL;
			}

			else
			{
				greaterTail->next=cur;
				greaterTail=greaterTail->next;
			}
			cur=cur->next;
		}
	}
	if (greaterTail)
		greaterTail->next=NULL;
	if (lessHead==NULL)
	{
		return greaterHead;
	}
	if(greaterHead==NULL)
	{
		if(lessTail)
			lessTail->next=NULL;
		return lessHead;
	}
	lessTail->next=greaterHead;
	return lessHead;
}

//找中点
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow=head;
	struct ListNode* fast=head;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}




















/*

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
//#include"list.h"

#define SLTDateType int  
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
// 动态申请一个节点
SListNode* BySListNode(SLTDateType x)
{
	SListNode* Node = (SListNode*)malloc(sizeof(SListNode));
	Node->data = x;
	Node->next = NULL;
	return Node;
}
// 单链表打印
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

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode=BySListNode(x);
	if (*pplist==NULL)
		*pplist=newNode;
	else{
		SListNode* tail=*pplist;
		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		tail->next=newNode;
	}
}

// 单链表的头插
//void SListPushFront(SListNode** pplist, SLTDateType x)
//{
//	assert(pplist!=NULL);
//	SListNode* newNode=BySListNode(x);
//	if(*pplist==NULL)
//		*pplist=newNode;
//	else{
//		newNode->next=*pplist;
//		*pplist=newNode;
//	}
//}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	SListNode* prev=NULL;
	SListNode* tail=*pplist;
	if(tail==NULL||tail->next==NULL){
		free(tail);
		*pplist=NULL;
	}
	else{
		while(tail->next)
		{
			prev=tail;
			tail=tail->next;
		}
		free(tail);
		tail=NULL;
		prev->next=NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode* newNode=*pplist;
	if(newNode==NULL)
		return;
	else if(newNode->next==NULL)
	{
		free(newNode);
		*pplist=NULL;
	}
	else{
		SListNode* next=newNode->next;
		free(newNode);
		*pplist=next;
	}
	/*assert(*pplist!=NULL);
	SListNode* newNode=*pplist;
	if(newNode!=NULL)
	{
		*pplist=newNode->next;
		free(newNode);
	}*/
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* newNode=plist;
	while(newNode!=NULL && newNode->data!=x)
		newNode=newNode->next;
	return newNode;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos!=NULL);
	SListNode* next = pos->next;
	SListNode* newNode=BySListNode(x);
	pos->next = newNode;
	newNode->next = next;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos!=NULL);
	SListNode* next = pos->next;
	if (next != NULL)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}
// 单链表的销毁
void SListDestory(SListNode* plist)
{
	assert(plist!=NULL);
	SListNode* newNode= plist;
	SListNode* p=newNode->next;
	newNode->next=NULL;
	while(p!=NULL)
	{
		newNode=p;
		p=p->next;
		newNode->next=plist;
		plist=newNode;
	}
}

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
//	//初始化为空
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
//	//创建节点
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