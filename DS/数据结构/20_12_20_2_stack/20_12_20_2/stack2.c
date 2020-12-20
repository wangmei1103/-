#include "seqList.h"

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

}