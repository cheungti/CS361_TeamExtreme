/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
** Date: 05-05-2020
** Description: Buildings.hpp is the class specification for the
** Buildings class.  Member methods defined in separate implementation
** file.
*********************************************************************/
#ifndef Buildings_hpp
#define Buildings_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Die.hpp"

using namespace std;

class Buildings {

public:
	enum class BuildingType {
		Home, Pharmacy, GroceryStore, PoliceStation,
		Doctor, Work, HandwashStation, empty
	};

	Buildings(string, string, Die*);
	Buildings(string, string, Die*, vector<Buildings*>);
	Buildings(string, string, int, int);
	~Buildings();

	void setBuildingName(string);		// Set building type
	string getBuildingName();				// Get building type
    void updateLocation(int, int);
	int getX();
	int getY();
	bool isLocked();
	bool ifVisited();
    string getBuildingChar();
	void setBuildingChar(string);
	void setVisited();
	void unsetVisited();
	bool getVisited();

private:
	string buildingType;					// Building type
    string buildingChar;                          //char for board
	int row;									// row location of building
	int col;									// col location of building
	bool locked;
	bool visited;

	void randomWithPlacementCollision(Die*, vector<Buildings*>);
};

#endif
