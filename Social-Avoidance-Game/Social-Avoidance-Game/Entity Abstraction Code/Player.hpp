#ifndef PLAYER_HPP
#define PLAYER_HPP
//includes
#include "Entity.hpp"

using namespace std;

#pragma once
class Player : public Entity {
private:
	//Room* currentRoom;
	int health;
	int money;

public:
	Player();
	~Player();
	void updateHealth(int);
	int getHealth();
	void updateMoney(int);
	void addMoney(int);
	int getMoney();
	void Step(); //override parent class step loop
};

#endif