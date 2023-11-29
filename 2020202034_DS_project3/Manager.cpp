#include "Manager.h"
#include "GraphMethod.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Manager::Manager()	
{
	graph = nullptr;	
	fout.open("log.txt", ios::app);
	load = 0;	//Anything is not loaded
}

Manager::~Manager()
{
	if(load)	//if graph is loaded, delete graph
		delete graph;	
	if(fout.is_open())	//if fout is opened, close file
		fout.close();	//close log.txt File
}

void Manager::run(const char* command_txt){
	ifstream fin;	//Command File Input File Stream
	fin.open(command_txt, ios_base::in);//File open with read mode
		
	if(!fin) { //If command File cannot be read, Print error
		fout<<"command file open error"<<endl;
		return;	//Return
	}
	
	fin.close();
	return;
}

bool Manager::LOAD(const char* filename)
{
	ifstream		fg;
	string			buf1, buf2;
	stringstream	ss;
	vector <string>	v;
	int				from, to, weight;

	fg.open(filename);
	if (!fg)
		return false;
	if (load)
		delete graph;
	if (!getline(fg, buf1))
	{
		fg.close();
		return false;
	}
	if (buf1 == "L")
	{
		getline(fg, buf1);
		graph = new ListGraph(0, stoi(buf1));
		while (getline(fg, buf1))
		{
			to = 0;
			ss << buf1;
			while (getline(ss, buf2, ' '))
				v.push_back(buf2);
			if (v.size() == 1)
				from = stoi(v.at(0));
			else
			{
				to = stoi(v.at(0));
				weight = stoi(v.at(1));
			}
			if (to)
				graph->insertEdge(from, to, weight);
			ss.clear();
			v.clear();
		}
	}
	else if (buf1 == "M")
	{
		getline(fg, buf1);
		graph = new MatrixGraph(1, stoi(buf1));
		from = 0;
		while (getline(fg, buf1))
		{
			ss << buf1;
			while (getline(ss, buf2, ' '))
				v.push_back(buf2);
			for (to = 0; to < graph->getSize(); to++)
				graph->insertEdge(from, to, stoi(v.at(to)));
			from++;
			v.clear();
			ss.clear();
		}
	}
	else
	{
		fg.close();
		return false;
	}
	fg.close();
	load = 1;
	return true;
}

bool Manager::PRINT()	
{
	if (!graph)
		return false;
	if (!graph->printGraph(&fout))
		return false;
	return true;
}

bool Manager::mBFS(char option, int vertex)	
{
	
}

bool Manager::mDFS(char option, int vertex)	
{
	
}

bool Manager::mDIJKSTRA(char option, int vertex)	
{
	
}

bool Manager::mKRUSKAL()
{
 	
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex) 
{
	
}

bool Manager::mFLOYD(char option)
{
	
}

bool Manager::mKwoonWoon(int vertex) {
	
}

void Manager::printErrorCode(int n)
{
	fout<<"========ERROR======="<<endl;
	fout<<n<<endl;
	fout<<"===================="<<endl << endl;
}


