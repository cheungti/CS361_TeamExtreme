#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include "Player.hpp"
#include "Cpu.hpp"
#include <stdio.h>

class GameBoard {
private:
	Player* player;
	Cpu * cpu;
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
