#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <csignal>
#include "Player.hpp"
#include "GameBoard.hpp"

//instantiate class variables
Player* player;
GameBoard* board;

//define function declarations
void Avoidance();
void signalHandler(int);

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

    //game ending input registers
    signal(SIGINT, signalHandler);
    int tickReturn = 0;
    
	//main game loop
    while (tickReturn == 0) {
        tickReturn = board->Step();
    }
}


/***************************************************************************
 *								Signal Handler							   *
 *	Interpret and return signal int for a user break call                  *
 *																		   *
 *	Params: signum representing type of quit signal to send                *
 *	Return: N/A															   *
 *	Author: Bryce Hahn                                                     *
 ***************************************************************************/
void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    delete board;
    delete player;

    // terminate program  
    exit(signum);
}


int main(int argc, char** argv) {
	Avoidance();
	return 0;
}
