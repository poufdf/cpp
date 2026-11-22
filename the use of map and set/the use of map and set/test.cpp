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



int main()
{
	Test1();

	return 0;
}
