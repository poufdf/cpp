#define _CRT_SECURE_NO_WARNINGS
#include"BSTree.h"

void Test1()
{
	zcq::BSTree<int> B;
	B.Insert(82);
	B.Insert(33);
	B.Insert(11);
	B.Insert(10);
	B.Insert(56);
	B.Insert(71);
	B.Insert(1);
	B.Insert(15);
	B.Insert(48);
	B.Insert(127);
	B.Insert(174);
	B.Inorder();
	//B.Find(15);
	//B.Find(56);
	//B.Find(1);
	//B.Find(174);
	//B.Find(192);
	//B.Find(2);
	//B.Find(33);
	B.Erase(56);
	B.Inorder();

}


int main()
{
	Test1();

	return 0;
}