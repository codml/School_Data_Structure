#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
	f = 0;
	r = 0; // initiate indexes
}

MemberQueue::~MemberQueue()
{
	for (int i = (f + 1) % 101; i != (r + 1) % 101; i = (i + 1) % 101)
		delete queue[i]; // delete node which remain in queue
}

bool MemberQueue::empty()
{
	if (f == r) // front = read means queue is empty
		return true;
	else
		return false;
}

bool MemberQueue::full()
{
	if ((r + 1) % 101 == f) // front next to rear index means queue is full
		return true;
	else
		return false;
}

void MemberQueue::push(MemberQueueNode *pnode)
{
	if (full()) // if full, can't push
		exit(-1);
	queue[(r + 1) % 101] = pnode; // push to rear
	r = (r + 1) % 101;
}

MemberQueueNode *MemberQueue::pop()
{
	if (empty()) // if empty, can't pop
		exit(-1);
	f = (f + 1) % 101;
	return queue[f]; // pop from front
}

MemberQueueNode *MemberQueue::front()
{
	return queue[f]; // return front node
}