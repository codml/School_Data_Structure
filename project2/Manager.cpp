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
	while (getline(fin, oneCmd))
	{
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
		else if (oneCmd == "EXIT")
		{
			printSuccessCode("EXIT");
			break;
		}
		else
			printErrorCode(700);
	}
	fin.close();
	return;
}

bool Manager::LOAD()
{
	ifstream		floan;
	LoanBookData	*data;
	stringstream	ss;
	string			line, book;
	vector<string>	v;

	floan.open("loan_book.txt");
	if (!floan)
		return false;
	if (bptree->getRoot())
		return false;
	while (getline(floan, line))
	{
		if (*line.rbegin() == '\r')
			line.pop_back();
		ss << line;
		while(getline(ss, book, '\t'))
			v.push_back(book);
		if (v.size() != 5)
		{
			delete bptree;
			bptree = new BpTree(&flog);
			floan.close();
			return false;
		}
		data = new LoanBookData;
		data->setBookData(v.at(0), stoi(v.at(1)), v.at(2), stoi(v.at(3)), stoi(v.at(4)));
		bptree->Insert(data);
		v.clear();
		ss.clear();
	}
	floan.close();
	return true;
}

bool Manager::ADD(string data)
{
	vector <string>	v;
	stringstream	ss;
	string			buf;
	LoanBookData	*pdata;

	ss << data;
	while(getline(ss, buf, '\t'))
		v.push_back(buf);
	if (v.size() != 5)
		return false;
	pdata = new LoanBookData;
	pdata->setBookData(v.at(1), stoi(v.at(2)), v.at(3), stoi(v.at(4)), 0);
	if (!bptree->Insert(pdata))
	{
		while (pdata->getLoanCount() != 3 + ((pdata->getCode() % 500) / 300) - (pdata->getCode() / 500))
			pdata->updateCount();
		stree->Insert(pdata);
	}
	if (pdata->getCode())
	{
		flog << "========ADD========" << endl;
		flog << pdata->getName() << "/" << pdata->getCode() << "/" << pdata->getAuthor()
			<< "/" << pdata->getYear() << endl;
		flog << "===================" << endl << endl;
	}
	else
	{
		flog << "========ADD========" << endl;
		flog << pdata->getName() << "/" << "000" << "/" << pdata->getAuthor()
			<< "/" << pdata->getYear() << endl;
		flog << "===================" << endl << endl;
	}
	
	return true;
}

bool Manager::SEARCH_BP_BOOK(string book) 
{
	return bptree->searchBook(book);
}

bool Manager::SEARCH_BP_RANGE(string s, string e) 
{
	return bptree->searchRange(s, e);
}

bool Manager::PRINT_BP() 
{
	BpTreeNode *tmp;

	if (bptree->getRoot() == NULL)
		return false;
	tmp = bptree->getRoot();
	while (tmp->getMostLeftChild())
		tmp = tmp->getMostLeftChild();
	flog << "========PRINT_BP========" << endl;
	auto itr = tmp->getDataMap()->begin();
	while (tmp)
	{	
		if (itr->second)
		{
			if (itr->second->getCode())
			{
				flog << itr->second->getName() << "/"
				<< itr->second->getCode() << "/"
				<< itr->second->getAuthor() << "/"
				<< itr->second->getYear() << "/"
				<< itr->second->getLoanCount() << endl;
			}
			else
			{
				flog << itr->second->getName() << "/"
				<< "000" << "/"
				<< itr->second->getAuthor() << "/"
				<< itr->second->getYear() << "/"
				<< itr->second->getLoanCount() << endl;
			}
		}
		itr++;
		if (itr == tmp->getDataMap()->end())
		{
			tmp = tmp->getNext();
			if (!tmp)
				break;
			itr = tmp->getDataMap()->begin();
		}
	}
	flog << "========================" << endl << endl;
	return true;
}

bool Manager::PRINT_ST(int bookCode) 
{
	return (stree->printBookData(bookCode));
}

bool Manager::DELETE() 
{
	return stree->Delete();
}

void Manager::printErrorCode(int n) {				//ERROR CODE PRINT
	flog << "========ERROR========" << endl;
	flog << n << endl;
	flog << "=======================" << endl << endl;
}

void Manager::printSuccessCode(string code) {//SUCCESS CODE PRINT 
	flog << "========" << code << "========" << endl;
	flog << "Success" << endl;
	flog << "=======================" << endl << endl;
}

