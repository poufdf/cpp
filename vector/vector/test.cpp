#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"

void Test1() {
	zcq::vector<int> v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(9);
	v.Print();
	cout << endl;
	//v.insert(v.begin()+3, 10);
	//v.erase(v.begin()+5);
	//v.Print();
	zcq::vector<int>::iterator pos = v.begin();

	while (pos != v.end()) {
		if (*pos % 2 == 0) {
			pos = v.erase(pos);
		}
		else {
			++pos;
		}
	}

	v.Print();
}

void Test2() {
	zcq::vector<string> v;
	v.push_back("hello");
	v.push_back("world");
	v.push_back("!");
	v.insert(v.begin() + 1, "hello");
	v.insert(v.begin(), "world");
	v.Print();
}

void Test3() {
	zcq::vector<int> v = { 1,2,3,4,5,6 };
	v.Print();
	cout << endl;
	zcq::vector<string> v1 = { "Hello World" };
	v1.Print();
	cout << endl;
	zcq::vector<int> v2(v.begin()+1,v.end()-1);
	v2.Print();
	cout << endl;
	zcq::vector<int> v3(v);
	v3.Print();
	cout << endl;
	v3 = v;
	v3.Print();
}

void Test4() {
	zcq::vector<int> v1 = { 1,2,3,4,5 };
	v1.reserve(10);
	v1.Print();
	cout << endl;
	v1.resize(8,1);
	v1.Print();
	cout << endl;
	zcq::vector<int> v2(10u, 1);
	v2.Print();
}


int main() {
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}
