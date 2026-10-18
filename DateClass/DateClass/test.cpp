#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"

 void Test1()
{
	 Date d1(2026, 9, 9);
	 Date d2(2026, 9, 9);
	/* cout << d1.CheckDate() << endl;
	 cout << d2.CheckDate() << endl;*/
	 cout << (d1 > d2) << endl;
	 cout << (d1 < d2) << endl;
	 cout << (d1 <= d2) << endl;
	 cout << (d1 >= d2) << endl;
	 cout << (d1 == d2) << endl;
	 cout << (d1 !=d2) << endl;
}
 void Test2()
 {
	 Date d1(2026, 9, 13);
	/* d1 -=1000;
	 d1.Print();
	 d1 += 2000;
	  d1.Print();*/
	 d1 + 1000;
	 d1.Print();
	 d1 - 1000;
	 d1.Print();	 
 }
 void Test3()
 {
	Date d1(2026, 9, 13);
	//d1++;
	//d1.Print();
	//d1--;
	//d1.Print();
	Date d2(2019, 3, 8);
	cout << (d1 - d2);
 }
 void Test4()
 {
	 Date d1(2026, 9, 13);
	// cout << d1;
	 cin >> d1;
	 cout << d1;
 }
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();

	return 0;
}