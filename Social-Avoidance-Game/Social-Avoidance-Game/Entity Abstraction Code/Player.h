#ifndef PLAYER_H
#define PLAYER_H
//includes
#include "Entity.h"

using namespace std;

#pragma once
class Player : public Entity {
private:
	//Room* currentRoom;

public:
	Player();
	~Player();
	void Step(); //override parent class step loop
};

#endif