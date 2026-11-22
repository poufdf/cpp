#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

namespace zcq
{
	//红黑树只有红黑两种颜色
	enum Color
	{
		RED,
		BLACK
	};

	template<class K,class V>
	struct RBTreeNode
	{
		pair<K, V> _kv;
		RBTreeNode* _left;
		RBTreeNode* _right;
		RBTreeNode* _parent;
		Color _col;

		RBTreeNode(const pair<K, V>& kv)
			:_kv(kv)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
		    ,_col(RED){ }

	};

	template<class K,class V> 
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
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

		}
		//左右双旋
		void LRRotate(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			//先左单旋再右单旋
			LRotate(subL);
			RRotate(parent);
			
		}
		//右左双旋
		void RLRotate(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			//先右单旋再左单旋
			RRotate(subR);
			LRotate(parent);
		}

		bool Check(Node* root, int blackNum, int refValue)
		{
			//走前序遍历，如果根结点为空说明一条路径走完了
			if (root == nullptr)
			{
				//判断黑色结点个数是否相等
				if (blackNum != refValue)
				{
					cout << "存在一条路径黑色结点个数不相等" << endl;
					return false;
				}
				return true;

			}
			//判断是否有连续的红色结点
			if (root->_col == RED && root->_parent->_col == RED)
			{
				cout << root->_kv.first << "和其父结点" << root->_parent->_kv.first << "为连续的红色结点" << endl;
				return false;
			}
			//根结点为黑则blackNum++
			if (root->_col == BLACK)
			{
				blackNum++;
			}

			return Check(root->_left,blackNum,refValue) && Check(root->_right,blackNum,refValue);

		}


	public:
		//中序遍历
		void Inorder()
		{
			_Inorder(_root);
		}
		//插入
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
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
			cur->_col = RED;//插入新结点的颜色都为红色
			if (kv.first < parent->_kv.first)
			{
				//cur = parent->_right; //写代码时写昏头了，赋值都写反了，我说怎么cur突然变成空指针了,bug真的会出现在自己意想不到的地方
				parent->_left = cur;

			}
			else
			{
				//cur = parent->_right;
				parent->_right = cur;
			}
			cur->_parent = parent;
			//根据红黑树的的规则维护
			//连续的两个红结点需要处理
			while (parent && parent->_col == RED)
			{
				Node* grandParent = parent->_parent;
				//判断parent的位置，从而确定uncle的位置
				if (parent == grandParent->_left)
				{
					Node* uncle = grandParent->_right;      //       g(b)				 g(r)
					//根据uncle的颜色进行不同处理				 p(r)   u(r)  ---->   p(b)	 u(b)
					//uncle为红，则只需把g变为红。p，u都变为黑  c(r)				c(r)
					if (uncle != nullptr && uncle->_col == RED)
					{
						grandParent->_col = RED;
						parent->_col = BLACK;
						uncle->_col = BLACK;
						
					}
					//uncle为黑或不存在，处理逻辑一样,注意:当u不存在时,cur一定是新增结点，当u存在时,cur一定是更新上来的(根据每条路径黑色结点个数相同验证)										
					else                                //        g(b)				p(b)						
					{									//     p(r)			----> c(r)  g(r) 	
						//右单旋						//	 c(r)	
						if (cur == parent->_left)
						{
							RRotate(grandParent);
							parent->_col = BLACK;
							grandParent->_col = RED;
						}
														//      g(b)					 c(b)			
														//   p(r)          ---->      p(r)  g(r)
														//      c(r)
						//双旋加变色
						else
						{
							LRRotate(grandParent);
							cur->_col = BLACK;
							grandParent->_col = RED;
						}											
					}
					
				}
				//p为g右孩子
				else                                        //    g(b)                      g(r)
				{                                           //	u(r)  p(r)        ---->   u(b) p(b) 
					                                        //           c(r)                      c(r)
					Node* uncle = grandParent->_left;
					if (uncle != nullptr && uncle->_col == RED)
					{
						grandParent->_col = RED;
						uncle->_col = BLACK;
						parent->_col = BLACK;
					}
					else                                   //   g(b)                        p(b)
					{                                      //      p(r)     ---->        g(r)  c(r)
														   //        c(r)
						//左单旋
						if (cur == parent->_right)
						{
							LRotate(grandParent);
							grandParent->_col = RED;
							parent->_col = BLACK;
						}
															//    g(b)                  c(b)
														    //       p(r)      ---->  g(r) p(r)       
						                                    //    c(r)  
						//右左双旋
						else
						{
							RLRotate(grandParent);
							grandParent->_col = RED;
							cur->_col = BLACK;
						}
					}
				}
				cur = grandParent;
				parent = cur->_parent;
	
			}
			_root->_col = BLACK;
			return true;
		}
		//查找
		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_kv.first)
				{
					cur = cur->_left;
				}
				else if (key > cur->_kv.first)
				{
					cur = cur->_right;
				}
				else
				{	
					cout << key << "找到了" << endl;
					return true;
				}
			}
			cout << key << "没找到" << endl;
			return false;
		}
		//判断是否为红黑树
		bool isRBTree()
		{
			//空树也符合红黑树规则
			if (_root == nullptr)
			{
				return true;
			}

			if (_root->_col == RED)
			{
				return false;
			}

			//定义变量记录一条路径上黑色结点的个数
			int refValue = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_col == BLACK)
				{
					refValue++;
				}
				cur = cur->_left;
			}

			return Check(_root, 0, refValue);
		}
	private:
		Node* _root = nullptr;
	};


}