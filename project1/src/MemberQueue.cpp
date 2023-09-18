#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
	f = 0;
	r = 0;
}
MemberQueue::~MemberQueue()
{
	for (int i = (f + 1) % 101; i != (r + 1) % 101; i = (i + 1) % 101)
		delete (queue + i);
}

bool MemberQueue::empty()
{

}
bool MemberQueue::full()
{

}
void MemberQueue::push()
{
	
}
MemberQueueNode MemberQueue::pop()
{

}
MemberQueueNode MemberQueue::front()
{

}