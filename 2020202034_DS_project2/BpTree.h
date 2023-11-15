#ifndef _BpTree_H_
#define _BpTree_H_

#include "BpTreeDataNode.h"
#include "BpTreeIndexNode.h"
#include "LoanBookData.h"
#include <fstream>
#include <iostream>

using namespace std;

class BpTree {
private:
	BpTreeNode* root;
	int			order;		// m children
	ofstream* fout;

	void    PostorderDelete(BpTreeNode *node) // recursive delete function for destructor
    {
        if (node)
        {
            PostorderDelete(node->getMostLeftChild());
			if (node->getMostLeftChild()) // recursive in index node
			{
				for (auto itr = node->getIndexMap()->begin(); itr != node->getIndexMap()->end(); itr++)
					PostorderDelete(itr->second);
			}
            delete node;
        }
    }

public:
	BpTree(ofstream *fout, int order = 3) {
		root = NULL;
		this->order = order;
		this->fout = fout;
	}
	~BpTree()
	{
		PostorderDelete(root);
	}
	bool		Insert(LoanBookData* newData); // insert data
	bool		excessDataNode(BpTreeNode* pDataNode);
	bool		excessIndexNode(BpTreeNode* pIndexNode); // judge function
	void		splitDataNode(BpTreeNode* pDataNode);
	void		splitIndexNode(BpTreeNode* pIndexNode); // split function
	BpTreeNode* getRoot() { return root; }
	BpTreeNode* searchDataNode(string name);

	bool searchBook(string name);
	bool searchRange(string start, string end);

};

#endif
