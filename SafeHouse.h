#ifndef SAFEHOUSE_H
#define SAFEHOUSE_H

#include <iostream>
#include <sstream>
#include "WalkVertex.h"

using namespace std;

class SafeHouse : public WalkVertex
{
	public:
		SafeHouse();
		SafeHouse(string description);

		virtual string ToString() const;
		virtual walk_status_t Status() const;
};

#endif