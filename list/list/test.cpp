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
	zcq::list<int>::iterator it2 = l1.begin();
	while (it2 != l1.end())
	{
		cout << *it2 << ' ';
		++it2;
	}
	cout << endl;
}


int main()
{
	Test1();

	return 0;
}

