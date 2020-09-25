//#include<iostream>
//using namespace std;
#if 0
//命名空间定义格式
namespace N
{
	//变量
	//函数
}

int a = 10;

//三种定义方式
//1.最常见方式

namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}

}

//2.命名空间可以嵌套
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

//3.在同一工程中，可以定义多个名字相同的命名空间
//不会冲突    编译器会将多个相同名称的命名空间合并成一个
//相同作用域中不能出现相同的名字，  
//相同名称的多个命名空间中：也不能出现相同的名字 因为编译器会将多个相同名称的命名空间最终合并成一个
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
	//嵌套的方式---该方式不会冲突
	//相当于外层N命名空间中又包含了一个N的命名空间
	namespace N{
		int b = 10;
		int a = 10;
	}
}
#endif


#include<stdio.h>
#include<Windows.h>
#if 0
//命名空间中成员的使用方式
//1.命名空间名字::名字
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
	//就近原则
	printf("%d\n", a);

	////如果访问全局作用域中的
	//::作用域运算符
	//::a 
	printf("%d\n", ::a);
	return 0;
	system("pause");
}
#endif


//场景三  
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
//该场景：对N命名空间中的某些成员访问的非常频繁
//优点:写代码简单了
//缺点:如果该文件中有相同名称的变量或者函数，就会产生冲突
//该条语句加上之后，相当于将N命名空间中的a当初文件中的一个全局变量来使用。
using N::a;
//using namespace N;   将当前N命名空间中所有的成员当成该文件的全局变量
//优点：使用非常简单
//
int main()
{
	//访问N命名空间中的
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);
	printf("%d\n", ::a);

	//为了写代码简单  先要直接访问N命名空间中的
	printf("%d\n", ::a);
	return 0;
	system("pause");
}
#endif


//C++中的输入和输出
//注意：C语言中输入和输出的方式在C++中仍旧可以使用，---因为C++要兼容C语言
//C++自己还是搞了一套输入和输出的方式，因为C语言中输入和输出方式太麻烦了   cin  cout
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

