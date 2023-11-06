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
    for (int i = 7; i >= 1; i--)
    {
        int j = 2*i;
        if (v.at(j)->getBookData() != NULL || v.at(j + 1)->getBookData() != NULL)
        {
            if (v.at(j)->getBookData() != NULL && v.at(j + 1)->getBookData() != NULL)
            {
                if (v.at(j)->getBookData()->getName() < v.at(j + 1)->getBookData()->getName())
                    v.at(i)->setBookData(v.at(j)->getBookData());
                else
                    v.at(i)->setBookData(v.at(j + 1)->getBookData());
            }
            else if (v.at(j)->getBookData() == NULL)
                v.at(i)->setBookData(v.at(j + 1)->getBookData());
            else
                v.at(i)->setBookData(v.at(j)->getBookData());
        }
    }
}

bool SelectionTree::Delete() {

}

bool SelectionTree::printBookData(int bookCode) {

}