#pragma once
//优先队列可以看作堆，但不仅仅包含大堆，小堆。它可以根据一个规则top出一个元素，例如偶数
#include<iostream>
#include<vector>

namespace zcq
{	template<class T>
	class Less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
};
template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
	template<class T,class Container = std::vector<T>,class Compare = std::less<T>>
	class priority_queue
	{
	public:
		priority_queue(){}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		:_con(first, last) {
			for (int i = ((int)_con.size() - 1 - 1) / 2;i >= 0;i--)
			{
				adjust_down(i);
			}

		}
		void adjust_up(int child)
		{
			int parent = (child - 1) / 2;
		
			while (child > 0)
			{
				if (Compare()(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}

			}
		}

		void adjust_down(int parent)
		{
			int child = parent * 2 + 1;
			

			while (child < _con.size())
			{
				if (child + 1 < _con.size() && Compare()(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (Compare()(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up((int)_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}


		T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		int size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}
