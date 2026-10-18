#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
//一定记得在类里面声明的要加域作用限定符
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int GetMonthDayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	else
		return GetMonthDayArr[month];
}
bool Date::CheckDate()
{
	if (_month < 1 || _month>12 || _day < 1 || _day>GetMonthDay(_year, _month))
		return false;
	else
		return true;

}

bool Date::operator<(const Date& d)const
{ 
	if (_year < d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		else if(_month==d._month)
			return _day < d._day;
	}
	return false;

}
bool Date::operator<=(const Date& d)const
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d)const
{ 
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)const
{ 
	return !(*this < d);
}
bool Date::operator==(const Date& d)const
{ 
	return (_year == d._year && _month == d._month && _day == d._day);
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;

}
Date Date::operator+(int day)const
{
	Date temp = *this;
	temp += day;
	return temp;
}
Date& Date::operator-=(int day)
{ 
	if (day < 0)
		return *this += -day;
	_day -= day;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_month = 12;
			_year--;
		}
		else
		{
			_month--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day)const
{
	Date temp = *this;
	temp -= day;
	return temp;
}
//d1-d2
int Date::operator-(const Date& d)const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min != max)
	{
		min++;
		count++;
	}
	return count * flag;

}
//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;

}
//后置++,int只是作为区分，无实际含义
Date Date::operator++(int)
{
	Date temp (*this);
	*this += 1;
	return temp;
}
//前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//后置--
Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}
void Date::Print()
{
	cout << _year <<'/'<< _month<<'/' << _day<<endl;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month <<"月" << d._day << "日" << endl;
	return out;//连续赋值需要返回值
}
istream& operator>>(istream& in, Date& d)
{
	cout << "请输入年月日：";
	in >> d._year >> d._month >> d._day;
	if (!d.CheckDate())
	{
		cout << "输入的日期不合法";
		exit(-1);
	}
	return in;
	
}