#ifndef MY_TREE_H
# define MY_TREE_H

template <class T>
class Node
{
private:
	T data;
	Node *left;
	Node *right;

public:
	Node(T data);
	~Node();

	void		setData(T data);
	T			getData();
	void		setLeft(Node *node);
	Node<T>	*getLeft();
	void		setRight(Node *node);
	Node<T>	*getRight();
};

#endif