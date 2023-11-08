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
    void Setting();
    void reSort(SelectionTreeNode* node);

public:
    SelectionTree(ofstream* fout) {
        this->root = NULL;
        this->fout = fout;
        this->v.push_back(NULL);
        Setting();
    }
    ~SelectionTree() {
		for (int i = 1; i < v.size(); i++)
        {
            if (v.at(i))
                delete v.at(i);
        }
    }

    void setRoot(SelectionTreeNode* pN) { this->root = pN; }
    SelectionTreeNode* getRoot() { return root; }

    bool Insert(LoanBookData* newData);
    bool Delete();
    bool printBookData(int bookCode);
};

#endif