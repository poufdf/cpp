#define _CRT_SECURE_NO_WARNINGS
#include"Advanced Templates.h"


template<class T1,class T2>
class Data 
{
public:
	void func()
	{
		cout << "T1,T2" << endl;
	}
private:
	T1 _month;
	T2 _day;
};

template<>
class Data<int, char>
{
public:
	void func()
	{
		cout << "int,char" << endl;
	}

private:
	int _month;
	char _day;
};

//偏特化
template<class T1>
class Data<T1, int>
{
public:
	void func()
	{
		cout << "T1,int" << endl;

	}
private:
	T1 _month;
	int _day;
};

//对参数作进一步限制
template<class T1,class T2>
//引用在创建是必须赋值，含有引用成员且没有给它们初始化的类，编译器生成的默认构造函数会被隐式删除
class Data<T1&, T2&>
{
public:
	Data(int x ,int y)
		:_month(x),
		_day(y){ }
	void func()
	{
		cout << "T1&,T2&" << endl;
	}
private:
	T1& _month;
	T2& _day;
};


int main()
{
	Data<double, double> d1;
	Data<int, char> d2;
	Data<double, int> d3;
	Data<int&, int&> d4(1,2);
	d1.func();
	d2.func();
	d3.func();
	d4.func();


	return 0;
}













//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
////模板特化
//template<>
//bool Less<int*>(int* left, int* right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	int a = 3;
//	int b = 2;//不一定按照先a后b的顺序压栈，具体看编译器,C++标准并为规定
//	cout << &a << endl;//结果为000000280B1DFB04
//	cout << &b << endl;//结果为000000280B1DFB24
//	cout << Less(a, b)<<endl;
//	cout << Less(&a, &b);
//	return 0;
//}