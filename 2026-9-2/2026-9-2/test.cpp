#include<iostream>
#include<stdlib.h>
using namespace std;
//栈类
class Stack
{
public:
	Stack(int n = 4)
	{
		 _a = (int*)malloc(sizeof(int)*n);
		 if (_a == nullptr)
		 {
			 cout << "malloc申请空间失败";
			 exit(-1);
		 }
		 _top = 0;
		 _capacity = n;
	}
	//析构函数
	~Stack()
	{
		cout << "~Stack被调用";
		free(_a);
		_a = nullptr;
		_top = 0;
		_capacity = 0;
	}
	int* Getplace()
	{
		return _a;
	}
	//拷贝构造
	Stack(const Stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (_a == nullptr)
		{
			cout << "拷贝构造malloc失败";
			exit(-1);
		}
		memcpy(_a, st._a, sizeof(int) * st._top);
		_top = st._top;
		_capacity = st._capacity;

	}
private:
	int* _a;
	int _top;
	int _capacity;
};
//日期类
class Data
{
public:
	//无参构造
	Data()
	{
		_year = 2025;
		_month = 9;
		_day = 1;

	}
	//带参构造
	Data(int year, int month, int day)
	{ 
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造
	Data(Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

	}

	void Print()
	{
		cout << _year << ' ' << _month << ' ' << _day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Data d1;
	/*Data d1(2026, 9, 8);
	d1.Print();*/
	/*Stack st;
	cout << st.Getplace() << '\n';*/
	Data d1;
	Data d3(d1);
	d3.Print();
	Data d4 = d1;
	cout << '\n';
	d4.Print();
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Data {
//public:
//	void Init(int year = 2026, int month = 9, int day = 8)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day;
//	}
//
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1;
//	d1.Init(2026,1,1);
//	d1.Print();
//
//
//
//
//
//	return 0;
//}
////namespace zcq
////{
////	int a = 6;
////	int add(int x, int y)
////	{
////		return x + y;
////	}
////}
//int main()
//{
//	/*cout << zcq:: a;
//	int b = 0;
//	cin >> b;
//	cout << b;*/
//	
//
//
//	return 0;
//
//}

