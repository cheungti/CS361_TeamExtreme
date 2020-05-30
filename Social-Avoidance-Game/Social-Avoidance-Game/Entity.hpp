#ifndef ENTITY_H
#define ENTITY_H

#include <tuple>
#include <string>


using namespace std;

class Entity {

public:
	enum class EntityType {
		Player, Bystander, Police, null
	};

	Entity();
	Entity(EntityType t);
	void setType(EntityType type1);		//created
	EntityType getType();				//created 

	void updateLocation(int x, int y);	//created
	tuple<int, int> getLocation();
	int getInfectionRadius();			//created
	void setInfectionRadius(int r);		//created
	int getX();							//created
	int getY();							//created
    string getChar();
    void setChar(string aChar);
	

	
private:
	int x;
	int y;
	int infectionRadius;
	EntityType type;
    string entChar;
};

#endif
