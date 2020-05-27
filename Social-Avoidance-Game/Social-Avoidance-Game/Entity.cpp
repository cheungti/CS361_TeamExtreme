#include "Entity.hpp"


/***************************************************************************
 *						      Entity Constructor						   *
 *	The default Entity class constructor will initialize the Entit with    *
 *      the default values of an abstract entity                           *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, William Dam, Daniel Mesa, Tinron Cheung            *
 ***************************************************************************/
Entity::Entity() {
    setType(EntityType::null);
    updateLocation(0, 0); // -> Change this to random x and y in their respected child classes
}


/***************************************************************************
 *						      Entity Constructor						   *
 *	The Type Entity class constructor will initialize the Entitys' type    *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, William Dam, Daniel Mesa, Tinron Cheung            *
 ***************************************************************************/
Entity::Entity(EntityType type) {
    setType(type);
    updateLocation(0, 0); // -> Change this to random x and y in their respected child classes
}


/***************************************************************************
 *						    Entity Deconstructor						   *
 *	The default Entity class deconstructor will destroy the Entitys' type  *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, William Dam, Daniel Mesa, Tinron Cheung            *
 ***************************************************************************/
Entity::~Entity() {

}


/***************************************************************************
 *						      Infection Radius                             *
 *	Return the infection radius value of the entity                        *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The infection radius value									   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Entity::getInfectionRadius() {
    return this->infectionRadius;
}


/***************************************************************************
 *						      Infection Radius                             *
 *	Modify the infection radius value of the entity                        *
 *																		   *
 *	Params: The new infection radius                                       *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
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


/***************************************************************************
 *							       Get Type			    	    		   *
 *	The function will return the entity's type                             *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The entity type     				                           *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
Entity::EntityType Entity::getType() {
    return this->type;
}


/***************************************************************************
 *							       Get Char			    	    		   *
 *	The function will get the entity's printing char value                 *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: Entity Char printable value			                           *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
string Entity::getChar() {
    return this->entityChar;
}


/***************************************************************************
 *							       Set Char			    	    		   *
 *	The function will set the entity's printing char value                 *
 *																		   *
 *	Params: the new Entity Char printable value			                   *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::setChar(string newChar) {
    this->entityChar = newChar;
}