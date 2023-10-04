#include "NameBST.h"

void	NameBST::post_destructor(NameBSTNode* node)
{
	if (node)
	{
		post_destructor(node->getLeft());
		post_destructor(node->getRight());
		delete node;
	}
}

void	NameBST::in_print(NameBSTNode* node, std::ofstream &fout)
{
	if (node)
	{
		in_print(node->getLeft(), fout);
		fout << node->getName() << "/" << node->getAge() << "/"
			<< node->getInfor_date() << "/" << node->getEx_date() << std::endl;
		in_print(node->getRight(), fout);
	}
}

NameBST::NameBST() : root(nullptr)
{

}

NameBST::~NameBST()
{
	post_destructor(root);
}

NameBSTNode* NameBST::getRoot()
{
	return root;
}

void			NameBST::insert(NameBSTNode* node)
{
	NameBSTNode *p, *pp;

	p = root;
	pp = 0;
	while (p)
	{
		pp = p;
		if (p->getName().compare(node->getName()) > 0)
			p = p->getLeft();
		else
			p = p->getRight();
	}
	if (root)
	{
		if (pp->getName().compare(node->getName()) > 0)
			pp->setLeft(node);
		else
			pp->setRight(node);
	}
	else
		root = node;
}

NameBSTNode*	NameBST::search(std::string name)
{
	NameBSTNode *p;

	p = root;
	while (p)
	{
		if (p->getName().compare(name) > 0)
			p = p->getLeft();
		else if (p->getName().compare(name) < 0)
			p = p->getRight();
		else
			break;
	}
	return p;
}

void			NameBST::print(std::ofstream &fout)
{
	in_print(root, fout);
}

bool			NameBST::default_delete(std::string name)
{
	NameBSTNode *p, *pp;
	NameBSTNode *ppv, *pv, *cur;

	p = root;
	pp = 0;
	while (p && p->getName().compare(name) != 0)
	{
		pp = p;
		if (p->getName().compare(name) > 0)
			p = p->getLeft();
		else
			p = p->getRight();
	} // search node to delete
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
	p->setType(pv->getType());
	if (ppv == p)
		ppv->setRight(pv->getRight());
	else
		ppv->setLeft(pv->getRight());
	delete pv;
	return true;
}

bool	NameBST::date_delete(std::string date)
{

}