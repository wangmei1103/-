/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//���ϵ�������ѣ� logn
void shiftUp(int* arr, int n, int cur)
{
	//�����λ��
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		//�͸����Ƚ�
		if (arr[cur] > arr[parent])
		{
			//����
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;
			//���µ������λ�ã��������ϵ���
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;//��������
	}
}
//����Ϊ���
void shiftDown(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//�����Һ������ҵ�һ�����ֵ��λ��
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		//��Ҫ���������ݺ����ֵ���бȽ�
		if (arr[child] > arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;
			//����
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}

void HeapInit(Heap* hp)
{
	if (hp == NULL)
		return;
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	if (hp == NULL)
		return;
	int i = 0;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	for (i = 0; i < n; i++)
		hp->_a[i] = a[i];
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(a, n, i);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

void checkCapacity(Heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)* hp->_capacity);
	}
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp == NULL)
		return;
	checkCapacity(hp);
	hp->_a[hp->_size] = x;
	shiftUp(hp->_a, hp->_size, hp->_size - 1);
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// �ѵ�ɾ��(ɾ���Ѷ�)
void HeapPop(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	shiftDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	//����
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(a, n, i);
	}
	//������:O(nlogn)   end:������Ԫ�صĸ���
	int end = n - 1;
	while (end > 0)
	{
		//�ѵ�ɾ������
		swap(&a[0], &a[end]);
		shiftDown(a, end, 0);
		--end;
	}
}
// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��

void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	HeapCreate(&hp, a, n);
	for (int i = k; i < n; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapTop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
// ����С��ǰK��������K�����Ĵ��
void PrintTopK1(int* a, int n, int k)
{
	Heap hp;
	HeapCreate(&hp, a, n);
	for (int i = k; i < n; i++)
	{
		HeapPush(&hp, a[i]);
	}
	while(k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
void TestTopk()
{
	int n = 100;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	//ȷ��10��������
	a[5] = 100 + 1;
	a[35] = 100 + 2;
	a[67] = 100 + 3;
	a[51] = 100 + 4;
	a[15] = 100 + 5;
	a[23] = 100 + 6;
	a[99] = 100 + 7;
	a[76] = 100 + 8;
	a[43] = 100 + 9;
	a[31] = 100 + 10;
	PrintTopK(a, n, 10);
}

void test()
{
	Heap hp;
	int a[] = { 12,16,23,22,15,28 };
	HeapCreate(&hp, a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	test();
	TestTopk();
	return 0;
}
*/