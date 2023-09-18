#pragma once
#include <string>

class MemberQueueNode
{
private:
	std::string	name;
	int			age;
	std::string	infor_date;
	char		type;

public:
	MemberQueueNode(std::string n, int a, std::string i, char t): name(n), age(a),
				infor_date(i), type(t) {}
	~MemberQueueNode() {}

	MemberQueueNode& operator=(const MemberQueueNode &cpnode)
	{
		
	}
};