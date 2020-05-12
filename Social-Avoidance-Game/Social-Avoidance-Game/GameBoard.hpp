#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include "Player.hpp"
#include <stdio.h>
#include "Bystander.hpp"
#include "Buildings.hpp"
#include "Entity.hpp"
#include "Police.hpp"
#include <vector>

class GameBoard {
private:
	Player* player;
	char** board;
	char movement;
	//Room * rooms;
	int infectAmount;
	char* drawBox(int, int, int, int, int);
	Police* police;
	std::vector<Bystander> bystander;

public:
	GameBoard();
	GameBoard(Player* player);
	~GameBoard();
	char** createBoard();
	void printBoard();
	void Step();
	bool checkBystanderInteraction();
	
};

#endif
