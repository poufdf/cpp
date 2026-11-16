#pragma once
#include<iostream>
#include<assert.h>
#include<cstdlib>
#include<vector>
#include<ctime>
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
		//中序遍历
		void _Inorder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Inorder(root->_left);
			cout << root->_kv.first << ' ';
			_Inorder(root->_right);
		}
		//求高度
		int _Height(Node* root)
		{
			if (root == nullptr)
			{
				return 0;
			}
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}
		//求个数
		int _Size(Node* root)
		{
			if (root == nullptr)
			{
				return 0;
			}

			return _Size(root->_left) + _Size(root->_right) + 1;
		}
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
		//检测树是否平衡
		bool _isBalance(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			int dif = rightHeight - leftHeight;
			if (abs(dif) >= 2)
			{
				cout << root->_kv.first << "高度差异常" << endl;
				return false;
			}
			if (root->_bf != dif)
			{
				cout << root->_kv.first << "平衡因子异常" << endl;
				return false;
			}

			return _isBalance(root->_left) && _isBalance(root->_right);
		}
	public:
		//中序遍历
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		//求高度
		int Height()
		{
			return _Height(_root);
		}
		//求个数
		int Size()
		{
			return _Size(_root);
		}

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
		//检测是否平衡
		bool isBalance()
		{
			return _isBalance(_root);
		}
		//查找某一个结点
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_kv.first)
				{
					cur = cur->_right;
				}
				else if (key < cur->_kv.first)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

	private:
		Node* _root = nullptr;

	};

}
