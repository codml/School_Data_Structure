#ifndef _GRAPHMETHOD_H_
#define _GRAPHMETHOD_H_

#include "ListGraph.h"
#include "MatrixGraph.h"

void Union(int *parent, int i, int j);
int Find(int *parent, int i);
void insertionSort(vector <pair<int, pair <int, int> > > &v, int low, int high);
int partition(vector <pair<int, pair <int, int> > > &v, int low, int high);
void quickSort(vector <pair<int, pair <int, int> > > &v, int low, int high);

bool BFS(Graph* graph, char option, int vertex, ofstream *fout);     
bool DFS(Graph* graph, char option,  int vertex, ofstream *fout);     
bool KWANGWOON(Graph* graph, int vertex);  
bool Kruskal(Graph* graph, ofstream *fout);
bool Dijkstra(Graph* graph, char option, int vertex, ofstream *fout);    //Dijkstra
bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex, ofstream *fout); //Bellman - Ford
bool FLOYD(Graph* graph, char option, ofstream *fout);   //FLoyd

#endif
