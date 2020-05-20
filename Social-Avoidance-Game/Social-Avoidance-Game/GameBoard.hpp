#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include <stdio.h>
#include "Player.hpp"
#include "Bystander.hpp"
#include "Buildings.hpp"
#include "Entity.hpp"
#include "Police.hpp"
#include "Die.hpp"
#include "InputValidation.hpp"

#include <cmath>

#include <vector>

using namespace std;

class GameBoard {
private:
	//entities
	Player* player;
	vector<Entity*> entities;
	Buildings* home;
	Buildings* pharmacy;
	Buildings* grocery;
	Buildings* station;
	Buildings* doctor;
	Buildings* work;
    Die* die;

	string **board;
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
	string** createBoard();
	void updateBoard(Entity*, int, int);
	void printBoard();
	void Step();
	bool checkBystanderInteraction();
	bool overlappingRadius(Entity*, Entity*);
	void emptyPoint(int, int);
    bool occupied(int, int);
    void randomLocation(Entity*);
    void randomLocation(Buildings*);
    void updateLocation(string, int, int);
    void moveCPUs();
	bool outOfBounds(int, int);
};

#endif
