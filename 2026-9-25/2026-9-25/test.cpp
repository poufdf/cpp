#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void Test1()
{

	string s1;
	string s2("Hello World!");
	cout << s2 << endl;
	string s3(s2);
	cout << s3 << endl;
	string s4 = s3;
	cout << s4 << endl;
	string s5 = "asdf";
	cout << s5 << endl;
	s1 = s3;
	cout << s1 << endl;
	string s6(s2, 6);//从s2的第六个位置开始拷贝
	cout << s6 << endl;
	string s7("hello world", 5);//复制字符数组的前5个字符
	cout << s7 << endl;
	string s8(5, '*');
	cout << s8 << endl;
}
void Test2()
{
	string s1("12345");
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i]<<'|';
	}
	/*string s2;
	cin >> s2;
	cout << s2 << endl;*/
	cout << endl << endl;
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl << endl;
	for (auto ch : s1)
	{
		cout << ch << "%";
	}
}


int main()
{
	//Test1();
	Test2();
	return 0;
}