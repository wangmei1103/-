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

//向上调整（大堆） logn
void shiftUp(int* arr, int n, int cur)
{
	//父结点位置
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		//和父结点比较
		if (arr[cur] > arr[parent])
		{
			//交换
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;
			//更新到父结点位置，继续向上调整
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;//结束调整
	}
}
//假设为大堆
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最大值的位置
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		//需要调整的数据和最大值进行比较
		if (arr[child] > arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;
			//更新
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

// 堆的构建
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
// 堆的销毁
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
// 堆的插入
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
// 堆的删除(删除堆顶)
void HeapPop(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	shiftDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(a, n, i);
	}
	//堆排序:O(nlogn)   end:待排序元素的个数
	int end = n - 1;
	while (end > 0)
	{
		//堆的删除过程
		swap(&a[0], &a[end]);
		shiftDown(a, end, 0);
		--end;
	}
}
// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆

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
// 找最小的前K个，建立K个数的大堆
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
	//确定10个最大的数
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