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
    setChar("Δ");
    setType(Entity::EntityType::Player);
    updateHealth(100);
    updateMoney(100);
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

/***************************************************************************
 *							   Set Tickets   			    			   *
 *	The function will update the players tickets                           *
 ***************************************************************************/
void Player::setTickets(bool ticket){
    hasTickets = ticket;
}

/***************************************************************************
 *							   Get Tickets    			    			   *
 *	The function will return true if player has tickets                    *
 ***************************************************************************/
bool Player::getHasTickets(){
    return hasTickets;
}

