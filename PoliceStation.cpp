#include "PoliceStation.h"


PoliceStation::PoliceStation()
	: WalkVertex()
{
		//Empty constructor
}

PoliceStation::PoliceStation(double prob, string description)
	: WalkVertex(description)
{
	m_probability = prob;
}

string PoliceStation::ToString() const
{
	stringstream ss;
	ss << "ID " << GetID() << ": PoliceStation (" << m_description << ")";
	return ss.str();
}

walk_status_t PoliceStation::Status() const
{
	return FAILURE;
}