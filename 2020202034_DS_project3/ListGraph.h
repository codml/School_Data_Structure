#ifndef _LIST_H_
#define _LIST_H_

#include "Graph.h"

class ListGraph : public Graph{	
private:
	map < int, int >* m_List;
	vector<int>* kw_graph; // for KwangWoon

public:	
	ListGraph(bool type, int size);
	~ListGraph();
		
	int getWeight(int from_v, int to_v, char option); // return weight
	void getAdjacentEdges(int vertex, map<int, int>* m, char option); // option 'I' -> incoming
	void getIncomingEdges(int vertex, map<int, int>* m);	
	void getAdjacentEdgesDirect(int vertex, map<int, int>* m);
	void insertEdge(int from, int to, int weight);	
	bool printGraph(ofstream *fout);

	void setKw_graph(void); // set kw_graph
	int getKw_graph_size(int i); // return kw_graph[i].size()
	int getKw_graph_node(int i, int idx); // return kw_graph[i][j]

};

#endif