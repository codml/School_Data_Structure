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
	TermsBSTNode(std::string const &n, int a, std::string const &i, std::string const &e): name(n), age(a),
		infor_date(i), ex_date(e) {left = right = 0;}
	~TermsBSTNode() {}

	TermsBSTNode*	getLeft()			{ return left; }
	TermsBSTNode*	getRight()			{ return right; }

	void setLeft (TermsBSTNode* left)	{ this->left = left; }
	void setRight(TermsBSTNode* right)	{ this->right = right; }

	void	setName(std::string const &n) { name = n; }
	void	setAge(int a) { age = a; }
	void	setInfor_date(std::string const &i) { infor_date = i; }
	void	setEx_date(std::string const &e) { ex_date = e; }

	std::string		&getName() { return name; }
	int				getAge() { return age; }
	std::string		&getInfor_date() { return infor_date; }
	std::string		&getEx_date() { return ex_date; }
};