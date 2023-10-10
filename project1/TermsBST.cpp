#include "TermsBST.h"

void	TermsBST::post_destructor(TermsBSTNode* node)
{
	if (node)
	{
		post_destructor(node->getLeft());
		post_destructor(node->getRight());
		delete node;
	}
} // post order: visit child nodes first and visit parent 

void	TermsBST::post_delete(TermsBSTNode* p, TermsBSTNode* pp, std::string name, int &num)
{
	TermsBSTNode *ppv, *pv, *cur;

	if (p) // post order: visit child nodes first and visit parent 
	{
		post_delete(p->getLeft(), p, name, num);
		post_delete(p->getRight(), p, name, num);
		if (p->getName().compare(name) == 0) // if node needs to delete
		{
			num++; // count nodes that be deleted
			if (p->getLeft() == 0 && p->getRight() == 0) // if node is leaf
			{
				if (pp == 0)
					root = 0;
				else if (pp->getLeft() == p)
					pp->setLeft(0);
				else
					pp->setRight(0);
				delete p;
			}
			else if (p->getLeft() == 0) // if node has only right child
			{
				if (pp == 0)
					root = p->getRight();
				else if (pp->getLeft() == p)
					pp->setLeft(p->getRight());
				else
					pp->setRight(p->getRight());
				delete p;
			}
			else if (p->getRight() == 0) // if node has only left child
			{
				if (pp == 0)
					root = p->getLeft();
				else if (pp->getLeft() == p)
					pp->setLeft(p->getLeft());
				else
					pp->setRight(p->getLeft());
				delete p;
			}
			else // if node has two child
			{
				ppv = p;
				pv = p->getRight();
				cur = p->getRight()->getLeft();
				while (cur) // pv node will have the earliest ex_date in p's right subtree 
				{
					ppv = pv;
					pv = cur;
					cur = cur->getLeft();
				} // pv node will replace informations with p(need to delete) node
				p->setName(pv->getName());
				p->setAge(pv->getAge());
				p->setInfor_date(pv->getInfor_date());
				p->setEx_date(pv->getEx_date());
				if (ppv == p)
					ppv->setRight(pv->getRight());
				else
					ppv->setLeft(pv->getRight());
				delete pv;
			}
		}
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
	} // in-order: visit left child -> parent -> right child
}

TermsBST::TermsBST() : root(nullptr) // initiate root variable
{

}

TermsBST::~TermsBST()
{
	post_destructor(root);// post-order delete node from root -> delete all nodes in tree
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
	while (p) // search the place into which insert node
	{
		pp = p;
		if (p->getEx_date().compare(node->getEx_date()) > 0)
			p = p->getLeft();
		else
			p = p->getRight();
	}
	if (root) // if root exists
	{
		if (pp->getEx_date().compare(node->getEx_date()) > 0)
			pp->setLeft(node);
		else
			pp->setRight(node);
	}
	else // root is null
		root = node;
}

void	TermsBST::print(std::ofstream &fout)
{
	in_print(root, fout); // in-order print from root
}

bool	TermsBST::default_delete(std::string date) // just delete one node
{
	TermsBSTNode *p, *pp;
	TermsBSTNode *ppv, *pv, *cur;

	p = root;
	pp = 0;
	while (p && p->getEx_date().compare(date) >= 0)
	{
		pp = p;
		p = p->getLeft();
	} // search node to delete
	if (p == 0) // there is no node to delete
		return false;
	if (p->getLeft() == 0 && p->getRight() == 0) // if node is leaf
	{
		if (pp == 0)
			root = 0;
		else if (pp->getLeft() == p)
			pp->setLeft(0);
		else
			pp->setRight(0);
		delete p;
	}
	else if (p->getLeft() == 0) // if node has only right child
	{
		if (pp == 0)
			root = p->getRight();
		else if (pp->getLeft() == p)
			pp->setLeft(p->getRight());
		else
			pp->setRight(p->getRight());
		delete p;
	}
	else if (p->getRight() == 0) // if node has only left child
	{
		if (pp == 0)
			root = p->getLeft();
		else if (pp->getLeft() == p)
			pp->setLeft(p->getLeft());
		else
			pp->setRight(p->getLeft());
		delete p;
	}
	else // if node has two child
	{
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
	}
	return true;
}

void	TermsBST::name_delete(std::string name, int &num)
{
	post_delete(root, 0, name, num); // search from root and delete
}