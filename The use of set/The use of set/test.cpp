#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<vector>

using namespace std;

void Test1()
{
	set<int> s1;
	vector<int> v = { 1,3,16,7,17,123,2 };
	set<int> s2(v.begin(), v.end());
	for (auto& x : s2)
	{
		cout << x << ' ';
	}
	cout << endl;
	set<int> s3 = { 1,36,73,27,17,27 };
	for (auto& x : s3)
	{
		cout << x << ' ';
	}
	cout << endl;
	cout << s3.size() << endl;
	s1.insert(1);
	s1.insert(6);
	s1.insert(8);
	s1.insert(2);
	s1.insert(12);
	s1.insert(22);
	s1.insert(30);
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;
	s1.insert({ 5,6,7,8,9 });
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;
	s1.insert(v.begin(), v.end());
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;
	s1.erase(1);
	s1.erase(2);
	s1.erase(3);
	s1.erase(5);
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;
	set<int>::iterator it = s1.find(6);
	cout << *it << endl;
	cout << s1.count(6) << endl;
}

void Test2()
{
	set<int> s1 = { 1,2,3,4,5,6,7,8,9,10 };
	set<int>::iterator it1 = s1.lower_bound(2);
	set<int>::iterator it2 = s1.upper_bound(7);
	s1.erase(it1, it2);
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;


}






int main()
{
	//Test1();
	Test2();




	return 0;
}