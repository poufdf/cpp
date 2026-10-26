#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include"queue.h"

void Test1()
{
	zcq::stack<int,std::list<int>> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	std::cout << s1.size();
	std::cout << std::endl;
	int k = 4;
	while (k--)
	{
		std::cout << s1.top() << ' ';
		s1.pop();
	}
}

void Test2()
{
	zcq::queue<int,std::vector<int>> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	std::cout << q1.size();
	std::cout << std::endl;
	std::cout << q1.back();
	std::cout << std::endl;
	int k = 4;
	while (k--)
	{
		std::cout << q1.front() << ' ';
		q1.pop();
	}
}

int main()
{
	//Test1();
	Test2();

	return 0;
}

