/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
** Date: 05-05-2020
** Description: Buildings.cpp is the class implementation file for
** the Buildings class.  Member methods are defined within.
*********************************************************************/
#include "Buildings.hpp"


/***************************************************************************
 *							Building Constructor						   *
 *	The default Building class constructor will initialize the buildings'  *
 *		name, symbol and xy location                                       *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Buildings::Buildings(string bName, string buildingChar, int x, int y) {
    setBuildingName(bName);
    setBuildingChar(buildingChar);
    updateLocation(x, y);
    setLocked(false);
    setVisited(false);
}


/***************************************************************************
 *							  Building Name						           *
 *	Modify the building's name value to be printed in the board key        *
 *                                                                         *
 *	Params: buildingName as the new name value							   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::setBuildingName(string buildingName) {
    this->buildingType = buildingName;
}


/***************************************************************************
 *							  Building Name						           *
 *	Return the building's name value to be printed in the board key        *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: the buildings' name value									   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
string Buildings::getBuildingName() {
    return this->buildingType;
}


/***************************************************************************
 *							  Building Char						           *
 *	Return the building's char symbol to be printed on the gameboard       *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: The buildings' char symbol									   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
string Buildings::getBuildingChar() {
    return this->buildingChar;
}


/***************************************************************************
 *							  Building Char						           *
 *	Modify the building's char symbol to be printed on the gameboard       *
 *                                                                         *
 *	Params: The buildings' char symbol									   *
 *	Return: N/A                                                            *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::setBuildingChar(string newChar) {
    this->buildingChar = newChar;
}


/***************************************************************************
 *							  Building Locked						       *
 *	Return the locked building value. Only players can enter when unlocked *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: true if locked, else false                                     *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
bool Buildings::isLocked() {
	return locked;
}


/***************************************************************************
 *							  Building Locked						       *
 *	Modify the locked building value. Only players can enter when unlocked *
 *                                                                         *
 *	Params: The new lock value  										   *
 *	Return: N/A                                                            *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::setLocked(bool locked) {
    this->locked = locked;
}


/***************************************************************************
 *							 Building Visited						       *
 *	Return the building's visited status                                   *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: true if the player has already visited, else false             *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
bool Buildings::ifVisited() {
	return visited;
}


/***************************************************************************
 *							  Building Visited						       *
 *	Modify the buildings' visited status                                   *
 *                                                                         *
 *	Params: The new visited value  										   *
 *	Return: N/A                                                            *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::setVisited(bool visited) {
    this->visited = visited;
}


/***************************************************************************
 *						    Building Location						       *
 *	Modify the buildings row and column values where the symbol will be    *
 *         printed on the gameboard.                                       *
 *                                                                         *
 *	Params: x for row, y for column										   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::updateLocation(int x, int y) {
    setX(x);
    setY(y);
}


/***************************************************************************
 *							     Building X						           *
 *	Return the building's column (X) value of its location on the board    *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: x value as the column										   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
int Buildings::getX() {
    return this->col;
}


/***************************************************************************
 *							     Building Y						           *
 *	Return the building's row (Y) value of its location on the board       *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: y value as the row   										   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
int Buildings::getY() {
    return this->row;
}


/***************************************************************************
 *							     Building X						           *
 *	Modify the building's column (X) value of its location on the board    *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: x value as the column										   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::setX(int col) {
    this->col = col;
}


/***************************************************************************
 *							     Building Y						           *
 *	Modify the building's row (Y) value of its location on the board       *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: y value as the row   										   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Buildings::setY(int row) {
    this->row = row;
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