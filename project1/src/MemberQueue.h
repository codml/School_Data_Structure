#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
	MemberQueueNode queue[101];
	int				f;
	int				r;

public:
	MemberQueue();
	~MemberQueue();

	bool empty();
	bool full();
	void push();
	MemberQueueNode pop();
	MemberQueueNode front();
};

