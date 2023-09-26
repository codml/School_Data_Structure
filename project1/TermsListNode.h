#pragma once
#include "TermsBST.h"

class TermsListNode
{
private:
	char			type;
	int				num;
	TermsBST		*bst;
	TermsListNode	*next;


public:
	TermsListNode(char t): type(t), num(0), bst(new TermsBST), next(0) {}
	~TermsListNode() { delete bst; }

	char			getType() { return type; }
	int				getNum() { return num; }
	TermsBST*		getBST() { return bst; }
	TermsListNode*	getNext()		 { return next; }

	void setNum(int n) { num = n; }
	void setNext(TermsListNode* next)	 { this->next = next; }
};