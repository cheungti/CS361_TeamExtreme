#ifndef ENTITY_H
#define ENTITY_H

#include "Die.hpp"
#include <tuple>
#include <string>


using namespace std;

#pragma once
class Entity {

public:
	enum EntityType {
		Player, Bystander, Police, null
	};

	Entity();
	Entity(EntityType t);
	void setType(EntityType type1);		//created
	EntityType getType();			//created 

	void Step();
	void updateLocation(int x, int y);		//created
	tuple<int, int> getLocation();
	int getInfectionRadius();			//created
	void setInfectionRadius(int r);		//created
	int getX();						//created
	int getY();						//created
	
private:
	int x;
	int y;
	int infectionRadius;
	EntityType type;
	Die dice;
};

#endif