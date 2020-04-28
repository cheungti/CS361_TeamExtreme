#ifndef PLAYER_H
#define PLAYER_H
//includes
#include <tuple>

using namespace std;

#pragma once
class Player {
private:
	int x;
	int y;
	int health;
	int money;

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
};

#endif