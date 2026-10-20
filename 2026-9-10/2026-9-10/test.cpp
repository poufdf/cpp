#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (int*)malloc(sizeof(int) * n);
		if (_a == nullptr)
		{
			cout << "构造malloc失败";
			exit(-1);
		}
		_top = 0;
		_capacity = n;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
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

//class Date
//{
//public:
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print() 
//	{
//		cout << _year << '/' << _month << '/' << _day<<endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2026, 9, 10);
//	Date d2 = d1;
//	d1.Print();
//	d2.Print();
//
//
//	return 0;
//}
