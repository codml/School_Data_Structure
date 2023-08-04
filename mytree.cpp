#include "mytree.h"

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->left = 0;
    this->right = 0;
}

template <class T>
Node<T>::~Node()
{
	data = 0;
}

template <class T>
void	Node<T>::setData(T data)
{
	this->data = data;
}

template <class T>
T		Node<T>::getData()
{
	return data;
}

template <class T>
void	Node<T>::setLeft(Node *node)
{
	this->left = node;
}

template <class T>
Node<T>*	Node<T>::getLeft()
{
	return (left);
}

template <class T>
void	Node<T>::setRight(Node *node)
{
	this->right = node;
}

template <class T>
Node<T>*	Node<T>::getRight()
{
	return (right);
}