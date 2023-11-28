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
	delete m_List;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m)	 //Definition of getAdjacentEdges(No Direction == Undirected)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (vertex - 1 == i)
			m->insert(m_List[i].begin(), m_List[i].end());
		else
		{
			if (m_List[i].at(vertex - 1))
				m->insert(map<int, int>::value_type(i + 1, m_List[i].at(vertex - 1)));
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
			*fout << "->" << '(' << itr->first + 1 << ',' << itr->second << ')';
		*fout << endl;
	}
	*fout << "=====================" << endl;
}