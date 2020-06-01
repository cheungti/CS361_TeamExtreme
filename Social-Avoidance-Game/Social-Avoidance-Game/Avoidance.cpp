#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Player.hpp"
#include "GameBoard.hpp"

#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_RESET   "\x1b[0m"


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
					 printf(C_GREEN "You made it home alive!  YOU WIN!!!\n" C_RESET);
                break;
            }

        } else {
				printf(C_RED "You ran out of health and died!  GAME OVER :(\n" C_RESET);
            break;
        }
    }

    if (keepPlaying == false) {
        std::cout << "\nYou have quit the game.  GOODBYE!\n";
    }
}

/*********************************************************************
** Description: Main function
*********************************************************************/
int main(int argc, char** argv) {

	Avoidance();

	return 0;
}
