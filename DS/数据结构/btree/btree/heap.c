#include<stdio.h>

//向上调整（小堆）

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
}


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