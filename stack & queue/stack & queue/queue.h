#pragma once
#include<iostream>
#include<deque>
#include<vector>
#include<list>


namespace zcq
{	
	template<class T, class Container = std::deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			//_con.pop_front();//这种写法不能用vector,因为vector没有pop_front()
			_con.erase(_con.begin());
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;

	};

}