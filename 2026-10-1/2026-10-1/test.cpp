#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


void Test1()
{
	string s1("Hello World");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	string s2 = "string";
	for (auto ch : s2)
	{
		cout << ch;
	}
	cout << endl;
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit;
		rit++;
	}
}

void Test2()
{
	string s1("Hello World");
	cout << s1 << endl;
	s1.resize(25);
	cout << s1 << endl;//多余的空间都会插入\0
	cout << s1.capacity()<<endl;
	s1.reserve(60);
	cout << s1.capacity()<<endl;
	s1.clear();
	cout << s1<<endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	
}
void Test3()
{
	string s1("Hello World");
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << '%';
	}
	cout << endl;
	cout << s1.at(0)<<endl;
	cout << s1.back()<<endl;
	cout << s1.front() << endl;
}
void Test4()
{
	string s1("Hello World");
	s1.push_back('!');
	cout << s1 << endl;
	//s1.append("xxxxxxxxx");
	//cout << s1 << endl;
	string s2 = "yyyyyyyy";
	//s1.append(s2);
	//cout << s1 << endl;
	//s1 += "zzzzzzzz";
	//cout << s1 << endl;
	//s1.assign("string");
	//cout << s1 << endl;
	//s1 = "Hello World";
	//cout << s1 << endl;
	s1.insert(0, "Hello");
	s2.insert(0, s1);
	cout << s1 << endl << s2<<endl;
	s1.insert(0, 1, 'A');
	s2.insert(0, 2, 'A');
	cout << s1 << endl << s2 << endl;
	s1.erase(0, 5);
	s2.erase(0,10);
	cout << s1 << endl << s2 << endl;
}
void Test5()
{
	string s1("Hello World");
	string s2("string");
	//s1.replace(0, 2, s2);
	s1.replace(0, 2, "AAAAA");
	cout << s1 << endl;
	cout << s1.size()<<endl;
	s1.replace(0, 2, s2, 0, 6);
	cout << s1 << endl;
	cout << s1.size()<<endl;
	cout << s1 << endl << s2<<endl;
	s1.swap(s2);
	cout << s1 << endl << s2 <<endl;
	s1.pop_back();
	cout << s1 << endl;
}
void Test6()
{
	string s1("Hello World");
	const char* p = s1.c_str();//const char* c_str() const 就是s1里的_str
	for (int i = 0; i < s1.size(); i++)
	{
		cout << p[i];
	}
	cout << endl;
	cout << s1.find('l', 0)<<endl;
	cout << s1.rfind("W") << endl;//rfind里的npos是从npos位置开始向前找
	string s2 = s1.substr(0, 5);
	cout << s2 << endl;
	cout << "s1.size = " << s1.size() << ' ' << "s2.capacity = " << s2.size() << endl;
	cout << "s1.capacity = " << s1.capacity() << ' ' << "s2.capacity = " << s2.capacity() << endl;

}
void Test7()
{
	string s1("Hello World");
	string s2 = "stirng";
	cout << (s1 < s2)<<endl;
	cout << (s1 == s2) << endl;
	cout << s1 << endl << s2<< endl;
	s1.swap(s2);
	cout << s1 << endl << s2 << endl;
}

void Test8()
{
	string s1;
	/*cin >> s1;
	cout << s1;*/
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << s1 << endl<<s2<<endl; 
}


int main()
{

	//Test1();//测试迭代器和范围for
	//Test2();
	//Test3();
	Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	return 0;
}
