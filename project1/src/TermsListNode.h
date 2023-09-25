#pragma once
#include "TermsBSTNode.h"

class TermsListNode
{
private:
	char			type;
	int				num;
	TermsBSTNode	*root;
	TermsListNode	*next;


public:
	TermsListNode(): num(0), root(0), next(0) {}
	~TermsListNode() {}

	char			getType() { return type; }
	int				getNum() { return num; }
	TermsBSTNode*	getRoot() { return root; }
	TermsListNode*	getNext()		 { return next; }

	void setType(char t) { type = t; }
	void setNum(int n) { num = n; }
	void setRoot(TermsBSTNode* r) { root = r;}
	void setNext(TermsListNode* next)	 { this->next = next; }
};