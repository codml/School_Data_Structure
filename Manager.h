#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "SelectionTree.h"
#include "BpTree.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Manager
{
private:
	char* cmd;
	BpTree* bptree;
	SelectionTree* stree;
public:
	Manager(int bpOrder)	//constructor
	{
		cmd = NULL;
		flog.open("log.txt", ios::app); // app: append to exist file
		bptree = new BpTree(&flog);
		stree = new SelectionTree(&flog); // allocate b+tree, selection tree
	}


	~Manager()//destructor
	{
		delete bptree;
		delete stree;
		flog.close();
	}

	ifstream fin;
	ofstream flog;
	

	void run(const char* command);
	bool LOAD(); // load data from loan_book.txt
	bool ADD(string data); // add data into b+tree

	bool SEARCH_BP_BOOK(string book);
	bool SEARCH_BP_RANGE(string start, string end); // search one book and books in range

	bool PRINT_BP();
	bool PRINT_ST(int bookCode); // print b+tree and heap in selection tree

	bool DELETE(); // delete from selection tree

	void printErrorCode(int n);
	void printSuccessCode(string code);

};

#endif