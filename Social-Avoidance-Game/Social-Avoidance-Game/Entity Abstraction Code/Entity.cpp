#include "Entity.hpp"

/*********************************************************************
** Description: Default constructor for Entity class
*********************************************************************/
Entity::Entity() {
	type =  "";		// Initialize type
}

/*********************************************************************
** Description: Parameter constructor for Entity class
*********************************************************************/
Entity::Entity(string aType) {
	type =  aType;		// Initialize type
}

/*********************************************************************
** Description: Return type of Entity
*********************************************************************/
string Entity::getType() {
	return type;
}

/***************************************************************************
 *								Player Step								   *
 *	Every game tick the player class takes a Step loop. This function will *
 *		check for user input (movement, entity interaction, ect...), then  *
 *		call the nessesary update functions to calculate player's updated  *
 *		position information.											   *
 *																		   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::Step() {
    //testing, move one to right and down 1 every step
    updateLocation(getX() + 1, getY() - 1);

    //check for interactables in current room

    //check for entities in current room

    //get user input in console

    //update location if necessary

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






