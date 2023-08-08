#include "mytree.h"

int		OpNode::numOp(char op, int num1, int num2)
{
	if (op == '+')
		return num1 + num2;
	else if (op == '-')
		return num1 - num2;
	else if (op == '*')
		return num1 * num2;
	else
	{
		if (num2 == 0)
		{
			throw "can't devide by zero";
			return 0;
		}
		else
			return num1 / num2;
	}
}

OpNode::OpNode(char op)
{
	this->op = op;
	left = 0;
	right = 0;
	leftNum = 0;
	rightNum = 0;
}

OpNode::OpNode(char op, int left, int right)
{
	this->op = op;
	this->leftNum = left;
	this->rightNum = right;
	left = 0;
	right = 0;
}

void	OpNode::setOp(char op)
{
	this->op = op;
}

char	OpNode::getOp()
{
	return op;
}

void	OpNode::setLeft(OpNode *node)
{
	left = node;
}

OpNode*	OpNode::getLeft()
{
	return left;
}

void	OpNode::setRight(OpNode *node)
{
	right = node;
}

OpNode*	OpNode::getRight()
{
	return right;
}

void	OpNode::setLeftNum()
{
	if (left)
		numOp(left->getOp(), left->getLeftNum(), left->getRightNum());
}

int		OpNode::getLeftNum()
{
	return leftNum;
}

void	OpNode::setRightNum()
{
	if (right)
		numOp(right->getOp(), right->getLeftNum(), right->getRightNum());
}

int		OpNode::getRightNum()
{
	return rightNum;
}

int		OpNode::getExp(void)
{
	return numOp(this->op, this->leftNum, this->rightNum);
}