//#include<iostream>
//using namespace std;
#if 0
//�����ռ䶨���ʽ
namespace N
{
	//����
	//����
}

int a = 10;

//���ֶ��巽ʽ
//1.�����ʽ

namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}

}

//2.�����ռ����Ƕ��
namespace N2
{
	int a = 10;
	int b = 20;
	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int c = 10;
		int d = 20;
		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}

//3.��ͬһ�����У����Զ�����������ͬ�������ռ�
//�����ͻ    �������Ὣ�����ͬ���Ƶ������ռ�ϲ���һ��
//��ͬ�������в��ܳ�����ͬ�����֣�  
//��ͬ���ƵĶ�������ռ��У�Ҳ���ܳ�����ͬ������ ��Ϊ�������Ὣ�����ͬ���Ƶ������ռ����պϲ���һ��
namespace N1
{
	int Div(int left, int right)
	{
		return left / right;
	}
}

namespace N
{
	int a = 10;
	//Ƕ�׵ķ�ʽ---�÷�ʽ�����ͻ
	//�൱�����N�����ռ����ְ�����һ��N�������ռ�
	namespace N{
		int b = 10;
		int a = 10;
	}
}
#endif


#include<stdio.h>
#include<Windows.h>
#if 0
//�����ռ��г�Ա��ʹ�÷�ʽ
//1.�����ռ�����::����
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}
int a = 20;

int main()
{
	int a = 30;
	//�ͽ�ԭ��
	printf("%d\n", a);

	////�������ȫ���������е�
	//::�����������
	//::a 
	printf("%d\n", ::a);
	return 0;
	system("pause");
}
#endif


//������  
#if 0
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}
//�ó�������N�����ռ��е�ĳЩ��Ա���ʵķǳ�Ƶ��
//�ŵ�:д�������
//ȱ��:������ļ�������ͬ���Ƶı������ߺ������ͻ������ͻ
//����������֮���൱�ڽ�N�����ռ��е�a�����ļ��е�һ��ȫ�ֱ�����ʹ�á�
using N::a;
//using namespace N;   ����ǰN�����ռ������еĳ�Ա���ɸ��ļ���ȫ�ֱ���
//�ŵ㣺ʹ�÷ǳ���
//
int main()
{
	//����N�����ռ��е�
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);

	//Ϊ��д�����  ��Ҫֱ�ӷ���N�����ռ��е�
	printf("%d\n", ::a);
	return 0;
	system("pause");
}
#endif


//C++�е���������
//ע�⣺C���������������ķ�ʽ��C++���Ծɿ���ʹ�ã�---��ΪC++Ҫ����C����
//C++�Լ����Ǹ���һ�����������ķ�ʽ����ΪC����������������ʽ̫�鷳��   cin  cout
#if 0
int main()
{
	int a = 10;
	printf("%d\n", 10, 20, 30);
	printf("%d  %s  %f\n", 10);
	return 0;
	system("pause");
}
#endif

