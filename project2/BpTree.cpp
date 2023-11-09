#include "BpTree.h"

bool BpTree::Insert(LoanBookData* newData) {

	return true;
}

bool BpTree::excessDataNode(BpTreeNode* pDataNode) {
	if (pDataNode->getDataMap()->size() > order - 1) return true;//order is equal to the number of elements 
	else return false;
}

bool BpTree::excessIndexNode(BpTreeNode* pIndexNode) {
	if (pIndexNode->getIndexMap()->size() > order - 1)return true;//order is equal to the number of elements 
	else return false;
}

void BpTree::splitDataNode(BpTreeNode* pDataNode) {
	
}

void BpTree::splitIndexNode(BpTreeNode* pIndexNode) {
	auto begin = pIndexNode->getIndexMap()->begin();
	auto mid = ++(pIndexNode->getIndexMap()->begin());
	auto end = pIndexNode->getIndexMap()->end();

	BpTreeNode *third = new BpTreeIndexNode;
	third->setMostLeftChild(mid->second);
	third->insertIndexMap(end->first, end->second);
	third->setParent(pIndexNode->getParent());
	if (pIndexNode->getParent())
		pIndexNode->getParent()->insertIndexMap(mid->first, third);
	else
	{
		BpTreeNode *parent = new BpTreeIndexNode;
		parent->setMostLeftChild(pIndexNode);
		parent->insertIndexMap(mid->first, third); // need to fix
	}
	third->setParent(pIndexNode->getParent());
}

BpTreeNode* BpTree::searchDataNode(string name) {
	BpTreeNode* pCur = root;
	
	return pCur;
}

bool BpTree::searchBook(string name) {

}

bool BpTree::searchRange(string start, string end) {
	
}
