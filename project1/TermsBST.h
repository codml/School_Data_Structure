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
	bool	default_delete(std::string date);
	bool	name_delete(std::string name);
};