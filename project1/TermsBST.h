#pragma once
#include "TermsBSTNode.h"
#include <fstream>
#include <cstring>

class TermsBST
{
private:
	TermsBSTNode* root;
	void	post_destructor(TermsBSTNode* node); // post-order delete
	void	post_delete(TermsBSTNode* p, TermsBSTNode* pp, std::string name, int &num); // post-order delete
	void	in_print(TermsBSTNode* node, std::ofstream &fout); // in-order

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot(); // return root node

	void	insert(TermsBSTNode* node); // insert node
	void	print(std::ofstream &fout); // in-order print
	bool	default_delete(std::string date); // date delete
	void	name_delete(std::string name, int &num); // name delete
};