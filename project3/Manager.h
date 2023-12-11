#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "GraphMethod.h"

#include <sstream>

class Manager{	
private:
	Graph* graph;	
	ofstream fout;	// log.txt
	int load; // load = 1 -> graph exists

public:
	Manager();	
	~Manager();	

	void run(const char * command_txt); // run commands 
	
	bool LOAD(const char* filename); // load graph_L.txt or graph_M.txt
	bool PRINT();	
	bool mBFS(char option, int vertex);	 // graph search method start
	bool mDFS(char option, int vertex);	
	bool mDIJKSTRA(char option, int vertex);	
	bool mKRUSKAL();	
	bool mBELLMANFORD(char option, int s_vertex, int e_vertex);	
	bool mFLOYD(char option); 
	bool mKwoonWoon(int vertex); // graph search method end
	void printErrorCode(int n); 
};

#endif