#ifndef _LIST_H_
#define _LIST_H_

#include "Graph.h"

class ListGraph : public Graph{	
private:
	map < int, int >* m_List;
	vector<int>* kw_graph;

public:	
	ListGraph(bool type, int size);
	~ListGraph();
		
	int getWeight(int from_v, int to_v, char option);
	void getAdjacentEdges(int vertex, map<int, int>* m, char option);
	void getIncomingEdges(int vertex, map<int, int>* m);	
	void getAdjacentEdgesDirect(int vertex, map<int, int>* m);
	void insertEdge(int from, int to, int weight);	
	bool printGraph(ofstream *fout);

	void setKw_graph(void);
	void getKw_graph(vector<int> &v, int i);

};

#endif