/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Buildings.cpp is the class implementation file for
** the Buildings class.  Member methods are defined within.
*********************************************************************/

#include "Buildings.hpp"
#include <iostream>
#include <string>

/*********************************************************************
** Description: Parameter constructor for Buildings class
*********************************************************************/
Buildings::Buildings(std::string aType) {

	buildingType = aType;
	visited = false;
	locked = false;

}

/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
void Buildings::setBuilding(std::string buildingName) {

	buildingType = buildingName;

}

/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
std::string Buildings::getBuilding() {

	return buildingType;

}

/*********************************************************************
** Description: Set location
*********************************************************************/
void Buildings::setLocation(tupleList coordinates){

	location = coordinates;
}

/*********************************************************************
** Description: return if locked or not
*********************************************************************/
bool Buildings::isLocked(){

	return locked; 
}

/*********************************************************************
** Description: return if building has been visited
*********************************************************************/
bool Buildings::ifVisited(){

	return visited; 
}

/*********************************************************************
** Description: Get list of location points
*********************************************************************/
tupleList Buildings::getLocation(){
	return location;
}


/*********************************************************************
** Description: Class destructor
*********************************************************************/
Buildings::~Buildings() {

}