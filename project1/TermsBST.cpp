#include "TermsBST.h"

void	TermsBST::post_destructor(TermsBSTNode* node)
{
	if (node)
	{
		post_destructor(node->getLeft());
		post_destructor(node->getRight());
		delete node;
	}
}

void	TermsBST::in_print(TermsBSTNode* node, std::ofstream &fout)
{
	if (node)
	{
		in_print(node->getLeft(), fout);
		fout << node->getName() << "/" << node->getAge() << "/"
			<< node->getInfor_date() << "/" << node->getEx_date() << std::endl;
		in_print(node->getRight(), fout);
	}
}

TermsBST::TermsBST() : root(nullptr)
{

}

TermsBST::~TermsBST()
{
	post_destructor(root);
}

TermsBSTNode* TermsBST::getRoot()
{
	return root;
}


void	TermsBST::insert(TermsBSTNode* node)
{
	TermsBSTNode *p, *pp;

	p = root;
	pp = 0;
	while (p)
	{
		pp = p;
		if (p->getEx_date().compare(node->getEx_date()) > 0)
			p = p->getLeft();
		else
			p = p->getRight();
	}
	if (root)
	{
		if (pp->getEx_date().compare(node->getEx_date()) > 0)
			pp->setLeft(node);
		else
			pp->setRight(node);
	}
	else
		root = node;
}

void	TermsBST::print(std::ofstream &fout)
{
	in_print(root, fout);
}

bool	TermsBST::default_delete(std::string date)
{
	TermsBSTNode *p, *pp;
	TermsBSTNode *ppv, *pv, *cur;

	p = root;
	pp = 0;
	while (p && p->getEx_date().compare(date) >= 0)
	{
		pp = p;
		p = p->getLeft();
	}
	if (p == 0)
		return false;
	if (p->getLeft() == 0 && p->getRight() == 0)
	{
		if (pp == 0)
			root = 0;
		else if (pp->getLeft() == p)
			pp->setLeft(0);
		else
			pp->setRight(0);
		delete p;
		return true;
	}
	if (p->getLeft() == 0)
	{
		if (pp == 0)
			root = p->getRight();
		else if (pp->getLeft() == p)
			pp->setLeft(p->getRight());
		else
			pp->setRight(p->getRight());
		delete p;
		return true;
	}
	if (p->getRight() == 0)
	{
		if (pp == 0)
			root = p->getLeft();
		else if (pp->getLeft() == p)
			pp->setLeft(p->getLeft());
		else
			pp->setRight(p->getLeft());
		delete p;
		return true;
	}
	ppv = p;
	pv = p->getRight();
	cur = p->getRight()->getLeft();
	while (cur)
	{
		ppv = pv;
		pv = cur;
		cur = cur->getLeft();
	}
	p->setName(pv->getName());
	p->setAge(pv->getAge());
	p->setInfor_date(pv->getInfor_date());
	p->setEx_date(pv->getEx_date());
	if (ppv == p)
		ppv->setRight(pv->getRight());
	else
		ppv->setLeft(pv->getRight());
	delete pv;
	return true;
}

bool	name_delete(std::string name)
{

}