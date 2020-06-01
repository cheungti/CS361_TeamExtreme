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

#define C_MAGENTA "\x1b[35m"
#define C_RESET   "\x1b[0m"


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
