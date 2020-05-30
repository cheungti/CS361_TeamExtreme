#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Player.hpp"
#include "GameBoard.hpp"




//instantiate class variables
Player* player;
GameBoard* board;

//define function declarations
void Avoidance();

/***************************************************************************
 *								Avoidance							       *
 *	Initialization function to setup the start of the game and call the	   *
 *		main game loop to ensure the game keeps going.					   *
 *																		   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung, William Dam                         *
 ***************************************************************************/
void Avoidance() {

	//setup player
	player = new Player();

	//setup game board
	board = new GameBoard(player);
    
	//main game loop
    bool keepPlaying = true;

    while(keepPlaying == true) {
        
        if (player->getHealth() > 0) {

            keepPlaying = board->Step();

            // Win game if player returns home, errands done, and no tickets (fines)
            if (board->playerHome() == true && board->errandsDone() == true && player->getHasTickets() == false) {
                std::cout << "You made it home alive!  YOU WIN!!!\n";
                break;
            }
        }
        else {
            std::cout << "You ran out of health and died!  GAME OVER :(\n";
            break;
        }
    }
    
    if (keepPlaying == false) {
        delete player;
        delete board;

        std::cout << "\nYou have quit the game.  GOODBYE!\n";
        exit(1);
    }
}


/*********************************************************************
** Description: Main function
*********************************************************************/
int main(int argc, char** argv) {

	Avoidance();

	return 0;
}
