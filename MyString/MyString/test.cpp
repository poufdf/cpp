#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

void Test1()
{
	zcq::String s1;
	zcq::String s2("Hello World!");
	//s1 = s2;
	//s1.push_back('A');
	//s2.push_back('h');
	//s1.append("Hello");
	//s2.append("hello");
	s1 += 'A';
	s1 += "Hello World!";
	s2 += 'a';
	s2 += "hello";
}
void Test2()
{
	zcq::String s1("Hello World!");
	zcq::String s2("string");
	//s1.insert(0, 'A');
	//s1.insert(5, 'B');
	//s2.insert(0, 'S');
	//s2.insert(1, 't');
	//s2.insert(2, 'r');
	//s1.insert(0, "hello");
	//s2.insert(0, "Hello World!");
	//s2.insert(0, "AA");
	//s1.erase(0);
	//s1.erase(2, 1);
	//s2.erase(1);
	cout << s1.find("llo")<<endl;
	cout << s1.find("Wor")<<endl;
	cout << s2.find("stin")<<endl;
}
void Test3()
{
	zcq::String s1("Hello World");
	zcq::String s2 = s1.substr(6, 5);
	zcq::String s3 = s1.substr(0);
	s1.swap(s2);

}
void Test4()
{
	zcq::String s1("Hello World!");
	cout << s1 << endl;
	zcq::String s2("AAAAAA");
	zcq::String s3 = s1 + s2;
	for (auto ch : s3)
	{
		cout << ch;
	}
	cout << endl;
	//zcq::String s4;
	//getline(cin, s4);
	//cout << s4;
	swap(s1, s2);
	cout << s1 << endl << s2 << endl;
}
void Test5()
{
	zcq::String s1("Hello World");
	zcq::String s2(s1);
	cout << s2 << endl;
	zcq::String s3("string");
	s2 = s3;
	cout << s2 << endl;
	cin >> s2;
	cout << s2 << endl;
	getline(cin, s2);
	cout << s2 << endl;
}


int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	return 0;
}
