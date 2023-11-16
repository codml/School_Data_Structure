#include "LoanBookHeap.h"

void LoanBookHeap::heapifyUp(LoanBookHeapNode* pN) {
    LoanBookData	*tmp;
    
    if (pN == root || pN->getBookData()->getName() > pN->getParent()->getBookData()->getName())
        return; // stop heapify up
    tmp = pN->getBookData();
    pN->setBookData(pN->getParent()->getBookData());
    pN->getParent()->setBookData(tmp); // swap data between pN, pN's parent
    heapifyUp(pN->getParent()); // recursive
}

void LoanBookHeap::heapifyDown(LoanBookHeapNode* pN) {
    LoanBookData                *tmp;
	LoanBookHeapNode            *left, *right, *child;
    LoanBookHeapNode            *last, *parent;
    queue<LoanBookHeapNode *>   q;

    if (pN == root) // if start of heapify down(it always from root)
    {
        if (root->getLeftChild() == NULL && root->getRightChild() == NULL) // just one node in heap
        {
            delete root;
            root = 0;
            return;
        }
        last = root;
        while (last) // search the last node by level order travesal
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
        last->setBookData(tmp); // swap data
        if (last->getParent()->getRightChild())
            last->getParent()->setRightChild(NULL);
        else
            last->getParent()->setLeftChild(NULL);
        delete last; // delete last node
    }
	left = pN->getLeftChild();
	right = pN->getRightChild();
	if (left == NULL)
		return;
	if (right && left->getBookData()->getName() > right->getBookData()->getName())
		child = right;
	else
		child = left; // select child node
	if (child->getBookData()->getName() > pN->getBookData()->getName()) // stop heapify down
		return;
	tmp = pN->getBookData();
	pN->setBookData(child->getBookData());
	child->setBookData(tmp); // swap data between pN, pN's child
	heapifyDown(child); // recursive
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
    while (p.second) // find last node's place by level order travesal
    {
        q.push(make_pair(p.second, p.second->getLeftChild()));
        q.push(make_pair(p.second, p.second->getRightChild()));
        p = q.front();
        q.pop();
    } // p.second is the place where to insert node, p.first is it's parent
    if (p.first->getLeftChild())
        p.first->setRightChild(node);
    else
        p.first->setLeftChild(node);
    node->setParent(p.first);
    heapifyUp(node);
    return true;
}
