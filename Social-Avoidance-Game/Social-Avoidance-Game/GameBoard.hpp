#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include <stdio.h>
#include "Player.hpp"
#include "Bystander.hpp"
#include "Buildings.hpp"
#include "Entity.hpp"
#include "Police.hpp"
#include "Windows.h"
#include <cmath>
#include <conio.h>
#include <vector>

using namespace std;

class GameBoard {
private:
	//entities
	Player* player;
	vector<Entity*> entities;
	vector<Buildings*> buildings;

	char **board;
	char movement;
	//Room * rooms;
	int infectAmount;
	char* drawBox(int, int, int, int, int);
	char getEntityChar(Entity::EntityType);		//created
	void handleKeybinds();

public:
	GameBoard();
	GameBoard(Player*);
	~GameBoard();
	char** createBoard();
	void updateBoard(Entity, int, int);
	void printBoard();
	void Step();
	bool checkBystanderInteraction();
	bool overlappingRadius(Entity*, Entity*);
	void emptyPoint(int, int);
};

#endif
