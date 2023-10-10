#pragma once
#include "TermsListNode.h"

class TermsLIST
{
private:
	TermsListNode* head; // head of list


public:
	TermsLIST();
	~TermsLIST();

	void			setHead(TermsListNode* node); // setter
	TermsListNode*	getHead(); // getter

	void	insert(TermsListNode *node); // insert node
	TermsListNode*	search(char type); // search node and return node's address
	void	Delete(TermsListNode *node); // delete node
};
