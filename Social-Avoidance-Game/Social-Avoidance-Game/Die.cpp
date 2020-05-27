/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Cpu.cpp is the class implementation file for
** the Cpu base class.  Member methods are defined within.
*********************************************************************/
#include "Die.hpp"


/***************************************************************************
 *							    Dice Constructor						   *
 *	The default Dice class constructor will initialize the random seed time*
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Die::Die() {
	srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
}


/***************************************************************************
 *							    Dice Constructor						   *
 *	The sized Dice class constructor will initialize the random seed time  *
 *      and initialize the width and height values                         *
 *                                                                         *
 *	Params: width for boardWidth, height for boardHeight    			   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Die::Die(int width, int height) {
    srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
    setBoardSize(width, height);
}


/***************************************************************************
 *							  Dice Deconstructor						   *
 *	The default Dice class deconstructor will destroy the die's values     *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Die::~Die() {

}


/***************************************************************************
 *							Dice Roll Height                               *
 *	Roll for a random height based on the Board Height constraint          *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: Randomly rolled height										   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
int Die::dieRollHeight() {
    return rand() % this->height + 1;
}


/***************************************************************************
 *							 Dice Roll Width                               *
 *	Roll for a random width based on the Board Width constraint            *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: Randomly rolled width   									   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
int Die::dieRollWidth() {
    return rand() % this->width + 1;
}


/***************************************************************************
 *							   Dice Set Size                               *
 *	Modify the Die Width Height constraints                                *
 *                                                                         *
 *	Params: Width for the width const, height for the height const		   *
 *	Return: N/A                       									   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Die::setBoardSize(int width, int height) {
    this->width = width;
    this->height = height;
}


/***************************************************************************
 *							  Dice Roll 100                                *
 *	Roll for a random number int he 1 to 100 range                         *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: Randomly rolled int from 1 to 100							   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
int Die::dieRoll100(){
    return rand() % 100 + 1;
}