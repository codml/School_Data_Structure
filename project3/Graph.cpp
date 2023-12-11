#include "Graph.h"

Graph::Graph(bool type, int size)
{
	m_Type = type;
	m_Size = size;
	m_Neg = false; // default = false
}

Graph::~Graph()	
{

}

bool Graph::getNeg(){return m_Neg;}
void Graph::setNeg(bool tf){m_Neg = tf;}
bool Graph::getType(){return m_Type;}	
int Graph::getSize(){return m_Size;}
