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

using namespace std;


class Buildings {

public:
	Buildings(std::string aType, string aBuildingChar, int x, int y);
	~Buildings();

	void setBuildingName(std::string name);		// Set building type
	std::string getBuildingName();				// Get building type
	int getRow();									// Get x coordinate
	int getCol();									// Get y coordinate
    void updateLocation(int x, int y);
	int getX();
	int getY();
	bool isLocked();
	bool ifVisited();
    string getBuildingChar();

private:
	std::string buildingType;					// Building type
    string buildingChar;                          //char for board
	int row;									// row location of building
	int col;									// col location of building
	bool locked;
	bool visited;

};

#endif
