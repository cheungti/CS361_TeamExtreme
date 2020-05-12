#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Logger.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

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
	//setup player
	player = new Player();
	//setup game board
	board = new GameBoard(player);
	board->printBoard(); //draw gameboard


	//setup rooms

	//setup entities

	//main game loop
	while (true) {
		player->Step();
		board->Step();
		//printf("Player POS: (x, y) ->[%i, %i]\n", player->getX(), player->getY()); //this should eventually be sent to gameboard hug to update player's X,Y print debug
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

	//io->Debug("hello world");
	Avoidance();

	return 0;
}