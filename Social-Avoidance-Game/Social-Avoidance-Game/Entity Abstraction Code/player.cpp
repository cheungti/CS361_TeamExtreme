#include "Player.h"


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
	//testing, move one to right and down 1 every step
    updateLocation(getX() + 1, getY() - 1);

    //check for interactables in current room

    //check for entities in current room

    //get user input in console

    //update location if necessary

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
