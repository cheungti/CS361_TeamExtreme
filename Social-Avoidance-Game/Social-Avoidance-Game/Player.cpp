/*********************************************************************
** Author: Bryce Hahn, Tinron Cheung
** Date: 05-15-2020
** Description: Player.cpp is the class implementation file for the
** Player class.  Member methods defined within.
*********************************************************************/
#include "Player.hpp"

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
    if (PLATFORM_NAME == "windows")
        setChar("Y");
    else
        setChar("Δ");
    setType(Entity::EntityType::Player);
    updateHealth(100);
    updateLocation(22, 25); // Start at home building
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

/***************************************************************************
 *							Player Destructor						       *
 *	The player class deconstructor will ensure we have no memory leaks at  *
 *		the end of the game when shutting down. Keep coding clean!		   *
 *																		   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
Player::~Player() {

}