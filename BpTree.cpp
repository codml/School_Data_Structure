#include "BpTree.h"

bool BpTree::Insert(LoanBookData* newData) {
	BpTreeNode *ptr, *next;
	string		name;
	int			code;

	if (root == NULL)
	{
		root = new BpTreeDataNode;
		root->insertDataMap(newData->getName(), newData);
		return true;
	} // insert if B+tree is empty
	for (ptr = root; ptr->getMostLeftChild(); ptr = next) // search place where to insert data
	{
		if (ptr->getIndexMap()->begin()->first > newData->getName())
			next = ptr->getMostLeftChild(); // go to A0
		else if (ptr->getIndexMap()->rbegin()->first <= newData->getName())
			next = ptr->getIndexMap()->rbegin()->second; // go to A2
		else
			next = ptr->getIndexMap()->begin()->second; // go to A1
	}
	if (ptr->getDataMap()->find(newData->getName()) != ptr->getDataMap()->end()) // if already exist
	{
		if (ptr->getDataMap()->find(newData->getName())->second == NULL) // already delete
			return false;
		ptr->getDataMap()->find(newData->getName())->second->updateCount(); // update count
		name = newData->getName();
		code = newData->getCode();
		if (ptr->getDataMap()->find(name)->second->getLoanCount()
			== 3 + ((code % 500) / 300) - (code / 500)) // get max loan count per code
		{
			delete ptr->getDataMap()->at(name);
			ptr->getDataMap()->at(name) = NULL;
			return false; // it's not fail of insert, time to toss node to Selection tree
		}
		delete newData;
		return true;
	}
	ptr->insertDataMap(newData->getName(), newData); // insert new data
	if (excessDataNode(ptr)) // exceed b+tree's order
	{
		splitDataNode(ptr); // split
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
	auto mid = ++(pDataNode->getDataMap()->begin()); // to be made index node
	auto end = pDataNode->getDataMap()->rbegin();

	BpTreeNode *third = new BpTreeDataNode;
	third->insertDataMap(mid->first, mid->second);
	third->insertDataMap(end->first, end->second); // split
	if (!pDataNode->getParent()) // there is no index node
	{
		BpTreeNode *parent = new BpTreeIndexNode;
		parent->setMostLeftChild(pDataNode);
		pDataNode->setParent(parent);
		root = parent;
	}
	third->setParent(pDataNode->getParent());
	pDataNode->getParent()->insertIndexMap(mid->first, third); // link
	if (pDataNode->getNext()) // link between data node
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
	auto mid = ++(pIndexNode->getIndexMap()->begin()); // to be made parent index
	auto end = pIndexNode->getIndexMap()->rbegin();

	BpTreeNode *third = new BpTreeIndexNode;
	third->setMostLeftChild(mid->second);
	mid->second->setParent(third);
	third->insertIndexMap(end->first, end->second);
	end->second->setParent(third);
	if (!pIndexNode->getParent()) // if node that is splitted is root
	{
		BpTreeNode *parent = new BpTreeIndexNode; // make new root
		parent->setMostLeftChild(pIndexNode);
		pIndexNode->setParent(parent);
		root = parent;
	}
	pIndexNode->getParent()->insertIndexMap(mid->first, third);
	third->setParent(pIndexNode->getParent()); // link index node
	
	pIndexNode->deleteMap(mid->first);
	pIndexNode->deleteMap(end->first);
}

BpTreeNode* BpTree::searchDataNode(string name) {
	BpTreeNode* pCur = root;
	BpTreeNode* next;

	if (root == NULL)
		return NULL; // if b+tree is empty
	for (pCur = root; pCur->getMostLeftChild(); pCur = next) // search by index until reach data node
	{
		if (pCur->getIndexMap()->begin()->first > name)
			next = pCur->getMostLeftChild();
		else if (pCur->getIndexMap()->rbegin()->first <= name)
			next = pCur->getIndexMap()->rbegin()->second;
		else
			next = pCur->getIndexMap()->begin()->second;
	}
	if (pCur->getDataMap()->find(name) != pCur->getDataMap()->end()) // if exist in data node
		return pCur;
	else
		return NULL;
}

bool BpTree::searchBook(string name) {
	BpTreeNode* pCur = root;
	BpTreeNode* next;

	if (root == NULL)
		return false; // if b+tree is empty
	for (pCur = root; pCur->getMostLeftChild(); pCur = next) // search in index node
	{
		if (pCur->getIndexMap()->begin()->first > name)
			next = pCur->getMostLeftChild();
		else if (pCur->getIndexMap()->rbegin()->first <= name)
			next = pCur->getIndexMap()->rbegin()->second;
		else
			next = pCur->getIndexMap()->begin()->second;
	}
	if (pCur->getDataMap()->find(name) != pCur->getDataMap()->end() // if exist in data node
		&& pCur->getDataMap()->find(name)->second)
	{
		*fout << "========SEARCH_BP========" << endl; // print data
		if (pCur->getDataMap()->at(name)->getCode())
		{
			*fout << pCur->getDataMap()->at(name)->getName() << "/"
			<< pCur->getDataMap()->at(name)->getCode() << "/"
			<< pCur->getDataMap()->at(name)->getAuthor() << "/"
			<< pCur->getDataMap()->at(name)->getYear() << "/"
			<< pCur->getDataMap()->at(name)->getLoanCount() << endl;
		}
		else
		{
			*fout << pCur->getDataMap()->at(name)->getName() << "/"
			<< "000" << "/"
			<< pCur->getDataMap()->at(name)->getAuthor() << "/"
			<< pCur->getDataMap()->at(name)->getYear() << "/"
			<< pCur->getDataMap()->at(name)->getLoanCount() << endl;
		}
		*fout << "========================" << endl << endl;
		return true;
	}
	else
		return false;
}

bool BpTree::searchRange(string start, string end) { // range search
	BpTreeNode* pCur = root;
	BpTreeNode* next;
	bool flagS = false;
	bool flag = false;

	if (root == NULL) // if b+tree is empty
		return false;
	for (pCur = root; pCur->getMostLeftChild(); pCur = next) // search by index until reach data node
	{
		if (pCur->getIndexMap()->begin()->first > start)
			next = pCur->getMostLeftChild();
		else if (pCur->getIndexMap()->rbegin()->first <= start)
			next = pCur->getIndexMap()->rbegin()->second;
		else
			next = pCur->getIndexMap()->begin()->second;
	}
	auto itr = pCur->getDataMap()->begin(); // start point
	while (pCur && itr->first.at(0) <= end.at(0)) // data's name <= end
	{
		if (itr->first.at(0) >= start.at(0) && itr->second) // data's name >= start
		{
			if (!flagS)
			{
				*fout << "========SEARCH_BP========" << endl; // data print
				flagS = true;
			}
			if (itr->second->getCode())
			{
				*fout << itr->second->getName() << "/"
					<< itr->second->getCode() << "/"
					<< itr->second->getAuthor() << "/"
					<< itr->second->getYear() << "/"
					<< itr->second->getLoanCount() << endl;
			}
			else
			{
				*fout << itr->second->getName() << "/"
					<< "000" << "/"
					<< itr->second->getAuthor() << "/"
					<< itr->second->getYear() << "/"
					<< itr->second->getLoanCount() << endl;
			}
			
			if (!flag)
				flag = true;
		}
		itr++;
		if (itr == pCur->getDataMap()->end()) // move to next data node
		{
			pCur = pCur->getNext();
			if (!pCur)
				break;
			itr = pCur->getDataMap()->begin();
		}
	}
	if (flag)
		*fout << "========================" << endl << endl;
	return flag;
}
