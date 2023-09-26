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
	ifstream	fdata;
	string		data;
	char		*pdata;
	
	fdata.open("data.txt");
    if (!fdata)
		return false;
	
	return true;
}

bool Manager::add(string vars)
{

}

bool Manager::qpop()
{

}

bool Manager::search(string name)
{

}

bool Manager::print(string data)
{

}

bool Manager::delete_data(string vars)
{

}
