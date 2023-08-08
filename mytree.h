#ifndef MY_TREE_H
# define MY_TREE_H

/*
template <class T>
class Node
{
private:
	T data;
	Node *left;
	Node *right;

public:
	Node(T data);
	virtual ~Node();

	void	setData(T data);
	T		getData();
	void	setLeft(Node *node);
	virtual Node<T>	*getLeft();
	void	setRight(Node *node);
	virtual Node<T>	*getRight();
};
*/

class OpNode
{
	private:
		char 	op;
		OpNode	*left;
		OpNode	*right;
		int 	leftNum;
		int 	rightNum;
		int		numOp(char op, int num1, int num2);

	public:
		OpNode(char op);
		OpNode(char op, int left, int right);
		~OpNode();

		void	setOp(char op);
		char	getOp();
		void	setLeft(OpNode *node);
		OpNode	*getLeft();
		void	setRight(OpNode *node);
		OpNode	*getRight();
		void	setLeftNum();
		int		getLeftNum();
		void	setRightNum();
		int		getRightNum();
		int		getExp(void);
};

class ExprissionTree
{
	private:
		OpNode root;
};
#endif