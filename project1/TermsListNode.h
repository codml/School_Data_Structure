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
	TermsListNode(char t): type(t), num(0), bst(new TermsBST), next(0) {} // constructor
	~TermsListNode() { delete bst; } // destructor: none

	char			getType() { return type; }
	int				getNum() { return num; }
	TermsBST*		getBST() { return bst; }
	TermsListNode*	getNext()		 { return next; } // getter

	void increaseNum() { num++; }
	void decreaseNum() { num--; } // change num variable
	void setNext(TermsListNode* next)	 { this->next = next; } // setter
};