#ifndef BinSearchTree_H
#define	BinSearchTree_H
#include <iostream>
using namespace std;

class BinNode
{

public:
	friend class BinTree;
	BinNode() {}
	BinNode(int data)
	{
		m_data = data;
		m_id = -1;
		m_parent = NULL;
		m_leftchild = NULL;
		m_rightchild = NULL;
	}
	bool insertNode(int data);		//插入数据为data的结点
	BinNode* getMaxNode();		//获取子树的最大结点
	BinNode* getMinNode();		//获取子树的最小结点
	BinNode* getPreNode();		//获取前驱结点，也即当前结点的左子树中最大的结点
	BinNode* getNextNode();		//获取后继结点，也即当前结点的右子树中的最小的结点
	bool deleteNode();		//删除当前结点
	BinNode* searchNode(int data);		//在子树中搜索数据为data的结点是否存在
	bool inOrderTraverse();			//中序遍历
	void clean();		//删除子树的所有结点
	int get_m_data() 
	{ 
		if (this != NULL)
			return m_data;
		else return -1;
	}
private:
	int m_data;
	BinNode* m_parent;
	BinNode* m_leftchild;
	BinNode* m_rightchild;
	int m_id;
};

class BinTree
{
public:
	BinTree()
	{
		size = 0;
		root = NULL;
	}
	~BinTree()
	{
		cout << "**********~BinTree()*******" << endl;
		cleanTree();
	}
	void insertTree(int* arry,int size);		//将序列中的size个数据插入到当前树中或者用该序列生成一棵二叉搜索树
	void insertTree(int data);		//插入数据为data的结点
	bool deleteTreeNode(int data);			//删除数据为data的结点
	BinNode* searchTree(int data);		//搜索树中数据为data的结点是否存在
	BinNode* getPreTreeNode(int data);	//获取数据为data的结点的前驱结点
	BinNode* getNextTreeNode(int data);	//获取数据为data的结点的后继结点
	BinNode* getTreeMaxNode();		//获取树的最大结点
	BinNode* getTreeMinNode();		//获取树的最小结点
	bool inOrderTree();				//中序遍历
	void cleanTree();		//清空树，将其变为一颗空树
private:
	BinNode* root;
	int size;   //树的所有结点个数
};
#endif 

