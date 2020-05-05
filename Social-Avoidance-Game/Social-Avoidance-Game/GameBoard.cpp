#include "GameBoard.hpp"

const int boardWidth = 100;
const int boardHeight = 60;


/***************************************************************************
 *				        	  Default Constructor						   *
 * The default constructor instantiates a new gameboard object and defaults*
 *      starting values.                                                   *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn, Tinron Cheung									   *
 ***************************************************************************/
GameBoard::GameBoard() {
    this->board = createBoard();
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

    //redraw board

    //clear console

    //redraw console

    //clear HUD/Inventory

    //redraw HUD/Inventory

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
char** GameBoard::createBoard() {
    char** board = 0;
    board = new char*[boardHeight]; //define y value size

    for (int i = 0; i < boardHeight; i++) { //columns
        if (i > 10) { //fill the gameboard with temp t's
            board[i] = new char[boardWidth]; //define x value size
            for (int j = 0; j < boardWidth; j++) { //rows
                board[i][j] = 't'; //thats the tea
            }
        } else {  //make a box in the first 10 spaces
            //print user hud
            board[i] = drawBox(0, 0, boardWidth, 10, i);
        }
    }
	return board;
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
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            printf("%c", this->board[i][j]);
        }
        if ((i + 1) <= boardWidth) {
            printf("\n");
        }
    }
}
