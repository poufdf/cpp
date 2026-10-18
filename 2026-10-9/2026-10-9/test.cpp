#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int add(int x, int y)
{
	return x + y;
}
double add(double x, double y)
{
	return x + y;
}
int main()
{
	cout << add(1, 3) << endl;//4
	cout << add(6.1, 5.2) << endl;//11.3


	return 0;
}