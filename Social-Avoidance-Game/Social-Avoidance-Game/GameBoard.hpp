#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include <stdio.h>
#include "Player.hpp"
#include "Bystander.hpp"
#include "Buildings.hpp"
#include "Entity.hpp"
#include "Police.hpp"
#include <cmath>
#include <vector>

using namespace std;

class GameBoard {
private:
	//entities
	Player* player;
	Police* police;
	vector<Bystander*> bystander;
	vector<Entity*> entities;

	char **board;
	char movement;
	//Room * rooms;
	int infectAmount;
	char* drawBox(int, int, int, int, int);
	char getEntityChar(Entity::EntityType type);		//created

public:
	GameBoard();
	GameBoard(Player* player);
	~GameBoard();
	char** createBoard();
	void updateBoard(Entity::EntityType, int, int);
	void printBoard();
	void Step();
	bool checkBystanderInteraction();
	bool overlappingRadius(Entity* e1, Entity* e2);
	bool checkPoliceInteraction();
	void emptyPoint(int i, int j);
};

#endif
