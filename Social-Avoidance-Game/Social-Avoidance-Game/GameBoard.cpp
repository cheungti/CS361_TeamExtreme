#include "GameBoard.hpp"

const int boardWidth = 14; //101;
const int boardHeight = 26; //61;

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

    // Initialize all buildings on game board

    buildings.push_back(new Buildings("home", 60, 50));
    buildings.push_back(new Buildings("pharmacy", 30, 0));
    buildings.push_back(new Buildings("grocery", 0, 0));
    buildings.push_back(new Buildings("police", 0, 50));
    buildings.push_back(new Buildings("doctor", 0, 100));
    buildings.push_back(new Buildings("work", 30, 100));

    //create gameboard
    createBoard();
	
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

    entities.clear(); //delete the vectors efficiently
    buildings.clear();
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

    //clear console
    //system("clear");

    //redraw board
    printBoard();
    
    //player movements
    handleKeybinds();

    //cpu movements


    //check collisions
    checkBystanderInteraction();
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
    cin >> ascii;
    printf("\n");
    if(ascii == 'w') {      //if the character is a 'w'
        //move up
        if (outOfBounds(player->getX(), player->getY() - 1)) {
            updateBoard(*player, player->getX(), player->getY() - 1);
            player->move(0, -1);
        }
    }
    else if(ascii == 'a') {  //if the character is an 'a'
        //move left
        if (outOfBounds(player->getX() - 1, player->getY())) {
            updateBoard(*player, player->getX() - 1, player->getY());
            player->move(-1, 0);
        }
    }
    else if(ascii == 's') { //if the character is an 's'
        //move down
        if (outOfBounds(player->getX(), player->getY() + 1)) {
            updateBoard(*player, player->getX(), player->getY() + 1);
            player->move(0, 1);
        }
    }
    else if(ascii == 'd') { //if the character is a 'd'
        //move right
        if (outOfBounds(player->getX() + 1, player->getY())) {
            updateBoard(*player, player->getX() + 1, player->getY());
            player->move(1, 0);
        }
    } else { //dont' move
        printf("Error, invalid move key %c! Please use W, A, S or D\n", (char)ascii);
    }

}

/***************************************************************************
 *							    Out of Bounds							   *
 * This function will initialize the 2D array of chars used to represent   *
 *      the gameboard, hud, console and inventory. Once initialized, will  *
 *      then fill the board with (currently) TEMPORARY values.             *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: 2D array of chars representing the renderable board            *
 *	Author: Bryce Hahn, Jonathan Dressel								   *
 ***************************************************************************/
bool GameBoard::outOfBounds(int x, int y) {
    if(x >= boardWidth || x < 0 || y >= boardHeight || y < 0) {
        printf("Error, failed to move player to (%i, %i). Position is out of bounds!\n", x, y);
        return false;
    }
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
void GameBoard::createBoard() {
    this->board = new char*[boardHeight]; //define y value size

    for (int i = 0; i < boardHeight; i++) { //columns
        this->board[i] = new char[boardWidth]; //define x value size
        for (int j = 0; j < boardWidth; j++) { //rows
            this->board[i][j] = 't'; //thats the tea
        }
    }

    //set player's position on board
    this->board[player->getX()][player->getY()] = getEntityChar(Entity::EntityType::Player);

    //set cpus positions on board
    //for (int i = 0; i < entities.size(); i++) {
        //printf("test: %i -> %c\n", i, getEntityChar(entities[i]->getType()));
     //   this->board[entities[i]->getX()][entities[i]->getY()] = getEntityChar(entities[i]->getType());
   // }
}



void GameBoard::updateBoard(Entity e, int newX, int newY) {
    emptyPoint(e.getX(), e.getY()); //empty old position
	this->board[newX][newY] = getEntityChar(e.getType()); //set entity char at new x,y
}




char GameBoard::getEntityChar(Entity::EntityType type) {
    if (type == Entity::EntityType::Bystander) {
		return 'B';
	} else if (type == Entity::EntityType::Police) {
		return 'P';
	} else if (type == Entity::EntityType::Player) {
		return '☺';
	} else {
        return 'E';
	}
}


void GameBoard::emptyPoint(int i, int j) {
	this->board[i][j] = ' ';
}

/***************************************************************************
*							        Draw Box							   *
 * This function will initialize the 1D array of chars which will then be  *
 *      filled with a desired box of characters. Implementation involves   *
 *      an external loop to call this function for the height of the box   *
 *      since the board is a 2D array and this function works on one row   *
 *      at a time before returning.                                        *
 *                                                                         *
 *	Params: x,y as the starting positions in the board 2D array. Width,    *
 *              Height representing the size of the box. Iter representing *
 *              the current place in the external loop call.               *
 *	Return: 1D array of chars representing the renderable box row          *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
char* GameBoard::drawBox(int x, int y, int width, int height, int iter) {
    char* ret = new char[width]; //define box width
    if (iter == y || iter == y + height) { //top or bottom row (only ------- chars)
        for (int i = 0; i < width; i++) {
            ret[i] = '-';
        }
    } else {
        for (int i = 0; i < width; i++) {
            if (i == 0 || i == (width - 1)) {
                ret[i] = '|';
            } else {
                ret[i] = ' ';
            }
        }
    }
    return ret;
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
    /*for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            printf("%c", this->board[i][j]);
        }
        if ((i + 1) <= boardWidth) {
            printf("\n");
        }
    }*/
    //board = new char*[14];
	//for(int i = 0; i < 14; i++) {
	//	board[i] = new char[26];
	//}
    //std::locale::global(std::locale("☺"));
	
	for(int i = 1; i < boardWidth; i++) {
		for(int j = 0; j < boardHeight; j++) {
			board[i][j] = ' ';
		}
	}
	
	for(int j = 0; j < boardHeight; j++) {
		board[0][j] = '═';
		board[13][j] = '═';
	}
	
	for(int i = 0; i < boardWidth; i++) {
		board[i][0] = '|';
		board[i][25] = '|';
	}
	
	for(int k = 0; k < 25; k+=5) {
		for(int i = 0; i < 3; i++) {
			board[i][k] = '|';
			board[i][k] = '|';
			board[i][k] = '|';
		}
	}	
	for(int k = 0; k < boardHeight; k+=5) {
		for(int j = k; j < k+4; j++) {
			board[2][j] = '═';
		}
	}
	
	for(int j = 0; j < 5; j++) {
		board[7][j] = '═';
		board[9][j] = '═';
	}

	board[this->player->getY()][this->player->getX()] = '@';
	
    for(int i = 0; i < boardWidth; i++) {
		for(int j = 0; j < boardHeight; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;

}

