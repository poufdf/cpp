#define _CRT_SECURE_NO_WARNINGS
#include"priority_queue.h"

void Test1()
{
	zcq::priority_queue<int,std::vector<int>,zcq::Greater<int>> q1;
	q1.push(1);
	q1.push(2);
	q1.push(5);
	q1.push(6);
	q1.push(7);
	q1.push(3);
	q1.push(4);
	int k = 7;
	while (k--)
	{
		std::cout <<q1.top() << ' ';
		q1.pop();
	}
}

void Test2()
{
	std::vector<int> v1 = { 5,51,1,61,3,22,27 };
	zcq::priority_queue<int,std::vector<int>,zcq::Less<int>> q(v1.begin(), v1.end());
	int k = 7;
	while (k--)
	{
		std::cout << q.top() << ' ';
		q.pop();
	}
}


int main()
{
	//Test1();
	Test2();
	return 0;
}
