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

#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
	#define PLATFORM_NAME "windows" // Windows
#elif defined(__APPLE__) || defined(__linux__)
	#define PLATFORM_NAME "apple" // apple
#endif

class Bystander : public Entity {

public:
	Bystander();				// Default constructor
	~Bystander();				// Destructor
	
	void setInfection(bool n);
	void penalty(Player* player);
	bool isInfected();
	void setInfected(bool);
	void setHealthDecline(int deduction);
	int getHealthDecline();

private:
	bool infected;
	int infectionRadius;		// How close another entity needs to be to get infected
	int healthDecline;
	
	

};

#endif