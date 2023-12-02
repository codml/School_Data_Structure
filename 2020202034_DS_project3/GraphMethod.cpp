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
	if (option == 'Y')
		*fout << "Directed ";
	else
		*fout << "Undirected ";
	*fout << "Graph BFS result" << endl;
	*fout << "startvertex: " << vertex << endl;
	*fout << vertex;
	while (!q.empty())
	{
		vertex = q.front();
		q.pop();
		graph->getAdjacentEdges(vertex, &m, option);
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
	if (option == 'Y')
		*fout << "Directed ";
	else
		*fout << "Undirected ";
	*fout << "Graph DFS result" << endl;
	*fout << "startvertex: " << vertex << endl;
	*fout << vertex;
	while (!s.empty())
	{
		vertex = s.top();
		s.pop();
		graph->getAdjacentEdges(vertex, &m, option);
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
	if (graph->getNeg())
		return false;
	s = new bool[graph->getSize() + 1];
	dist = new int[graph->getSize() + 1];
	parent = new int[graph->getSize() + 1];
	fill(s, s + graph->getSize() + 1, false);
	fill(parent, parent + graph->getSize() + 1, -1);
	graph->getAdjacentEdges(vertex, &temp, option);
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
		parent[itr->first] = vertex; // set parent
	for (int i = 1; i <= graph->getSize(); i++)
		dist[i] = graph->getWeight(vertex, i, option);
	s[vertex] = true;
	dist[vertex] = 0;
	for(int i = 0; i < graph->getSize() - 1; i++)
	{
		dis = 2147483647;
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
				if (dist[u] + graph->getWeight(u, j, option) < dist[j])
				{
					dist[j] = dist[u] + graph->getWeight(u, j, option);
					parent[j] = u;
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

bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex, ofstream *fout) 
{
	int *dist;
	int *parent;
	map <int, int> temp;
	stack <int> stack;

	if (!graph)
		return false;
	if (s_vertex < 1 || s_vertex > graph->getSize()
		|| e_vertex < 1 || e_vertex > graph->getSize())
		return false;
	if (option != 'Y' && option != 'N')
		return false;
	dist = new int [graph->getSize() + 1];
	parent = new int [graph->getSize() + 1];
	fill(parent, parent + graph->getSize() + 1, -1);
	graph->getAdjacentEdges(s_vertex, &temp, option);
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
		parent[itr->first] = s_vertex;
	for (int i = 1; i <= graph->getSize(); i++)
		dist[i] = graph->getWeight(s_vertex, i, option);
	for (int i = 2; i < graph->getSize(); i++)
	{
		for (int j = 1; j <= graph->getSize(); j++)
		{
			temp.clear();
			graph->getAdjacentEdges(j, &temp, 'I');
			if (j == s_vertex || temp.empty())
				continue;
			for (int k = 1; k <= graph->getSize(); k++)
			{
				if (dist[k] + graph->getWeight(k, j, option) < dist[j])
				{
					dist[j] = dist[k] + graph->getWeight(k, j, option);
					parent[j] = k;
				}
			}
		}
	}
	for (int j = 1; j <= graph->getSize(); j++)
	{
		temp.clear();
		graph->getAdjacentEdges(j, &temp, 'I');
		if (j == s_vertex || temp.empty())
			continue;
		for (int k = 1; k <= graph->getSize(); k++)
		{
			if (dist[k] + graph->getWeight(k, j, option) < dist[j])
			{
				delete [] dist;
				delete [] parent;
				return false;
			}
		}
	}
	*fout << "========Bellman-Ford========" << endl;
	if (option == 'Y')
		*fout << "Directed ";
	else
		*fout << "Undirected ";
	*fout << "Graph Bellman-Ford result" << endl;
	for (int i = e_vertex; i > 0; i = parent[i])
		stack.push(i);
	if (stack.empty() || stack.top() != s_vertex)
		*fout << 'x' << endl;
	else
	{
		*fout << stack.top();
		stack.pop();
		while (!stack.empty())
		{
			*fout << "->" << stack.top();
			stack.pop();
		}
		*fout << endl << "cost: " << dist[e_vertex] << endl;
	}
	*fout << "=====================" << endl << endl;
	delete [] dist;
	delete [] parent;
	return true;
}

bool FLOYD(Graph* graph, char option, ofstream *fout)
{
	int **dist;
	map <int, int> temp;
	stack <int> stack;

	if (!graph)
		return false;
	if (option != 'Y' && option != 'N')
		return false;
	dist = new int *[graph->getSize() + 1];
	for (int i = 1; i < graph->getSize() + 1; i++)
		dist[i] = new int [graph->getSize() + 1];
	for (int i = 1; i < graph->getSize() + 1; i++)
	{
		for (int j = 1; j < graph->getSize() + 1; j++)
			dist[i][j] = graph->getWeight(i, j, option);
	}
	for (int k = 1; k <= graph->getSize(); k++)
	{
		for (int i = 1; i <= graph->getSize(); i++)
		{
			for (int j = 1; j <= graph->getSize(); j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	for (int i = 1; i < graph->getSize() + 1; i++)
	{
		if (dist[i][i] < 0)
		{
			for (int i = 1; i < graph->getSize() + 1; i++)
       			delete[] dist[i];
    		delete[] dist;
			return false;
		}
	}
	*fout << "========FLOYD========" << endl;
	if (option == 'Y')
		*fout << "Directed ";
	else
		*fout << "Undirected ";
	*fout << "Graph FLOYD result" << endl;
	*fout << "    ";
    for (int i = 1; i < graph->getSize() + 1; i++)
        *fout << '[' << i << "] ";
    *fout << endl;
    for (int i = 1; i < graph->getSize() + 1; i++)
    {
        *fout << '[' << i << "] ";
        for (int j = 1; j < graph->getSize() + 1; j++)
        {
            fout->width(3);
            fout->fill(' ');
			if (dist[i][j] > 500000000) // need to fix
				*fout << 'x';
			else
            	*fout << dist[i][j];
            *fout << ' ';
        }
        *fout << endl;
    }
    *fout << "=====================" << endl << endl;
	for (int i = 1; i < graph->getSize() + 1; i++)
        delete[] dist[i];
    delete[] dist;
	return true;
}

bool KWANGWOON(Graph* graph, int vertex) {

}