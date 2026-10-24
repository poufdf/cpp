#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void Test1()
{
	//stack<int> st;
	//st.push(1);
	//st.push(2);
	//st.push(3);
	//st.push(4);
	//cout << st.size();
	//cout << endl;
	//cout << st.top();
	//cout << endl;
	//st.pop();
	//cout << st.top();
	//cout << endl;
	//cout << st.size();
	
	//不能写stack<int> st2 = {1，2，3，4，5} explicit stack (const container_type& ctnr); explicit关键字禁止构造函数隐式类型转换
	stack<int,vector<int>> st2({1,2,3,4,5});
	cout << st2.top();
}

void Test2()
{
	queue<int,list<int>> q({ 1,2,3,4,5 });
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.push(6);
	cout << q.back() << endl;
	q.pop();
	cout << q.front() << endl;
	queue<int,list<int>> q2(q);
	cout << q2.front() << endl;
	cout << q2.size() << endl;
}


int main()
{
	Test1();
	//Test2();
	return 0;
}