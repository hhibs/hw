#include <iostream>
#include <fstream>
#include <vector>

#include "BSTree.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: hw5.exe <filename containing integers for BST>" << endl;
		return -1;
	}

	ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		cout << "Error in opening the file. Please check file exists and file name is correct." << endl;
		return -1;
	}

	int num;
        BSTree bst;
	while (inFile >> num)
	{
		bst.insertValue(num);
	}
	inFile.close();

	cout << "Numbers from the file have been read." << endl;
        bst.preOrderPrint();
	return 0;
}
