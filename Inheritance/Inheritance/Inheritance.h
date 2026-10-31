#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace zcq
{
	//派生类的默认成员函数
	class Person
	{
	public:
		Person(const string& name,const int& age)
			:_name(name),
			_age(age)
		{
			cout << "Person默认构造" << endl;
		}

		Person(const Person& p)//为什么这里可以访问p的成员，因为类的成员函数可以访问同类型对象的私有成员
		{
			_name = p._name;
			_age = p._age;
			cout << "Person拷贝构造" << endl;
		}

		Person& operator=(const Person& p)
		{
			_name = p._name;
			_age = p._age;
			cout << "Person赋值重载" << endl;
			return *this;
		}

		 ~Person()
		{
			cout << "Person析构" << endl;

		}
	protected:
		string _name;
		int _age;

	};
	class Student :public Person
	{
	public:
		Student(const string& name, const int& age, const string& id)
			:Person(name,age),
			_id(id)
		{
			cout << "Student默认构造" << endl;
		}

		Student(const Student& s)
		:Person(s),
		_id(s._id)
		{
			cout << "Student拷贝构造" << endl;
		}

		Student& operator=(const Student& s)
		{
			Person::operator=(s);
			_id = s._id;
			cout << "Student赋值重载" << endl;
			return *this;
		}
		//派生类析构调用完成后自动调用基类析构，不管有没有构成隐藏
		~Student()
		{
			cout << "Student析构" << endl;
		}
	protected:
		string _id;
	};
	//继承类模板
	template<class T>
	class stack :public vector<T>
	{
	public:
		void push(const T& x)
		{
			vector<T>::push_back(x);
		}
		void pop()
		{
			vector<T>::pop_back();
		}

	};

//普通继承
	//class Person
	//{
	//public:
	//	void identity()
	//	{
	//		cout << "void identity" << endl;
	//	}
	//protected:
	//	string _name ;
	//	int age ;
	//};

	//class Student :public Person
	//{
	//public:
	//	void study()
	//	{
	//		cout << "void study" << endl;
	//	}

	//protected:
	//	string id;
	//};

	//class Teacher :public Person
	//{
	//public:
	//	void teach()
	//	{
	//		cout << "void teach" << endl;
	//	}

	//protected:
	//	string major;
	//};
}