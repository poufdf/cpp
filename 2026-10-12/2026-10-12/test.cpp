#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void Test1()
{
	vector<int> v1;
	vector<int> v2(10, 1);
	v1 = v2;
	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	for (auto x : v1)
	{
		cout << x<< ' ';
	}
	cout << endl;
	vector<int>::reverse_iterator it = v1.rbegin();
	while (it != v1.rend())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
	cout << v1.capacity()<<endl;
	v1.reserve(100);
	//v1.resize(15);
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	//cout << v1.front()<<endl;
	//cout << v1.back()<<endl;
	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	//vector的insert的第一个参数是iterator position
	v1.insert(v1.begin(), 6);
	v1.insert(v1.begin() + v1.size(), 10);
	v1.insert(v1.begin() + 5,152);
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	v1.erase(v1.begin()+1, v1.end());//[first,last)
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	v1.swap(v2);
	//v1.clear();
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	v1.swap(v2);
	vector<int> v3(10, 1);
	v1 = v3;
	v2 = v3;
	cout << (v1 != v2)<<endl;
	//v1.insert(v1.begin(), 1);
	//v2.insert(v2.begin(), 2);
	v1.push_back(1);
	cout << (v1 > v2) << endl;
	swap(v1, v2);
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	for (auto x : v2)
	{
		cout << x << ' ';
	}
	cout << endl;


}


int main()
{
	Test1();



	return 0;
}