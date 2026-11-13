#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zcq
{
	//树结点
	template<class K,class V>
	struct AVLTreeNode
	{
		pair<K, V> _kv;
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		int _bf;//平衡因子

		AVLTreeNode(const pair<K,V>& kv)
			:_kv(kv)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_bf(0){ }
	};

	//树
	template<class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	private:
		//右单旋
		void RRotate(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}
			subL->_right = parent;
			Node* parentParent = parent->_parent;
			parent->_parent = subL;
			if (parentParent == nullptr)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (parent == parentParent->_left)
				{
					parentParent->_left = subL;
				}
				else
				{
					parentParent->_right = subL;
				}
				subL->_parent = parentParent;
			}
			subL->_bf = 0;
			parent->_bf = 0;
		}
		//左单旋
		void LRotate(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			Node* parentParent = parent->_parent;
			subR->_left = parent;
			parent->_parent = subR;
			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			if (parentParent == nullptr)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (parent == parentParent->_left)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR;
				}
				subR->_parent = parentParent;
			}
			//更新平衡因子
			subR->_bf = 0;
			parent->_bf = 0;
		}
		//左右双旋
		void LRRotate(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;
			//先左单旋再右单旋
			LRotate(subL);
			RRotate(parent);
			//更新平衡因子
			if (bf == 0)
			{
				subLR->_bf = 0;
				subL->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == -1)
			{
				subLR->_bf = 0;
				subL->_bf = 0;
				parent->_bf = 1;
			}
			else if (bf == 1)
			{
				subLR->_bf = 0;
				subL->_bf = -1;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		//右左双旋
		void RLRotate(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;
			//先右单旋再左单旋
			RRotate(subR);
			LRotate(parent);
			//更新平衡因子
			if (bf == 0)
			{
				subRL->_bf = 0;
				subR->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == -1)
			{
				subRL->_bf = 0;
				subR->_bf = 1;
				parent ->_bf = 0;
			}
			else if (bf == 1)
			{
				subRL->_bf = 0;
				subR->_bf = 0;
				parent->_bf = -1;
			}
			else
			{
				assert(false);
			}
		}


	public:
		//插入并更新平衡因子
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}

			}
			cur = new Node(kv);
			if (kv.first < parent->_kv.first)
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_right = cur;
				cur->_parent = parent;
			}


			while (parent)
			{
				//插入完成，更新平衡因子,应在循环里面
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				if (parent->_bf == -1 || parent->_bf == 1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == -2 || parent->_bf == 2)
				{
					//右单旋
					if (cur->_bf == -1 && parent->_bf == -2)
					{
						RRotate(parent);
					}
					//左单旋
					if (cur->_bf == 1 && parent->_bf == 2)
					{
						LRotate(parent);
					}
					//左右双旋
					if (cur->_bf == 1 && parent->_bf == -2)
					{
						LRRotate(parent);
					}
					//右左双旋
					if (cur->_bf == -1 && parent->_bf == 2)
					{
						RLRotate(parent);
					}


					break;
				}
			}
			
			return true;



		}






	private:
		Node* _root = nullptr;

	};









}
