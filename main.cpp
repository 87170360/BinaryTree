#include <iostream>
#include <stddef.h>
#include "readfile.h"
#include "BinaryTree.h"


int main()
{
	std::vector<int> conf = parseInputFile();
	for(std::vector<int>::const_iterator iter = conf.begin(); iter != conf.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "Hello, BinaryTree!" << std::endl;
	return 0; 
}