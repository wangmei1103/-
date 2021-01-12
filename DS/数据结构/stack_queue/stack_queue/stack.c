/*
#include<stdio.h>
#include<string.h>

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _size;
	int _capacity;  // 容量 
}Stack;

void cheakCapacity(Stack* ps)
{
	if (ps->_size == ps->_capacity)
	{
		int newCap = ps->_capacity == 0 ? 1 : 2 * ps->_capacity;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newCap);
		ps->_capacity = newCap;
	}
}

// 初始化栈 
void StackInit(Stack* ps)
{
	if (ps == NULL)
		return;
	ps->_a = NULL;
	ps->_capacity = ps->_size = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	if (ps == NULL)
		return;
	cheakCapacity(ps);
	ps->_a[ps->_size++] = data;
}
// 出栈 
void StackPop(Stack* ps)
{
	if (ps == NULL || ps->_size == 0)
		return;
	ps->_size--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	return ps->_a[ps->_size - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	if (ps == NULL)
		return 0;
	return ps->_size;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	if (ps == NULL || ps->_size == 0)
		return 1;
	else
		return 0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_size = ps->_capacity = 0;
	}
}
int main()
{
	return 0;
}
*/