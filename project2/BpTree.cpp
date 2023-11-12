#include "BpTree.h"

bool BpTree::Insert(LoanBookData* newData) {
	BpTreeNode *ptr, *next;
	string		name;
	int			code, loan_count;

	if (root == NULL)
	{
		root = new BpTreeDataNode;
		root->insertDataMap(newData->getName(), newData);
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
	if (ptr->getDataMap()->find(newData->getName()) != ptr->getDataMap()->end())
	{
		name = newData->getName();
		code = newData->getCode() / 100;
		ptr->getDataMap()->find(newData->getName())->second->updateCount();
		delete newData;
		loan_count = ptr->getDataMap()->find(name)->second->getLoanCount();
		if (loan_count == 3 + ((code % 5) / 3) - (code / 5))
			return false; // it's not fail of insert, time to toss node to Selection tree
		return true;
	}
	ptr->insertDataMap(newData->getName(), newData);
	if (excessDataNode(ptr))
	{
		splitDataNode(ptr);
		ptr = ptr->getParent();
		while (excessIndexNode(ptr))
		{
			splitIndexNode(ptr);
			ptr = ptr->getParent();
		}
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
	if (!pDataNode->getParent())
	{
		BpTreeNode *parent = new BpTreeIndexNode;
		parent->setMostLeftChild(pDataNode);
		pDataNode->setParent(parent);
		root = parent;
	}
	third->setParent(pDataNode->getParent());
	pDataNode->getParent()->insertIndexMap(mid->first, third);

	if (pDataNode->getNext())
	{
		pDataNode->getNext()->setPrev(third);
		third->setNext(pDataNode->getNext());
	}
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
	if (!pIndexNode->getParent())
	{
		BpTreeNode *parent = new BpTreeIndexNode;
		parent->setMostLeftChild(pIndexNode);
		pIndexNode->setParent(parent);
		root = parent; // think twice...
	}
	pIndexNode->getParent()->insertIndexMap(mid->first, third);
	third->setParent(pIndexNode->getParent());
	
	pIndexNode->deleteMap(mid->first);
	pIndexNode->deleteMap(end->first);
}

BpTreeNode* BpTree::searchDataNode(string name) {
	BpTreeNode* pCur = root;
	BpTreeNode* next;

	if (root == NULL)
		return NULL;
	for (pCur = root; pCur->getMostLeftChild(); pCur = next)
	{
		if (pCur->getIndexMap()->begin()->first > name)
			next = pCur->getMostLeftChild();
		else if (pCur->getIndexMap()->rbegin()->first <= name)
			next = pCur->getIndexMap()->rbegin()->second;
		else
			next = pCur->getIndexMap()->begin()->second;
	}
	if (pCur->getDataMap()->find(name) != pCur->getDataMap()->end())
		return pCur;
	else
		return NULL;
}

bool BpTree::searchBook(string name) {
	BpTreeNode* pCur = root;
	BpTreeNode* next;

	if (root == NULL)
		return false;
	for (pCur = root; pCur->getMostLeftChild(); pCur = next)
	{
		if (pCur->getIndexMap()->begin()->first > name)
			next = pCur->getMostLeftChild();
		else if (pCur->getIndexMap()->rbegin()->first <= name)
			next = pCur->getIndexMap()->rbegin()->second;
		else
			next = pCur->getIndexMap()->begin()->second;
	}
	if (pCur->getDataMap()->find(name) != pCur->getDataMap()->end())
	{
		*fout << "========SEARCH_BP========" << endl;
		*fout << pCur->getDataMap()->find(name)->second->getName() << "/"
			<< pCur->getDataMap()->find(name)->second->getCode() << "/"
			<< pCur->getDataMap()->find(name)->second->getAuthor() << "/"
			<< pCur->getDataMap()->find(name)->second->getYear() << "/"
			<< pCur->getDataMap()->find(name)->second->getLoanCount() << endl;
		*fout << "========================" << endl;
		return true;
	}
	else
		return false;
}

bool BpTree::searchRange(string start, string end) {
	BpTreeNode* pCur = root;
	BpTreeNode* next;
	bool flagS = false;
	bool flag = false;

	if (root == NULL)
		return false;
	for (pCur = root; pCur->getMostLeftChild(); pCur = next)
	{
		if (pCur->getIndexMap()->begin()->first > start)
			next = pCur->getMostLeftChild();
		else if (pCur->getIndexMap()->rbegin()->first <= start)
			next = pCur->getIndexMap()->rbegin()->second;
		else
			next = pCur->getIndexMap()->begin()->second;
	}
	auto itr = pCur->getDataMap()->begin();
	while (pCur && itr->first <= end)
	{
		if (itr->first >= start)
		{
			if (!flagS)
			{
				*fout << "========SEARCH_BP========" << endl;
				flagS = true;
			}	
			*fout << itr->second->getName() << "/"
			<< itr->second->getCode() << "/"
			<< itr->second->getAuthor() << "/"
			<< itr->second->getYear() << "/"
			<< itr->second->getLoanCount() << endl;
			if (!flag)
				flag = true;
		}
		itr++;
		if (itr == pCur->getDataMap()->end())
		{
			pCur = pCur->getNext();
			if (!pCur)
				break;
			itr = pCur->getDataMap()->begin();
		}
	}
	if (flag)
		*fout << "========================" << endl;
	return flag;
}
