#include "SafeHouse.h"

SafeHouse::SafeHouse()
	: WalkVertex()
{
		//Empty constructor
}

SafeHouse::SafeHouse(string description)
	: WalkVertex(description)
{
	//Empty constructor
}

string SafeHouse::ToString() const
{
	stringstream ss;
	ss << "ID " << GetID() << ": SafeHouse (" << m_description << ")";
	return ss.str();
}

walk_status_t SafeHouse::Status() const
{
	return SUCCESS;
}