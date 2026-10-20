#define _CRT_SECURE_NO_WARNINGS
//C++入门第一课，输入与输出代码
#include<iostream>
using namespace std;//日常练习为了方便，直接展开使用

int main()
{
	
	int  a = 0;
	//scanf("%d", &a);
	//printf("%d", a);//需要指定格式
	double b = 0.0;
	char c = 'x';

	cin >> a >> b >> c;
	cout << a << endl;
	cout << b <<' ' << c;//不需要指定格式，很方便快捷


	return 0;
}
