#ifndef POLICESTATION_H
#define POLICESTATION_H

#include <iostream>
#include <sstream>
#include "WalkVertex.h"

using namespace std;

class PoliceStation : public WalkVertex
{
	public:
		PoliceStation();
		PoliceStation(double prob, string decription);

		virtual string ToString() const;
		virtual walk_status_t Status() const;

	private:
		double m_probability;
};

#endif