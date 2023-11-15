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
		flog.open("log.txt", ios::app);
		bptree = new BpTree(&flog);
		stree = new SelectionTree(&flog);
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
	bool LOAD();
	bool ADD(string data);

	bool SEARCH_BP_BOOK(string book);
	bool SEARCH_BP_RANGE(string start, string end);

	bool PRINT_BP();
	bool PRINT_ST(int bookCode);

	bool DELETE();

	void printErrorCode(int n);
	void printSuccessCode(string code);

};

#endif