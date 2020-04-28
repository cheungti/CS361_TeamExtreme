#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Logger.h"
#include "Player.h"
#include "GameBoard.h"

//instantiate class variables
Logger* io;
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
	//setup game board
	board = new GameBoard();
	//setup player
	player = new Player();

	//setup rooms

	//setup entities

	//main game loop
	while (true) {
		player->Step();
		board->Step();
		printf("Player POS: (x, y) ->[%i, %i]\n", player->getX(), player->getY());
	}
}


int main(int argc, char** argv) {
	io = new Logger(true);
	if (argc > 0) {
		for (int i = 0; i < argc; i++) {
			if (argv[i] == "-d") { //debug mode
				io->setDebug(true);
				io->Debug("Debug mode has been enabled by Command Line Argument.");
			}
		}
	}

	io->Debug("hello world");
	//io->Debug("This is string 1", "This is string 2");
	//io->Error("Invalid Type Exception");
	Avoidance();

	return 0;
}