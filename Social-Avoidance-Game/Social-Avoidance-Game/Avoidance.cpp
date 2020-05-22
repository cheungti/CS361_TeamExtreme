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
 *	Author: Bryce Hahn, Tinron Cheung, 									   *
 ***************************************************************************/
void Avoidance() {
	//setup player
	player = new Player();
	//setup game board
	board = new GameBoard(player);
    
	//main game loop

    while(true) {
        board->Step();
    }
    
}


int main(int argc, char** argv) {
	Avoidance();
	return 0;
}
