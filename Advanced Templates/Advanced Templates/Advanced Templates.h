#pragma once
//模板进阶内容的练习
#include<iostream>

using namespace std;

namespace zcq {
	template<class T, size_t N = 10>
	class arr {
	public:
		

		T& operator[](size_t pos)
		{
			return _arr[pos];
		}

	private:
		T _arr[N];
	};



}

