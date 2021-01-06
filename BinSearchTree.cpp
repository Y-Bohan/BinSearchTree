#include <iostream>
#include "BinSearchTree.h"
using namespace std;

void BinTree::insertTree(int* arry,int size)	//使用初始序列构造一棵二叉搜索树
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
	BinNode*  temp= this->searchTree(data);		//找到需要删除的结点
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
	if (data >= this->m_data)			//大的插入到右子树
	{
		if (this->m_rightchild == NULL)					//如果右孩子为空，则直接作为右孩子插入
		{
			this->m_rightchild = new BinNode;
			this->m_rightchild->m_parent = this;
			this->m_rightchild->m_data = data;
			this->m_rightchild->m_id = this->m_id * 2 + 2;
			this->m_rightchild->m_leftchild = NULL;
			this->m_rightchild->m_rightchild = NULL;
		}
		else			//如果右孩子不为空，则递归插入函数，直到作为叶子结点插入
		{
			this->m_rightchild->insertNode(data);
		}
		return true;
	}
	else								//小的插入到左子树
	{
		if (this->m_leftchild == NULL)			//如果左孩子为空，则直接作为左孩子插入
		{
			this->m_leftchild = new BinNode;
			this->m_leftchild->m_parent = this;
			this->m_leftchild->m_data = data;
			this->m_leftchild->m_id = this->m_id * 2 + 1;
			this->m_leftchild->m_leftchild = NULL;
			this->m_leftchild->m_rightchild = NULL;
		}
		else			//如果左孩子不为空，则递归插入函数，直到作为叶子结点插入
		{
			this->m_leftchild->insertNode(data);
		}
		return true;
	}
}

BinNode* BinNode::getMinNode()
{
	if (this->m_leftchild == NULL)		//没有左孩子，说明自己就是最小的结点
		return this;
	else		//如果左子树存在，则递归左子树，在左子树中找最小的结点
	{
		return this->m_leftchild->getMinNode();
	}
}
BinNode* BinNode::getMaxNode()
{
	if (this->m_rightchild == NULL)		//没有右孩子，说明自己就是最大的结点
		return this;
	else		//如果右子树存在，则递归右子树，在右子树中找最大的结点
	{
		return this->m_rightchild->getMaxNode();
	}
}

BinNode* BinNode::getPreNode()
{
	if (this->m_leftchild == NULL)		//左孩子为空，说明没有前驱
		return NULL;
	return this->m_leftchild->getMaxNode();				//左子树中的最大结点即为前驱
}

BinNode* BinNode::getNextNode()
{
	if (this->m_rightchild == NULL)
		return NULL;		//右孩子为空，说明没有后继
	return this->m_rightchild->getMinNode();		//右子树中的最小结点即为后继
}

BinNode* BinNode::searchNode(int data)
{
	if (this->m_data == data)
		return this;
	else if (data < this->m_data)			//小的在左边
	{
		if (this->m_leftchild == NULL)		//左边已经到底
			return NULL;
		else return this->m_leftchild->searchNode(data);
	}	
	else		//大于等于的在右边
	{
		if (this->m_rightchild == NULL)		//右边已经到底
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
	/****************第一种情况，该结点为叶子结点，没有左右孩子，则直接删除结点****************/
	if (this->m_leftchild == NULL && this->m_rightchild == NULL)			
	{
		if (this->m_parent->m_leftchild == this)				//改结点是左叶子
		{
			this->m_parent->m_leftchild = NULL;
			delete this;
			return true;
		}
		else							//该结点是右叶子
		{
			this->m_parent->m_rightchild = NULL;
			delete this;
			return true;
		}
	}

	/*********第二种情况，该结点只有左孩子或者只有右孩子，则用该结点的子树代替该结点********************/
	else if (this->m_leftchild != NULL&& this->m_rightchild == NULL)						//只有左孩子			
	{
		if (this->m_parent->m_leftchild == this)     //该结点是其父结点的左孩子
		{
			this->m_parent->m_leftchild = this->m_leftchild;		//其父结点的左孩子变为其左子节点
			this->m_leftchild->m_parent = this->m_parent;			//千万不要忘记其子结点的父结点也要该变
			delete this;
		}
		else		//该结点是其父结点的右孩子
		{
			this->m_parent->m_rightchild = this->m_leftchild;		//其父结点的右孩子变为其左子节点
			this->m_leftchild->m_parent = this->m_parent;			//千万不要忘记其子结点的父结点也要该变
			delete this;
		}
	}
	else if (this->m_leftchild == NULL && this->m_rightchild != NULL)						//只有右孩子	
	{

		if (this->m_parent->m_leftchild == this)     //该结点是其父结点的左孩子
		{
			this->m_parent->m_leftchild = this->m_rightchild;		//其父结点的左孩子变为其左子节点
			this->m_rightchild->m_parent = this->m_parent;			//千万不要忘记其子结点的父结点也要该变
			delete this;
		}
		else		//该结点是其父结点的右孩子
		{
			this->m_parent->m_rightchild = this->m_rightchild;		//其父结点的右孩子变为其左子节点
			this->m_rightchild->m_parent = this->m_parent;			//千万不要忘记其子结点的父结点也要该变
			delete this;
		}
	}

	/**********最后一种情况，该结点既有左孩子，又有右孩子，则找到该结点的后继代替该结点，该结点后继结点的子树上移（后继结点如果有子树，则一定是右子树）*****************/
	/****后继替换需要删除的结点时，直接用后继结点的数据代替需要删除结点的数据即可。然后将后继结点的子树替换后继结点，最后删除后继结点********/
	else
	{
		BinNode* thisNext= this->getNextNode();					//获取后继结点

		/****************用后继结点代替需要删除的结点this**********************************/
		this->m_data = thisNext->m_data;			//由于删除结点位置的孩子和父亲没有发生改变，所以直接用后继结点的数据替换删除结点的数据即可。否则如果用整个后继结点的内存替换删除结点，还要还原替换后结点的父亲和孩子

		/***************用后继结点的子树代替后继结点的位置******************/
		if (thisNext->m_parent->m_leftchild == thisNext)			//如果后继是其父结点的左子树
		{
			if (thisNext->m_rightchild == NULL)		//后继没有右孩子，也即没有孩子
			{
				thisNext->m_parent->m_leftchild = NULL;
			}
			else
			{
				thisNext->m_parent->m_leftchild = thisNext->m_rightchild;			//父亲孩子结点改变
				thisNext->m_rightchild->m_parent = thisNext->m_parent;				//孩子结点的父亲改变
			}
		}
		else	//后继是其父结点的右子树
		{
			if (thisNext->m_rightchild == NULL)		//后继没有右孩子，也即没有孩子
			{
				thisNext->m_parent->m_rightchild =NULL;
			}
			else
			{
				thisNext->m_parent->m_rightchild = thisNext->m_rightchild;			//父亲孩子结点改变
				thisNext->m_rightchild->m_parent = thisNext->m_parent;				//孩子结点的父亲改变
			}
		}
		delete thisNext;		//由于后继结点的数据已经替换到了删除的结点，此时就可以将后继结点的内存空间删除
	}
}

void BinNode::clean()
{
	if (this->m_leftchild != NULL)
	{
		this->m_leftchild->clean();		//如果左子树存在，则递归删除左子树

	}

	if (this->m_rightchild != NULL)
	{
		this->m_rightchild->clean();	//如果右子树存在，则递归删除右子树
	}

	/***********此时说明this没有左右子树，是叶子结点，使this的父节点指向空，此叶子结点就从树上删除了，但是this本身的空间还未删除，最后还需要再删除this本身的内存********************/
	/***********注意是this的父节点指向空，this才从树上断开。而不是this指向空。仅仅是this指向空，则this的父结点还是指向this，this结点并没有从树上撤下来***********************/
	/***********所以从树上撤下this结点的关键是this的父节点指向空。********************************/
	if (this->m_parent != NULL)			//必须加这句，因为如果是根结点，其m_parent为空时，NULL->m_leftchild访问权限错误，因为NULL是不能访问的
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
	delete this;			//上面的步骤只是讲this从树上撤下来，但是this本身的内存并没有释放，此时才释放
}