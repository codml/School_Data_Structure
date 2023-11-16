#include "SelectionTree.h"

void SelectionTree::Setting() { // init setting for selection tree and run(heap)
    SelectionTreeNode *node;
    pair <SelectionTreeNode *, SelectionTreeNode* > p;

    root = new SelectionTreeNode;
    for (int i = 2; i < 16; i++)
    {
        node = new SelectionTreeNode;
        p = {NULL, root};
        queue <pair <SelectionTreeNode*, SelectionTreeNode* > > q;
        while (p.second) // insert node by level order
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
    }
}

SelectionTreeNode* SelectionTree::returnIdx(int code)
{
    switch (code)
    {
    case 0: // heap for code 000
        return root->getLeftChild()->getLeftChild()->getLeftChild();
    case 100: // heap for code 100
        return root->getLeftChild()->getLeftChild()->getRightChild();
    case 200:
        return root->getLeftChild()->getRightChild()->getLeftChild();
    case 300:
        return root->getLeftChild()->getRightChild()->getRightChild();
    case 400:
        return root->getRightChild()->getLeftChild()->getLeftChild();
    case 500:
        return root->getRightChild()->getLeftChild()->getRightChild();
    case 600:
        return root->getRightChild()->getRightChild()->getLeftChild();
    case 700:
        return root->getRightChild()->getRightChild()->getRightChild();
    default:
        return NULL;
    }
}

void SelectionTree::reSort(SelectionTreeNode* node) // start from run(heap)
{
    SelectionTreeNode *sib, *cur;

    cur = node;
    while (cur != root) // until cur == root
    {
        if (cur->getParent()->getLeftChild() == cur)
            sib = cur->getParent()->getRightChild();
        else
            sib = cur->getParent()->getLeftChild(); // choose sibling which is cur's rival
        if (!(cur->getBookData()) && !(sib->getBookData()))
            cur->getParent()->setBookData(NULL); // cur, sib both NULL
        else if (cur->getBookData() && sib->getBookData()) // cur, sib both have data
        {
            if (cur->getBookData()->getName() < sib->getBookData()->getName())
                cur->getParent()->setBookData(cur->getBookData());
            else
                sib->getParent()->setBookData(sib->getBookData());
        }
        else if (cur->getBookData()) // only cur have data
            cur->getParent()->setBookData(cur->getBookData());
        else // only sib have data
            sib->getParent()->setBookData(sib->getBookData());
        cur = cur->getParent();
    }
}

bool SelectionTree::Insert(LoanBookData* newData) {
    LoanBookHeap        *tmp;
    SelectionTreeNode   *idx;

    idx = returnIdx(newData->getCode()); // get address of selection tree's run
    if (idx->getHeap() == NULL) // heap is NULL
    {
        tmp = new LoanBookHeap;
        tmp->Insert(newData);
        idx->setHeap(tmp);
    }
    else
        idx->getHeap()->Insert(newData);
    idx->setBookData(idx->getHeap()->getRoot()->getBookData());
    reSort(idx); // re-order selection tree -> winner may be changed
    return true;
}

bool SelectionTree::Delete() {
    SelectionTreeNode   *idx;
    
    if (root->getBookData() == NULL) // selection tree's run are NULL
        return false;
    idx = returnIdx(root->getBookData()->getCode());
    idx->getHeap()->heapifyDown(idx->getHeap()->getRoot()); // heapify down == delete in heap
    if (idx->getHeap()->getRoot() == NULL) // heap is empty after delete
    {
        delete idx->getHeap();
        idx->setBookData(NULL);
        idx->setHeap(NULL);
    }
    else
        idx->setBookData(idx->getHeap()->getRoot()->getBookData()); // renewal run's root
    reSort(idx); // renewal winner
    return true;
}

bool SelectionTree::printBookData(int bookCode) {
    map <string, LoanBookData *> copyHeap; // copy of original heap
    SelectionTreeNode   *idx;

    idx = returnIdx(bookCode);
    if (idx->getHeap() == NULL)
        return false;
    PreorderHeap(idx->getHeap()->getRoot(), copyHeap); // copy heap by preorder travesal
    *fout << "========PRINT_ST========" << endl; // map will sort heap's data
    for (auto itr = copyHeap.begin(); itr != copyHeap.end(); itr++) // print data
    {
        if (itr->second->getCode())
        {
            *fout << itr->second->getName() << "/" << itr->second->getCode() << "/"
            << itr->second->getAuthor() << "/" << itr->second->getYear() << "/"
            << itr->second->getLoanCount() << endl;
        }
        else
        {
            *fout << itr->second->getName() << "/" << "000" << "/"
            << itr->second->getAuthor() << "/" << itr->second->getYear() << "/"
            << itr->second->getLoanCount() << endl;
        }
    }
    *fout << "========================" << endl << endl;
    return true;
}