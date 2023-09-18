#pragma once
#include <string>

class TermsBSTNode
{
private:
	std::string		name;
	int				age;
	std::string		infor_date;
	std::string		ex_date;
	TermsBSTNode*	left;
	TermsBSTNode*	right;


public:
	TermsBSTNode(std::string n, int a, std::string i, std::string e): name(n), age(a),
		infor_date(i), ex_date(e) {left = right = 0;}
	~TermsBSTNode() {}

	TermsBSTNode*	getLeft()			{ return left; }
	TermsBSTNode*	getRight()			{ return right; }

	void setLeft (TermsBSTNode* left)	{ this->left = left; }
	void setRight(TermsBSTNode* right)	{ this->right = right; }

	std::string		getEx_date() { return ex_date; }
};