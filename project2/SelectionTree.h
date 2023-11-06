#ifndef _SELECTIONTREE_H_
#define _SELECTIONTREE_H_
#include "SelectionTreeNode.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class SelectionTree
{
private:
    SelectionTreeNode* root;
    ofstream* fout;
    vector <SelectionTreeNode *> v;

public:
    SelectionTree(ofstream* fout) {
        this->root = NULL;
        this->fout = fout;
        this->v.push_back(NULL);
    }
    ~SelectionTree() {

    }

    void setRoot(SelectionTreeNode* pN) { this->root = pN; }
    SelectionTreeNode* getRoot() { return root; }

    bool Setting();

    bool Insert(LoanBookData* newData);
    bool Delete();
    bool printBookData(int bookCode);
};

#endif