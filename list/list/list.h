#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace zcq
{	template<class T>
struct list_node
	{
		list_node(const T& x = T())
			:_prev(nullptr)
			,_next(nullptr)
			,val(x){ }

	
		list_node<T>* _prev;
		list_node<T>* _next;
		T val;
	};

template<class T>
struct list_iterator
{
	typedef list_node<T> Node;
	Node* _node;

	list_iterator(Node* node)
		:_node(node) {
	}

	T& operator*()
	{
		return _node->val;
	}

	list_iterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	bool operator!= (const list_iterator<T>& it)//end()返回的是一个临时对象，必须用const引用接收
	{
		return _node != it._node;
	}

};


template<class T>
class list
{
public:
	typedef list_node<T> Node;
	typedef list_iterator<T> iterator;
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

	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
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
		insert(end(), x);
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}



private:
	Node* _head;
	size_t _size;

};

}

