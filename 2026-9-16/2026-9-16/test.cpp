#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	A() 
	{
		_count++;
	}
	A(const A& a)
	{
		_count++;
	}
	static int GetCount()
	{
		return _count;
	}
private:
	static int _count;
};
int A::_count = 0;


class Date
{
public:
	Date(int year=2025,int month=6,int day = 16)
		:_year(year)
		,_month(month)
		,_day(day)
	{
	 }
	void Print()
	{
		cout << _year << ' '<<_month<<' '<< _day<<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test1()
{
	//发生了类型转换
	Date d1 = { 2026,9,16 };
	d1.Print();
}
void Test2() 
{
	A aa1, aa2;
	A aa3(aa1);
	cout << A::GetCount()<<endl;
	cout << aa1.GetCount()<<endl;
	cout << aa3.GetCount()<<endl;

}
int main()
{
	//Test1();
	Test2();




	return 0;
}
