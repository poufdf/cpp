#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>//头文件里包含rand这个函数
int rand = 0;
int main()
{
	printf("%d", rand);//error C2365: “rand”: 重定义；以前的定义是“函数”
	return 0;
}

////C++实现
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello World!";
//	return 0;
//}
//test.cpp
//#include<stdio.h>
//int main()
//{
//	printf("Hello World!");
//	return 0;
//}