#ifndef ENTITY_H
#define ENTITY_H

#include "Die.hpp"
#include <tuple>
#include <string>


using namespace std;

#pragma once
class Entity {
private:
	int x;
	int y;
	string type;					// Character type
	Die dice;

public:
	Entity();
	Entity(string aType);
	string getType();
	void Step();
	void updateLocation(int x, int y);
	tuple<int, int> getLocation();
	int getX();
	int getY();
	void setType(string name);		// Set character type


};

#endif