#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

namespace zcq {
	class String {
	public:
		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
		char* begin()
		{
			return _str;
		}
		char* end()
		{
			return _str + _size;
		}
		const char* begin()const
		{
			return _str;
		}
		const char* end()const
		{
			return _str + _size;
		}

		String();
		String(const char* str);
		String(const String& s);
		~String();
		//String& operator=(const String& s);//赋值
		String& operator=(String s);//赋值优化写法
		void reserve(size_t n);//扩容
		void push_back(char ch);//尾插
		void append(const char* str);//尾插多个字符
		String& operator+=(char ch);
		String& operator+=(const char* str);
		void insert(size_t pos, char ch);//插入一个字符
		void insert(size_t pos, const char* str);//插入字符串
		void erase(size_t pos = 0, size_t len = String::npos);//删除字符
		size_t find(char ch, size_t pos = 0)const;//查找字符，返回下标
		size_t find(const char* str, size_t pos = 0)const;//查找字符数组，返回下标
		String substr(size_t pos = 0, size_t len = String::npos)const;//截取指定长度的字符串
		void swap(String& s);
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		static const size_t npos = -1;

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	String operator+(const String& lhs, const String& rhs);
	String operator+(const String& lhs, const char* rhs);
	String operator+(const char* lhs, const String& rhs);
	bool operator==(const String& lhs, const String& rhs);
	bool operator!=(const String & lhs, const String& rhs);
	bool operator>(const String& lhs, const String& rhs);
	bool operator<(const String& lhs, const String& rhs);
	bool operator>=(const String& lhs, const String& rhs);
	bool operator<=(const String& lhs, const String& rhs);
	ostream& operator<<(ostream& out, const String& s);
	istream& operator>>(istream& in,  String& s);
	istream& getline(istream& in, String& s);//可以输入含空格的字符串
}
void swap(zcq::String& lhs, zcq::String& rhs);


