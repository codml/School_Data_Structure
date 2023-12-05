#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Graph{	
protected:
	bool m_Type;
	int m_Size;
	bool m_Neg;
public:
	Graph(bool type, int size);
	virtual ~Graph();

	bool getType();	
	int getSize();

	bool getNeg();
	void setNeg(bool tf);

	virtual int getWeight(int from_v, int to_v, char option) = 0;
	virtual void getAdjacentEdges(int vertex, map<int, int>* m, char option) = 0;	
	virtual void getIncomingEdges(int vertex, map<int, int>* m) = 0;	
	virtual void getAdjacentEdgesDirect(int vertex, map<int, int>* m) = 0;	
	virtual void insertEdge(int from, int to, int weight) = 0;				
	virtual	bool printGraph(ofstream *fout) = 0;

	virtual void setKw_graph(void) = 0;
	virtual vector<int>* getKw_graph(void) = 0;
};

#endif
