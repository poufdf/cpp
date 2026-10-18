#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void Test1()
{
	string s1("123456");
	string::reverse_iterator it = s1.rbegin();
	while (it != s1.rend())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	cout << s1.capacity() << endl;
	s1.reserve(100);
	cout << s1.capacity() << endl;//可能大于100
}
void Test2()
{
	string s2("654321");
	cout << s2 << endl;
	cout << s2.back() << endl;
	cout << s2.front() << endl;
	s2.push_back('w');
	s2.push_back('o');
	s2.push_back('r');
	s2.push_back('l');
	s2.push_back('d');
	cout << s2 << endl;
}
void Test3()
{
	string s3 = "hello ";
	string s4("world");
	//s3.append(s4);
	//cout << s3 << endl;
	//s3.append("world");
	//cout << s3 << endl;
	//s3.append(s4, 0,1);
	//cout << s3 << endl;
	//s3.append("world", 3);
	//cout << s3 << endl;
	s3.append(3, 'w');
	cout << s3 << endl;
}

void Test4()
{
	string s1("hello ");
	//s1 += "world";
	//cout << s1 << endl;
	string s2("world");
	s1 += s2;
	cout << s1 << endl;
	s1 += '!';
	cout << s1 << endl;
	s1.assign("123456");//用括号里的值替换掉s1的值
	cout << s1 << endl;
	s1 = "hello world";
	cout << s1 << endl;
	s1.assign(s2);
	cout << s1 << endl;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();


	return 0;
}