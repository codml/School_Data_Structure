#pragma once
#include "MemberQueue.h"
#include "TermsList.h"
#include "TermsBST.h"
#include "NameBST.h"
#include <string>
#include <fstream>
using namespace std;

class Manager
{
private:

	ifstream	fcmd;
	ofstream	flog;


public:
	Manager();
	~Manager();

	void run(const char* command);
	
	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);

	void load();
	void add(string vars);
	void qpop();
	void search(string name);
	void print(string data);
	void delete_data(string vars);
};
