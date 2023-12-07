#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <map>
#include "Graph.h"

class MatrixGraph : public Graph{	
private:
	int** m_Mat;

public:
	MatrixGraph(bool type, int size);
	~MatrixGraph();
		
	int getWeight(int from_v, int to_v, char option);
	void getAdjacentEdges(int vertex, map<int, int>* m, char option);
	void getIncomingEdges(int vertex, map<int, int>* m);
	void getAdjacentEdgesDirect(int vertex, map<int, int>* m);
	void insertEdge(int from, int to, int weight);
	bool printGraph(ofstream *fout);

	void setKw_graph();
	int getKw_graph_size(int i);
	int getKw_graph_node(int i, int idx);
};

#endif