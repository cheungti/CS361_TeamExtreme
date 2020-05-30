/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
** Date: 05-05-2020
** Description: Buildings.cpp is the class implementation file for
** the Buildings class.  Member methods are defined within.
*********************************************************************/
#include "Buildings.hpp"
#include <string>

/*********************************************************************
** Description: Parameter constructor for Buildings class
*********************************************************************/
Buildings::Buildings(string aType, string aBuildingChar, int buildingRow, int buildingCol) {
	buildingType = aType;
    buildingChar = aBuildingChar;
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
** Description: Get building Char
*********************************************************************/
string Buildings::getBuildingChar() {

    return buildingChar;

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

void Buildings::updateLocation(int x, int y) {

    // Update new placement on board
    row = x;
    col = y;

}

/*********************************************************************
** Description: Get x coordinate position
*********************************************************************/
int Buildings::getX() {
	return row;
}

/*********************************************************************
** Description: Get y coordinate position
*********************************************************************/
int Buildings::getY() {
	return col;
}

/*********************************************************************
** Description: Set visted to true
** Arguments: None
** Return: Void
** Author: Tinron Cheung
*********************************************************************/
void Buildings::setVisited() {

	this->visited = true;

}

/*********************************************************************
** Description: Set visted to false
** Arguments: None
** Return: Void
** Author: Tinron Cheung
*********************************************************************/
void Buildings::unsetVisited() {

	this->visited = false;

}

/*********************************************************************
** Description: Get visted status
** Arguments: None
** Return: bool visited or not
** Author: William Dam
*********************************************************************/
bool Buildings::getVisited() {

	return this->visited;

}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Buildings::~Buildings() {

}
