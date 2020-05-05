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
#include <vector>
#include <tuple>
#include "Cpu.hpp"

typedef std::vector< std::tuple<int,int> > tupleList;

class Buildings : public Cpu
{

public:
	Buildings();
	~Buildings();

	void setBuilding(std::string name);		// Set building type
	tupleList getLocation();				//returns a list of (x,y) coordinates for building location
	void setLocation(tupleList coordinates); //set building location

private:
	std::string buildingType;				// Building type
	tupleList location;
};

#endif