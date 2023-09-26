#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
	f = 0;
	r = 0;
}
MemberQueue::~MemberQueue()
{
	for (int i = (f + 1) % 101; i != (r + 1) % 101; i = (i + 1) % 101)
		delete queue[i];
}

bool MemberQueue::empty()
{
	if (f == r)
		return true;
	else
		return false;
}

bool MemberQueue::full()
{
	if ((r + 1) % 101 == f)
		return true;
	else
		return false;
}

void MemberQueue::push(MemberQueueNode *pnode)
{
	if (full())
		exit(1);
	queue[(r + 1) % 101] = pnode;
	r = (r + 1) % 101;
}

MemberQueueNode *MemberQueue::pop()
{
	if (empty())
		exit(1);
	f = (f + 1) % 101;
	return queue[f];
}

MemberQueueNode *MemberQueue::front()
{
	return queue[f];
}