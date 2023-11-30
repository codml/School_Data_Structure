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

bool Dijkstra(Graph* graph, char option, int vertex)
{
	map <int, int > temp;
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
	for (int i = 1; i < graph->getSize(); i++)
	{
		// parent initialization
	}
	for (int i = 1; i <= graph->getSize(); i++)
		dist[i] = graph->getWeight(vertex, i); // need to consider Undirected
	s[vertex] = true;
	dist[vertex] = 0;
	for(int i = 0; i < graph->getSize() - 1; i++)
	{
		dis = -1;
		for (int j = 1; j <= graph->getSize(); j++)
		{
			if (!s[j] && (dis < 0 || dis > dist[j]))
			{
				u = j;
				dis = dist[u];
			}		
		}
		s[u] = true;
		for (int j = 1; j <= graph->getSize(); j++)
		{
			if (s[j] == false)
				dist[j] = min(dist[u] + graph->getWeight(u, j), dist[j]);
		}
	}
	for (int i = 1; i <= graph->getSize(); i++)
		cout << dist[i] << endl;
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