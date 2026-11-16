#define _CRT_SECURE_NO_WARNINGS
#include"AVLTree.h"


void Test1()
{
	zcq::AVLTree<int, int> T;
	int a[] = { 6,3,27,1,73,34,27,16,623,28};
	for (auto& x : a)
	{
		T.Insert({ x,x });

	}
	T.Inorder();
	cout << "高度为:" << T.Height() << endl;
	cout << "结点个数为:" << T.Size() << endl;
	cout << "是否为AVL树:" << T.isBalance() << endl;
}

void Test2()
{
	const int N = 1000000;
	std::vector<int> v;
	v.reserve(N + 10);
	srand(time(0));//初始化随机数生成器
	for (int i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}
	zcq::AVLTree<int, int> T;
	size_t begin1 = clock();
	for (auto& x : v)
	{
		T.Insert({ x,x });
	}
	size_t end1 = clock();
	cout << "插入时间:" << end1-begin1 << endl;
	cout << "高度为:" << T.Height() << endl;
	cout << "结点个数为:" << T.Size() << endl;
	cout << "是否为AVL树:" << T.isBalance() << endl;
	size_t begin2 = clock();
	for (int i = 0; i < N; i++)
	{
		T.Find(rand() + i);
	}
	size_t end2 = clock();
	cout << "查找时间为:" << end2 - begin2 << endl;
}


int main()
{
	//Test1();
	Test2();

	return 0;
}