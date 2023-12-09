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
		while (getline(ss, buf, ' ')) // split words by space
			v.push_back(buf);
		if (v.empty()) // line is blank or only space
			printErrorCode(1000);
		else if (v.at(0) == "LOAD") // load
		{
			if (v.size() != 2) // argument lack or too much
				printErrorCode(100);
			else if (!LOAD(v.at(1).c_str()))
				printErrorCode(100);
		}
		else if (v.at(0) == "PRINT") // print
		{
			if (v.size() != 1)
				printErrorCode(200);
			else if (!PRINT())
				printErrorCode(200);
		}
		else if (v.at(0) == "BFS") // bfs
		{
			if (v.size() != 3)
				printErrorCode(300);
			else if (!mBFS(v.at(1)[0], stoi(v.at(2))))
				printErrorCode(300);
		}
		else if (v.at(0) == "DFS") // dfs
		{
			if (v.size() != 3)
				printErrorCode(400);
			else if (!mDFS(v.at(1)[0], stoi(v.at(2))))
				printErrorCode(400);
		}
		else if (v.at(0) == "KWANGWOON") // kwangwoon
		{
			if (v.size() != 2)
				printErrorCode(500);
			else if (!mKwoonWoon(stoi(v.at(1))))
				printErrorCode(500);
		}
		else if (v.at(0) == "KRUSKAL") // kruskal
		{
			if (v.size() != 1)
				printErrorCode(600);
			else if (!mKRUSKAL())
				printErrorCode(600);
		}
		else if (v.at(0) == "DIJKSTRA") // dijkstra
		{
			if (v.size() != 3)
				printErrorCode(700);
			else if (!mDIJKSTRA(v.at(1)[0], stoi(v.at(2))))
				printErrorCode(700);
		}
		else if (v.at(0) == "BELLMANFORD") // bellman-ford
		{
			if (v.size() != 4)
				printErrorCode(800);
			else if (!mBELLMANFORD(v.at(1)[0], stoi(v.at(2)), stoi(v.at(3))))
				printErrorCode(800);
		}
		else if (v.at(0) == "FLOYD") // floyd
		{
			if (v.size() != 2)
				printErrorCode(900);
			else if (!mFLOYD(v.at(1)[0]))
				printErrorCode(900);
		}
		else if (v.at(0) == "EXIT") // exit
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
	if (!fg) // fail to open file
		return false;
	if (!getline(fg, buf1)) // check empty file
	{
		fg.close();
		return false;
	}
	if (buf1 != "L" && buf1 != "M") // option is neither "L" nor "M"
	{
		fg.close();
		return false;
	}
	if (load) // already load
		delete graph;
	if (buf1 == "L") // list graph
	{
		getline(fg, buf1); // read graph size
		graph = new ListGraph(0, stoi(buf1)); // new graph data
		while (getline(fg, buf1)) // read line
		{
			to = 0;
			ss << buf1;
			while (getline(ss, buf2, ' '))
				v.push_back(buf2);
			if (v.size() == 1) // from vertex
				from = stoi(v.at(0));
			else // to vertex
			{
				to = stoi(v.at(0));
				weight = stoi(v.at(1));
			}
			if (to) // only update 'to vertex' exists
			{
				graph->insertEdge(from, to, weight);
				if (weight < 0)
					graph->setNeg(true); // graph has negative edge
			}
			ss.clear();
			v.clear();
		}
		graph->setKw_graph();
	}
	else // matrix graph
	{
		getline(fg, buf1);
		graph = new MatrixGraph(1, stoi(buf1));
		from = 0; // 'from edge' start with 1 (0 + 1)
		while (getline(fg, buf1))
		{
			ss << buf1;
			while (getline(ss, buf2, ' '))
				v.push_back(buf2); // push weights to vector v
			for (to = 0; to < graph->getSize(); to++)
			{
				graph->insertEdge(from, to, stoi(v.at(to)));
				if (stoi(v.at(to)) < 0)
					graph->setNeg(true); // graph has negative edge
			}
			from++;
			v.clear();
			ss.clear();
		}
	}
	fg.close();
	load = 1;
	fout << "========LOAD========" << endl << "Success" << endl; // print success
	fout << "=====================" << endl << endl;
	return true;
}

bool Manager::PRINT()	
{
	if (!graph) // has no graph
		return false;
	if (!graph->printGraph(&fout)) // fail to print
		return false;
	return true;
}

bool Manager::mBFS(char option, int vertex)	// BFS
{
	return (BFS(graph, option, vertex, &fout));
}

bool Manager::mDFS(char option, int vertex)	// DFS
{
	return (DFS(graph, option, vertex, &fout));
}

bool Manager::mDIJKSTRA(char option, int vertex) // Dijkstra	
{
	return Dijkstra(graph, option, vertex, &fout);
}

bool Manager::mKRUSKAL() // Kruskal
{
 	return Kruskal(graph, &fout);
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex) // Bellman-Ford
{
	return Bellmanford(graph, option, s_vertex, e_vertex, &fout);
}

bool Manager::mFLOYD(char option) // Floyd
{
	return FLOYD(graph, option, &fout);
}

bool Manager::mKwoonWoon(int vertex) { // Kwangwoon
	return KWANGWOON(graph, 1, &fout);
}

void Manager::printErrorCode(int n)
{
	fout<<"========ERROR======="<<endl;
	fout<<n<<endl; // print error code
	fout<<"===================="<<endl << endl;
}


