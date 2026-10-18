#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Time
{
public:
	Time(int hour)
		:_hour(hour)
	{ }
	int GetHour()
	{
		return _hour;
	}

private:
	int _hour;
};

class Date
{
public:
	Date(int& x, int year = 2025, int month = 9, int day = 15)
		:_year(year)
		, _month(month)
		, _day(day)
		, _rx(x)
		, _i(53)
		,_t(6)
		
	{
	}
	void Print()
	{
		cout << _year << ' ' << _month << ' ' << _day<<endl;
		cout << "_rx="<<_rx <<endl<< "_i="<<_i<<endl<<"_t.hour="<<_t.GetHour();

	}

private:
	int _year;
	int _month;
	int _day;
	int& _rx;
	const int _i;
	Time _t;
};

int main()
{
	int x = 36;
	Date d1(x);
	d1.Print();


	return 0;
}