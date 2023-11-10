#include "LoanBookHeap.h"

void LoanBookHeap::heapifyUp(LoanBookHeapNode* pN) {
    LoanBookData	*tmp;
    
    if (pN == root || pN->getBookData()->getName() > pN->getParent()->getBookData()->getName())
        return;
    tmp = pN->getBookData();
    pN->setBookData(pN->getParent()->getBookData());
    pN->getParent()->setBookData(tmp);
    heapifyUp(pN->getParent());
}

void LoanBookHeap::heapifyDown(LoanBookHeapNode* pN) {
    LoanBookData                *tmp;
	LoanBookHeapNode            *left, *right, *child;
    LoanBookHeapNode            *last, *parent;
    queue<LoanBookHeapNode *>   q;

    if (pN == root)
    {
        if (root->getLeftChild() == NULL && root->getRightChild() == NULL)
        {
            delete root;
            root = 0;
            return;
        }
        last = root;
        while (last)
        {
            q.push(last->getLeftChild());
            q.push(last->getRightChild());
            if (!q.front())
                break;
            last = q.front();
            q.pop();
        }
        tmp = root->getBookData();
        root->setBookData(last->getBookData());
        last->setBookData(tmp);
        if (last->getParent()->getRightChild())
            last->getParent()->setRightChild(NULL);
        else
            last->getParent()->setLeftChild(NULL);
        delete last;
    }
	left = pN->getLeftChild();
	right = pN->getRightChild();
	if (left == NULL)
		return;
	if (right && left->getBookData()->getName() > right->getBookData()->getName())
		child = right;
	else
		child = left;
	if (child->getBookData()->getName() > pN->getBookData()->getName())
		return;
	tmp = pN->getBookData();
	pN->setBookData(child->getBookData());
	child->setBookData(tmp);
	heapifyDown(child);
}

bool LoanBookHeap::Insert(LoanBookData* data) {
    LoanBookHeapNode    *node;
    queue <pair <LoanBookHeapNode *, LoanBookHeapNode * > > q;
    pair <LoanBookHeapNode*, LoanBookHeapNode *> p;

    node = new LoanBookHeapNode;
    node->setBookData(data);
    if (root == NULL)
    {
        root = node;
        return true;
    }
    p = {NULL, root};
    while (p.second)
    {
        q.push(make_pair(p.second, p.second->getLeftChild()));
        q.push(make_pair(p.second, p.second->getRightChild()));
        p = q.front();
        q.pop();
    }
    if (p.first->getLeftChild())
        p.first->setRightChild(node);
    else
        p.first->setLeftChild(node);
    node->setParent(p.first);
    heapifyUp(node);
    return true;
}
