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
	int						i;
	char					str[1024];
	Node<int>				*node;
	std::stack<char> 		a;
	std::stack<Node<int> *>	b;

	std::cout << "Write expression: ";
	std::cin >> str;
	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			node = new Node<int>(atoi(str + i));
			b.push(node);
			while (isdigit(str[i++]));
		}
		else
		{
			switch (str[i])
			{
			case '(':
				a.push(str[i]);
				break;
			case ')':
				while (!a.empty() && a.top() != '(')
				{
					node = new Node<int>(a.top());
					a.pop();
					node->setRight(b.top());
					b.pop();
					node->setLeft(b.top());
					b.pop();
					b.push(node);
				}
				if (!a.empty() && a.top() == '(')
					a.pop();
				break;
			case '+':
			case '-':
				while (!a.empty() && a.top() != '(')
				{
					node = new Node<int>(a.top());
					a.pop();
					node->setRight(b.top());
					b.pop();
					node->setLeft(b.top());
					b.pop();
					b.push(node);
				}
				a.push(str[i]);
				break;
			case '*':
			case '/':
				while (!a.empty() && (a.top() == '*' || a.top() == '/'))
				{
					node = new Node<int>(a.top());
					a.pop();
					node->setRight(b.top());
					b.pop();
					node->setLeft(b.top());
					b.pop();
					b.push(node);
				}
				a.push(str[i]);
				break;
			}
			i++;
		}
	}
	while (!a.empty())
	{
		node = new Node<int>(a.top());
		a.pop();
		node->setRight(b.top());
		b.pop();
		node->setLeft(b.top());
		b.pop();
		b.push(node);
	}
	root = node;
}

int		ExpressionTree::doOp()
{
	return PostOrder_op(root);
}
