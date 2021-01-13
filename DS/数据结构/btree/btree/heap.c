#include<stdio.h>

//假设为小堆
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	//从左右孩子中找到一个最小值的位置
	if (arr[child + 1] < arr[child])
		++child;

}