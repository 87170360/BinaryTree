#include <iostream>

#include "readfile.h"
#include "BinaryTree.h"


int main()
{
	INTVEC conf = parseInputFile();
	for(INTVEC_CITER iter = conf.begin(); iter != conf.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "Create BinaryTree!" << std::endl;
	pNode pRoot = CreateBinaryTree(conf, 1, conf.size());

	std::cout << "Print BinaryTree!" << std::endl;
	printBinaryTree(pRoot, 0);
	return 0; 
}