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
	TermsListNode(): num(0), bst(0), next(0) {}
	~TermsListNode() { if (bst) delete bst; }

	char			getType() { return type; }
	int				getNum() { return num; }
	TermsBST*		getBST() { return bst; }
	TermsListNode*	getNext()		 { return next; }

	void setType(char t) { type = t; }
	void setNum(int n) { num = n; }
	void setBST() { bst = new TermsBST;}
	void setNext(TermsListNode* next)	 { this->next = next; }
};