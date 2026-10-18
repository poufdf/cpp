#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//日期类的实现
//涉及的知识：构造函数，拷贝构造，运算符重载(核心)，友元函数
class Date
{
	//友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in,  Date& d);
public:
	Date(int year, int month, int day);
	Date(const Date& d);
	//获取当前月的天数，单独写成一个函数极为方便
	int GetMonthDay(int year, int month);
	void Print();
	bool CheckDate();

	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	Date& operator+=(int day);
	Date operator+(int day)const;
	Date& operator-=(int day);
	Date operator-(int day)const;
	//d1-d2
	int operator-(const Date& d)const;
	//前置++
	Date& operator++();
	//后置++,int只是作为区分，无实际含义
	Date operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};
//写在类外面，因为成员函数第一个参数默认是this,重载后使用形式为d << cout,不符合使用习惯
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in,  Date& d);