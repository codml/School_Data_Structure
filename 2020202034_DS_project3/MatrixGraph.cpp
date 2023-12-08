#include "MatrixGraph.h"
#include <iostream>
#include <vector>
#include <string>

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size)
{
    m_Mat = new int * [size];
    for (int i = 0; i < size; i++)
        m_Mat[i] = new int [size]; // allocation dimension 2 matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            m_Mat[i][j] = 0; // initiate with 0
    }
}

MatrixGraph::~MatrixGraph()
{
    for (int i = 0; i < m_Size; i++)
        delete[] m_Mat[i];
    delete[] m_Mat; // free memory
}

int MatrixGraph::getWeight(int from_v, int to_v, char option)
{
	if (m_Mat[from_v - 1][to_v - 1])
		return m_Mat[from_v - 1][to_v - 1]; // for digraph
	if (option == 'N') // for undirected graph
	{
		if (m_Mat[to_v - 1][from_v - 1])
        	return m_Mat[to_v - 1][from_v - 1];
	}
	if (from_v == to_v)
		return 0;
	return 987654321; // inf
}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int>* m)
{	
    getIncomingEdges(vertex, m); // get incoming edges
    getAdjacentEdgesDirect(vertex, m); // get Outgoing edges
}

void MatrixGraph::getIncomingEdges(int vertex, map<int, int>* m)
{
    for (int i = 0; i < m_Size; i++)
    {
        if (m_Mat[i][vertex - 1]) // connection exists
            m->insert(map<int, int>::value_type(i + 1, m_Mat[vertex - 1][i]));
    }
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)
{
	for (int i = 0; i < m_Size; i++)
    {
        if (m_Mat[vertex - 1][i]) // connection exist
            m->insert(map<int, int>::value_type(i + 1, m_Mat[vertex - 1][i]));
    }
}

void MatrixGraph::insertEdge(int from, int to, int weight)	
{
	m_Mat[from][to] = weight; // return weight
}

bool MatrixGraph::printGraph(ofstream *fout)	
{
    if (!(fout->is_open()))
        return false;
	*fout << "========PRINT========" << endl;
    *fout << "    ";
    for (int i = 0; i < m_Size; i++)
        *fout << "    " << '[' << i + 1 << ']';
    *fout << endl;
    for (int i = 0; i < m_Size; i++)
    {
        *fout << '[' << i + 1 << "] ";
        for (int j = 0; j < m_Size; j++)
        {
            fout->width(6); // set format(-99999~999999 will be in format)
            fout->fill(' ');
            *fout << m_Mat[i][j];
            *fout << ' ';
        }
        *fout << endl;
    }
    *fout << "=====================" << endl << endl;
    return true;
}

void MatrixGraph::setKw_graph() // None
{
    
}

int MatrixGraph::getKw_graph_size(int i)
{

}

int MatrixGraph::getKw_graph_node(int i, int idx)
{

}
