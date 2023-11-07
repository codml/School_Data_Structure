#include "SelectionTree.h"

bool SelectionTree::Setting() {
    SelectionTreeNode *node;

    if (root != NULL)
        return false;
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
    return true;
}

LoanBookData* SelectionTree::reSort(SelectionTreeNode* node) // need to fix!!!
{
    LoanBookData *left, *right;

    if (node == NULL)
        return NULL;
    left = reSort(node->getLeftChild());
    right = reSort(node->getRightChild());
    if (node->getHeap())
    {
        node->setBookData(node->getHeap()->getRoot()->getBookData());
        return node->getBookData();
    }
    if (!left || !right)
    {
        if (left && right)
        {
            if (left->getName() < right->getName())
                node->setBookData(left);
            else
                node->setBookData(right);
        }
        else if (!right) // only left exists
            node->setBookData(left);
        else    // only right exists
            node->setBookData(right);
    }
    return node->getBookData();
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
    reSort(root);
    // for (int i = 7; i >= 1; i--)
    // {
    //     int j = 2*i;
    //     if (v.at(j)->getBookData() != NULL || v.at(j + 1)->getBookData() != NULL)
    //     {
    //         if (v.at(j)->getBookData() != NULL && v.at(j + 1)->getBookData() != NULL)
    //         {
    //             if (v.at(j)->getBookData()->getName() < v.at(j + 1)->getBookData()->getName())
    //                 v.at(i)->setBookData(v.at(j)->getBookData());
    //             else
    //                 v.at(i)->setBookData(v.at(j + 1)->getBookData());
    //         }
    //         else if (v.at(j)->getBookData() == NULL)
    //             v.at(i)->setBookData(v.at(j + 1)->getBookData());
    //         else
    //             v.at(i)->setBookData(v.at(j)->getBookData());
    //     }
    // }
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
        v.at(idx)->setHeap(NULL);
    }
    reSort(root);
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