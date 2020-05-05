/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Buildings.hpp is the class specification for the
** Buildings class.  Member methods defined in separate implementation 
** file.
*********************************************************************/

#ifndef Buildings_hpp
#define Buildings_hpp

#include <string>

class Buildings
{

public:
	Buildings();
	~Buildings();

	void setBuilding(std::string name);		// Set building type

private:
	std::string buildingType;				// Building type

};

#endif