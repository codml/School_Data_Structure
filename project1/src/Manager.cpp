#include "Manager.h"

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
        if (cmd.compare("LOAD") == 0)
        {
			if (load())
				PrintSuccess("LOAD");
			else
				PrintErrorCode(100);
        }
        else if ((cmd.substr(0, 3)).compare("ADD") == 0)
        {

        }
		else if (cmd.compare("QPOP") == 0)
        {
			if (qpop())
				PrintSuccess("QPOP");
			else
				PrintErrorCode(100);
        }
		else if ((cmd.substr(0, 6)).compare("SEARCH") == 0)
        {

        }
		else if ((cmd.substr(0, 5)).compare("PRINT") == 0)
        {

        }
		else if ((cmd.substr(0, 6)).compare("DELETE") == 0)
        {

        }
		else if (cmd.compare("EXIT") == 0)
		{
			PrintSuccess("EXIT");
			break;
		}
		else
		{
			PrintErrorCode(1000);
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

bool Manager::load()
{
	ifstream		fdata;
	string			data, tmp;
	stringstream	stream;
	vector<string>	v;
    string			name;
	int				age;
	string			infor_date;
	char			type;
	MemberQueueNode *ptr;

	fdata.open("data.txt");
    if (!fdata)
		return false;
	if (!queue.empty())
		return false;
	while (getline(fdata, data))
    {
		stream.str(data);
		while (getline(stream, tmp, ' '))
			v.push_back(tmp);
		if (v.size() != 4)
			return false;
		name = v.at(0);
		age = stoi(v.at(1));
		infor_date = v.at(2);
		type = (v.at(3)).at(0);
		MemberQueueNode node(name, age, infor_date, type);
		queue.push(&node);
    }
	while (!queue.empty())
	{
		ptr = queue.pop();
		flog << ptr->getName() << "/" << ptr->getAge() << "/" << ptr->getInfor_date() << "/" << ptr->getType() << endl;
	}
	return true;
}

bool Manager::add(string vars)
{
	return true;
}

bool Manager::qpop()
{
	return true;
}

bool Manager::search(string name)
{
	return true;
}

bool Manager::print(string data)
{
	return true;
}

bool Manager::delete_data(string vars)
{
	return true;
}
