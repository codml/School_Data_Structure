#pragma once
#include "NameBSTNode.h"
#include <fstream>

class NameBST
{
private:
	NameBSTNode* root;
	void	post_destructor(NameBSTNode* node); // post-order delete
	void	post_delete(NameBSTNode* p, NameBSTNode* pp, std::string date); // post-order delete
	void	in_print(NameBSTNode* node, std::ofstream &fout); // in-order

public:
	NameBST();
	~NameBST();

	NameBSTNode* 	getRoot(); // return root node

	void			insert(NameBSTNode* node); // insert node
	NameBSTNode*	search(std::string name); // search node
	void			print(std::ofstream &fout); // in-order print
	bool			default_delete(std::string name); // name delete
	void			date_delete(std::string date); // date delete
};