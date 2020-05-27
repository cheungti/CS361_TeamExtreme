#include "GameBoard.hpp"


/***************************************************************************
 *				        	  GameBoard Constructor						   *
 * The player constructor instantiates a new gameboard object and defaults *
 *      starting values with the addition to a player pointer.             *
 *                                                                         *
 *	Params: Player pointer to the instantiated player object from avoidance*
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
GameBoard::GameBoard(Player* player) {
    this->player = player;
    //Instantiate 5 new CPUs
    for (int i = 0; i < 5; i++) {
        entities.push_back(new Bystander());
    }

    // Instantiate 3 new police officers
    for (int i = 0; i < 3; i++) {
        entities.push_back(new Police());
    }
    
    //set die height and width
    die = new Die(boardHeight - 1, boardWidth - 1);
    
    //create gameboard
    this->board = createBoard();

    // Initialize all buildings on game board & update their char on the board
    buildings.push_back(new Buildings("home", "H", 20, 15));
    buildings.push_back(new Buildings("pharmacy", "J", 25, 1));
    buildings.push_back(new Buildings("grocery", "G", 1, 1));
    buildings.push_back(new Buildings("station", "S", 1, 20));
    buildings.push_back(new Buildings("doctor", "D", 1, 25));
    buildings.push_back(new Buildings("work","W", 15, 20));
    buildings.push_back(new Buildings("bathroom", "B", (int)boardWidth/2, (int)boardHeight/2));

    //update board building locations
    for (int i = 0; i < buildings.size(); i++) {
        updateLocation(buildings[i]->getBuildingChar(), buildings[i]->getX(), buildings[i]->getY());
    }
    
    //Randomize entity locations
    for (int i = 0; i < entities.size(); i++){
        randomLocation(entities[i]);
        //set entity position on board
        this->board[entities[i]->getX()][entities[i]->getY()] = entities[i]->getChar();
    }
     
     
    //Randomize Player location
    randomLocation(player);
     
    //set player's position on board
    this->board[player->getX()][player->getY()] = player->getChar();

    this->printBoard();
}


/***************************************************************************
 *				           GameBoard Deconstructor						   *
 * The default deconstructor destroys the memory for the gameboard pointer *
 *      starting values.                                                   *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
GameBoard::~GameBoard() {
    delete this->player;
    delete this->die;

    this->entities.clear(); //delete the vectors efficiently
    this->buildings.clear();

    deleteGameboard();
}


/***************************************************************************
 *				           GameBoard Deconstructor						   *
 * Delete all values from the board 2D array ensuring no mem leaks         *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn              									   *
 ***************************************************************************/
void GameBoard::deleteGameboard() {
    for (int i = 0; i < this->boardWidth; i++) {
        for (int j = 0; j < this->boardHeight; j++) {
            delete[] this->board[j];
        }
        delete[] this->board[i];
    }
}


/***************************************************************************
*						    Entity Interaction                             *
*	This function will check to see if the player and a given CPU are in   *
*		interaction range												   *
*                                                                          *
*																		   *
*	Params: N/A															   *
*	Return: True if any entity radius collides with player radius		   *
*	Author: Bryce Hahn, Tinron Cheung									   *
***************************************************************************/
bool GameBoard::checkBystanderInteraction() {
	for (int i = 0; i < this->entities.size(); i++) {
		//checks if player is within the infection radius of a cpu

        if (overlappingRadius(this->player, this->entities[i])) {
            return true;
        }
	}
	//false if player is not 1 tile away or on same tile as bystander
	return false;
}


/***************************************************************************
*				            Entity Radius Overlap					       *
*	This function will check to see if two entities overlap at the         *
*       infection radius distance.                                         *
*                                                                          *
*																		   *
*	Params: e1 as the first entity (most likely player) e2 as the          *
*               offending entity (most likely a bystander)                 *
*	Return: true if the two entities overlap							   *
*	Author: Bryce Hahn               									   *
***************************************************************************/
bool GameBoard::overlappingRadius(Entity* e1, Entity* e2) {
    int distanceSquared  = pow((e2->getX() - e1->getX()), 2) + pow((e2->getY() - e1->getY()), 2);
    int radiusSumSquared = pow((e1->getInfectionRadius() + e2->getInfectionRadius()), 2);
    if (distanceSquared >= radiusSumSquared)
        return false;
    else
        return true;
}


/***************************************************************************
 *								Player Step								   *
 *	Every game tick the gameboard class takes a Step loop. This function   *
 *		will call for all updates on the gameboard including the print and *
 *      cpu control.                                                       *
 *																		   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
int GameBoard::Step() {
    //player movements
    if (!handleKeybinds()) {
        printf("shutting down...\n");
        return -1; //close return
    }
    
    //redraw board
    printBoard();

    //check collisions
    //checkBystanderInteraction();
    return 0; //safe return, keep looping
}


/***************************************************************************
 *								User Input								   *
 *	Pause the thread to wait for user input for player movement. If user   *
 *      enter's anything other than an acceptable movement key, throw an   *
 *      error and let the player know what their options are.              *
 *																		   *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Jonathan Dresel									   *
 ***************************************************************************/
bool GameBoard::handleKeybinds() { 
    char ascii = 0;   
    
    //getch() returns an ASCII value. That's why I have an int for getting the input.
    printf("Move (W,A,S,D) or press Q to quit ");
	printf("\n");
    

	system("/bin/stty raw");
	ascii = tolower(getchar());
    system("/bin/stty cooked");

    

    if (ascii == 'w') {      //if the character is a 'w'
        //move up
        cout << player->getX();
        cout << " " << player->getY() <<endl;
        updateBoard(player, player->getX()-1, player->getY());
        cout << player->getX();
        cout << " " << player->getY() <<endl;
        
    } else if (ascii == 'a') {  //if the character is an 'a'
        //move left
        updateBoard(player, player->getX(), player->getY()-1);
    } else if (ascii == 's') { //if the character is an 's'
        //move down
        updateBoard(player, player->getX()+1, player->getY());
    } else if(ascii == 'd') { //if the character is a 'd'
        //move right
        updateBoard(player, player->getX(), player->getY()+1);
    } else if (ascii == 'q') { //user asking to quit
        printf("Quit input registered. Ending game!\n");
        return false;
    } else {
        //dont' move
        printf("Error, invalid move key! '%c' -> Please use W, A, S or D", (char)ascii);
    }
    
    moveCPUs();
    return true;
}


/***************************************************************************
 *							    Create Board							   *
 * This function will initialize the 2D array of chars used to represent   *
 *      the gameboard, hud, console and inventory. Once initialized, will  *
 *      then fill the board with (currently) TEMPORARY values.             *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: 2D array of chars representing the renderable board            *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
string** GameBoard::createBoard() {
    string** board = 0;
    board = new string*[boardHeight]; //define y value size

    for (int i = 0; i < boardHeight; i++) { //columns
        board[i] = new string[boardWidth]; //define x value size
        for (int j = 0; j < boardWidth; j++) { //rows
            if (i == 0) {
                if (j == 0) {
				    board[i][j] = "╔";
				} else if (j > 0 && j < boardWidth - 1) {
                    board[i][j] = "═";
				} else if (j == boardWidth - 1) {
                    board[i][j] = "╗";
				}
            } else if (i > 0 && i < boardHeight - 1) {
                if (j == 0 || j == boardWidth - 1) {
                    board[i][j] = "║";
				} else {
				    board[i][j] = " ";
			    }
			} else if (i == boardHeight - 1) {
                if (j == 0) {
				    board[i][j] = "╚";
				} else if (j > 0 && j < boardWidth - 1) {
                    board[i][j] = "═";
				} else if (j == boardWidth - 1) {
                    board[i][j] = "╝";
				}
			}
		}
    }
	return board;
}


/***************************************************************************
 *							 Random Entity Location						   *
 * 
 *                                                                         *
 *	Params: N/A															   *
 *	Return: Entity pointer to the entity we wish to move                   *
 *	Author:                         									   *
 ***************************************************************************/
void GameBoard::randomLocation(Entity* anEntity) {
    int row = die->dieRollHeight();
    int column = die->dieRollWidth();
    
    while (occupied(column, row)) {
        row = die->dieRollHeight();
        column = die->dieRollWidth();
    }
    
    anEntity->updateLocation(column, row);
}


/***************************************************************************
 *						 Random Building Location						   *
 *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: Building pointer to the building we wish to move               *
 *	Author:                         									   *
 ***************************************************************************/
void GameBoard::randomLocation(Buildings* aBuilding) {
    int row = die->dieRollHeight();
    int column = die->dieRollWidth();
    
    while (occupied(column, row)) {
        row = die->dieRollHeight();
        column = die->dieRollWidth();
    }
    
    aBuilding->updateLocation(column, row);
}


/***************************************************************************
 *							    Update Board						       *
 *  Update the board after the movement of an entity. Cleans up entity's   *
 *      old location and modifies the new xy the entity has moved to       *
 *                                                                         *
 *	Params: e for the moved entity, newX/newY for the new x,y locations	   *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn              									   *
 ***************************************************************************/
void GameBoard::updateBoard(Entity* e, int newX, int newY) {
    if (!occupied(newX, newY)) {
        emptyPoint(e->getX(), e->getY()); //empty old position
        this->board[newX][newY] = e->getChar(); //set entity char at new x,y
        e->updateLocation(newX, newY);
    }
}


/***************************************************************************
 *							    Update Location						       *
 *  Similar to updateBoard, will modify the x,y char value on the board arr*
 *                                                                         *
 *	Params: aChar as the new char to print, row/column to show x,y location*
 *      on the board array.                                                *
 *	Return: N/A                                                            *
 *	Author:                           									   *
 ***************************************************************************/
void GameBoard::updateLocation(string aChar, int row, int column) {
    this->board[row][column] = aChar;
}


/***************************************************************************
 *							    Empty Point 						       *
 *  Set the x,y location on the board to an empty space (open)             *
 *                                                                         *
 *	Params: the x,y locations to empty                                	   *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn              									   *
 ***************************************************************************/
void GameBoard::emptyPoint(int i, int j) {
	this->board[i][j] = " ";
}


/***************************************************************************
 *							    Print Key						           *
 *  Loop through the vector of buildings and print their name and          *
 *      respective char value to a key box.                                *
 *                                                                         *
 *	Params: N/A                                                     	   *
 *	Return: N/A                                                            *
 *	Author: Bryce Hahn              									   *
 ***************************************************************************/
void GameBoard::printInstructions() {
    int iter = 0;
    printf("\n----------------------------------------------\n");
    for (int i = 0; i < this->buildings.size(); i++) {
        printf("%s - %c", this->buildings[i]->getBuildingName(), this->buildings[i]->getBuildingChar());
        if (iter == 3) {
            printf("\n"); //3 building prints, new line
            iter = 0;
        } else {
            printf("\t"); //before 3 building prints, print tab
            iter++;
        }
    }
    //printf("Police - ₱      Player - Δ      CPU - ф\n   ");
    //printf("Home - H        RX - J          Doctor - D\n");
    //printf("Store - G       Station - S     Work - W\n  ");
    printf("----------------------------------------------\n");
}


/***************************************************************************
 *								Print Board								   *
 * This function will call a redraw on the gameboard to update new room    *
 *      details and entities.                                              *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
void GameBoard::printBoard() {
    printInstructions();
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            cout << this->board[i][j];
        }
        if ((i + 1) <= boardHeight) {
            printf("\n");
        }
    }
}


/***************************************************************************
 *						      Point Occupied							   *
 * Ensure the desired position is marked as empty.                         *
 *                                                                         *
 *	Params: column as move X, row as move Y								   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
bool GameBoard::occupied(int col, int row) {
    if (board[col][row] != " ") {
        return true;
    }
    return false;
}


/***************************************************************************
 *						        Move CPUs						           *
 *  Call a move on all entities, based on a random dice roll to choose     *
 *      what direction the entity will move.                               *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A                                                            *
 *	Author:                         									   *
 ***************************************************************************/
void GameBoard::moveCPUs() {
    bool moved;
    int looped;
    for (int i = 0; i < entities.size(); i++) {
        moved = false;
        looped = 0;
        while (!moved && looped < 20) {
            int rand1 = die->dieRoll100() % 8;
            switch (rand1) {
                case 0: //move up
                    if (!occupied(entities[i]->getX() - 1, entities[i]->getY())){
                        updateBoard(entities[i], entities[i]->getX() - 1, entities[i]->getY());
                        moved = true;
                    }
                    break;
                case 1: //move down
                    if (!occupied(entities[i]->getX() + 1, entities[i]->getY())){
                        updateBoard(entities[i], entities[i]->getX() + 1, entities[i]->getY());
                        moved = true;
                    }
                    break;
                case 2: //move left
                    if (!occupied(entities[i]->getX(), entities[i]->getY() - 1)){
                        updateBoard(entities[i], entities[i]->getX(), entities[i]->getY() - 1);
                        moved = true;
                    }
                    break;
                case 3: //move right
                    if (!occupied(entities[i]->getX(), entities[i]->getY() + 1)){
                        updateBoard(entities[i], entities[i]->getX(), entities[i]->getY() + 1);
                        moved = true;
                    }
                    break;
                case 4: //move top right (diag.)
                    if (!occupied(entities[i]->getX() + 1, entities[i]->getY() - 1)) {
                        updateBoard(entities[i], entities[i]->getX() + 1, entities[i]->getY() - 1);
                        moved = true;
                    }
                    break;
                case 5: //move top left (diag.)
                    if (!occupied(entities[i]->getX() - 1, entities[i]->getY() - 1)) {
                        updateBoard(entities[i], entities[i]->getX() - 1, entities[i]->getY() - 1);
                        moved = true;
                    }
                    break;
                case 6: //move bottom right (diag.)
                    if (!occupied(entities[i]->getX() + 1, entities[i]->getY() + 1)) {
                        updateBoard(entities[i], entities[i]->getX() + 1, entities[i]->getY() + 1);
                        moved = true;
                    }
                    break;
                case 7: //move top left (diag.)
                    if (!occupied(entities[i]->getX() - 1, entities[i]->getY() + 1)) {
                        updateBoard(entities[i], entities[i]->getX() - 1, entities[i]->getY() + 1);
                        moved = true;
                    }
                    break;
                default:
                    break;
            }
            looped++;
        }
    }
}