#pragma once
#include <string>

class NameBSTNode
{
private:
	std::string		name;
	int				age;
	std::string		infor_date;
	std::string		ex_date;
	char			type;
	NameBSTNode*	left;
	NameBSTNode*	right;
	

public:
	NameBSTNode(std::string const &n, int a, std::string const &i, std::string const &e, char t): name(n), age(a),
		infor_date(i), ex_date(e), type(t) {left = right = 0;} // constructor
	~NameBSTNode() {} // destructor: none

	NameBSTNode*	getLeft()			{ return left; }
	NameBSTNode*	getRight()			{ return right; }

	void setLeft(NameBSTNode* left)						{ this->left = left; }
	void setRight(NameBSTNode* right)					{ this->right = right; }

	void	setName(std::string const &n) { name = n; }
	void	setAge(int a) { age = a; }
	void	setInfor_date(std::string const &i) { infor_date = i; }
	void	setEx_date(std::string const &e) { ex_date = e; }
	void	setType(char t) { type = t; }

	std::string&	getName() { return name; }
	int				getAge() { return age; }
	std::string&	getInfor_date() { return infor_date; }
	std::string&	getEx_date() { return ex_date; }
	char			getType() { return type; } // getter & setter
};