#pragma once
#include "TermsListNode.h"

class TermsLIST
{
private:
	TermsListNode* head;


public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();

	void	insert(TermsListNode *node);
	TermsListNode*	search(char type);
	void	nDelete(TermsListNode *node);
};
