#include "SelectionTree.h"

void SelectionTree::Setting() {
    SelectionTreeNode *node;

    node = new SelectionTreeNode;
    root = node;
    v.push_back(node);
    for (int i = 2; i < 16; i++)
    {
        node = new SelectionTreeNode;
        if (v.size() % 2)
            v.at(v.size() / 2)->setRightChild(node);
        else
            v.at(v.size() / 2)->setLeftChild(node);
        node->setParent(v.at(v.size() / 2));
        v.push_back(node);
    }
}

void SelectionTree::reSort(SelectionTreeNode* node) // need to fix!!!
{
    SelectionTreeNode *sib, *cur;

    cur = node;
    while (cur != root)
    {
        if (cur->getParent()->getLeftChild() == cur)
            sib = cur->getParent()->getRightChild();
        else
            sib = cur->getParent()->getLeftChild();
        if (!(cur->getBookData()) && !(sib->getBookData()))
            cur->getParent()->setBookData(NULL);
        else if (cur->getBookData() && sib->getBookData())
        {
            if (cur->getBookData()->getName() < sib->getBookData()->getName())
                cur->getParent()->setBookData(cur->getBookData());
            else
                sib->getParent()->setBookData(sib->getBookData());
        }
        else if (cur->getBookData())
            cur->getParent()->setBookData(cur->getBookData());
        else
            sib->getParent()->setBookData(sib->getBookData());
        cur = cur->getParent();
    }
}

bool SelectionTree::Insert(LoanBookData* newData) {
    int idx;
    LoanBookHeap *tmp;

    idx = (newData->getCode() / 100) + 8;
    if (v.at(idx)->getHeap() == NULL)
    {
        tmp = new LoanBookHeap;
        tmp->Insert(newData);
        v.at(idx)->setHeap(tmp);
    }
    else
        v.at(idx)->getHeap()->Insert(newData);
    v.at(idx)->setBookData(v.at(idx)->getHeap()->getRoot()->getBookData());
    reSort(v.at(idx));
    return true;
}

bool SelectionTree::Delete() {
    int idx;
    
    if (root->getBookData() == NULL)
        return false;
    idx = (root->getBookData()->getCode() / 100) + 8;
    v.at(idx)->getHeap()->heapifyDown(v.at(idx)->getHeap()->getRoot());
    if (v.at(idx)->getHeap()->getRoot() == NULL)
    {
        delete v.at(idx)->getHeap();
        v.at(idx)->setBookData(NULL);
        v.at(idx)->setHeap(NULL);
    }
    else
        v.at(idx)->setBookData(v.at(idx)->getHeap()->getRoot()->getBookData());
    reSort(v.at(idx));
    return true;
}

bool SelectionTree::printBookData(int bookCode) {
    int idx;
    vector <LoanBookHeapNode *> *pv;

    idx = bookCode / 100 + 8;
    if (v.at(idx)->getHeap() == NULL)
        return false;
    pv = v.at(idx)->getHeap()->sortV();
    cout << endl << endl;
    for (int i = 1; i < pv->size(); i++)
    {
        // *fout
        cout << pv->at(i)->getBookData()->getName() << "/" << pv->at(i)->getBookData()->getCode() << "/"
            << pv->at(i)->getBookData()->getAuthor() << "/" << pv->at(i)->getBookData()->getYear() << "/"
            << pv->at(i)->getBookData()->getLoanCount() << endl;
    }
    cout << endl << endl;
    delete pv;
    return true;
}