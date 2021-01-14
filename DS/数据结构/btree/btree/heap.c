#include<stdio.h>

//���ϵ�����С�ѣ�

void shiftUp(int* arr, int n, int cur)
{
	//�����λ��
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		//�͸����Ƚ�
		if (arr[cur] < arr[parent])
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

//����ΪС��
//���µ���
void shiftDown(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//�����Һ������ҵ�һ����Сֵ��λ��
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//��Ҫ���������ݺ���Сֵ���бȽ�
		if (arr[child] < arr[curPos])
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

void createHeap(int* arr, int n)
{
	//�����һ����Ҷ�ӿ�ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		//shiftDown������ָ�룬����Ԫ�ظ�������������ʼλ�ã�
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