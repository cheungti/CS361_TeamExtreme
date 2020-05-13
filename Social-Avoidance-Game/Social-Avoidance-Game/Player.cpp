#include "Player.hpp"


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
void Player::Step() {
	
}

/***************************************************************************
 *							Player Constructor							   *
 *	The default player class constructor will initialize the Player entity *
 *		and set up the required user input classes to ensure everything	   *
 *		cooperates with the players movement.							   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
Player::Player() {
    dice = new Die();
    setType(Entity::EntityType::Player);
    updateHealth(100);
    updateMoney(0);
    updateLocation(0, 0); //start at 0, 0 -> board can go into the negatives
}

/***************************************************************************
 *							Player Deconstructor						   *
 *	The player class deconstructor will ensure we have no memory leaks at  *
 *		the end of the game when shutting down. Keep coding clean!		   *
 *																		   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
Player::~Player() {
    //nothing?
}

/***************************************************************************
 *							  Update Location			    			   *
 *	The function will update the players (x, y) integer coordinates        *
 *																		   *
 *	Params: int x defines new X position, int y defines new Y position     *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Player::updateLocation(int x, int y) {
    this->x = x;
    this->y = y;
}

/***************************************************************************
 *							    Move Location			    			   *
 *	The function will move the players relative (x, y) integer coordinates *
 *																		   *
 *	Params: int x defines the X increase, int y defines the Y increase     *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Jonathan Dressel								   *
 ***************************************************************************/
void Player::move(int xMove, int yMove) {
    updateLocation(getX() + xMove, getY() + yMove);
}

/***************************************************************************
 *							    Get Location			    			   *
 *	The function will return the players (x, y) integer coordinates        *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: tuple<int, int> of the players (x, y) coordinates respectively *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
tuple<int, int> Player::getLocation() {
    return tuple<int, int>(this->x, this->y);
}

/***************************************************************************
 *							       Get X			    	    		   *
 *	The function will return the player's x integer coordinate             *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: the player's x coordinate									   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Player::getX() {
    return this->x;
}

/***************************************************************************
 *							       Get Y			    	    		   *
 *	The function will return the player's y integer coordinate             *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: the player's y coordinate									   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Player::getY() {
    return this->y;
}

/***************************************************************************
 *							  Update Health 			    			   *
 *	The function will update the players integer health value              *
 *																		   *
 *	Params: int for new player health                                      *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Player::updateHealth(int newhealth) {
    this->health = newhealth;
}

/***************************************************************************
 *							     Get Health    			    			   *
 *	The function will return the players health value                      *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The player's current health                                    *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Player::getHealth() {
    return this->health;
}

/***************************************************************************
 *							    Update Money 			    			   *
 *	The function will update the players integer money value               *
 *																		   *
 *	Params: int for new player money value                                 *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Player::updateMoney(int money) {
    this->money = money;
}

/***************************************************************************
 *							      Add Money 			    		  	   *
 *	The function will add a designated ammount of cash to the players      *
 *      integer money value                                                *
 *																		   *
 *	Params: int for new player money going to be added                     *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Player::addMoney(int additionalmoney) {
    this->money += additionalmoney;
}

/***************************************************************************
 *							     Get Money    			    			   *
 *	The function will return the players money value                       *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The player's current money value                               *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int Player::getMoney() {
    return this->money;
};

/***************************************************************************
 *							   Is Infected    			    			   *
 *	The function will return the players infection status                  *
 *																		   *
 *	Params: N/A                                                            *
 *	Return: The player's current infection status                          *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
bool Player::isInfected() {
    return this->infected;
}

/***************************************************************************
 *							   Set Infected    			    			   *
 *	The function will update the players infection status                  *
 *																		   *
 *	Params: The player's new infection status                              *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void Player::setInfected(bool infectionStatus) {
    this->infected = infectionStatus;
}