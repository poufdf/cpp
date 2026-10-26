#pragma once
#include<iostream>
#include<deque>
#include<vector>
#include<list>

namespace zcq
{	
	//Container指容器，可以是vector,list,deque,所以代码可以直接复用容器的接口
	template<class T,class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
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
