//#include<stdio.h>
//#include<stdlib.h>

/*
//堆排序:nlogn
//建堆--循环（删除过程：交换，剩余元素向下调整）
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curPos])
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
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void test()
{
	int arr[] = {20,17,4,16,5,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	//堆排序:O(nlogn)   end:待排序元素的个数
	int end = n - 1;
	while(end > 0)
	{
		//堆的删除过程
		swap(&arr[0], &arr[end]);
		shiftDown(arr, end, 0);
		--end;
	}
}
int main()
{
	test();
	return 0;
}
*/
/*
//假设为小堆
typedef int HDataType;
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//初始化堆
void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//向上调整（小堆）
//logn
void shiftUp(int* arr, int n, int cur)
{
	//父结点位置
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		//和父结点比较
		if (arr[cur] < arr[parent])
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
//假设为小堆
//向下调整
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curPos])
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

void checkCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)* hp->_capacity);
	}
}

//堆的插入
void heapPush(heap* hp,HDataType val)
{
	//检查容量
	checkCapacity(hp);
	//尾插
	hp->_data[hp->_size] = val;
	//向上调整
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//堆的删除(删除堆顶元素)
void heapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	//交换
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	//尾删
	hp->_size--;
	//向下调整
	shiftDown(hp->_data, hp->_size, 0);
}

int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}


void test()
{
	heap hp;
	heapInit(&hp);
	heapPush(&hp, 28);
	heapPush(&hp, 29);
	heapPush(&hp, 45);
	heapPush(&hp, 46);
	heapPush(&hp, 25);
	heapPush(&hp, 38);
	heapPush(&hp, 19);
	heapPush(&hp, 8);
	heapPop(&hp);
	heapPop(&hp);
	heapPop(&hp);
	heapPop(&hp);
	heapPop(&hp);
	heapPop(&hp);
	heapPop(&hp);
	heapPop(&hp);
	while (!heapEmpty)
	{
		printf("%d ", heapTop(&hp));
		heapPop(&hp);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}
*/
/*
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

void test()
{
	int arr[] = { 7,56,30,25,15,10 };
	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
}
int main()
{
	test();
	return 0;
}
*/

/*
//假设为小堆
//向下调整
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curPos])
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
void createHeap(int* arr, int n)
{
	//从最后一个非叶子开始向下调整
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		//shiftDown（数组指针，数组元素个数，调整的起始位置）
		shiftDown(arr, n, i);
	}
}
void test()
{
	//int arr[] = { 10,5,3,8,7,6 };
	//shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
	int arr[] = { 100,20,3,6,89,12,15,36,25 };
	createHeap(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	test();
	return 0;
}*/