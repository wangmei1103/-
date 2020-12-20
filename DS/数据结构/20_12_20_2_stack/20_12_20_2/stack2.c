#include "seqList.h"
//已经实现了一个顺序表
typedef struct stack2
{
	struct seqList sq;
};

void initStack(stack2* st)
{
	initseqList(&st->_sq);
}

void stackPush(stack2* st,DataType val)
{
	seqListPushBack(&st->_sq,val);
}

void stackPop(stack2* st)
{
	seqListPopBack(&st->_sq);
}

DataType stackTop(stack2* st)
{
	return seqListAt(&st->_sq,st->_sq._size-1);
}

int stackSize(stack2* st)
{
	return seqListSize(&st->_sq);
}

int stackEmpty(stack2* st)
{
	return seqListSize(&st->_sq) == 0;
}