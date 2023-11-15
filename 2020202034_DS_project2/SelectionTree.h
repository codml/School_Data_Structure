#ifndef _SELECTIONTREE_H_
#define _SELECTIONTREE_H_
#include "SelectionTreeNode.h"

#include <fstream>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

class SelectionTree
{
private:
    SelectionTreeNode* root;
    ofstream* fout;

    void Setting();
    SelectionTreeNode* returnIdx(int code);
    void reSort(SelectionTreeNode* node);
    void PreorderHeap(LoanBookHeapNode* node, map <string, LoanBookData *> &heap)
    {
        if (node)
        {
            heap.insert(map<string, LoanBookData*>::value_type(node->getBookData()->getName(), node->getBookData()));
            PreorderHeap(node->getLeftChild(), heap);
            PreorderHeap(node->getRightChild(), heap);
        }
    }
    void    PostorderDelete(SelectionTreeNode *node)
    {
        if (node)
        {
            PostorderDelete(node->getLeftChild());
            PostorderDelete(node->getRightChild());
            delete node;
        }
    }

public:
    SelectionTree(ofstream* fout) {
        this->root = NULL;
        this->fout = fout;
        Setting();
    }
    ~SelectionTree() {
		PostorderDelete(root);
    }

    void setRoot(SelectionTreeNode* pN) { this->root = pN; }
    SelectionTreeNode* getRoot() { return root; }

    bool Insert(LoanBookData* newData);
    bool Delete();
    bool printBookData(int bookCode);
};

#endif