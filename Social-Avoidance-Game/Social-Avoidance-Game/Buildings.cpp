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
** Description: Default constructor for Buildings class
*********************************************************************/
Buildings::Buildings() {

	buildingType = "";

}

/*********************************************************************
** Description: Set function sets building type
*********************************************************************/
void Buildings::setBuilding(std::string buildingName) {

	buildingType = buildingName;

}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Buildings::~Buildings() {

}