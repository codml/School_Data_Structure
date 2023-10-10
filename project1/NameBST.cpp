#include "NameBST.h"

void	NameBST::post_destructor(NameBSTNode* node)
{
	if (node)
	{
		post_destructor(node->getLeft());
		post_destructor(node->getRight());
		delete node;
	} // post order: visit child nodes first and visit parent 
}

void	NameBST::post_delete(NameBSTNode* p, NameBSTNode* pp, std::string date)
{
	NameBSTNode *ppv, *pv, *cur;

	if (p) // post order: visit child nodes first and visit parent 
	{
		post_delete(p->getLeft(), p, date);
		post_delete(p->getRight(), p, date);
		if (p->getEx_date().compare(date) < 0) // if node needs to delete
		{
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
				p->setType(pv->getType());
				if (ppv == p)
					ppv->setRight(pv->getRight());
				else
					ppv->setLeft(pv->getRight());
				delete pv;
			}
		}
		
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
	} // in-order print
}

NameBST::NameBST() : root(nullptr) // initiate root variable
{

}

NameBST::~NameBST()
{
	post_destructor(root); // post-order delete node from root -> delete all nodes in tree
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
	while (p) // search the place into which insert node
	{
		pp = p;
		if (p->getName().compare(node->getName()) > 0)
			p = p->getLeft();
		else
			p = p->getRight();
	}
	if (root) // if root exists
	{
		if (pp->getName().compare(node->getName()) > 0)
			pp->setLeft(node);
		else
			pp->setRight(node);
	}
	else // root is null
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
		else // if p->getName() == name
			break;
	}
	return p; // if fail to find, return null
}

void			NameBST::print(std::ofstream &fout)
{
	in_print(root, fout); // print from root
}

bool	NameBST::default_delete(std::string name)
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
	if (p == 0) // if node that has the name doesn't exists
		return false; // return false
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
		p->setType(pv->getType());
		if (ppv == p)
			ppv->setRight(pv->getRight());
		else
			ppv->setLeft(pv->getRight());
		delete pv;
	}
	return true;
}

void	NameBST::date_delete(std::string date)
{
	post_delete(root, 0, date); // search from root and delete nodes
}