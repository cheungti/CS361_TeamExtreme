/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
** Date: 05-05-2020
** Description: Bystander.hpp is the class specification file for the
** Bystander class.  Bystander is a derived class of the Cpu base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Bystander_hpp
#define Bystander_hpp
#include <iostream>
#include <string>
#include "Entity.hpp"
#include "Player.hpp"

#define C_YELLOW  "\x1b[33m"
#define C_RESET   "\x1b[0m"


class Bystander : public Entity {

public:
	Bystander();				// Default constructor
	~Bystander();

	void penalty(Player*);
	bool isInfected();
	void setInfection(bool);
	void setHealthDecline(int);
	int getHealthDecline();

private:
	bool infected;
	int infectionRadius;		// How close another entity needs to be to get infected
	int healthDecline;


};

#endif
