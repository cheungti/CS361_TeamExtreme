/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Bystander.hpp is the class specification file for the
** Bystander class.  Bystander is a derived class of the Cpu base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Bystander_hpp
#define Bystander_hpp
#include "Cpu.hpp"
#include <string>

class Bystander : public Cpu
{

public:
	Bystander();				// Default constructor
	~Bystander();				// Destructor
	
	void setInfection(bool n);

private:
	bool infected;

};

#endif