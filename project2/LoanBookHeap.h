#ifndef _LOANBOOKHEAP_H_
#define _LOANBOOKHEAP_H_
#include "LoanBookData.h"
#include "LoanBookHeapNode.h"
#include <vector>

using namespace std;

class LoanBookHeap
{
private:
    LoanBookHeapNode* root;
    vector <LoanBookHeapNode *> v;

public:
    LoanBookHeap() {
        this->root = NULL;
        this->v.push_back(NULL);
    };
    ~LoanBookHeap() {
        int size;

		size = v.size();
		for (int i = 0; i < size; i++)
			delete v.at(i);
    }
    
    void setRoot(LoanBookHeapNode* pN) { this->root = pN; }
    LoanBookHeapNode* getRoot() { return root; }

    void heapifyUp(LoanBookHeapNode* pN);
    void heapifyDown(LoanBookHeapNode* pN);
    
    bool Insert(LoanBookData* data);
};

#endif