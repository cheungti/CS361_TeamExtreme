#ifndef GAMEBOARD_H
#define GAMEBOARD_H
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
	//private class objects
	Player* player;
	vector<Entity*> entities;
	vector<Buildings*> buildings;
	vector<string> text;
	Die* die;

	//private class vars
	string** textBox;
	string** board;
	char movement;
	int infectAmount;

	//private class methods
	bool handleKeybinds();
	char getWindowsInput();
	void checkBystanderInteraction();
	bool overlappingRadius(Entity*, Entity*);
	void emptyPoint(int, int);
	bool occupied(int, int);
	void randomLocation(Entity*);
	void randomLocation(Buildings*);
	void updateLocation(string, int, int);
	void moveCPUs();
	void printBuildingWalls(Buildings*);
	bool checkBuildingInteraction();
	bool buildingRadius(Entity*, Buildings*);
	void updateBoard(Entity*, int, int);
	void printInstructions();
	void printBoard();
	void clearScreen();

public:
	GameBoard(Player*);
	~GameBoard();
	string** createBoard();
	string** createBoardWindows();
	bool Step();
	bool playerHome();
	bool errandsDone();
};

#endif
