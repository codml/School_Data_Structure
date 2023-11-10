#include "Manager.h"

void Manager::run(const char* command) 
{
	string	oneCmd, buf;
	vector <string> v;
	stringstream ss;

	fin.open(command);
	if(!fin)
	{
		flog << "File Open Error" << endl;
		return;
	}
	while (!fin.eof())
	{
		getline(fin, oneCmd);
		if (*oneCmd.rbegin() == '\r')
			oneCmd.pop_back();
		if (oneCmd == "LOAD")
		{
			if (LOAD())
				printSuccessCode("LOAD");
			else
				printErrorCode(100);
		}
		else if (oneCmd.substr(0, 3) == "ADD")
		{
			if (!ADD(oneCmd))
				printErrorCode(200);
		}
		else if (oneCmd.substr(0, 9) == "SEARCH_BP")
		{
			ss << oneCmd;
			while (getline(ss, buf, '\t'))
				v.push_back(buf);
			if (v.size() == 2)
			{
				if (!SEARCH_BP_BOOK(v.at(1)))
					printErrorCode(300);
			}
			else if (v.size() == 3)
			{
				if (!SEARCH_BP_RANGE(v.at(1), v.at(2)))
					printErrorCode(300);
			}
			else
				printErrorCode(300);
			v.clear();
			ss.clear();
		}
		else if (oneCmd == "PRINT_BP")
		{
			if (!PRINT_BP())
				printErrorCode(400);
		}
		else if (oneCmd.substr(0, 8) == "PRINT_ST")
		{
			ss << oneCmd;
			while (getline(ss, buf, '\t'))
				v.push_back(buf);
			if (v.size() == 2)
			{
				if (!PRINT_ST(stoi(v.at(1))))
					printErrorCode(500);
			}
			else
				printErrorCode(500);
			v.clear();
			ss.clear();
		}
		else if (oneCmd == "DELETE")
		{
			if (DELETE())
				printSuccessCode("DELETE");
			else
				printErrorCode(600);
		}
		else
			printErrorCode(700);
	}
	fin.close();
	return;
}

bool Manager::LOAD()
{
	ifstream floan;

	floan.open("loan_book.txt");
	if (!floan)
		return false;
	while (!floan.eof())
	{
		
	}
	return true;
}

bool Manager::ADD(string data)
{
	
	return true;
}

bool Manager::SEARCH_BP_BOOK(string book) 
{
	
}

bool Manager::SEARCH_BP_RANGE(string s, string e) 
{
	
}

bool Manager::PRINT_BP() 
{
	
}

bool Manager::PRINT_ST(int bookCode) 
{

}

bool Manager::DELETE() 
{

}

void Manager::printErrorCode(int n) {				//ERROR CODE PRINT
	flog << "=======================" << endl;
	flog << "ERROR " << n << endl;
	flog << "=======================" << endl << endl;
}

void Manager::printSuccessCode(string code) {//SUCCESS CODE PRINT 
	flog << "========" << code << "========" << endl;
	flog << "Success" << endl;
	flog << "=======================" << endl << endl;
}

