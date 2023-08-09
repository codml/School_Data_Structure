#include "mytree.h"

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
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
	left = node;
}

template <class T>
Node<T>* Node<T>::getLeft()
{
	return left;
}

template <class T>
void	Node<T>::setRight(Node *node)
{
	right = node;
}

template <class T>
Node<T>* Node<T>::getRight()
{
	return right;
}

ExpressionTree::ExpressionTree()
{
	root = 0;
}

ExpressionTree::~ExpressionTree()
{

}

void	ExpressionTree::makeTree()
{
	int						num, ctrl;
	Node<int>				*node;
	std::stack<Node<int> *>	stack;

	while (true)
	{
		std::cout << "choose input(0: break, 1: int, 2: op)\n";
		std::cin >> ctrl;
		if (ctrl == 0)
			break;
		std::cin >> num;
		node = new Node<int>(num);
		if (ctrl == 1)
			stack.push(node);
		else if (ctrl == 2)
		{
			node->setRight(stack.top());
			stack.pop();
			node->setLeft(stack.top());
			stack.pop();
			stack.push(node);
		}
	}
	root = node;
}

int		ExpressionTree::doOp()
{
	
}
