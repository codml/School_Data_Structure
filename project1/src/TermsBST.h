#pragma once
#include "TermsBSTNode.h"
#include <fstream>
#include <cstring>

class TermsBST
{
private:
	TermsBSTNode* root;
	void	post_destructor(TermsBSTNode* node);
	void	in_print(TermsBSTNode* node, std::ofstream &fout);

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();

	void	insert(TermsBSTNode* node);
	void	print(std::ofstream &fout);
	void	nDelete(TermsBSTNode* node);
};