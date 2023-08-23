#include "mytree.h"

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
}

template <class T>
Node<T>::~Node()
{
	std::cout << "Node " << data << " is deleted\n"; 
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

void ExpressionTree::PostOrder_del(Node<int> *node)
{
	if (node)
	{
		PostOrder_del(node->getLeft());
		PostOrder_del(node->getRight());
		delete node;
	}
}

int ExpressionTree::PostOrder_op(Node<int> *node)
{
	int left, right;
	int op;

	if (node)
	{
		left = PostOrder_op(node->getLeft());
		right = PostOrder_op(node->getRight());
		if (node->getLeft())
		{
			op = node->getData();
			switch (op)
			{
				case '+':
					return left + right;
				case '-':
					return left - right;
				case '*':
					return left * right;
				case '/':
					return left / right;
			}
		}
		return node->getData();
	}
	return (0);
}

ExpressionTree::ExpressionTree()
{
	root = 0;
}

ExpressionTree::~ExpressionTree()
{
	PostOrder_del(root);
}

void	ExpressionTree::makeTree()
{
	int						num, ctrl;
	char					ch;
	Node<int>				*node;
	std::stack<Node<int> *>	stack;

	while (true)
	{
		std::cout << "choose input(break: -1, int: 0, op: 1)" << std::endl;
		std::cin >> ctrl;
		if (ctrl == -1)
			break;
		if (ctrl == 0)
			std::cin >> num;
		else if (ctrl == 1)
		{
			std::cin >> ch;
			num = (int)ch;
		}
		else
			continue;
		node = new Node<int>(num);
		if (num < 42 || num > 47)
			stack.push(node);
		else
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
	return PostOrder_op(root);
}
