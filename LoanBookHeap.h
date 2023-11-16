#ifndef _LOANBOOKHEAP_H_
#define _LOANBOOKHEAP_H_
#include "LoanBookData.h"
#include "LoanBookHeapNode.h"
#include <queue>
#include <utility>

using namespace std;

class LoanBookHeap
{
private:
    LoanBookHeapNode* root;
    void    PostorderDelete(LoanBookHeapNode *node) // postorder travesal for destructor
    {
        if (node)
        {
            PostorderDelete(node->getLeftChild());
            PostorderDelete(node->getRightChild());
            delete node;
        }
    }

public:
    LoanBookHeap() {
        this->root = NULL;
    };
    ~LoanBookHeap() {
		PostorderDelete(root);
    }
    
    void setRoot(LoanBookHeapNode* pN) { this->root = pN; }
    LoanBookHeapNode* getRoot() { return root; } // setter, getter

    void heapifyUp(LoanBookHeapNode* pN); // for insert
    void heapifyDown(LoanBookHeapNode* pN); // for delete
    
    bool Insert(LoanBookData* data);
};

#endif