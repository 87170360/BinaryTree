#include <iostream>
#include "readfile.h"

#include "readfile.h"
#include "BinaryTree.h"


int main()
{
	INTVEC conf = parseInputFile();
	/*
	for(INTVEC_CITER iter = conf.begin(); iter != conf.end(); ++iter)
	{
	std::cout << *iter << " ";
	}
	std::cout << std::endl;
	*/

	std::cout << "Create BinaryTree!" << std::endl;
	pNode pRoot = CreateBinaryTree(conf, 0, conf.size());

	std::cout << "Print BinaryTree!" << std::endl;
	printBinaryTree(pRoot, 0);
	for(std::map<int, INTVEC>::const_iterator mciter = m_tmp.begin(); mciter != m_tmp.end(); ++mciter)
	{
		for(INTVEC_CITER iter = mciter->second.begin(); iter != mciter->second.end(); ++iter)
		{
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
	}
	return 0; 

}