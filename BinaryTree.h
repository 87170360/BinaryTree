#ifndef __BINARYTREE_LSX_
#define __BINARYTREE_LSX_

#include <vector>
#include <map>
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
int i: ��ǰ�ڵ����� 
int j: �������ڵ����
pNode: �½��������ĸ��ڵ�ָ�� 
*/
pNode CreateBinaryTree(const INTVEC& vec, int i, int j)
{
	if(i >= j) return(NULL);
	pNode p = new Node;
	p->value = vec[i];
	//std::cout << p->value << std::endl;
	p->left = CreateBinaryTree(vec, 2 * i + 1, j);
	p->right = CreateBinaryTree(vec, 2 * i + 2, j);

	return p;
}

static std::map<int, INTVEC> m_tmp;

void printBinaryTree(pNode p, int layer)
{
	
	if(p == NULL) return;

	printBinaryTree(p->right, ++layer);

	for(int i = 0; i < layer; ++i)
	{
		//std::cout << " ";
	}
	m_tmp[layer].push_back(p->value);
	/*
	std::cout << "layer:" << layer << " value:" << p->value << std::endl;
	if(p->left)
		std::cout << "  layer:" << layer + 1 << " left value:" << p->left->value << std::endl;
	if(p->right)
		std::cout << "  layer:" << layer + 1 << " right value:" << p->right->value << std::endl;
	*/
	printBinaryTree(p->left, ++layer);
}

#endif