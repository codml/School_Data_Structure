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
		
	int getWeight(int from_v, int to_v);
	int getWeightDirect(int from_v, int to_v);
	void getAdjacentEdges(int vertex, map<int, int>* m);
	void getAdjacentEdgesDirect(int vertex, map<int, int>* m);
	void insertEdge(int from, int to, int weight);
	bool printGraph(ofstream *fout);
};

#endif