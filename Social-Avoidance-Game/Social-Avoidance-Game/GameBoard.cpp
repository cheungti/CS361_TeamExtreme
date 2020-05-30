#include "GameBoard.hpp"

const int boardWidth = 51;
const int boardHeight = 27;
const int boxHeight = 5;

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

    // Instantiate bystanders
    for (int i = 0; i < 5; i++) {
        entities.push_back(new Bystander());
    }

    // Instantiate police officers
    for (int i = 0; i < 3; i++) {
        entities.push_back(new Police());
    }

    // Set die height and width
    die = new Die();
    die->setHeightWidth(boardHeight - 1, boardWidth - 1);

    // Create gameboard
    this->board = createBoard();

    // Initialize all buildings on game board & update their char on the board
    buildings.push_back(new Buildings("home", "H", 24, 25));
    buildings.push_back(new Buildings("pharmacy", "J", 13, 2));
    buildings.push_back(new Buildings("grocery", "G", 2, 2));
    buildings.push_back(new Buildings("station", "S", 2, 25));
    buildings.push_back(new Buildings("doctor", "D", 2, 48));
    buildings.push_back(new Buildings("work", "W", 13, 48));
    buildings.push_back(new Buildings("handwash", "N", 13, 25));

    for (int i = 0; i < buildings.size(); i++) {
        printBuildingWalls(buildings[i]);
    }

    //update board building locations
    for (int i = 0; i < buildings.size(); i++) {
        updateLocation(buildings[i]->getBuildingChar(), buildings[i]->getX(), buildings[i]->getY());
    }

    //Randomize entity locations
    for (int i = 0; i < entities.size(); i++) {
        randomLocation(entities[i]);
        //set entity position on board
        board[entities[i]->getX()][entities[i]->getY()] = entities[i]->getChar();
    }

    //set player's position on board
    board[player->getX()][player->getY()] = player->getChar();

    this->printBoard();


}

void GameBoard::updateLocation(string aChar, int row, int column) {
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
void GameBoard::checkBystanderInteraction() {
    for (int i = 0; i < entities.size(); i++) {
        //checks if player is within the infection radius of a cpu

        if (overlappingRadius(this->player, this->entities[i])) {
            //penalty
            if (entities[i]->getChar() == "₱") {
                //if police is in radius
                Police* policeman = static_cast<Police*>(entities[i]);

                //check if Bystander is also in radius
                for (int j = 0; j < entities.size(); j++) {
                    if (j != i) {
                        if (overlappingRadius(this->entities[j], policeman)) {
                            policeman->penalty(this->player);
                            text.push_back("Police caught you near a Bystander. You received a fine!");
                        }


                    }

                }
            }

            // Health deduction for getting too close to bystander
            else if (entities[i]->getChar() == "ф") {
                Bystander* aBystander = static_cast<Bystander*>(entities[i]);
                aBystander->penalty(this->player);

                text.push_back("You got too close to a bystander! Health Deducted: " + std::to_string(aBystander->getHealthDecline()));

            }


        }
    }


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
    int x = e1->getX();
    int y = e1->getY();
    int circle_x = e2->getX();
    int circle_y = e2->getY();
    int rad = e2->getInfectionRadius();
    if ((x - circle_x) * (x - circle_x) +
        (y - circle_y) * (y - circle_y) <= rad * rad)
        return true;
    else
        return false;
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
bool GameBoard::Step() {

    bool keepPlaying = false;

    //player movements
    keepPlaying = handleKeybinds();

    //clear console
    //system("clear"); //system only works on windows

    //check collisions
    if (keepPlaying == true) {
        checkBystanderInteraction();
        checkBuildingInteraction();

        //redraw board
        printBoard();
    }


    return keepPlaying;
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
    printf("w = up, a = left, s = down, d = right, q = Quit Game\n");
    printf("Enter your move (w,a,s,d): ");

    system("/bin/stty raw");
    ascii = tolower(getchar());
    system("/bin/stty cooked");

    if (ascii == 'w') {      //if the character is a 'w'
        //move up
        cout << player->getX();
        cout << " " << player->getY() << endl;
        updateBoard(player, player->getX() - 1, player->getY());
        cout << player->getX();
        cout << " " << player->getY() << endl;

    }
    else if (ascii == 'a') {  //if the character is an 'a'
        //move left
        updateBoard(player, player->getX(), player->getY() - 1);
    }
    else if (ascii == 's') { //if the character is an 's'
        //move down
        updateBoard(player, player->getX() + 1, player->getY());
    }
    else if (ascii == 'd') { //if the character is a 'd'
        //move right
        updateBoard(player, player->getX(), player->getY() + 1);
    }
    else if (ascii == 'q') {
        return false;
    }
    else {
        //dont' move
        printf("Error, invalid move key! '%c' -> Please use W, A, S or D", (char)ascii);
    }

    moveCPUs();
    player->updateHealth(player->getHealth() - 1);

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
    board = new string * [boardHeight]; //define y value size

    for (int i = 0; i < boardHeight; i++) { //columns
        board[i] = new string[boardWidth]; //define x value size
        for (int j = 0; j < boardWidth; j++) { //rows
            if (i == 0) {
                if (j == 0) {
                    board[i][j] = "╔";
                }
                else if (j > 0 && j < boardWidth - 1) {
                    board[i][j] = "═";
                }
                else if (j == boardWidth - 1) {
                    board[i][j] = "╗";
                }
            }
            else if (i > 0 && i < boardHeight - 1) {
                if (j == 0 || j == boardWidth - 1) {
                    board[i][j] = "║";
                }
                else {
                    board[i][j] = " ";
                }
            }
            else if (i == boardHeight - 1) {
                if (j == 0) {
                    board[i][j] = "╚";
                }
                else if (j > 0 && j < boardWidth - 1) {
                    board[i][j] = "═";
                }
                else if (j == boardWidth - 1) {
                    board[i][j] = "╝";
                }
            }
        }
    }


    return board;
}

void GameBoard::randomLocation(Entity* anEntity) {
    int row = die->dieRollHeight();
    int column = die->dieRollWidth();

    while (occupied(row, column)) {
        row = die->dieRollHeight();
        column = die->dieRollWidth();
    }

    anEntity->updateLocation(row, column);
}

void GameBoard::randomLocation(Buildings* aBuilding) {
    int row = die->dieRollHeight();
    int column = die->dieRollWidth();

    while (occupied(row, column)) {
        row = die->dieRollHeight();
        column = die->dieRollWidth();
    }

    aBuilding->updateLocation(row, column);
}


void GameBoard::updateBoard(Entity* e, int newX, int newY) {
    if (!occupied(newX, newY)) {
        emptyPoint(e->getX(), e->getY()); //empty old position
        this->board[newX][newY] = e->getChar(); //set entity char at new x,y
        e->updateLocation(newX, newY);
    }
}


void GameBoard::emptyPoint(int i, int j) {
    this->board[i][j] = " ";
}

void GameBoard::printInstructions() {
    //system("CLS");
    printf("\n----------------------------------------------\n");
    printf("Police - ₱      Player - Δ      Bystander - ф\n");
    printf("Home - H        Pharmacy - J    Doctor - D\n");
    printf("Grocery - G     Station - S     Work - W\n");
    printf("Handwash Station (recharge health) - N\n");
    printf("----------------------------------------------\n");
}

/***************************************************************************
 *								Print Board								   *
 * This function will call a redraw on the gameboard to update new room    *
 *      details and entities.                                              *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung, William Dam						   *
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

    // Display player health score
    cout << "Health: " << this->player->getHealth() << endl;

    // Display message if player has received a fine
    if (this->player->getHasTickets()) {

        cout << "Visit Police Station to pay your fine!" << endl;

    }

    cout << "Visited: ";
    for (int i = 0; i < buildings.size(); i++) {

        // Mark visited, except home and handwash station
        if (buildings[i]->getBuildingName() != "home" && buildings[i]->getBuildingName() != "handwash") {

            if (buildings[i]->getVisited() == true) {
                cout << buildings[i]->getBuildingName() << "  ";
            }

        }

    }
    cout << endl;

    int enters = 5;

    for (vector<string>::const_iterator i = text.begin(); i != text.end(); ++i) {
        cout << *i << endl;
        enters--;
    }

    text.clear();

    for (int i = 0; i < enters; i++) {
        cout << endl;
    }

}

/*********************************************************************
** Description: Print borders around each building
** Arguments: Buildings*
** Return: Void
** Author: William Dam
*********************************************************************/
void GameBoard::printBuildingWalls(Buildings* building) {

    for (int i = -1; i < 2; i++) {
        if (i == 0) {
            board[building->getX()][building->getY() - 1] = "*";
            board[building->getX()][building->getY() + 1] = "*";
        }
        else {
            for (int j = -1; j < 2; j++) {
                board[building->getX() + i][building->getY() + j] = "*";
            }
        }
    }

}

/***************************************************************************
*                                Occupied                             *

***************************************************************************/
bool GameBoard::occupied(int row, int column) {
    if (board[row][column] != " ") {
        return true;
    }
    return false;
}

/***************************************************************************
*                                Move CPUs                         *

***************************************************************************/
void GameBoard::moveCPUs() {
    for (int i = 0; i < entities.size(); i++) {
        bool moved = false;
        int looped = 0;
        while (!moved && looped < 20) {
            int rand1 = die->dieRoll100() % 8;
            switch (rand1) {
            case 0:
                //move up
                if (!occupied(entities[i]->getX() - 1, entities[i]->getY())) {
                    updateBoard(entities[i], entities[i]->getX() - 1, entities[i]->getY());
                    moved = true;
                }
                break;
            case 1:
                //move down
                if (!occupied(entities[i]->getX() + 1, entities[i]->getY())) {
                    updateBoard(entities[i], entities[i]->getX() + 1, entities[i]->getY());
                    moved = true;
                }
                break;
            case 2:
                //move left
                if (!occupied(entities[i]->getX(), entities[i]->getY() - 1)) {
                    updateBoard(entities[i], entities[i]->getX(), entities[i]->getY() - 1);
                    moved = true;
                }
                break;
            case 3:
                //move right
                if (!occupied(entities[i]->getX(), entities[i]->getY() + 1)) {
                    updateBoard(entities[i], entities[i]->getX(), entities[i]->getY() + 1);
                    moved = true;
                }
                break;
            case 4:
                //move top right (diag.)
                if (!occupied(entities[i]->getX() + 1, entities[i]->getY() - 1)) {
                    updateBoard(entities[i], entities[i]->getX() + 1, entities[i]->getY() - 1);
                    moved = true;
                }
                break;
            case 5:
                //move top left (diag.)
                if (!occupied(entities[i]->getX() - 1, entities[i]->getY() - 1)) {
                    updateBoard(entities[i], entities[i]->getX() - 1, entities[i]->getY() - 1);
                    moved = true;
                }
                break;
            case 6:
                //move bottom right (diag.)
                if (!occupied(entities[i]->getX() + 1, entities[i]->getY() + 1)) {
                    updateBoard(entities[i], entities[i]->getX() + 1, entities[i]->getY() + 1);
                    moved = true;
                }
                break;
            case 7:
                //move top left (diag.)
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

/*********************************************************************
** Description: This function will check to see if the player and
** building are in interaction range will set building visited to true.
** Arguments: None
** Return: bool
** Author: Tinron Cheung
*********************************************************************/

bool GameBoard::checkBuildingInteraction() {

    for (int i = 0; i < buildings.size(); i++) {

        if (buildingRadius(this->player, this->buildings[i])) {
            this->buildings[i]->setVisited();

            // Pay ticket at police station
            if (this->player->getHasTickets() && this->buildings[i]->getBuildingName() == "station") {
                this->player->setTickets(false);
            }

            // Recharge health by washing hands
            if (this->buildings[i]->getBuildingName() == "handwash") {
                this->player->updateHealth(100);
                text.push_back("You washed your hands.  Health restored to 100!\n");
            }

            // Can't go home without finishing errands
            if (playerHome() == true) {
                if (errandsDone() == false) {
                    text.push_back("You can't go home yet! You must visit: ");
                    for (int i = 0; i < this->buildings.size(); i++) {
                        if (i != 0 && i != 6) {
                            if (this->buildings[i]->getVisited() == false) {

                                text.push_back(this->buildings[i]->getBuildingName());
                            }
                        }
                    }
                }
                else if (errandsDone() == true && this->player->getHasTickets() == true) {
                    text.push_back("You can't go home yet!\nGo to the police station to pay your fine.");
                }
            }


            return true;
        }
    }

    return false;
}

/*********************************************************************
** Description: This function will check to see if player is on the
** border of building.
** Arguments: e1 as player e2 as the  building
** Return: true if the player is at building boundary
** Author: Tinron Cheung
*********************************************************************/
bool GameBoard::buildingRadius(Entity* e1, Buildings* e2) {
    int playerXcoord = e1->getX();
    int playerYcoord = e1->getY();

    int buildingXcoord = e2->getX();
    int buildingYcoord = e2->getY();


    if ((playerYcoord == buildingYcoord + 2) || (playerYcoord == buildingYcoord - 2))
    {
        if ((playerXcoord == buildingXcoord - 1) || (playerXcoord == buildingXcoord + 1) || (playerXcoord == buildingXcoord))
        {
            return true;
        }
    }
    if ((playerXcoord == buildingXcoord + 2) || (playerXcoord == buildingXcoord - 2))
    {
        if ((playerYcoord == buildingYcoord - 1) || (playerYcoord == buildingYcoord + 1) || (playerYcoord == buildingYcoord))
        {
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Description: Check to see if player is home
** Arguments: None
** Return: bool
** Author: William Dam
*********************************************************************/
bool GameBoard::playerHome() {

    if (buildingRadius(this->player, this->buildings[0])) {
        return true;
    }

    return false;
}

/*********************************************************************
** Description: Check to see if errands are done.  Errands considered
** done if all buildings have been visited.  Note: Handwash station
** and home are not counted.
** Arguments: None
** Return: bool
** Author: William Dam
*********************************************************************/
bool GameBoard::errandsDone() {

    for (int i = 0; i < buildings.size(); i++) {
        if (i != 0 && i != 6 && buildings[i]->getVisited() == false) {
            return false;
        }
    }

    return true;
}