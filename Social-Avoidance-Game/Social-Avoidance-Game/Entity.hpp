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
	~Entity();
	Entity(EntityType);
	void setType(EntityType);		//created
	EntityType getType();				//created 

	void updateLocation(int, int);	//created
	tuple<int, int> getLocation();
	int getInfectionRadius();			//created
	void setInfectionRadius(int);		//created
	int getX();							//created
	int getY();							//created
    string getChar();
    void setChar(string);

	
private:
	int x;
	int y;
	int infectionRadius;
	EntityType type;
    string entityChar;
};

#endif
