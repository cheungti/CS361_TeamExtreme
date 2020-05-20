/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
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

class Buildings {
public:
	Buildings(std::string aType, int x, int y);
	~Buildings();

	void setBuildingName(std::string name);		// Set building type
	std::string getBuildingName();				// Get building type
	int getRow();									// Get x coordinate
	int getCol();									// Get y coordinate
	bool isLocked();
	bool ifVisited();

private:
	std::string buildingType;					// Building type
	int row;									// row location of building
	int col;									// col location of building
	bool locked;
	bool visited;
	bool hasBathroom;

};

#endif