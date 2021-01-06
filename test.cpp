#include <iostream>
#include "BinSearchTree.h"
using namespace std;

int main()
{
	BinTree tree;
	int a[] = { 45,12,53,3,37,100,61,24,90,78 };		
	tree.insertTree(a,sizeof(a)/sizeof(int));		//�����г�ʼ��������
	tree.insertTree(47);		//������
	tree.insertTree(93);
	tree.inOrderTree();			//�������
	cout <<"Max= "<< tree.getTreeMaxNode()->get_m_data() << endl;		//��ȡ���������
	cout << "Min= " << tree.getTreeMinNode()->get_m_data() << endl;		//��ȡ������С���

	/***********�������+ǰ����̽�����**********************/
	for (int i = 0; i <= 100; i++)							
	{
		if (tree.searchTree(i))				//���i�������У���ӡ��ǰ���ͺ��
		{
			cout << tree.getPreTreeNode(i)->get_m_data() << "->" << i << "->" << tree.getNextTreeNode(i)->get_m_data() << endl;					//���ΪNULLʱ��get_m_data()���Ϊ-1����ʾ������
		}
	}

	/********ɾ��������***********/
	tree.deleteTreeNode(61);			//ɾ�����Ϊֻ���Һ���
	tree.inOrderTree();
	tree.deleteTreeNode(37);			//ɾ�����Ϊֻ������
	tree.inOrderTree();
	tree.deleteTreeNode(3);				//ɾ�����ΪҶ�ӽ��
	tree.inOrderTree();
	tree.deleteTreeNode(45);		//ɾ�����������ӣ������Һ��ӣ����Ǹ����
	tree.inOrderTree();

	tree.cleanTree();			//�����
	tree.inOrderTree();
	return 0;
}