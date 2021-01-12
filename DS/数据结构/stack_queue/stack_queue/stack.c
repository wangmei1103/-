/*
#include<stdio.h>
#include<string.h>

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _size;
	int _capacity;  // ���� 
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

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	if (ps == NULL)
		return;
	ps->_a = NULL;
	ps->_capacity = ps->_size = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	if (ps == NULL)
		return;
	cheakCapacity(ps);
	ps->_a[ps->_size++] = data;
}
// ��ջ 
void StackPop(Stack* ps)
{
	if (ps == NULL || ps->_size == 0)
		return;
	ps->_size--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	return ps->_a[ps->_size - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	if (ps == NULL)
		return 0;
	return ps->_size;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	if (ps == NULL || ps->_size == 0)
		return 1;
	else
		return 0;
}
// ����ջ 
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