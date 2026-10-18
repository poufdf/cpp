#define _CRT_SECURE_NO_WARNINGS
//C++入门第一课博客代码
//#include<iostream>
//using namespace std;
////命名空间的定义
//namespace zcq1
//{
//	int a = 0; //定义变量
//	int b = 0;
//	void func() //定义函数
//	{
//
//	}
//	struct zcq //定义结构体
//	{
//		int age;
//	};
//	namespace zcq2 //命名空间可以嵌套定义
//	{
//		int c = 0;
//	}
//}
#include<stdio.h>
#include<stdlib.h>

//这里rand变量被“保护”在了命名空间里面
namespace zcq
{
	int rand = 0;
}


int main()
{
	//这里编译器会去找rand,由于rand变量被命名空间保护起来了，因此这里访问到的是stdlib.h头文件里的rand函数
	printf("%p", rand);
	return 0;
}