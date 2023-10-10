#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
	MemberQueueNode *queue[101]; // array
	int				f; // front index <- delete
	int				r; // rear index <- insert

public:
	MemberQueue();
	~MemberQueue();

	bool empty(); // check that queue is empty
	bool full(); // check that queue is full
	void push(MemberQueueNode *pnode); // push node
	MemberQueueNode *pop(); // pop node
	MemberQueueNode *front(); // return front node
};

