#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"seqList.h"
//初始化
void initSeqList(SeqList* ps)
{
	assert(ps);
	ps->a=NULL;
	ps->size=0;
	ps->capacity=0;
};
//销毁
void SeqListDestory(SeqList* ps)
{
	if(ps !=NULL && ps->a != NULL)
	{
		free(ps->a);
		ps->a = NULL;
	}
	ps->capacity = ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	for (int i = 0;i < (ps->size);++i)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SeqList* ps)
{
	if(ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 1 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity* sizeof(SLDataType));
		memcpy(tmp,ps->a,sizeof(SLDataType)* ps->size);
		free(ps->a);
		ps->a =tmp;
		ps->capacity = newCapacity;
	}
}

void SeqListPushBack(SeqList* ps,SLDataType x)
{
	assert(ps != NULL);
	SeqListCheckCapacity(ps);
	ps->a[ps->size]=x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps,SLDataType x)
{
	assert(ps != NULL);
	SeqListCheckCapacity(ps);
	for(int i = (ps->size); i > 0; --i)
	{
		ps->a[i]=ps->a[i-1];
	}
	ps->a[0]=x;
	ps->size++;
}

bool Isempty(SeqList* ps)
{
	assert(ps != NULL);
	return ps->size == 0;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps != NULL);
	if(Isempty(ps))
	{
		return;
	}
	for(int i=0;i<ps->size;++i)
	{
		ps->a[i]=ps->a[i+1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	if(Isempty(ps))
	{
		return;
	}
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps != NULL);
	int pos = 0;
	while(pos<ps->size && x != ps->a[pos])
		pos++;
	if(pos == ps->size)
		pos=-1;
	return pos;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps != NULL);
	if (0 <= pos <= ps->size)
	{
		SeqListCheckCapacity(ps);
		int end = ps->size;
		while(end < pos)
		{
			ps->a[end]=ps->a[end-1];
			--end;
		}
		ps->a[pos]=x;
		++ps->size;
	}
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps != NULL);
	if (0 <= pos <= ps->size)
	{
		int start = pos + 1;
		while(start < ps->size)
		{
			ps->a[start-1] = ps->a[start];
			++start;
		}
		--ps->size;
	}
}
int main()
{
	return 0;
}