#define _CRT_SECURE_NO_WARNINGS
#include"Inheritance.h"


void Test1()
{
	//zcq::Person p;
	//zcq::Student s;
	//zcq::Teacher t;
	//p.identity();
	//s.identity();
	//t.identity();
	//s.study();
	//t.teach();
	////派生类对象可以赋值给基类的指针或引用
	//zcq::Person* ptr = &s;
	//zcq::Person& pt = s;
	//p = s;

}

void Test2()
{
	zcq::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	//stack继承了vector,s也支持迭代器了
	for (auto& x : s)
	{
		cout << x<< " ";
	}

 }

void Test3()
{
	//zcq::Person p("张三",15);
	//zcq::Student s("李四", 18, "123");
	//p = s;
	//zcq::Person p1(p);
	zcq::Student s("李四", 18, "123");
	zcq::Student s1(s);
	s = s1;

}
int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}