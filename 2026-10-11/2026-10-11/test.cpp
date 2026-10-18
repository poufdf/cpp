#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void Test1()
{
	vector<int> v2(10, 1);
	vector<int> v1(v2);
	vector<int> v3;
	v3 = v1;
	for (auto x : v2)
	{
		cout << x << ' ';
	}
	cout << endl;
	for (auto x : v1)
	{
		cout << x << ' ';
	}
	cout << endl;
	for (auto x : v3)
	{
		cout << x << ' ';
	}
	cout << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	vector::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;





}

int main()
{
	Test1();




	return 0;
}