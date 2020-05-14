/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
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
Buildings::Buildings(std::string aType, int buildingRow, int buildingCol) {

	buildingType = aType;
	row = buildingRow;
	col = buildingCol;
	visited = false;
	locked = false;

}

/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
void Buildings::setBuildingName(std::string buildingName) {

	buildingType = buildingName;

}

/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
std::string Buildings::getBuildingName() {

	return buildingType;

}

/*********************************************************************
** Description: return if locked or not
*********************************************************************/
bool Buildings::isLocked() {

	return locked; 

}

/*********************************************************************
** Description: return if building has been visited
*********************************************************************/
bool Buildings::ifVisited() {

	return visited; 

}

/*********************************************************************
** Description: Get x coordinate position
*********************************************************************/
int Buildings::getRow() {

	return row;

}

/*********************************************************************
** Description: Get y coordinate position
*********************************************************************/
int Buildings::getCol() {

	return col;

}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Buildings::~Buildings() {

}