#include <iostream>
#include <vector>
#include "GraphMethod.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

using namespace std;

bool BFS(Graph* graph, char option, int vertex, ofstream *fout)
{
	queue <int> q;
	bool *visited;
	map <int, int> m;

	if (!graph)
		return false;
	if (vertex < 1 || vertex > graph->getSize())
		return false;
	if (option != 'Y' && option != 'N')
		return false;
	*fout << "========BFS========" << endl;
	visited = new bool[graph->getSize() + 1];
	fill(visited, visited + graph->getSize() + 1, false);
	visited[vertex] = true;
	q.push(vertex);
	switch (option)
	{
		case 'Y':
			*fout << "Directed Graph BFS result" << endl;
			*fout << "startvertex: " << vertex << endl;
			*fout << vertex;
			while (!q.empty())
			{
				vertex = q.front();
				q.pop();
				graph->getAdjacentEdgesDirect(vertex, &m);
				for (auto itr = m.begin(); itr != m.end(); itr++)
				{
					if (!visited[itr->first])
					{
						*fout << "->" << itr->first;
						q.push(itr->first);
						visited[itr->first] = true;
					}
				}
				m.clear();
			}
			break;
		case 'N':
			*fout << "Undirected Graph BFS result" << endl;
			*fout << "startvertex: " << vertex << endl;
			*fout << vertex;
			while (!q.empty())
			{
				vertex = q.front();
				q.pop();
				graph->getAdjacentEdges(vertex, &m);
				for (auto itr = m.begin(); itr != m.end(); itr++)
				{
					if (!visited[itr->first])
					{
						*fout << "->" << itr->first;
						q.push(itr->first);
						visited[itr->first] = true;
					}
				}
				m.clear();
			}
			break;
	}
	*fout << endl << "=====================" << endl << endl;
	delete []visited;
	return true;
}

bool DFS(Graph* graph, char option, int vertex, ofstream *fout)
{
	bool *visited;
	stack <int> s;
	map <int, int> m;

	if (!graph)
		return false;
	if (vertex < 1 || vertex > graph->getSize())
		return false;
	if (option != 'Y' && option != 'N')
		return false;
	*fout << "========DFS========" << endl;
	visited = new bool [graph->getSize() + 1];
	fill(visited, visited + graph->getSize() + 1, false);
	visited[vertex] = true;
	s.push(vertex);
	switch (option)
	{
		case 'Y':
			*fout << "Directed Graph DFS result" << endl;
			*fout << "startvertex: " << vertex << endl;
			*fout << vertex;
			while (!s.empty())
			{
				vertex = s.top();
				s.pop();
				graph->getAdjacentEdgesDirect(vertex, &m);
				for (auto itr = m.begin(); itr != m.end(); itr++)
				{
					if (!visited[itr->first])
					{
						s.push(vertex);
						*fout << "->" << itr->first;
						s.push(itr->first);
						visited[itr->first] = true;
						break;
					}
				}
				m.clear();
			}
			break;
		case 'N':
			*fout << "Undirected Graph DFS result" << endl;
			*fout << "startvertex: " << vertex << endl;
			*fout << vertex;
			while (!s.empty())
			{
				vertex = s.top();
				s.pop();
				graph->getAdjacentEdges(vertex, &m);
				for (auto itr = m.begin(); itr != m.end(); itr++)
				{
					if (!visited[itr->first])
					{
						s.push(vertex);
						*fout << "->" << itr->first;
						s.push(itr->first);
						visited[itr->first] = true;
						break;
					}
				}
				m.clear();
			}
			break;
	}
	*fout << endl << "=====================" << endl << endl;
	delete []visited;
	return true;
}

bool Kruskal(Graph* graph)
{
   
}

bool Dijkstra(Graph* graph, char option, int vertex, ofstream *fout)
{
	map <int, int > temp;
	stack <int> stack;
	int *dist, *parent;
	bool *s;
	int u, dis;

	if (!graph)
		return false;
	if (vertex < 1 || vertex > graph->getSize())
		return false;
	if (option != 'Y' && option != 'N')
		return false;
	s = new bool[graph->getSize() + 1];
	dist = new int[graph->getSize() + 1];
	parent = new int[graph->getSize() + 1];
	fill(s, s + graph->getSize() + 1, false);
	fill(parent, parent + graph->getSize() + 1, -1);
	if (option == 'Y')
		graph->getAdjacentEdgesDirect(vertex, &temp);
	else
		graph->getAdjacentEdges(vertex, &temp);
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
		parent[itr->first] = vertex; // set parent
	for (int i = 1; i <= graph->getSize(); i++)
	{
		if (option == 'Y')
			dist[i] = graph->getWeightDirect(vertex, i);
		else
			dist[i] = graph->getWeight(vertex, i);
	}
	s[vertex] = true;
	dist[vertex] = 0;
	for(int i = 0; i < graph->getSize() - 1; i++)
	{
		dis = INT32_MAX;
		for (int j = 1; j <= graph->getSize(); j++)
		{
			if (!s[j] && dis > dist[j])
			{
				u = j;
				dis = dist[u];
			}
		}
		s[u] = true;
		for (int j = 1; j <= graph->getSize(); j++)
		{
			if (s[j] == false)
			{
				if (option == 'Y')
				{
					if (dist[u] + graph->getWeightDirect(u, j) < dist[j])
					{
						dist[j] = dist[u] + graph->getWeightDirect(u, j);
						parent[j] = u;
					}
				}
				else
				{
					if (dist[u] + graph->getWeight(u, j) < dist[j])
					{
						dist[j] = dist[u] + graph->getWeight(u, j);
						parent[j] = u;
					}
				}
				
			}
		}
	}
	*fout << "========Dijkstra========" << endl;
	if (option == 'Y')
		*fout << "Directed ";
	else
		*fout << "Undirected ";
	*fout << "Graph Dijkstra result" << endl;
	*fout << "startvertex: " << vertex << endl;
	for (int i = 1; i <= graph->getSize(); i++)
	{
		if (i == vertex)
			continue;
		*fout << "[" << i << "] ";
		if (parent[i] > 0)
		{
			*fout << vertex;
			for (int j = i; j != vertex; j = parent[j])
				stack.push(j);
			while (!stack.empty())
			{
				*fout << "->" << stack.top();
				stack.pop();
			}
			*fout << "(" << dist[i] << ")";
		}
		else
			*fout << "x";
		*fout << endl;
	}
	*fout << "=====================" << endl << endl;
	delete [] s;
	delete [] dist;
	delete [] parent;
	return true;
}

bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex) 
{
   
}

bool FLOYD(Graph* graph, char option)
{
   
}

bool KWANGWOON(Graph* graph, int vertex) {

}