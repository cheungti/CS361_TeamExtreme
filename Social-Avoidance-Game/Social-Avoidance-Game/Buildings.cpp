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

/***************************************************************************
 *							Building Constructor						   *
 *	The default building constructor takes a building name a char to show  *
 *		when printing to board, but will generate the building location on *
 *		its own for a more random gameboard each playthrough			   *
 *	Params: building name, building char, die pointer for random locations *
 *																	       *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
Buildings::Buildings(string aType, string aBuildingChar, Die* d) {
	buildingType = aType;
    buildingChar = aBuildingChar;
	col = d->dieRollWidth();
	row = d->dieRollHeight();
	visited = false;
	locked = false;
}


/***************************************************************************
 *							Building Constructor						   *
 *	The random building constructor takes a building name a char to show   *
 *		when printing to board, but will generate the building location on *
 *		its own for a more random gameboard each playthrough, while also   *
 *		verifying the placement is a valid (non-collision) position on map *
 *																	       *
 *	Params: building name, building char, die pointer for random locations *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
Buildings::Buildings(string aType, string aBuildingChar, Die* d, vector<Buildings*> buildings) {
	buildingType = aType;
	buildingChar = aBuildingChar;
	randomWithPlacementCollision(d, buildings);
	visited = false;
	locked = false;
}

Buildings::~Buildings() {

}


void Buildings::randomWithPlacementCollision(Die* d, vector<Buildings*> buildings) {
	bool goodPlacement = false, replacement = true;
	int x, y, xDisplacement, yDisplacement;
	int minDisplacement = 5;


	while (!goodPlacement) {
		if (replacement) {
			replacement = false;
			x = d->dieRollWidth();
			y = d->dieRollHeight();

			for (int i = 0; i < buildings.size(); i++) {
				xDisplacement = (buildings[i]->getX() - x);
				yDisplacement = (buildings[i]->getY() - y);
				if (xDisplacement < minDisplacement && xDisplacement > -minDisplacement) {
					if (yDisplacement < minDisplacement && yDisplacement > -minDisplacement) {
						replacement = true;
					}
				}
			}
		}
		goodPlacement = true;
	}

	//once we've verified the building can't overlap others, define its xy coords
	this->col = x;
	this->row = y;
}


/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
void Buildings::setBuildingName(string buildingName) {

	this->buildingType = buildingName;

}

/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
string Buildings::getBuildingName() {

	return buildingType;

}

/*********************************************************************
** Description: Get building Char
*********************************************************************/
string Buildings::getBuildingChar() {

    return buildingChar;

}

void Buildings::setBuildingChar(string buildingChar) {

	this->buildingChar = buildingChar;

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