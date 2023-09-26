#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr)
{

}
TermsLIST::~TermsLIST()
{
	TermsListNode *now, *tmp;

	now = head;
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
	while (now)
	{
		prev = now;
		now = now->getNext();
	}
	if (!head)
		head = node;
	else
		prev->setNext(node);
}

TermsListNode*	TermsLIST::search(char type)
{
	TermsListNode *now;

	now = head;
	while (now && now->getType() != type)
		now = now->getNext();
	return now;
}

void	TermsLIST::nDelete(TermsListNode *node)
{
	TermsListNode *now, *prev;

	now = head;
	prev = 0;
	while (now && now != node)
	{
		prev = now;
		now = now->getNext();
	}
	if (!now)
		return ;
	prev->setNext(now->getNext());
	delete now;
}
