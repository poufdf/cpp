#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<map>

using namespace std;

void Test1()
{
	set<int> s1 = { 1,6,327,171,3,7133,71 };
	//s1.insert(1);
	//s1.insert(3);
	//s1.insert(548);
	//s1.insert(27);
	//s1.insert(28);
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;
	set<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
	set<int>::iterator it2 = s1.find(6);
	s1.erase(it2);
	for (auto& x : s1)
	{
		cout << x << ' ';
	}
	cout << endl;
}

void Test2()
{
	map<string, int> m = { {"Æ»¹û",1},{"Î÷¹Ï",1},{"Ïã½¶",1} };
	map<string, int>::iterator it = m.begin();
	//while (it != m.end())
	//{
	//	cout << it->first << ':' << it->second << endl;
	//	it++;
	//}
	
	while (it != m.end())
	{
		if (it->first == "Æ»¹û")
		{
			it->second++;
		}
		cout << it->first << ':' << it->second << endl;
		it++;

	}




}


int main()
{
	//Test1();
	Test2();

	return 0;
}
