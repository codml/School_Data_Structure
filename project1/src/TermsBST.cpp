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

void	TermsBST::nDelete(TermsBSTNode* node)
{
	
}
