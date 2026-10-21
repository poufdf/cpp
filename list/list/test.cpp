#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

void Test1()
{

	zcq::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	zcq::list<int>::iterator it1 = l1.begin();
	while (it1 != l1.end())
	{
		cout << *it1 << ' ';
		++it1;
	}
	cout << endl;
	l1.push_front(10);
	l1.push_front(20);
	l1.push_front(30);
	l1.push_front(40);
	//zcq::list<int>::iterator it2 = l1.begin();
	//while (it2 != l1.end())
	//{
	//	cout << *it2 << ' ';
	//	++it2;
	//}
	//cout << endl;
	//for (auto& x : l1)
	//{
	//	cout << x << ' ';
	//}
	l1.Print();
	cout << endl;
	//cout << l1.size();
	//cout << endl;
	zcq::list<int>::iterator it2 = l1.begin();
	int n = 3;
	while (n--)
	{
		++it2;
	}
	l1.insert(it2, 100);
	//for (auto& x : l1)
	//{
	//	cout << x << ' ';
	//}
	l1.Print();
	cout << endl;
	l1.erase(it2);
	//for (auto& x : l1)
	//{
	//	cout << x << ' ';
	//}
	l1.Print();
	cout << endl;
	//测试迭代器是否失效
	zcq::list<int>::iterator it3 = l1.begin();
	while (it3 != l1.end())
	{
		if (*it3 % 2 == 0)
		{
			it3 = l1.erase(it3);
		}
		
		else//记得写不满足if条件的情况
		{
			++it3;
		}
	}
	//for (auto& x : l1)
	//{
	//	cout << x << ' ';
	//}
	l1.Print();
	cout << endl;
	l1.pop_back();
	l1.Print();
	cout << endl;
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.Print();
	cout << endl;
	l1.pop_front();
	l1.Print();
	cout << endl;
}

void Test2()
{
	zcq::list<int> l1 = { 1,2,3,4,5 };
	l1.Print();
	cout << endl;
	cout << l1.size();
	cout << endl;
	zcq::list<int> l2(l1);
	l2.push_back(10);
	l2.Print();
	cout << endl;
	zcq::list<int> l3;
	l3 = l2;
	l3.clear();
	l3.Print();
	cout << endl;
}

void Test3()
{
	// zcq::list<string> l1 = {"hello","world"};
	//zcq::list<string>::const_iterator it = l1.begin();//报错，非const对象优先调用非const成员函数
	 const zcq::list<string> l1 = { "hello","world" };
	zcq::list<string>::const_iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	struct Pos
	{
		int row ;
		int col ;
	};
	Pos p = { 1,2 };
	Pos* ptr = &p;
	zcq::list<Pos> l2;
	l2.push_back(p);
	l2.push_back(p);
	l2.push_back(p);
	zcq::list<Pos>::iterator it2 = l2.begin();
	while (it2 != l2.end())
	{
		//cout << (*it2).row << ':' <<(*it2).col << ' ';
		cout << it2->row << ':' << it2->col << ' ';
		++it2;
	}
}


int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}

