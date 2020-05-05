#include "Entity.h"



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

/***************************************************************************
 *							  Update Health 			    			   *
 *	The function will update the entitys integer health value              *
 *																		   *
 *	Params: int for new entity health                                      *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::updateHealth(int newhealth) {
    this->health = newhealth;
}

/***************************************************************************
 *							     Get Health    			    			   *
 *	The function will return the entitys health value                      *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The entity's current health                                    *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Entity::getHealth() {
    return this->health;
}

/***************************************************************************
 *							    Update Money 			    			   *
 *	The function will update the entitys integer money value               *
 *																		   *
 *	Params: int for new entity money value                                 *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::updateMoney(int money) {
    this->money = money;
}

/***************************************************************************
 *							      Add Money 			    		  	   *
 *	The function will add a designated ammount of cash to the entitys      *
 *      integer money value                                                *
 *																		   *
 *	Params: int for new entity money going to be added                     *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::addMoney(int additionalmoney) {
    this->money += additionalmoney;
}

/***************************************************************************
 *							     Get Money    			    			   *
 *	The function will return the entitys money value                       *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The entity's current money value                               *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Entity::getMoney() {
    return this->money;
};

/***************************************************************************
 *							   Is Infected    			    			   *
 *	The function will return the entitys infection status                  *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The entity's current infection status                          *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
bool Entity::isInfected() {
    return this->infected;
}

/***************************************************************************
 *							   Set Infected    			    			   *
 *	The function will update the entitys infection status                  *
 *																		   *
 *	Params: The entity's new infection status                              *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Entity::setInfected(bool infectionStatus) {
    this->infected = infectionStatus;
}

