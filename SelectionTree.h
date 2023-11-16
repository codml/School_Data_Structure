#ifndef _SELECTIONTREE_H_
#define _SELECTIONTREE_H_
#include "SelectionTreeNode.h"

#include <fstream>
#include <iostream>
#include <map>
#include <utility> // for pair

using namespace std;

class SelectionTree
{
private:
    SelectionTreeNode* root;
    ofstream* fout;

    void Setting(); // init selection tree
    SelectionTreeNode* returnIdx(int code); // get address of run
    void reSort(SelectionTreeNode* node);
    void PreorderHeap(LoanBookHeapNode* node, map <string, LoanBookData *> &heap)
    {
        if (node)
        {
            heap.insert(map<string, LoanBookData*>::value_type(node->getBookData()->getName(), node->getBookData()));
            PreorderHeap(node->getLeftChild(), heap);
            PreorderHeap(node->getRightChild(), heap);
        }
    } // preorder travesal to copy heap
    void    PostorderDelete(SelectionTreeNode *node)
    {
        if (node)
        {
            PostorderDelete(node->getLeftChild());
            PostorderDelete(node->getRightChild());
            delete node;
        }
    } // for destructor

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

    bool Insert(LoanBookData* newData); // insert data into heap and selection tree
    bool Delete(); // delete winner
    bool printBookData(int bookCode);
};

#endif