#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include "Player.hpp"
#include <stdio.h>

class GameBoard {
private:
	Player* player;
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
