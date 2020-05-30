#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//class imports
#include <stdio.h>
#include <cmath>
#include <vector>
#include "Player.hpp"
#include "Bystander.hpp"
#include "Buildings.hpp"
#include "Entity.hpp"
#include "Police.hpp"
#include "Die.hpp"


#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_YELLOW  "\x1b[33m"
#define C_BLUE    "\x1b[34m"
#define C_MAGENTA "\x1b[35m"
#define C_CYAN    "\x1b[36m"
#define C_RESET   "\x1b[0m"

using namespace std;

class GameBoard {
private:
	//entities
	Player* player;
	vector<Entity*> entities;
	vector<Buildings*> buildings;
	vector<string> text;
    Die* die;

	string **board;
	char movement;
	//Room * rooms;
	int infectAmount;
	char* drawBox(int, int, int, int, int);
	bool handleKeybinds();
	string **textBox;

public:
	GameBoard();
	GameBoard(Player*);
	~GameBoard();
	string** createBoard();
	void updateBoard(Entity*, int, int);
	void printInstructions();
	void printBoard();
	bool Step();
	void checkBystanderInteraction();
	bool overlappingRadius(Entity*, Entity*);
	void emptyPoint(int, int);
    bool occupied(int, int);
    void randomLocation(Entity*);
    void randomLocation(Buildings*);
    void updateLocation(string, int, int);
    void moveCPUs();
	bool outOfBounds(int, int);
	void printBuildingWalls(Buildings* building);
	bool checkBuildingInteraction();
	bool buildingRadius(Entity*, Buildings*);
	bool playerHome();
	bool errandsDone();
};

#endif
