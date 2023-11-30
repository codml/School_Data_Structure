#include "ListGraph.h"
#include <iostream>
#include <utility>

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_List = new map<int, int> [size];
    kw_graph = 0;
}

ListGraph::~ListGraph()	
{
	delete[] m_List;
}

int ListGraph::getWeight(int from_v, int to_v)
{
	if (m_List[from_v - 1].find(to_v) != m_List[from_v - 1].end())
		return m_List[from_v - 1].at(to_v);
	else if (m_List[to_v - 1].find(from_v) != m_List[to_v - 1].end())
		return m_List[to_v - 1].at(from_v);
	else
		return 987654321;
}

int ListGraph::getWeightDirect(int from_v, int to_v)
{
	if (m_List[from_v - 1].find(to_v) != m_List[from_v - 1].end())
		return m_List[from_v - 1].at(to_v);
	else
		return 987654321;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m)	 //Definition of getAdjacentEdges(No Direction == Undirected)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (vertex - 1 == i)
			m->insert(m_List[i].begin(), m_List[i].end());
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