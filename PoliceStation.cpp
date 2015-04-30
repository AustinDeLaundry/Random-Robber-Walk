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

//CHANGE THIS TO INCLUDE PROBABILITY
walk_status_t PoliceStation::Status() const
{
	double r = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
	if (r < m_probability)
    	return FAILURE;      // caught by the police
	else
		return CONTINUE; // got away
}