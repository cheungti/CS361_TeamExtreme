#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include "Player.h"
#include <stdio.h>

#pragma once
class GameBoard {
private:
	Player* player;
	//CPU * cpu;
	char** board;
	char movement;
	//Room * rooms;
	int infectAmount;
	char* drawBox(int, int, int, int, int);

public:
	GameBoard();
	~GameBoard();
	char** createBoard();
	void printBoard();
	void Step();
};

#endif
