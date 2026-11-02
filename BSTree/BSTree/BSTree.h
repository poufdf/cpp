#pragma once
#include<iostream>

using namespace std;

namespace zcq
{
	template<class K>
	struct BSTNode
	{
		BSTNode(const K& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr){ }
		
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;

	};


	template<class K>
	class BSTree
	{
		typedef BSTNode<K> Node;
	public:

		
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;//相同的值不允许插入
				}
			}
			cur = new Node(key);
			if (key > parent->_key)
			{
				parent->_right = cur;
				return true;
			}
			else
			{
				parent->_left = cur;
				return true;
			}
		}
		void Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key == cur->_key)
				{
					cout << "找到了" << "->" << key <<endl;
					return ;
				}
				else if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
			}
			cout << "没找到" << key<<endl;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			if (cur->_left == nullptr && cur->_right == nullptr)
			{
				delete cur;
				return true;
			}

			while (key != cur->_key)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					parent = cur;
					cur = cur->_left;
				}
			}
			if (cur->_left == nullptr)
			{
				if (key > parent->_key)
				{
					parent->_right = cur->_right;
					delete cur;
					return true;
				}
				else
				{
					parent->_left = cur->_right;
					delete cur;
					return true;
				}
			}
			else if (cur->_right == nullptr)
			{
				if (key > parent->_key)
				{
					parent->_right = cur->_left;
					delete cur;
					return true;
				}
				else
				{
					parent->_left = cur->_left;
					delete cur;
					return true;
				}
			}
			else
			{	
				
				Node* max = cur->_left;
				parent = cur;
				while (max->_right)
				{
					parent = max;
					max = max->_right;
				}
				swap(max->_key, cur->_key);
				if (parent == cur)
				{
					parent->_left = max->_left;
				}
				else {
					parent->_right = max->_left;
				}
				
				delete max;
				return true;
			
			}
			return false;
		}
		void Inorder()
		{	
			//给外部调用的Inorder不方便传_root,所以写一个子函数传_root。外部只要调用就行了，不用传参
			_Inorder(_root);
			cout << endl;
		}

		void _Inorder(const Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Inorder(root->_left);
			cout << root->_key << ' ';
			_Inorder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};

}
