#include "Entity.hpp"


/*********************************************************************
** Description: Parameter constructor for Entity class
*********************************************************************/
Entity::Entity(EntityType type) {
	this->type = type;		        // Initialize type

    // Generate random position
	updateLocation(0, 0); // -> Change this to random x and y in their respected child classes
}

Entity::Entity() {
    this->type = EntityType::null;

    // Generate random position
    updateLocation(0, 0);
}

Entity::~Entity() {

}

int Entity::getInfectionRadius() {

    return this->infectionRadius;

}

void Entity::setInfectionRadius(int r) {

    this->infectionRadius = r;

}


/***************************************************************************
 *							  Update Location			    			   *
 *	The function will update the entitys (x, y) integer coordinates        *
 *																		   *
 *	Params: int x defines new X position, int y defines new Y position     *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::updateLocation(int x, int y) {

    // Update new placement on board
    this->x = x;
    this->y = y;

}

/***************************************************************************
 *							    Get Location			    			   *
 *	The function will return the entitys (x, y) integer coordinates        *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: tuple<int, int> of the entitys (x, y) coordinates respectively *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
tuple<int, int> Entity::getLocation() {

    return tuple<int, int>(this->x, this->y);

}

/***************************************************************************
 *							       Get X			    	    		   *
 *	The function will return the entity's x integer coordinate             *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: the entity's x coordinate									   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Entity::getX() {

    return this->x;

}

/***************************************************************************
 *							       Get Y			    	    		   *
 *	The function will return the entity's y integer coordinate             *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: the entity's y coordinate									   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Entity::getY() {

    return this->y;

}

/***************************************************************************
 *							       Set Type			    	    		   *
 *	The function will set the entity's type                                *
 *																		   *
 *	Params: EntityType type1                                               *
 *	Return: N/A									                           *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::setType(Entity::EntityType type) {

    this->type = type;

}

Entity::EntityType Entity::getType() {

    return this->type;

}

string Entity::getChar(){
    return entChar;
}


void Entity::setChar(string aChar){
    entChar = aChar;
}
