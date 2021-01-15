//#include<stdio.h>
//#include<stdlib.h>

/*
//������:nlogn
//����--ѭ����ɾ�����̣�������ʣ��Ԫ�����µ�����
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
	//����
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	//������:O(nlogn)   end:������Ԫ�صĸ���
	int end = n - 1;
	while(end > 0)
	{
		//�ѵ�ɾ������
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
//����ΪС��
typedef int HDataType;
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//��ʼ����
void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//���ϵ�����С�ѣ�
//logn
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

void checkCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)* hp->_capacity);
	}
}

//�ѵĲ���
void heapPush(heap* hp,HDataType val)
{
	//�������
	checkCapacity(hp);
	//β��
	hp->_data[hp->_size] = val;
	//���ϵ���
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//�ѵ�ɾ��(ɾ���Ѷ�Ԫ��)
void heapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	//����
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	//βɾ
	hp->_size--;
	//���µ���
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

/*
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
}*/