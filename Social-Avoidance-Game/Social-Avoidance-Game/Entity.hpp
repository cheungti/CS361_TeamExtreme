#ifndef ENTITY_H
#define ENTITY_H

#include "Die.hpp"
#include <tuple>
#include <string>

using namespace std;

class Entity {

public:
	enum class EntityType {
		Player, Bystander, Police, null
	};

	Entity();
	~Entity();
	Entity(EntityType t);
	void setType(EntityType type1);		//created
	EntityType getType();				//created 

	void Step();
	void updateLocation(int x, int y);	//created
	tuple<int, int> getLocation();
	int getInfectionRadius();			//created
	void setInfectionRadius(int r);		//created
	int getX();							//created
	int getY();							//created

	//public classes
	Die* dice;
	
private:
	int x;
	int y;
	int infectionRadius;
	EntityType type;
};

#endif