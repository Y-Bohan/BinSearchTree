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
	bool insertNode(int data);		//��������Ϊdata�Ľ��
	BinNode* getMaxNode();		//��ȡ�����������
	BinNode* getMinNode();		//��ȡ��������С���
	BinNode* getPreNode();		//��ȡǰ����㣬Ҳ����ǰ���������������Ľ��
	BinNode* getNextNode();		//��ȡ��̽�㣬Ҳ����ǰ�����������е���С�Ľ��
	bool deleteNode();		//ɾ����ǰ���
	BinNode* searchNode(int data);		//����������������Ϊdata�Ľ���Ƿ����
	bool inOrderTraverse();			//�������
	void clean();		//ɾ�����������н��
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
	void insertTree(int* arry,int size);		//�������е�size�����ݲ��뵽��ǰ���л����ø���������һ�ö���������
	void insertTree(int data);		//��������Ϊdata�Ľ��
	bool deleteTreeNode(int data);			//ɾ������Ϊdata�Ľ��
	BinNode* searchTree(int data);		//������������Ϊdata�Ľ���Ƿ����
	BinNode* getPreTreeNode(int data);	//��ȡ����Ϊdata�Ľ���ǰ�����
	BinNode* getNextTreeNode(int data);	//��ȡ����Ϊdata�Ľ��ĺ�̽��
	BinNode* getTreeMaxNode();		//��ȡ���������
	BinNode* getTreeMinNode();		//��ȡ������С���
	bool inOrderTree();				//�������
	void cleanTree();		//������������Ϊһ�ſ���
private:
	BinNode* root;
	int size;   //�������н�����
};
#endif 

