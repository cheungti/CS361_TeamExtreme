/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Bystander.hpp is the class specification file for the
** Bystander class.  Bystander is a derived class of the Cpu base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Bystander_hpp
#define Bystander_hpp
#include <iostream>
#include <string>
#include "Die.hpp"
#include "Entity.hpp"

class Bystander : public Entity {

public:
	Bystander();				// Default constructor
	~Bystander();				// Destructor
	
	void setInfection(bool n);

private:
	bool infected;
	int infectionRadius; //how close another entity needs to be to get infected
	bool isInfected();
	void setInfected(bool);

};

#endif