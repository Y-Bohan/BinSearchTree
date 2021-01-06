#include <iostream>
#include "BinSearchTree.h"
using namespace std;

int main()
{
	BinTree tree;
	int a[] = { 45,12,53,3,37,100,61,24,90,78 };		
	tree.insertTree(a,sizeof(a)/sizeof(int));		//用序列初始化搜索树
	tree.insertTree(47);		//插入结点
	tree.insertTree(93);
	tree.inOrderTree();			//中序遍历
	cout <<"Max= "<< tree.getTreeMaxNode()->get_m_data() << endl;		//获取树中最大结点
	cout << "Min= " << tree.getTreeMinNode()->get_m_data() << endl;		//获取树中最小结点

	/***********结点搜索+前驱后继结点测试**********************/
	for (int i = 0; i <= 100; i++)							
	{
		if (tree.searchTree(i))				//如果i存在树中，打印其前驱和后继
		{
			cout << tree.getPreTreeNode(i)->get_m_data() << "->" << i << "->" << tree.getNextTreeNode(i)->get_m_data() << endl;					//结点为NULL时，get_m_data()结果为-1，表示不存在
		}
	}

	/********删除结点测试***********/
	tree.deleteTreeNode(61);			//删除结点为只有右孩子
	tree.inOrderTree();
	tree.deleteTreeNode(37);			//删除结点为只有左孩子
	tree.inOrderTree();
	tree.deleteTreeNode(3);				//删除结点为叶子结点
	tree.inOrderTree();
	tree.deleteTreeNode(45);		//删除结点既有左孩子，又有右孩子，且是根结点
	tree.inOrderTree();

	tree.cleanTree();			//清空树
	tree.inOrderTree();
	return 0;
}