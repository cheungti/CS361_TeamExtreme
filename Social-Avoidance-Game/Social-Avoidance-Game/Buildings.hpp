/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Buildings.hpp is the class specification for the
** Buildings class.  Member methods defined in separate implementation 
** file.
*********************************************************************/

#ifndef Buildings_hpp
#define Buildings_hpp

#include <string>
#include <vector>
#include <tuple>
#include "Die.hpp"

typedef std::vector< std::tuple<int,int> > tupleList;

class Buildings 
{

public:
	Buildings(std::string aType);
	~Buildings();

	void setBuilding(std::string name);		// Set building type
	std::string getBuilding();
	tupleList getLocation();				//returns a list of (x,y) coordinates for building location
	void setLocation(tupleList coordinates); //set building location
	bool isLocked();
	bool ifVisited();

private:
	std::string buildingType;				// Building type
	tupleList location;
	bool locked;
	bool visited;
	Die dice;
};

#endif