#ifndef PLAYER_HPP
#define PLAYER_HPP
//includes
#include "Entity.hpp" 

using namespace std;

#pragma once
class Player : public Entity {
private:
	int health;
	int infectionRadius; //how close another entity needs to be to get infected
	bool infected;
	bool hasTickets;


public:
	Player();
	~Player();
	void Step();
	void move(int, int);
	void updateHealth(int);
	int getHealth();
	bool isInfected();
	void setInfected(bool);
	void setTickets(bool);
	bool getHasTickets();
	
};

#endif
