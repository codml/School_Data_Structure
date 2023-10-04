#pragma once
#include "TermsListNode.h"

class TermsLIST
{
private:
	TermsListNode* head;


public:
	TermsLIST();
	~TermsLIST();

	void			setHead(TermsListNode* node);
	TermsListNode*	getHead();

	void	insert(TermsListNode *node);
	TermsListNode*	search(char type);
	void	Delete(TermsListNode *node);
};
