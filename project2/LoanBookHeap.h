#ifndef _LOANBOOKHEAP_H_
#define _LOANBOOKHEAP_H_
#include "LoanBookData.h"
#include "LoanBookHeapNode.h"
#include <vector>
#include <algorithm>

using namespace std;

class LoanBookHeap
{
private:
    LoanBookHeapNode* root;
    vector <LoanBookHeapNode *> v;

    //bool compare(LoanBookHeapNode* a, LoanBookHeapNode* b);

public:
    LoanBookHeap() {
        this->root = NULL;
        this->v.push_back(NULL);
    };
    ~LoanBookHeap() {
		for (int i = 1; i < v.size(); i++)
        {
            if (v.at(i))
                delete v.at(i);
        }
    }
    
    void setRoot(LoanBookHeapNode* pN) { this->root = pN; }
    LoanBookHeapNode* getRoot() { return root; }

    vector <LoanBookHeapNode *> *sortV();

    void heapifyUp(LoanBookHeapNode* pN);
    void heapifyDown(LoanBookHeapNode* pN);
    
    bool Insert(LoanBookData* data);
};

#endif