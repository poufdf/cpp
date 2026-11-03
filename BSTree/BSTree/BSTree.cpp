#define _CRT_SECURE_NO_WARNINGS
#include"BSTree.h"

void Test1()
{
	zcq::BSTree<int> B;
	B.Insert(26);
	B.Insert(27);
	B.Insert(17);
	B.Insert(13);
	B.Insert(7);
	B.Insert(3178);
	B.Insert(22);
	B.Insert(92);
	B.Insert(81);
	B.Insert(91);
	B.Insert(82);
	B.Inorder();
	//B.Find(15);
	//B.Find(56);
	//B.Find(1);
	//B.Find(174);
	//B.Find(192);
	//B.Find(2);
	//B.Find(33);
	B.Erase(3178);
	B.Inorder();

}


int main()
{
	Test1();

	return 0;
}