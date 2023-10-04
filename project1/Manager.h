#pragma once
#include "MemberQueue.h"
#include "TermsList.h"
#include "TermsBST.h"
#include "NameBST.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class Manager
{
private:
	ifstream	fcmd;
	ofstream	flog;
	MemberQueue queue;
	NameBST		bst;
	TermsLIST	list;
	void		make_ex_date(string const &date, string& ex, char type);
public:
	Manager();
	~Manager();

	void run(const char* command);
	
	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);

	bool load();
	bool add(string vars);
	bool qpop();
	bool search(string data);
	bool print(string data);
	bool Delete(string vars);
};
