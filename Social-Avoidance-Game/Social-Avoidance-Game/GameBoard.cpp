#include "GameBoard.hpp"

const int boardWidth = 51;
const int boardHeight = 27;

/***************************************************************************
 *				        	  Default Constructor						   *
 * The default constructor instantiates a new gameboard object and defaults*
 *      starting values.                                                   *
 *                                                                         *
 *	Params: N/A															   *
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
    
    this->die = new Die();
    
    //set die height and width
    this->die->setHeightWidth(boardHeight-1, boardWidth-1);
    
    //create gameboard
    this->board = createBoard();

    // Initialize all buildings on game board & update their char on the board
    buildings.push_back(new Buildings("home", "H", 20, 15));
    buildings.push_back(new Buildings("pharmacy", "J", 25, 1));
    buildings.push_back(new Buildings("grocery", "G", 1, 1));
    buildings.push_back(new Buildings("station", "S", 1, 20));
    buildings.push_back(new Buildings("doctor", "D", 1, 25));
    buildings.push_back(new Buildings("work","W", 15, 20));

    for (int i = 0; i < buildings.size(); i++) {
        updateLocation(buildings[i]->getBuildingChar(), buildings[i]->getX(), buildings[i]->getY());
	}
    
     //Randomize entity locations
     for (int i = 0; i < entities.size(); i++){
         randomLocation(entities[i]);
         //set entity position on board
         board[entities[i]->getX()][entities[i]->getY()] = entities[i]->getChar();
     }
     
     
     //Randomize Player location
     randomLocation(player);
     
     //set player's position on board
     board[player->getX()][player->getY()] = player->getChar();

    this->printBoard();
    cout<<endl;
	
}

void GameBoard::updateLocation(string aChar, int row, int column){
    board[row][column] = aChar;
}


/***************************************************************************
*						    Entity Interaction                             *
*	This function will check to see if the player and a given CPU are in   *
*		interaction range												   *
*                                                                          *
*																		   *
*	Params: N/A															   *
*	Return: N/A															   *
*	Author: Bryce Hahn, Tinron Cheung									   *
***************************************************************************/
bool GameBoard::checkBystanderInteraction() {
	for (int i = 0; i < entities.size(); i++) {
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
*	Author: Bryce Hahn, Tinron Cheung									   *
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
 *				        	  Class Deconstructor						   *
 * The default deconstructor destroys the memory for the gameboard pointer *
 *      starting values.                                                   *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
GameBoard::~GameBoard() {
    delete board;
    delete player;

    entities.clear(); //delete the vector efficiently
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
void GameBoard::Step() {
    //clear gameboard
    

    //player movements
    handleKeybinds();
    
    //clear console
    system("clear");
    
    //redraw board
    printBoard();

    //cpu movements

    //check collisions
    //checkBystanderInteraction();
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
void GameBoard::handleKeybinds() { 
    char ascii = 0;
        
    
    //getch() returns an ASCII value. That's why I have an int for getting the input.
    printf("Move (w,a,s,d): ");
    ascii = inputValidationChar();
    if(ascii == 'w') {      //if the character is a 'w'
        //move up
        cout << player->getX();
        cout << " " << player->getY() <<endl;
        updateBoard(player, player->getX()-1, player->getY());
        cout << player->getX();
        cout << " " << player->getY() <<endl;
        
    }
    else if(ascii == 'a') {  //if the character is an 'a'
        //move left
        updateBoard(player, player->getX(), player->getY()-1);
    }
    else if(ascii == 's') { //if the character is an 's'
        //move down
        updateBoard(player, player->getX()+1, player->getY());
    }
    else if(ascii == 'd') { //if the character is a 'd'
        //move right
        updateBoard(player, player->getX(), player->getY()+1);
    }
    else {
        //dont' move
        //printf("Error, invalid move key %c! Please use W, A, S or D", (char)ascii);
    }
    
    moveCPUs();
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
            if(i == 0){
                board[i][j] = '-';
            }else if(i == boardHeight-1){
                board[i][j] = '-';
            }else if(j == 0 || j == boardWidth - 1){
                board[i][j] = '|';
            }else{
                board[i][j] = ' '; //thats the tea
            }
            
        }
    }

	return board;
}

void GameBoard::randomLocation(Entity* anEntity) {
    int row = die->dieRollHeight();
    int column = die->dieRollWidth();
    
    while(occupied(row, column)){
        row = die->dieRollHeight();
        column = die->dieRollWidth();
    }
    
    anEntity->updateLocation(row, column);
}

void GameBoard::randomLocation(Buildings* aBuilding){
    int row = die->dieRollHeight();
    int column = die->dieRollWidth();
    
    while(occupied(row, column)){
        row = die->dieRollHeight();
        column = die->dieRollWidth();
    }
    
    aBuilding->updateLocation(row, column);
}



void GameBoard::updateBoard(Entity* e, int newX, int newY) {
    if(!occupied(newX, newY)){
        emptyPoint(e->getX(), e->getY()); //empty old position
        this->board[newX][newY] = e->getChar(); //set entity char at new x,y
        e->updateLocation(newX, newY);
    }
    
}




char GameBoard::getEntityChar(Entity::EntityType type) {
    if (type == Entity::EntityType::Bystander) {
		return 'B';
	} else if (type == Entity::EntityType::Police) {
		return 'P';
	} else if (type == Entity::EntityType::Player) {
		return '\@';
	} else {
        return 'E';
	}
}


void GameBoard::emptyPoint(int i, int j) {
	this->board[i][j] = " ";
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
*                                Occupied                             *
                                   
***************************************************************************/
bool GameBoard::occupied(int row, int column){
    if(board[row][column] != " "){
        return true;
    }else{
        return false;
    }
        
}

/***************************************************************************
*                                Move CPUs                         *
                                   
***************************************************************************/
void GameBoard::moveCPUs(){
    for(int i = 0; i < entities.size(); i++){
        bool moved = false;
        int looped = 0;
        while(!moved && looped < 20){
            int rand1 = die->dieRoll100()%4;
            switch (rand1) {
                case 0:
                    //move up
                    if(!occupied(entities[i]->getX()-1, entities[i]->getY())){
                       updateBoard(entities[i], entities[i]->getX()-1, entities[i]->getY());
                        moved = true;
                    }
                    break;
                case 1:
                    //move down
                    if(!occupied(entities[i]->getX()+1, entities[i]->getY())){
                       updateBoard(entities[i], entities[i]->getX()+1, entities[i]->getY());
                        moved = true;
                    }
                    break;
                case 2:
                    //move left
                    if(!occupied(entities[i]->getX(), entities[i]->getY() - 1)){
                       updateBoard(entities[i], entities[i]->getX(), entities[i]->getY()-1);
                        moved = true;
                    }
                    break;
                case 3:
                    //move right
                    if(!occupied(entities[i]->getX(), entities[i]->getY()+1)){
                       updateBoard(entities[i], entities[i]->getX(), entities[i]->getY()+1);
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
    
