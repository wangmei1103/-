#include<stdio.h>

//����ΪС��
void shiftDown(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	//�����Һ������ҵ�һ����Сֵ��λ��
	if (arr[child + 1] < arr[child])
		++child;

}