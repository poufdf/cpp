#define _CRT_SECURE_NO_WARNINGS
#include"RBTree.h"



void Test1()
{
	//int a[] = { 1,36,72,4,71,82,29,95,72,84,28 };
	//zcq::RBTree<int, int> T;
	//for (auto& x : a)
	//{
	//	T.Insert({ x,x });
	//}
	//T.Inorder();
	//cout << endl;
	//T.Find(28);
	//cout << T.isRBTree();
	zcq::RBTree<int, int> T;
	srand(time(0));
	const int N = 1000;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}
	for (auto& x : v)
	{
		T.Insert({ x,x });
	}
	int temp = v[10];
	T.Inorder();
	cout << endl;
	T.Find(temp);
	cout << T.isRBTree();

}



int main()
{
	Test1();




	return 0;
}