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

//8. 输入两个链表，找出它们的第一个公共结点
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* curA,* curB;
    curA=headA;curB=headB;
    int lenA=0,lenB=0;
    while(curA)
    {
        ++lenA;
        curA=curA->next;
    }
    while(curB)
    {
        ++lenB;
        curB=curB->next;
    }
    curA=headA;curB=headB;
    int gap=abs(lenA-lenB);
    if(lenA>lenB)
    {
        while(gap--)
        {
            curA=curA->next;
        }
    }
    else{
        while(gap--)
        {
            curB=curB->next;
        }
    }
    while(curA && curB)
    {
        if(curA==curB)
        {
            return curA;
        }
        curA=curA->next;
        curB=curB->next;
    }
    return NULL;
}

//9. 给定一个链表，判断链表中是否有环
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast,*slow;
    fast=slow=head;
    if(head==NULL)
        return false;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
            return true;
    }
    return false;
}

struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL)
        return NULL;
    struct ListNode* fast,* slow;
    fast = slow = head;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            slow=head;
            while(slow!=fast)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}


// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深度拷贝



//对链表进行插入排序
struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* node=head->next;
    //有序数据的尾结点
    struct ListNode* tail=head;
    while(node)
    {
        if(node->val < tail->val)
        {
            struct ListNode* prev,*cur;
            prev=NULL;
            cur=head;
            while(cur && cur->val <= node->val)
            {
                prev=cur;
                cur=cur->next;
            }
            tail->next=node->next;
            if(prev)
            {
                prev->next=node;
            }
            else{
                head=node;
            }
            node->next=cur;
            node=tail->next;
        }
        else{
            tail = tail->next;
            node = tail->next;
        }
    }
    return head;
}