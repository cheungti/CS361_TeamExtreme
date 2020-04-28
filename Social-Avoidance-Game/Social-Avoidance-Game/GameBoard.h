#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include "Player.h"

#pragma once
class GameBoard {
private:
	Player p;
	//CPU * cpu;
	char** board;
	char movement;
	//Room * rooms;
	int infectAmount;


public:
	GameBoard();
	~GameBoard();
	char** createBoard();
	void printBoard();
	void Step();
};

#endif
