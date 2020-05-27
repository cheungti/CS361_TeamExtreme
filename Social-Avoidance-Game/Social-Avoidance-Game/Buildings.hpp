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

using namespace std;

class Buildings {

public:
	Buildings(string, string, int, int);
	~Buildings();

	void setBuildingName(string);		// Set building type
	string getBuildingName();				// Get building type
    void updateLocation(int, int);
	int getX();
	void setX(int);
	int getY();
	void setY(int);
	bool isLocked();
	void setLocked(bool);
	bool ifVisited();
	void setVisited(bool);
    string getBuildingChar();
	void setBuildingChar(string);

private:
	string buildingType;					// Building type
    string buildingChar;                          //char for board
	int row;									// row location of building
	int col;									// col location of building
	bool locked;
	bool visited;

};

#endif
