#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

void Test1()
{
	list<int> l1 = { 1,2,3,4,5,6,7 };
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int> l2(10, 1);
	for (auto& x : l2)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int> l3(l1.begin(), l1.end());
	for (auto& x : l3)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int> l4(l2);
	for (auto& x : l4)
	{
		cout << x << ' ';
	}
	cout << endl;
	l4 = l1;
	for (auto& x : l4)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int>::reverse_iterator it = l1.rbegin();
	while (it != l1.rend())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;
	cout << l1.size();
}
void Test2()
{
	list<int> l1 = { 1,2,3,4,5,6,7 };
	cout << l1.front()<<endl;
	cout << l1.back() << endl;
	//l1.assign(10, 1);
	//l1 = { 1,45,6 };//特殊
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	l1.push_front(10);
	l1.push_back(11);
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	l1.pop_front();
	l1.pop_back();
	for (auto& x : l1)
	{
		cout << x <<' ';
	}
	cout << endl;
	list<int>::iterator it = l1.begin();//迭代器指向元素1
	int n = 3;
	while (n--)
	{
		++it;
	}//此时迭代器指向元素4
	l1.insert(it, 19);//插入之后迭代器依旧指向元素4// 1 2 3 19 4 5 6 7
	for (auto& x : l1)
	{
		cout << x <<' ';
	}
	cout << endl;
	list<int> l2(5, 6);// 1 2 3 19 6 6 6 6 6 4 5 6 7
	l1.insert(it, l2.begin(), l2.end());
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	l1.erase(it);
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	int a = 4;
	int b = 9;
	list<int>::iterator it3 = l1.begin();
	list<int>::iterator it4 = l1.begin();
	while (a--)
	{
		++it3;
	}
	while (b--)
	{
		++it4;
	}
	l1.erase(it3, it4);
	for (auto& x : l1)
	{
		cout << x << ' ';

	}
	cout << endl;
}
bool is_even(int x)
{
	return x % 2 == 0;
}
void Test3()
{
	list<int> l1 = { 1,2,3,4,5,6,7 };
	list<int> l2 (5,6);
	//l1.swap(l2);
	//l1.resize(5);
	//l1.clear();
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int>::iterator it1 = l1.begin();
	list<int>::iterator it2 = l2.begin();
	list<int>::iterator it3 = l2.end();
	l1.splice(it1, l2,it2,it3);
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	l1.remove(6);
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	l1.remove_if(is_even);
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int> l4 = { 1,1,1,1,2,2,2,2,3,3,4,5 };
	list<int> l3 = { 1,2,3,4,5 };
	l4.unique();
	for (auto& x : l4)
	{
		cout << x << ' ';
	}
	cout << endl;
	l3.unique();
	for (auto& x : l3)
	{
		cout << x << ' ';
	}
	cout << endl;
	l3.merge(l4);//将两个链表归并成有序的，因此l3和l4都应该各自有序
	for (auto& x : l3)
	{
		cout << x << ' ';
	}
	cout << endl;
	list<int> l5 = { 125,52,6,36,26,27,3,61,6 };
	l5.sort();
	for (auto& x : l5)
	{
		cout << x << ' ';
	}
	cout << endl;
	l5.reverse();
	for (auto& x : l5)
	{
		cout << x << ' ';
	}
	cout << endl;
	swap(l1, l5);
	for (auto& x : l1)
	{
		cout << x << ' ';
	}
	cout << endl;

}


int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}