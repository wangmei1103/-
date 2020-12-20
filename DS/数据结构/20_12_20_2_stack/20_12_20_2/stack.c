#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef int STDataType;

//顺序结构实现：实现一个更简单的顺序表
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;

void initStack(stack* st)
{
	if(st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapacity(stack* st)
{
	if(st->_size == st->_capacity)
	{
		int newCap = st->_capacity ==0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*) realloc (st->_data,sizeof(STDataType)* newCap);
		st->_capacity = newCap;
	}
}

void stackPush(stack* st,STDataType val)
{
	if(st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack* st)
{
	if(st == NULL || st->_size == 0)
		return;
	--st->_size;
}


int stackSize(stack* st)
{
	if(st == NULL)
		return 0;
	return st->_size;
}

int stackEmpty(stack* st)
{
	if(st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}

STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}

int main()
{
	system("pause");
	return 0;
}