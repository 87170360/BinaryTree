#ifndef __BINARYTREE_LSX_
#define __BINARYTREE_LSX_

#include <vector>
#include <stddef.h>

typedef std::vector<int> INTVEC;
typedef INTVEC::const_iterator INTVEC_CITER;
typedef INTVEC::iterator INTVEC_ITER;

typedef struct NodeDef 
{
	NodeDef(void)
		: value(0)
		, left(NULL)
		, right(NULL)
	{}
    int value;
    NodeDef *left;
    NodeDef *right;
}Node, *pNode;

/*
int i: 当前节点的序号 
int j: 二叉树节点个数
pNode: 新建二叉树的根节点指针 
*/
pNode CreateBinaryTree(const INTVEC& vec, int i, int j)
{
	if(i >= j) return(NULL);
	pNode p = new Node;
	p->value = vec[i];
	std::cout << p->value << std::endl;
	p->left = CreateBinaryTree(vec, 2 * i + 1, j);
	p->right = CreateBinaryTree(vec, 2 * i + 2, j);

	return p;
}

void printBinaryTree(pNode p, int layer)
{
	if(p == NULL) return;

	printBinaryTree(p->right, ++layer);

	for(int i = 0; i < layer; ++i)
	{
		//std::cout << " ";
	}
	std::cout << "layer:" << layer << " value" << p->value << std::endl;
	printBinaryTree(p->left, ++layer);
}

#endif