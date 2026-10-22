#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace zcq
{
	template<class T>
	struct list_node
	{
		list_node(const T& x = T())
			:_prev(nullptr)
			, _next(nullptr)
			, val(x) {
		}


		list_node<T>* _prev;
		list_node<T>* _next;
		T val;
	};

	template<class T,class Ref>
	struct list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		list_iterator(Node* node)
			:_node(node) {
		}

		Ref operator*()
		{
			return _node->val;
		}

		T* operator->()
		{
			return &(_node->val);
		}
		//前置++
		list_iterator<T,Ref>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//后置++,int是占位符，无实际意义，只是用来表明这是后置++。传值返回
		list_iterator<T, Ref> operator++(int)
		{
			list_iterator<T, Ref> temp(*this);//调用默认的拷贝构造，迭代器用浅拷贝没问题，因为只是拷贝指针变量，并不是一块内存空间
			_node = _node->_next;
			return temp;
		}

		list_iterator<T,Ref>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
		list_iterator<T, Ref> operator--(int)
		{
			list_iterator<T, Ref> temp(*this);
			_node = _node->_prev;
			return temp;
		}
		bool operator!= (const list_iterator<T,Ref>& it)//end()返回的是一个临时对象，必须用const引用接收
		{
			return _node != it._node;
		}

	};


	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T,T&> iterator;
		typedef list_iterator<T,const T&> const_iterator;
		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

		list()
		{
			empty_init();
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		//用列表初始化
		list(initializer_list<T> il)
		{ 
			empty_init();
			for (auto& x : il)
			{
				push_back(x);
			}
			_size = il.size();
		}

		list(const list<T>& l1)
		{
			empty_init();
			for (auto& x : l1)
			{
				push_back(x);
			}
		}

		list<T>& operator=(list<T> lt)
		{
			Swap(lt);
			return *this;
		}

		void Swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}
		size_t size()
		{
			return _size;
		}

		void Print()
		{
			for (auto& x : *this)
			{
				cout << x << ' ';
			}
		}
		void insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* prev = pos._node->_prev;
			Node* next = pos._node;
			prev->_next = newnode;
			next->_prev = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			++_size;
		}
		//尾插，直接代码复用
		void push_back(const T& x)
		{
			insert(end(), x);//insert里面已经++_size了
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)
		{
			assert(pos._node != _head);
			Node* next = (pos._node)->_next;
			Node* prev = (pos._node)->_prev;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			pos._node = nullptr;
			--_size;
			return iterator(next);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		//清空除头结点之外的其他所有结点
		void clear()
		{
			iterator it = begin();

			while (it != end())
			{
				it = erase(it);
			}
		}

	private:
		Node* _head;
		size_t _size;

	};

}

