#include "Manager.h"

void Manager::run(const char* command) 
{
	string	oneCmd, buf;
	vector <string> v;
	stringstream ss;

	fin.open(command); // open file stream for read
	if(!fin)
	{
		flog << "File Open Error" << endl; // fail file open
		return;
	}
	while (getline(fin, oneCmd)) // read a line until meet eof
	{
		if (*oneCmd.rbegin() == '\r') // new line signal is \r\n
			oneCmd.pop_back();
		if (oneCmd == "LOAD") // LOAD
		{
			if (LOAD())
				printSuccessCode("LOAD");
			else
				printErrorCode(100);
		}
		else if (oneCmd.substr(0, 3) == "ADD") // ADD data
		{
			if (!ADD(oneCmd))
				printErrorCode(200);
		}
		else if (oneCmd.substr(0, 9) == "SEARCH_BP") // SEARCH_BP name or a z
		{
			ss << oneCmd;
			while (getline(ss, buf, '\t')) // data parsing
				v.push_back(buf);
			if (v.size() == 2) // SEARCH_BP name
			{
				if (!SEARCH_BP_BOOK(v.at(1)))
					printErrorCode(300);
			}
			else if (v.size() == 3) // SEARCH_BP start end
			{
				if (!SEARCH_BP_RANGE(v.at(1), v.at(2)))
					printErrorCode(300);
			}
			else
				printErrorCode(300);
			v.clear();
			ss.clear();
		}
		else if (oneCmd == "PRINT_BP") // PRINT_BP
		{
			if (!PRINT_BP())
				printErrorCode(400);
		}
		else if (oneCmd.substr(0, 8) == "PRINT_ST") // PRINT_ST code
		{
			ss << oneCmd;
			while (getline(ss, buf, '\t')) // data parsing
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
		else if (oneCmd == "DELETE") // DELETE
		{
			if (DELETE())
				printSuccessCode("DELETE");
			else
				printErrorCode(600);
		}
		else if (oneCmd == "EXIT") // EXIT
		{
			printSuccessCode("EXIT");
			break;
		}
		else
			printErrorCode(700); // wrong command
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
	while (getline(floan, line)) // read a line
	{
		if (*line.rbegin() == '\r')
			line.pop_back();
		ss << line;
		while(getline(ss, book, '\t'))
			v.push_back(book); // data parsing
		if (v.size() != 5) // argument number error
		{
			delete bptree;
			bptree = new BpTree(&flog);
			floan.close();
			return false;
		}
		data = new LoanBookData;
		data->setBookData(v.at(0), stoi(v.at(1)), v.at(2), stoi(v.at(3)), stoi(v.at(4))); // make loanbookdata
		bptree->Insert(data); // insert data in b+tree
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
	while(getline(ss, buf, '\t')) // data parsing
		v.push_back(buf);
	if (v.size() != 5) // the number of argument error
		return false;
	pdata = new LoanBookData;
	pdata->setBookData(v.at(1), stoi(v.at(2)), v.at(3), stoi(v.at(4)), 0);
	if (!bptree->Insert(pdata)) // insert data into Selection tree
	{
		while (pdata->getLoanCount() != 3 + ((pdata->getCode() % 500) / 300) - (pdata->getCode() / 500))
			pdata->updateCount();
		stree->Insert(pdata);
	}
	if (stoi(v.at(2))) // code != 000
	{
		flog << "========ADD========" << endl;
		flog << v.at(1) << "/" << stoi(v.at(2)) << "/" << v.at(3)
			<< "/" << stoi(v.at(4)) << endl;
		flog << "===================" << endl << endl;
	}
	else // code == 000
	{
		flog << "========ADD========" << endl;
		flog << v.at(1) << "/" << "000" << "/" << v.at(3)
			<< "/" << stoi(v.at(4)) << endl;
		flog << "===================" << endl << endl;
	}
	return true;
}

bool Manager::SEARCH_BP_BOOK(string book)
{
	return bptree->searchBook(book); // search one book
}

bool Manager::SEARCH_BP_RANGE(string s, string e) 
{
	return bptree->searchRange(s, e); // search range
}

bool Manager::PRINT_BP() 
{
	BpTreeNode *tmp;

	if (bptree->getRoot() == NULL) // if B+tree is empty
		return false;
	tmp = bptree->getRoot();
	while (tmp->getMostLeftChild())
		tmp = tmp->getMostLeftChild(); // move to first data node
	flog << "========PRINT_BP========" << endl;
	auto itr = tmp->getDataMap()->begin(); // first data in first data node
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
		itr++; // move to next data in data map
		if (itr == tmp->getDataMap()->end()) // end of map
		{
			tmp = tmp->getNext(); // move to next node
			if (!tmp)
				break;
			itr = tmp->getDataMap()->begin();
		}
	}
	flog << "========================" << endl << endl;
	return true;
}

bool Manager::PRINT_ST(int bookCode) // print selection tree's run(heap)
{
	return (stree->printBookData(bookCode));
}

bool Manager::DELETE() 
{
	return stree->Delete(); // delete winner of selection tree
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

