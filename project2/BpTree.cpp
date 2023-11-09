#include "BpTree.h"

bool BpTree::Insert(LoanBookData* newData) {
	BpTreeNode *ptr, *next;

	if (root == NULL)
	{
		root = new BpTreeIndexNode;
		BpTreeNode *data = new BpTreeDataNode;
		data->setParent(root);
		data->insertDataMap(newData->getName(), newData);
		root->insertIndexMap(newData->getName(), data);
		return true;
	}
	for (ptr = root; ptr->getMostLeftChild(); ptr = next)
	{
		if (ptr->getIndexMap()->begin()->first > newData->getName())
			next = ptr->getMostLeftChild();
		else if (ptr->getIndexMap()->rbegin()->first <= newData->getName())
			next = ptr->getIndexMap()->rbegin()->second;
		else
			next = ptr->getIndexMap()->begin()->second;
	}
	ptr->insertDataMap(newData->getName(), newData);
	if (excessDataNode(ptr))
	{
		splitDataNode(ptr);
		ptr = ptr->getParent();
	}
	while (excessIndexNode(ptr))
	{
		splitIndexNode(ptr);
		ptr = ptr->getParent();
	}
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
	auto begin = pDataNode->getDataMap()->begin();
	auto mid = ++(pDataNode->getDataMap()->begin());
	auto end = pDataNode->getDataMap()->rbegin();

	BpTreeNode *third = new BpTreeDataNode;
	third->insertDataMap(mid->first, mid->second);
	third->insertDataMap(end->first, end->second);
	third->setParent(pDataNode->getParent());
	pDataNode->getParent()->insertIndexMap(mid->first, third);

	pDataNode->setNext(third);
	third->setPrev(pDataNode);

	pDataNode->deleteMap(mid->first);
	pDataNode->deleteMap(end->first);
}

void BpTree::splitIndexNode(BpTreeNode* pIndexNode) {
	auto begin = pIndexNode->getIndexMap()->begin();
	auto mid = ++(pIndexNode->getIndexMap()->begin());
	auto end = pIndexNode->getIndexMap()->rbegin();

	BpTreeNode *third = new BpTreeIndexNode;
	third->setMostLeftChild(mid->second);
	mid->second->setParent(third);
	third->insertIndexMap(end->first, end->second);
	end->second->setParent(third);
	if (pIndexNode->getParent())
		pIndexNode->getParent()->insertIndexMap(mid->first, third);
	else
	{
		BpTreeNode *parent = new BpTreeIndexNode;
		parent->setMostLeftChild(pIndexNode);
		pIndexNode->setParent(parent);
		parent->insertIndexMap(mid->first, third);
		root = parent; // think twice...
	}
	third->setParent(pIndexNode->getParent());
	pIndexNode->deleteMap(mid->first);
	pIndexNode->deleteMap(end->first);
}

BpTreeNode* BpTree::searchDataNode(string name) {
	BpTreeNode* pCur = root;
	
	return pCur;
}

bool BpTree::searchBook(string name) {

}

bool BpTree::searchRange(string start, string end) {
	
}
