#define _CRT_SECURE_NO_WARNINGS
//C++入门第一课 缺省参数代码
#include<iostream>
using namespace std;

//全缺省
int add1(int x = 10, int y = 20)
{
	return x + y;
}
//半缺省
int  add2(int x, int y= 10,int z=20 )//从右往左缺省原因:实参是从左往右写的，右面没有被传参的形参可以用缺省值
{
	return x + y+z;
}
int add2(int x = 10, int y=30, int z )//这种写法是错误的，如果写add2(a,b),那z既没有实参传值，又没有缺省值，直接报错
{
	return x + y + z;
}

void Test1()
{
	int a = 1;
	int b = 2;
	cout << add1() << endl;//这里没有传实参，形参默认用缺省值x=10,y=20,结果为30
	cout << add1(a, b) << endl;//这里传了实参，x=a,y=b,缺省值没用了，结果为3
	cout << add1(a) << endl;//这里x=a,y=20,x用实参的值，y用缺省值，结果为21
}

void Test2()
{
	int a = 1;
	int b = 2;
	int c = 3;
	cout << add2(a);//x=a,y=10,z=20
}


int main()
{
	Test1();//测试全缺省
	Test2();//测试半缺省
	//看看是不是提交成功了






	return 0;
}