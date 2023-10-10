#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr) // initiate head to null
{

}

TermsLIST::~TermsLIST() // delete nodes in list
{
	TermsListNode *now, *tmp;

	now = head; // from head, delete all node
	while (now)
	{
		tmp = now;
		now = now->getNext();
		delete tmp;
	}
}

void	TermsLIST::setHead(TermsListNode* node)
{
	head = node;
}

TermsListNode* TermsLIST::getHead()
{
	return head;
}

void	TermsLIST::insert(TermsListNode *node)
{
	TermsListNode *now, *prev;

	now = head;
	prev = 0;
	while (now) // now start from head, reach null next to last node
	{
		prev = now;
		now = now->getNext();
	} // prev will be last node in list
	if (!head) // if head is null
		head = node; // node will be new head
	else
		prev->setNext(node); // insert node next to last node
}

TermsListNode*	TermsLIST::search(char type)
{
	TermsListNode *now;

	now = head;
	while (now && now->getType() != type) // if now is null or find node, break
		now = now->getNext();
	return now; // if failed to find, return null
}

void	TermsLIST::Delete(TermsListNode *node)
{
	TermsListNode *now, *prev;

	now = head;
	prev = 0;
	while (now && now != node) // find node to delete
	{
		prev = now;
		now = now->getNext();
	}
	if (!now) // can't find node to delete
		return ;
	if (!prev) // delete head node
		head = now->getNext();
	else
		prev->setNext(now->getNext());
	delete now;
}
