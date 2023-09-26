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
	NameBSTNode(std::string &n, int a, std::string &i, std::string &e, char t): name(n), age(a),
		infor_date(i), ex_date(e), type(t) {left = right = 0;}
	~NameBSTNode() {}

	NameBSTNode*	getLeft()			{ return left; }
	NameBSTNode*	getRight()			{ return right; }

	void setLeft(NameBSTNode* left)						{ this->left = left; }
	void setRight(NameBSTNode* right)					{ this->right = right; }

	std::string		getName() { return name; }
	int				getAge() { return age; }
	std::string		getInfor_date() { return infor_date; }
	std::string		getEx_date() { return ex_date; }
	char			getType() { return type; }
};