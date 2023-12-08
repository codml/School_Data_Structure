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
	queue <int> q; // BFS uses queue
	bool *visited; // visit or not
	map <int, int> m;

	if (!graph)
		return false;
	if (vertex < 1 || vertex > graph->getSize())
		return false;
	if (option != 'Y' && option != 'N')
		return false;
	*fout << "========BFS========" << endl;
	visited = new bool[graph->getSize() + 1];
	fill(visited, visited + graph->getSize() + 1, false); // initiate visited
	visited[vertex] = true;
	q.push(vertex); // visit start and push to queue
	if (option == 'Y')
		*fout << "Directed ";
	else
		*fout << "Undirected ";
	*fout << "Graph BFS result" << endl;
	*fout << "startvertex: " << vertex << endl;
	*fout << vertex;
	while (!q.empty()) // repeat until queue empty
	{
		vertex = q.front();
		q.pop(); // pop vertex from queue
		if (option == 'Y')
			graph->getAdjacentEdgesDirect(vertex, &m);
		else
			graph->getAdjacentEdges(vertex, &m); // collect incident edges
		for (auto itr = m.begin(); itr != m.end(); itr++)
		{
			if (!visited[itr->first]) // if not visit
			{
				*fout << "->" << itr->first;
				q.push(itr->first);
				visited[itr->first] = true; // visit and push to queue
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
	fill(visited, visited + graph->getSize() + 1, false); // initiate visited
	visited[vertex] = true;
	s.push(vertex); // visit start and push to stack
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
		s.pop(); // pop vertex from stack
		if (option == 'Y')
			graph->getAdjacentEdgesDirect(vertex, &m);
		else
			graph->getAdjacentEdges(vertex, &m);
		for (auto itr = m.begin(); itr != m.end(); itr++)
		{
			if (!visited[itr->first])
			{
				s.push(vertex); // push back before vertex to stack
				*fout << "->" << itr->first;
				s.push(itr->first);
				visited[itr->first] = true; // visit and push vertex to stack
				break;
			}
		}
		m.clear();
	}
	*fout << endl << "=====================" << endl << endl;
	delete []visited;
	return true;
}

void Union(int *parent, int i, int j)
{
	parent[i] = j; // union two tree
}

int Find(int *parent, int i)
{
	while (parent[i] > 0) // until meet i's root
		i = parent[i];
	return i;
}

void insertionSort(vector <pair<int, pair <int, int> > > &v, int low, int high)
{
	int i, j;
	pair <int, pair <int, int> > key;

	for (i = low + 1; i <= high; i++)
	{
		key = v[i]; // value that will be inserted
		for (j = i - 1; j >= 0 && v[j].first < key.first; j--)
			v[j + 1] = v[j]; // push values until find place to push key
		v[j + 1] = key; // push key
	}
}

int partition(vector <pair<int, pair <int, int> > > &v, int low, int high)
{
	int i = low;
	int j = high + 1;
	int pivot = v[low].first;

	do {
		do i++; while (v[i].first > pivot); // left from pivot > pivot
		do j--; while (v[j].first < pivot); // right from pivot < pivot
		if (i < j) swap(v[i], v[j]); // descending order
	} while (i < j);
	swap(v[low], v[j]);
	return j; // return pivot index
}

void quickSort(vector <pair<int, pair <int, int> > > &v, int low, int high)
{
	int pivot;

	if (low < high)
	{
		if (high-low+1 <= 6) // array size less than 7
			insertionSort(v, low, high); // sort it by insertion sort
		else
		{
			pivot = partition(v, low, high); // split by two array(< pivot, > pivot)
			quickSort(v, low, pivot - 1);
			quickSort(v, pivot + 1, high); // split by recursion
		}
	}
}

bool Kruskal(Graph* graph, ofstream *fout)
{
	int *parent;
	int weight, v, w, t_size, cost;
	vector <pair <int , pair <int, int > > > E;
	pair <int, pair <int, int> > edge;
	map <int, int> temp;
	map <int, int> *T;

	if (!graph)
		return false;
	parent = new int [graph->getSize() + 1]; // for union set
	fill(parent, parent + graph->getSize() + 1, -1); // initiate
	T = new map<int, int> [graph->getSize() + 1];
	for (int i = 1; i <= graph->getSize(); i++)
	{
		graph->getAdjacentEdgesDirect(i, &temp);
		for (auto itr = temp.begin(); itr != temp.end(); itr++)
			E.push_back(make_pair(itr->second, make_pair(i, itr->first)));
		temp.clear(); // add all edges to E
	}
	quickSort(E, 0, E.size() - 1); // sort E by weight(descending order)
	t_size = 0;
	cost = 0;
	while (t_size < graph->getSize() - 1 && !E.empty())
	{
		edge = *E.rbegin(); // smallest weight edge in E
		v = edge.second.first;
		w = edge.second.second;
		weight = edge.first;
		E.pop_back(); // delete edge from E
		if (Find(parent, v) != Find(parent, w)) // v, w are not in same group
		{
			Union(parent, Find(parent, v), Find(parent, w)); // union groups
			T[v].insert(map<int, int>::value_type(w, weight));
			T[w].insert(map<int, int>::value_type(v, weight)); // add edge to T
			t_size++;
			cost += weight; // MST total cost
		}
	}
	if (t_size < graph->getSize() - 1) // MST didn't be made
	{
		delete []parent;
		delete []T;
		return false;
	}
	*fout << "========Kruskal========" << endl;
	for (int i = 1; i <= graph->getSize(); i++)
	{
		if (T[i].empty()) // no edge that is incident to vertex i
			continue;
		*fout << '[' << i << ']' << '\t';
		for (auto itr = T[i].begin(); itr != T[i].end(); itr++)
			*fout << itr->first << '(' << itr->second << ')';
		*fout << endl;
	}
	*fout << "cost: " << cost << endl; // print total cost
	*fout << "=====================" << endl << endl;
	delete []parent;
	delete []T; // memory free
	return true;
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
	fill(s, s + graph->getSize() + 1, false); // set s
	fill(parent, parent + graph->getSize() + 1, -1);
	if (option == 'Y')
		graph->getAdjacentEdgesDirect(vertex, &temp);
	else
		graph->getAdjacentEdges(vertex, &temp);
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
		parent[itr->first] = vertex; // set parent
	parent[vertex] = -1;
	for (int i = 1; i <= graph->getSize(); i++)
		dist[i] = graph->getWeight(vertex, i, option); // set dist(length from start)
	s[vertex] = true; // visit start vertex
	dist[vertex] = 0;
	for(int i = 0; i < graph->getSize() - 1; i++)
	{
		dis = INT32_MAX; // int max
		for (int j = 1; j <= graph->getSize(); j++)
		{
			if (!s[j] && dis > dist[j]) // unvisit j vertex and dist[j] are min
			{
				u = j;
				dis = dist[u]; // update u, dis
			}
		}
		s[u] = true; // visit u
		for (int j = 1; j <= graph->getSize(); j++)
		{
			if (s[j] == false)
			{
				if (dist[u] + graph->getWeight(u, j, option) < dist[j])
				{
					dist[j] = dist[u] + graph->getWeight(u, j, option);
					parent[j] = u; // parent update
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
		if (i == vertex) // ignore vertex
			continue;
		*fout << "[" << i << "] ";
		for (int j = i; j > 0; j = parent[j])
			stack.push(j); // push from end vertex to start vertex
		if (stack.empty() || stack.top() != vertex) // disconnect
			*fout << 'x';
		else
		{
			*fout << stack.top();
			stack.pop(); // pop from stack = start vertex
			while (!stack.empty())
			{
				*fout << "->" << stack.top(); // pop until meet end vertex
				stack.pop(); // print path
			}
			*fout << "(" << dist[i] << ")";
		}
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
	if (option == 'Y')
		graph->getAdjacentEdgesDirect(s_vertex, &temp);
	else
		graph->getAdjacentEdges(s_vertex, &temp);
	for (auto itr = temp.begin(); itr != temp.end(); itr++)
		parent[itr->first] = s_vertex;
	parent[s_vertex] = -1; // initiate parent
	for (int i = 1; i <= graph->getSize(); i++)
		dist[i] = graph->getWeight(s_vertex, i, option); // initiate dist
	for (int i = 2; i < graph->getSize(); i++)
	{
		for (int j = 1; j <= graph->getSize(); j++)
		{
			temp.clear();
			if (option == 'N')
				graph->getAdjacentEdges(j, &temp);
			else
				graph->getIncomingEdges(j, &temp);
			if (j == s_vertex || temp.empty()) // j has incoming edges
				continue;
			for (int k = 1; k <= graph->getSize(); k++)
			{
				if (dist[k] + graph->getWeight(k, j, option) < dist[j]) // dist update
				{
					dist[j] = dist[k] + graph->getWeight(k, j, option);
					parent[j] = k; // parent update
				}
			}
		}
	}
	for (int j = 1; j <= graph->getSize(); j++) // check negative cycle
	{
		temp.clear();
		if (option == 'N')
			graph->getAdjacentEdges(j, &temp);
		else
			graph->getIncomingEdges(j, &temp);
		if (j == s_vertex || temp.empty())
			continue;
		for (int k = 1; k <= graph->getSize(); k++)
		{
			if (dist[k] + graph->getWeight(k, j, option) < dist[j]) // dist update
			{ // -> have negative cycle
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
	for (int i = e_vertex; i > 0; i = parent[i]) // loop until meet -1
		stack.push(i);
	if (stack.empty() || stack.top() != s_vertex) // no path from s_vertex
		*fout << 'x' << endl;
	else
	{
		*fout << stack.top();
		stack.pop(); // pop s_vertex, print
		while (!stack.empty()) // pop until pop e_vertex
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
	stack <int> stack; // no parent array: if make it, it should be 2 dimension array

	if (!graph || (option != 'Y' && option != 'N'))
		return false;
	dist = new int *[graph->getSize() + 1];
	for (int i = 1; i < graph->getSize() + 1; i++)
		dist[i] = new int [graph->getSize() + 1];
	for (int i = 1; i < graph->getSize() + 1; i++)
	{
		for (int j = 1; j < graph->getSize() + 1; j++)
			dist[i][j] = graph->getWeight(i, j, option); // initiate dist
	}
	for (int k = 1; k <= graph->getSize(); k++) // usable vertex number
	{
		for (int i = 1; i <= graph->getSize(); i++)
		{
			for (int j = 1; j <= graph->getSize(); j++)
			{
				if (dist[i][k] != 987654321 && dist[k][j] != 987654321) // if connect
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // update dist[i][j]
			}
		}
	}
	for (int i = 1; i < graph->getSize() + 1; i++) // check negative cycle
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
		*fout << "    " << '[' << i << ']';
    *fout << endl;
    for (int i = 1; i < graph->getSize() + 1; i++)
    {
        *fout << '[' << i << "] ";
        for (int j = 1; j < graph->getSize() + 1; j++)
        {
            fout->width(6); // set format
            fout->fill(' ');
			if (dist[i][j] >= 987654321) // inf: disconnect
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
    delete[] dist; // free memory
	return true;
}

int init(int node, int start, int end, vector<int> &_seg) {
	if (start == end) return _seg[node] = 1; // leaf node
	int mid = (start + end) / 2;
	init(node * 2, start, mid, _seg);
	init(node * 2 + 1, mid + 1, end, _seg); // recursive to left, right child
	_seg[node] = _seg[node * 2] + _seg[node * 2 + 1]; // sum of left, right child
}

void update(int node, int start, int end, int target, int diff_value, vector<int>& _seg) {
	if (target < start || target > end) return; // out of range
	
	_seg[node] += diff_value; // update value

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, target, diff_value, _seg); // left child
		update(node * 2 + 1, mid + 1, end, target, diff_value,_seg); // right child
	}
}

int sum(int node, int start, int end, int left, int right, vector<int>& _seg) {
	if (left > end || right < start) return 0; // out of range

	if (left <= start && end <= right) return _seg[node]; // in range

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right, _seg) + sum(node * 2 + 1, mid + 1, end, left, right, _seg);
} // recursive

bool KWANGWOON(Graph* graph, int vertex, ofstream *fout) { // vertex must be 1
	vector<int> *segment_tree;
	int num, before_vertex, update_vertex;

	if (!graph || graph->getType() || vertex != 1)
		return false; // only in ListGraph and vertex 1
	segment_tree = new vector<int> [graph->getSize() + 1];
	for (int i = 1; i < graph->getSize() + 1; i++)
	{
		segment_tree[i].resize(graph->getKw_graph_size(i) * 4);
		init(1, 0, graph->getKw_graph_size(i) - 1, segment_tree[i]);
	} // initiate segment tree
	*fout << "========KWANGWOON========" << endl;
	*fout << "startvertex: " << vertex << endl;
	*fout << vertex;
	while (num = sum(1, 0, graph->getKw_graph_size(vertex) - 1, 0, graph->getKw_graph_size(vertex) - 1, 
		segment_tree[vertex])) // there is a way to go
	{
		before_vertex = vertex;
		if (num % 2) // biggest vertex
		{
			for (int i = graph->getKw_graph_size(vertex) - 1; i >= 0; i--)
			{
				if (sum(1, 0, graph->getKw_graph_size(vertex) - 1, i, i, segment_tree[vertex]))
				{
					vertex = graph->getKw_graph_node(vertex, i);
					break;
				}
			}
		}
		else // smallest vertex
		{
			for (int i = 0; i < graph->getKw_graph_size(vertex); i++)
			{
				if (sum(1, 0, graph->getKw_graph_size(vertex) - 1, i, i, segment_tree[vertex]))
				{
					vertex = graph->getKw_graph_node(vertex, i);
					break;
				}
			}
		}
		*fout << "->" << vertex;
		for (int i = 0; i < graph->getKw_graph_size(before_vertex); i++) // disconnect from before_vertex
		{
			update_vertex = graph->getKw_graph_node(before_vertex, i);
			for (int j = 0; j < graph->getKw_graph_size(update_vertex); j++)
			{
				if (graph->getKw_graph_node(update_vertex, j) == before_vertex)
				{
					update(1, 0, graph->getKw_graph_size(update_vertex) - 1, j, -1, segment_tree[update_vertex]);
					break; // update by -1 to make 1 -> 0
				}
			}
		}
	}
	*fout << endl << "=====================" << endl << endl;
	delete [] segment_tree;
	return true;
}