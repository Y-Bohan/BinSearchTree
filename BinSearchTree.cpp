#include <iostream>
#include "BinSearchTree.h"
using namespace std;

void BinTree::insertTree(int* arry,int size)	//ʹ�ó�ʼ���й���һ�ö���������
{
	int i = 0;
	if (root == NULL)
	{
		root = new BinNode;
		root->m_id = 0;
		root->m_data = *arry;
		root->m_parent = NULL;
		root->m_leftchild = NULL;
		root->m_rightchild = NULL;
		i++;
	}
	while(i<size)
	{
		root->insertNode(arry[i]);
		i++;
	}
}

void BinTree::insertTree(int data)
{
	if (root == NULL)
	{
		root = new BinNode;
		root->m_id = 0;
		root->m_data = data;
		root->m_parent = NULL;
		root->m_leftchild = NULL;
		root->m_rightchild = NULL;
	}
	else 
		root->insertNode(data);
}

bool BinTree::deleteTreeNode(int data)
{
	BinNode*  temp= this->searchTree(data);		//�ҵ���Ҫɾ���Ľ��
	if (temp != NULL)
	{
		temp->deleteNode();
		return true;
	}
	return false;
}

BinNode* BinTree::searchTree(int data)
{
	if (root == NULL)
		return NULL;
	else return root->searchNode(data);
}

bool BinTree::inOrderTree()
{
	if (root == NULL)
		return false;
	else
	{
		root->inOrderTraverse();
		cout << endl;
		return true;
	}
}

BinNode* BinTree::getPreTreeNode(int data)
{
	BinNode* temp = searchTree(data);
	if (temp == NULL)
		return NULL;
	else return temp->getPreNode();
}

BinNode* BinTree::getNextTreeNode(int data)
{
	BinNode* temp = searchTree(data);
	if (temp == NULL)
		return NULL;
	else return temp->getNextNode();
}

BinNode* BinTree::getTreeMaxNode()
{
	if (root != NULL)
		return root->getMaxNode();
	else return NULL;
}

BinNode* BinTree::getTreeMinNode()
{
	if (root != NULL)
		return root->getMinNode();
	else return NULL;
}

void BinTree::cleanTree()
{
	if (root == NULL)
		return;
	root->clean();
	root = NULL;
}


bool BinNode::insertNode(int data)
{
	if (data >= this->m_data)			//��Ĳ��뵽������
	{
		if (this->m_rightchild == NULL)					//����Һ���Ϊ�գ���ֱ����Ϊ�Һ��Ӳ���
		{
			this->m_rightchild = new BinNode;
			this->m_rightchild->m_parent = this;
			this->m_rightchild->m_data = data;
			this->m_rightchild->m_id = this->m_id * 2 + 2;
			this->m_rightchild->m_leftchild = NULL;
			this->m_rightchild->m_rightchild = NULL;
		}
		else			//����Һ��Ӳ�Ϊ�գ���ݹ���뺯����ֱ����ΪҶ�ӽ�����
		{
			this->m_rightchild->insertNode(data);
		}
		return true;
	}
	else								//С�Ĳ��뵽������
	{
		if (this->m_leftchild == NULL)			//�������Ϊ�գ���ֱ����Ϊ���Ӳ���
		{
			this->m_leftchild = new BinNode;
			this->m_leftchild->m_parent = this;
			this->m_leftchild->m_data = data;
			this->m_leftchild->m_id = this->m_id * 2 + 1;
			this->m_leftchild->m_leftchild = NULL;
			this->m_leftchild->m_rightchild = NULL;
		}
		else			//������Ӳ�Ϊ�գ���ݹ���뺯����ֱ����ΪҶ�ӽ�����
		{
			this->m_leftchild->insertNode(data);
		}
		return true;
	}
}

BinNode* BinNode::getMinNode()
{
	if (this->m_leftchild == NULL)		//û�����ӣ�˵���Լ�������С�Ľ��
		return this;
	else		//������������ڣ���ݹ�����������������������С�Ľ��
	{
		return this->m_leftchild->getMinNode();
	}
}
BinNode* BinNode::getMaxNode()
{
	if (this->m_rightchild == NULL)		//û���Һ��ӣ�˵���Լ��������Ľ��
		return this;
	else		//������������ڣ���ݹ������������������������Ľ��
	{
		return this->m_rightchild->getMaxNode();
	}
}

BinNode* BinNode::getPreNode()
{
	if (this->m_leftchild == NULL)		//����Ϊ�գ�˵��û��ǰ��
		return NULL;
	return this->m_leftchild->getMaxNode();				//�������е�����㼴Ϊǰ��
}

BinNode* BinNode::getNextNode()
{
	if (this->m_rightchild == NULL)
		return NULL;		//�Һ���Ϊ�գ�˵��û�к��
	return this->m_rightchild->getMinNode();		//�������е���С��㼴Ϊ���
}

BinNode* BinNode::searchNode(int data)
{
	if (this->m_data == data)
		return this;
	else if (data < this->m_data)			//С�������
	{
		if (this->m_leftchild == NULL)		//����Ѿ�����
			return NULL;
		else return this->m_leftchild->searchNode(data);
	}	
	else		//���ڵ��ڵ����ұ�
	{
		if (this->m_rightchild == NULL)		//�ұ��Ѿ�����
			return NULL;
		else return this->m_rightchild->searchNode(data);
	}	
}

bool BinNode::inOrderTraverse()
{
	if (this->m_leftchild != NULL)
		this->m_leftchild->inOrderTraverse();
	cout << this->m_data << " ";
	if (this->m_rightchild != NULL)
		this->m_rightchild->inOrderTraverse();
	return true;
}

bool BinNode::deleteNode()
{
	/****************��һ��������ý��ΪҶ�ӽ�㣬û�����Һ��ӣ���ֱ��ɾ�����****************/
	if (this->m_leftchild == NULL && this->m_rightchild == NULL)			
	{
		if (this->m_parent->m_leftchild == this)				//�Ľ������Ҷ��
		{
			this->m_parent->m_leftchild = NULL;
			delete this;
			return true;
		}
		else							//�ý������Ҷ��
		{
			this->m_parent->m_rightchild = NULL;
			delete this;
			return true;
		}
	}

	/*********�ڶ���������ý��ֻ�����ӻ���ֻ���Һ��ӣ����øý�����������ý��********************/
	else if (this->m_leftchild != NULL&& this->m_rightchild == NULL)						//ֻ������			
	{
		if (this->m_parent->m_leftchild == this)     //�ý�����丸��������
		{
			this->m_parent->m_leftchild = this->m_leftchild;		//�丸�������ӱ�Ϊ�����ӽڵ�
			this->m_leftchild->m_parent = this->m_parent;			//ǧ��Ҫ�������ӽ��ĸ����ҲҪ�ñ�
			delete this;
		}
		else		//�ý�����丸�����Һ���
		{
			this->m_parent->m_rightchild = this->m_leftchild;		//�丸�����Һ��ӱ�Ϊ�����ӽڵ�
			this->m_leftchild->m_parent = this->m_parent;			//ǧ��Ҫ�������ӽ��ĸ����ҲҪ�ñ�
			delete this;
		}
	}
	else if (this->m_leftchild == NULL && this->m_rightchild != NULL)						//ֻ���Һ���	
	{

		if (this->m_parent->m_leftchild == this)     //�ý�����丸��������
		{
			this->m_parent->m_leftchild = this->m_rightchild;		//�丸�������ӱ�Ϊ�����ӽڵ�
			this->m_rightchild->m_parent = this->m_parent;			//ǧ��Ҫ�������ӽ��ĸ����ҲҪ�ñ�
			delete this;
		}
		else		//�ý�����丸�����Һ���
		{
			this->m_parent->m_rightchild = this->m_rightchild;		//�丸�����Һ��ӱ�Ϊ�����ӽڵ�
			this->m_rightchild->m_parent = this->m_parent;			//ǧ��Ҫ�������ӽ��ĸ����ҲҪ�ñ�
			delete this;
		}
	}

	/**********���һ��������ý��������ӣ������Һ��ӣ����ҵ��ý��ĺ�̴���ý�㣬�ý���̽����������ƣ���̽���������������һ������������*****************/
	/****����滻��Ҫɾ���Ľ��ʱ��ֱ���ú�̽������ݴ�����Ҫɾ���������ݼ��ɡ�Ȼ�󽫺�̽��������滻��̽�㣬���ɾ����̽��********/
	else
	{
		BinNode* thisNext= this->getNextNode();					//��ȡ��̽��

		/****************�ú�̽�������Ҫɾ���Ľ��this**********************************/
		this->m_data = thisNext->m_data;			//����ɾ�����λ�õĺ��Ӻ͸���û�з����ı䣬����ֱ���ú�̽��������滻ɾ���������ݼ��ɡ����������������̽����ڴ��滻ɾ����㣬��Ҫ��ԭ�滻����ĸ��׺ͺ���

		/***************�ú�̽������������̽���λ��******************/
		if (thisNext->m_parent->m_leftchild == thisNext)			//���������丸����������
		{
			if (thisNext->m_rightchild == NULL)		//���û���Һ��ӣ�Ҳ��û�к���
			{
				thisNext->m_parent->m_leftchild = NULL;
			}
			else
			{
				thisNext->m_parent->m_leftchild = thisNext->m_rightchild;			//���׺��ӽ��ı�
				thisNext->m_rightchild->m_parent = thisNext->m_parent;				//���ӽ��ĸ��׸ı�
			}
		}
		else	//������丸����������
		{
			if (thisNext->m_rightchild == NULL)		//���û���Һ��ӣ�Ҳ��û�к���
			{
				thisNext->m_parent->m_rightchild =NULL;
			}
			else
			{
				thisNext->m_parent->m_rightchild = thisNext->m_rightchild;			//���׺��ӽ��ı�
				thisNext->m_rightchild->m_parent = thisNext->m_parent;				//���ӽ��ĸ��׸ı�
			}
		}
		delete thisNext;		//���ں�̽��������Ѿ��滻����ɾ���Ľ�㣬��ʱ�Ϳ��Խ���̽����ڴ�ռ�ɾ��
	}
}

void BinNode::clean()
{
	if (this->m_leftchild != NULL)
	{
		this->m_leftchild->clean();		//������������ڣ���ݹ�ɾ��������

	}

	if (this->m_rightchild != NULL)
	{
		this->m_rightchild->clean();	//������������ڣ���ݹ�ɾ��������
	}

	/***********��ʱ˵��thisû��������������Ҷ�ӽ�㣬ʹthis�ĸ��ڵ�ָ��գ���Ҷ�ӽ��ʹ�����ɾ���ˣ�����this����Ŀռ仹δɾ���������Ҫ��ɾ��this������ڴ�********************/
	/***********ע����this�ĸ��ڵ�ָ��գ�this�Ŵ����϶Ͽ���������thisָ��ա�������thisָ��գ���this�ĸ���㻹��ָ��this��this��㲢û�д����ϳ�����***********************/
	/***********���Դ����ϳ���this���Ĺؼ���this�ĸ��ڵ�ָ��ա�********************************/
	if (this->m_parent != NULL)			//�������䣬��Ϊ����Ǹ���㣬��m_parentΪ��ʱ��NULL->m_leftchild����Ȩ�޴�����ΪNULL�ǲ��ܷ��ʵ�
	{
		if (this->m_parent->m_leftchild == this)
		{
			this->m_parent->m_leftchild = NULL;
		}
		if (this->m_parent->m_rightchild == this)
		{
			this->m_parent->m_rightchild = NULL;
		}
	}
	cout << "delete " << this->m_data << endl;
	delete this;			//����Ĳ���ֻ�ǽ�this�����ϳ�����������this������ڴ沢û���ͷţ���ʱ���ͷ�
}