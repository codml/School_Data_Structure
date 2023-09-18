#pragma once
#include "TermsBSTNode.h"

class TermsBST
{
private:
	TermsBSTNode* root;

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();

	void	insert(TermsBSTNode* node);
	void	print(ofstream fout);
	void	nDelete(TermsBSTNode* node);
};