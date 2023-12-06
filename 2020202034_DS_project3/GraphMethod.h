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
bool KWANGWOON(Graph* graph, int vertex, ofstream *fout);
bool Kruskal(Graph* graph, ofstream *fout);
bool Dijkstra(Graph* graph, char option, int vertex, ofstream *fout);    //Dijkstra
bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex, ofstream *fout); //Bellman - Ford
bool FLOYD(Graph* graph, char option, ofstream *fout);   //FLoyd

int init(int node, int start, int end, vector<int> &_seg); // for segment tree
void update(int node, int start, int end, int target, int diff_value, vector<int>& _seg);
int sum(int node, int start, int end, int left, int right, vector<int>& _seg);

#endif
