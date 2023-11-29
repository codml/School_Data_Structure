#include "Manager.h"
#include <iomanip>

int main()
{
	Manager ds;	//Declare DS
	ds.LOAD("graph_M.txt");
	ds.PRINT();
	 // ds.run("command.txt");	//Run Program
	return 0;	//Return Program
}
