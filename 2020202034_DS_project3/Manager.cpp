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
	string oneLine, buf;
	vector <string> v;
	stringstream ss;

	fin.open(command_txt, ios_base::in);//File open with read mode
		
	if(!fin) { //If command File cannot be read, Print error
		fout<<"command file open error"<<endl;
		return;	//Return
	}
	while (getline(fin, oneLine))
	{
		ss << oneLine;
		while (getline(ss, buf, ' '))
			v.push_back(buf);
		if (v.empty())
			printErrorCode(1000);
		else if (v.at(0) == "LOAD")
		{
			if (v.size() != 2)
				printErrorCode(100);
			else if (!LOAD(v.at(1).c_str()))
				printErrorCode(100);
		}
		else if (v.at(0) == "PRINT")
		{
			if (v.size() != 1)
				printErrorCode(200);
			else if (!PRINT())
				printErrorCode(200);
		}
		else if (v.at(0) == "BFS")
		{
			if (v.size() != 3)
				printErrorCode(300);
			else if (!mBFS(v.at(1)[0], stoi(v.at(2))))
				printErrorCode(300);
		}
		else if (v.at(0) == "DFS")
		{
			if (v.size() != 3)
				printErrorCode(400);
			else if (!mDFS(v.at(1)[0], stoi(v.at(2))))
				printErrorCode(400);
		}
		else if (v.at(0) == "KWANGWOON")
		{
			if (v.size() != 2)
				printErrorCode(500);
			else if (!mKwoonWoon(stoi(v.at(1))))
				printErrorCode(500);
		}
		else if (v.at(0) == "KRUSKAL")
		{
			if (v.size() != 1)
				printErrorCode(600);
			else if (!mKRUSKAL())
				printErrorCode(600);
		}
		else if (v.at(0) == "DIJKSTRA")
		{
			if (v.size() != 3)
				printErrorCode(700);
			else if (!mDIJKSTRA(v.at(1)[0], stoi(v.at(2))))
				printErrorCode(700);
		}
		else if (v.at(0) == "BELLMANFORD")
		{
			if (v.size() != 4)
				printErrorCode(800);
			else if (!mBELLMANFORD(v.at(1)[0], stoi(v.at(2)), stoi(v.at(3))))
				printErrorCode(800);
		}
		else if (v.at(0) == "FLOYD")
		{
			if (v.size() != 2)
				printErrorCode(900);
			else if (!mFLOYD(v.at(1)[0]))
				printErrorCode(900);
		}
		else if (v.at(0) == "EXIT")
			break;
		else
			printErrorCode(1000);
		v.clear();
		ss.clear();
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
			{
				graph->insertEdge(from, to, weight);
				if (weight < 0)
					graph->setNeg(true);
			}
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
			{
				graph->insertEdge(from, to, stoi(v.at(to)));
				if (stoi(v.at(to)) < 0)
					graph->setNeg(true);
			}
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
	fout << "========LOAD========" << endl << "Success" << endl;
	fout << "=====================" << endl << endl;
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
	return (BFS(graph, option, vertex, &fout));
}

bool Manager::mDFS(char option, int vertex)	
{
	return (DFS(graph, option, vertex, &fout));
}

bool Manager::mDIJKSTRA(char option, int vertex)	
{
	return Dijkstra(graph, option, vertex, &fout);
}

bool Manager::mKRUSKAL()
{
 	return true;
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex) 
{
	return Bellmanford(graph, option, s_vertex, e_vertex, &fout);
}

bool Manager::mFLOYD(char option)
{
	return FLOYD(graph, option, &fout);
}

bool Manager::mKwoonWoon(int vertex) {
	return true;
}

void Manager::printErrorCode(int n)
{
	fout<<"========ERROR======="<<endl;
	fout<<n<<endl;
	fout<<"===================="<<endl << endl;
}


