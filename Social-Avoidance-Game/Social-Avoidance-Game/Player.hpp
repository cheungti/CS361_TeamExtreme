/*********************************************************************
** Author: Bryce Hahn, Tinron Cheung
** Date: 05-15-2020
** Description: Player.hpp is the class specification file for the
** Player class.  Member methods defined in separate implementation 
** file.
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp" 

#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
	#define PLATFORM_NAME "windows" // Windows
#elif defined(__APPLE__) || defined(__linux__)
	#define PLATFORM_NAME "apple" // apple
#endif

class Player : public Entity {

private:
	int health;
	int infectionRadius; //how close another entity needs to be to get infected
	bool infected;
	bool hasTickets;


public:
	Player();
	~Player();
	void move(int, int);
	void updateHealth(int);
	int getHealth();
	bool isInfected();
	void setInfected(bool);
	void setTickets(bool);
	bool getHasTickets();
	
};

#endif
