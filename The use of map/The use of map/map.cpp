#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>

using namespace std;

void Test1()
{
	map<string, string> m1;
	vector<pair<int, string>> v = { {3,"插入"},{2,"苹果"},{1,"香蕉"} };
	map<int, string> m2(v.begin(), v.end());
	for (auto& x : m2)
	{
		cout << x.first << ":" << x.second << ' ';
	}
	cout << endl;
	map<int, string> m3 = { {2,"香蕉"},{3,"苹果"},{1,"插入"} };
	for (auto& x : m3)
	{
		cout << x.first << ':' << x.second << ' ';
	}
	cout << endl;
	map<int, string>::iterator it = m2.begin();
	while (it != m2.end())
	{
		cout << it->first << ':' << it->second << ' ';
		++it;
	}
	cout << endl;
	m2.insert({ 6,"橘子" });
	m2.insert({ 8,"柚子" });
	m2.insert({ 10,"西瓜" });
	for (auto& x : m2)
	{
		cout << x.first << ':' << x.second << ' ';
	}
	cout << endl;
	m2.erase(6);
	m2.erase(8);
	for (auto& x : m2)
	{
		cout << x.first << ':' << x.second << ' ';
	}
	cout << endl;

	m2[10] = "土豆";
	map<int, string>::iterator it2 = m2.find(10);
	cout << it2->first << ':' << it2->second << endl;
	m2[6] = "番茄";
	m2[5] = "西柚";
	for (auto& x : m2)
	{
		cout << x.first << ':' << x.second << ' ';
	}
	cout << endl;



}





int main()
{
	Test1();



	return 0;
}