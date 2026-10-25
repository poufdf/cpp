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

//优先队列使用
void Test3()
{	//优先队列不能用初始化列表，可以用迭代器初始化
	vector<int> v = { 6,3,7,21,2,8, };
	priority_queue<int> q1(v.begin(), v.end());
	int k = 6;
	while (k--)
	{
		cout << q1.top() << ' ';
		q1.pop();
	}
	cout << endl;
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	int m = 7;
	q2.push(67);
	while (m--)
	{
		cout << q2.top() <<' ';
		q2.pop();
	}
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}