#define _CRT_SECURE_NO_WARNINGS
//C++入门第一课代码-命名空间的使用
#include<iostream>

namespace zcq
{
	int a = 2;
	int b = 3;

	int add(int x, int y)
	{
		return x + y;
	}
}

using namespace zcq;
int main()
{
	printf("a=%d b=%d\n", a, b);
	printf("a+b=%d", add(a, b));
	return 0;
}
//#include<iostream>
//
//namespace zcq
//{
//	int a = 2;
//	int b = 3;
//
//	int add(int x, int y)
//	{
//		return x + y;
//	}
//}
////注意在命名空间之后展开，不然编译器找不到。
////只能一个一个展开
//using zcq::a;
//using zcq::b;
//int main()
//{
//	printf("a=%d b=%d\n", a, b);
//	printf("a+b=%d", zcq::add(a,b));
//	return 0;
//}
//namespace zcq
//{
//	int a = 2;
//	int b = 3;
//
//	int add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//
//int main()
//{
//	printf("a=%d b=%d\n", zcq::a,zcq::b );
//	printf("a+b=%d", zcq::add(zcq::a, zcq::b));
//	return 0;
//}
