#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace zcq
{
	//无参构造
	String::String()
		:_str(new char[1])
		, _size(0)
		, _capacity(0)//存储有效字符的空间，不包含'\0'
	{
		_str[0] = '\0';
	}
	//带参构造
	String::String(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	//拷贝构造(传统写法是自己老老实实开一块空间，再把值拷贝过去)
	//	String::String(const String& s)
	//	:_str(new char[s._capacity + 1])
	//	, _size(s._size)
	//	, _capacity(s._capacity)
	//{
	//	strcpy(_str, s._str);
	//}
    //拷贝构造优化写法
	String::String(const String& s)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
		{
			String strtemp(s._str);
			swap(strtemp);
		}


	String::~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	//赋值(第一种写法)
	/*String& String::operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[s._capacity + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	*/
	//赋值(第二种写法)
	//String& String::operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[s._capacity + 1];
	//		strcpy(_str, s._str);
	//		_size = s._size;
	//		_capacity = s._capacity;
	//	}
	//	return *this;
	//}
	//赋值(优化写法1)
	//String& String::operator=(const String& s)
	//{
	//	String strtemp(s._str);
	//	swap(strtemp);
	//	return *this;
	//}
	//赋值(优化写法2-最极致的写法)
	String& String::operator=(String s)
	{
		swap(s);
		return *this;
	}
	void String::reserve(size_t n)
	{
		if (n > _capacity)//小于n则不执行扩容逻辑
		{
			char* temp = new char[n + 1];
			strcpy(temp, _str);
			delete[] _str;
			_str = temp;
			_capacity = n;
		}

	}
	void String::push_back(char ch)
	{
		if (_size + 1 > _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	void String::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		for (size_t i = 0; i < len; i++)
		{
			_str[_size + i] = str[i];
		}
		_size += len;
		_str[_size] = '\0';

	}
	String& String::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	String& String::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void String::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		//size_t end = _size;
		if (_size + 1 > _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		for (size_t i = _size + 1; i > pos; i--)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = ch;
		_size++;
	}
	void String::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		assert(str != nullptr);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		for (size_t i = _size + len; i >= pos + len; i--)
		{
			_str[i] = _str[i - len];
		}
		//strcpy(_str + pos, str);
		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
	}
	void String::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len == String::npos || len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len; i <= _size; i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
	}
	size_t String::find(char ch, size_t pos)const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
				return i;
		}
		return String::npos;

	}
	size_t String::find(const char* str, size_t pos)const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, str);
		if (ptr == nullptr)
		{
			return String::npos;
		}
			return ptr - _str;
	}
	String String::substr(size_t pos, size_t len)const
	{   
		assert(pos < _size);
		if (len == String::npos || len > _size - pos)
		{
			len = _size - pos;
		}
		String sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}
		return sub;
	}
	void String::swap(String& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	String operator+(const String& lhs, const String& rhs)
	{
		String s(lhs);
		s += rhs.c_str();
		return s;
	}
	String operator+(const String& lhs, const char* rhs)
	{
		String s(lhs);
		s += rhs;
		return s;
	}
	String operator+(const char* lhs, const String& rhs)
	{
		String s(lhs);
		s += rhs.c_str();
		return s;
	}
	bool operator==(const String& lhs, const String& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) == 0;
	}
	bool operator!=(const String& lhs, const String& rhs)
	{
		return !(lhs == rhs);
	}
	bool operator>(const String& lhs, const String& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) > 0;
	}
	bool operator<(const String& lhs, const String& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) < 0;
	}
	bool operator>=(const String& lhs, const String& rhs)
	{
		return !(lhs < rhs);
	}
	bool operator<=(const String& lhs, const String& rhs)
	{
		return !(lhs > rhs);
	}
	ostream& operator<<(ostream& out, const String& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	//输入
	//istream& operator>>(istream& in,  String& s)//s如果有值，这个输入不会覆盖掉原来的值，而是会在后面追加字符串
	//{
	//	char ch;
	//	ch = in.get();
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}
	//	return in;
	//}
	//输入优化写法(覆盖掉原字符串,避免频繁扩容)
	istream& operator>>(istream& in, String& s)
	{
		s.erase();
		char ch;
		ch = in.get();
		char buff[128];
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}

	//istream& getline(istream& in, String& s)
	//{
	//	char ch;
	//	ch = in.get();
	//	while ( ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}
	//	return in;
	//}
	istream& getline(istream& in, String& s)
	{
		s.erase();
		char ch;
		ch = in.get();
		char buff[128];
		int i = 0;
		while ( ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}
void swap(zcq::String& lhs, zcq::String& rhs)
{
	lhs.swap(rhs);
}


