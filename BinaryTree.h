#ifndef __BINARYTREE_LSX_
#define __BINARYTREE_LSX_

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



#endif