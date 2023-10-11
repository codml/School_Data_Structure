#include "Manager.h"

void	Manager::make_ex_date(string const &date, string &ex, char type)
{ // make expire date string
	string	tmp;
	int		month;
	int		year;

	ex = date;
	switch (type)
	{
	case 'A': // plus 6 months
		month = stoi(date.substr(5, 2)) + 6;
		if (month > 12) // +1 year
		{
			month -= 12;
			year = stoi(date.substr(0, 4)) + 1;
			ex.replace(0, 4, to_string(year));
		}
		tmp = to_string(month);
		if (month < 10) // make month two digit
			tmp.insert(0, 1, '0');
		ex.replace(5, 2, tmp);
		break;

	case 'B':
	case 'C':
	case 'D':
		year = stoi(date.substr(0, 4)) + (type - 'A'); // +1, +2, +3 year
		ex.replace(0, 4, to_string(year));
		break;

	default:
		break;
	}
}

Manager::Manager()
{

}
Manager::~Manager()
{

}

void Manager::run(const char* command)
{
    string	cmd;
	int		i;
    // Open command & log file
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd)
    {
        flog << "Fail to open command file" << endl;
        exit(-1);
    }

    // Run command
	while (getline(fcmd, cmd))
	{
        if (cmd.compare("LOAD") == 0) // LOAD command execute
        {
			if (!load())
				PrintErrorCode(100);
        }
        else if ((cmd.substr(0, 3)).compare("ADD") == 0) // ADD command execute
        {
			if (!add(cmd))
				PrintErrorCode(200);
        }
		else if (cmd.compare("QPOP") == 0) // QPOP command execute
        {
			if (qpop())
				PrintSuccess("QPOP");
			else
				PrintErrorCode(300);
        }
		else if ((cmd.substr(0, 6)).compare("SEARCH") == 0) // SEARCH command execute
        {
			if (!search(cmd))
				PrintErrorCode(400);
        }
		else if ((cmd.substr(0, 5)).compare("PRINT") == 0) // PRINT command execute
        {
			if (!print(cmd))
				PrintErrorCode(500);
        }
		else if ((cmd.substr(0, 6)).compare("DELETE") == 0) // DELETE command execute
        {
			if (Delete(cmd))
				PrintSuccess("DELETE");
			else
				PrintErrorCode(600);
        }
		else if (cmd.compare("EXIT") == 0) // EXIT command execute
		{
			PrintSuccess("EXIT");
			break;
		}
		else
		{
			PrintErrorCode(1000); // Wrong command
			break;
		}
	}

    fcmd.close();
    flog.close();
    return;
}

void Manager::PrintSuccess(const char* cmd)
{
    flog << "===== " << cmd << " =====" << endl;
    flog << "Success" << endl;
    flog << "===============" << endl << endl;
}
void Manager::PrintErrorCode(int num)
{
    flog << "===== ERROR =====" << endl;
    flog << num << endl;
    flog << "===============" << endl << endl;
}

bool Manager::load() // load data from data.txt
{
	ifstream		fdata;
	string			data, tmp;
	stringstream	stream;
	vector<string>	v;
	MemberQueueNode *node;
	MemberQueueNode *ptr;

	fdata.open("data.txt");
    if (!fdata)
		return false;
	if (!queue.empty()) // if queue is not empty
		return false;
	flog << "===== " << "LOAD" << " =====" << endl;
	while (getline(fdata, data)) // read file line by line
    {
		stream << data; // split string by blank
		while (stream >> tmp)
			v.push_back(tmp);
		if (v.size() != 4) // if argument is insuffient, return false
			return false;
		node = new MemberQueueNode(v.at(0), stoi(v.at(1)), v.at(2), (v.at(3)).at(0));
		flog << node->getName() << "/" << node->getAge() << "/"
			<< node->getInfor_date() << "/" << node->getType() << endl;
		queue.push(node); // make queue node and push to queue
		v.clear();
		stream.clear();
    }
	flog << "===============" << endl << endl;
	return true;
}

bool Manager::add(string vars) // add person to queue
{
	stringstream	stream;
	vector<string>	v;
	string			tmp;
	MemberQueueNode	*node;

	stream << vars;
	while (stream >> tmp)
		v.push_back(tmp);
	if (v.size() != 5)
		return false;
	flog << "===== " << "ADD" << " =====" << endl;
	node = new MemberQueueNode(v.at(1), stoi(v.at(2)), v.at(3), (v.at(4)).at(0));
	flog << node->getName() << "/" << node->getAge() << "/"
			<< node->getInfor_date() << "/" << node->getType() << endl;
	queue.push(node); // make queue node and push to queue
	flog << "===============" << endl << endl;
	return true;
}

bool Manager::qpop() // pop data from queue and push to bst, list
{
	MemberQueueNode *queuenode;
	TermsListNode	*listnode, *now, *prev;
	TermsBSTNode	*termsbstnode;
	NameBSTNode		*namebstnode;
	string			ex_date;

	if (queue.empty())
		return false;
	while (!queue.empty())
	{
		queuenode = queue.pop(); // pop data from queue
		ex_date = "";
		make_ex_date(queuenode->getInfor_date(), ex_date, queuenode->getType()); // make expire date
		namebstnode = new NameBSTNode(queuenode->getName(), queuenode->getAge(), queuenode->getInfor_date(),
			ex_date, queuenode->getType());
		bst.insert(namebstnode); // make NameBSTNode and insert
		termsbstnode = new TermsBSTNode(queuenode->getName(), queuenode->getAge(), queuenode->getInfor_date(),
			ex_date); // make TermsBSTNode
		if (listnode = list.search(queuenode->getType())) // if listnode that have same type to new node exists
		{
			listnode->increaseNum(); // increase the number of member
			listnode->getBST()->insert(termsbstnode); // insert node to TermsBST
		}
		else // there is no node that have same type to new node in TermsList
		{
			listnode = new TermsListNode(queuenode->getType());
			listnode->increaseNum();
			listnode->getBST()->insert(termsbstnode); // insert node to TermsBST
			now = list.getHead();
			prev = 0;
			while (now)
			{
				prev = now;
				now = now->getNext();
			}
			if (!list.getHead())
				list.setHead(listnode);
			else
				prev->setNext(listnode); // make listnode and insert to list
		}
		delete queuenode;
	}
	return true;
}

bool Manager::search(string data)
{
	string		name(data.substr(7));
	NameBSTNode	*node;

	if (node = bst.search(name)) // find node in NameBST
	{
		flog << "===== " << "SEARCH" << " =====" << endl;
		flog << node->getName() << "/" << node->getAge() << "/"
			<< node->getInfor_date() << "/" << node->getEx_date() << endl;
		flog << "===============" << endl << endl;
		return true;
	}
	else
		return false;
}

bool Manager::print(string data)
{
	TermsListNode	*listnode;

	if (data.substr(6).compare("NAME") == 0) // name-ordered print
	{
		flog << "===== " << "PRINT" << " =====" << endl;
		flog << "Name_BST" << endl;
		bst.print(flog); // print() in NameBST
		flog << "===============" << endl << endl;
	}
	else if (data.at(6) >= 'A' && data.at(6) <= 'D') // type print, date-ordered
	{
		if (listnode = list.search(data.at(6)))
		{
			flog << "===== " << "PRINT" << " =====" << endl;
			flog << "Terms_BST " << data.at(6) << endl;
			listnode->getBST()->print(flog); // print() in TermsBST
			flog << "===============" << endl << endl;
		}
		else
			return false;
	}
	else
		return false; // argument error
	return true;
}

bool Manager::Delete(string vars)
{
	stringstream	stream;
	vector<string>	v;
	string			tmp;
	TermsListNode	*node, *temp;
	TermsBSTNode	*del;
	bool			flag;
	int				cnt;

	cnt = 0;
	flag = false; // if flag is true, delete DATE in TermsBST succeed
	stream << vars;
	while (stream >> tmp)
		v.push_back(tmp);
	if (v.size() != 3) // the number of argument error
		return false;
	if (v.at(1) == "DATE") // delete date
	{
		node = list.getHead();
		while (node) // node: traversal TermsList
		{
			temp = node;
			while(node->getBST()->default_delete(v.at(2))) // TermsBST node delete success
			{
				flag = true;
				node->decreaseNum();
			}
			node = node->getNext();
			if (temp->getNum() == 0) // delete node which has empty TemrsBST
				list.Delete(temp);
		}
	}
	else if (v.at(1) == "NAME") // delete name
	{
		if (bst.default_delete(v.at(2))) // if NAME delete success in NameBST
		{
			node = list.getHead();
			while (node) // traversal
			{
				temp = node;
				node->getBST()->name_delete(v.at(2), cnt); // name delete and count
				while (cnt)
				{
					node->decreaseNum();
					cnt--;
				}
				node = node->getNext();
				if (temp->getNum() == 0)
					list.Delete(temp);
			}
			return true;
		}
		else
			return false;
	}
	else
		return false;
	if (flag) // if DATE delete in TermsBST success
	{
		bst.date_delete(v.at(2));
		return true;
	}
	else
		return false;
}
