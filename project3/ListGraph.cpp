#include "ListGraph.h"
#include <iostream>
#include <utility>

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_List = new map<int, int> [size]; // memory allocations
    kw_graph = 0;
}

ListGraph::~ListGraph()	
{
	delete[] m_List;
	if (kw_graph)
		delete[] kw_graph; // free memory
}

int ListGraph::getWeight(int from_v, int to_v, char option) // return weight
{
	if (m_List[from_v - 1].find(to_v) != m_List[from_v - 1].end())
		return m_List[from_v - 1].at(to_v); // for digraph
	if (option == 'N') // for undirected graph
	{
		if (m_List[to_v - 1].find(from_v) != m_List[to_v - 1].end())
			return m_List[to_v - 1].at(from_v);
	}
	if (from_v == to_v)
		return 0; // loop
	return 987654321; // disconnected
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m)
{ // Definition of getAdjacentEdges(No Direction == Undirected)
	getIncomingEdges(vertex, m);
	getAdjacentEdgesDirect(vertex, m); // get Outgoing edges
}

void ListGraph::getIncomingEdges(int vertex, map<int, int> *m)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (vertex - 1 == i) // only incoming edges
			continue;
		else
		{
			if (m_List[i].find(vertex) != m_List[i].end())
				m->insert(map<int, int>::value_type(i + 1, (m_List[i].find(vertex))->second));
		}
	}
}

void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)	//Definition of getAdjacentEdges(Directed graph)
{
	m->insert(m_List[vertex - 1].begin(), m_List[vertex - 1].end());
}

void ListGraph::insertEdge(int from, int to, int weight) //Definition of insertEdge
{ // from, to in ListGraph is vertex number(starts with 1)
	m_List[from - 1].insert(map<int, int>::value_type(to, weight));
}

bool ListGraph::printGraph(ofstream *fout)	//Definition of print Graph
{
	if (!(fout->is_open()))
		return false;
	*fout << "========PRINT========" << endl;
	for (int i = 0; i < m_Size; i++)
	{
		*fout << '[' << i + 1 << ']';
		for (auto itr = m_List[i].begin(); itr != m_List[i].end(); itr++)
			*fout << "->" << '(' << itr->first << ',' << itr->second << ')';
		*fout << endl;
	}
	*fout << "=====================" << endl << endl;
	return true;
}

void ListGraph::setKw_graph(void)
{
	map <int, int> m;

	kw_graph = new vector<int>[m_Size + 1];
	for (int i = 1; i < m_Size + 1; i++)
	{
		getAdjacentEdges(i, &m); // delete direction
		for (auto itr = m.begin(); itr != m.end(); itr++)
			kw_graph[i].push_back(itr->first);
		sort(kw_graph[i].begin(), kw_graph[i].end()); // sort by vertex number
		m.clear();
	}
}

int ListGraph::getKw_graph_size(int i) // return kw_graph's size
{
	return kw_graph[i].size();
}

int ListGraph::getKw_graph_node(int i, int idx) // return node number
{
	return kw_graph[i][idx];
}