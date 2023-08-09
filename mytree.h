#ifndef MY_TREE_H
# define MY_TREE_H

# include <stack>
# include <iostream>

template <class T>
class Node
{
private:
	T data;
	Node *left;
	Node *right;

public:
	Node(T data);

	void	setData(T data);
	T		getData();
	void	setLeft(Node *node);
	Node<T>	*getLeft();
	void	setRight(Node *node);
	Node<T>	*getRight();
};

class ExpressionTree
{
	private:
		Node<int> *root;
		
	public:
		ExpressionTree();
		~ExpressionTree();

		void	makeTree();
		int		doOp();
};

#endif