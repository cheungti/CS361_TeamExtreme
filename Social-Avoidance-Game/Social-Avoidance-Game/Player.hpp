#ifndef PLAYER_HPP
#define PLAYER_HPP
//includes
#include <tuple>
#include "Entity.hpp" 

using namespace std;

#pragma once
class Player : public Entity {
private:
	int x;
	int y;
	int health;
	int money;
	int infectionRadius; //how close another entity needs to be to get infected
	bool infected;

public:
	Player();
	~Player();
	void Step();
	void updateLocation(int x, int y);
	tuple<int, int> getLocation();
	int getX();
	int getY();
	void updateHealth(int);
	int getHealth();
	void updateMoney(int);
	void addMoney(int);
	int getMoney();
	bool isInfected();
	void setInfected(bool);
};

#endif