#ifndef PLAYER_HPP
#define PLAYER_HPP
//includes
#include <tuple>
#include "Entity.hpp" 

using namespace std;

#pragma once
class Player : public Entity {
private:
	int health;
	int money;
	int infectionRadius; //how close another entity needs to be to get infected
	bool infected;

public:
	Player();
	~Player();
	void Step();
	void move(int x, int y);
	void updateHealth(int);
	int getHealth();
	void updateMoney(int);
	void addMoney(int);
	int getMoney();
	bool isInfected();
	void setInfected(bool);
};

#endif
