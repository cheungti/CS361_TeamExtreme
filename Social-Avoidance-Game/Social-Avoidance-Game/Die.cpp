/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Cpu.cpp is the class implementation file for
** the Cpu base class.  Member methods are defined within.
*********************************************************************/
#include "Die.hpp"

/*********************************************************************
** Description: Default constructor for Cpu class
*********************************************************************/
Die::Die() {
    srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
    srand(time(NULL));
}

/*********************************************************************
** Description: dieRoll function generates random number and returns
** value.  Receives 2 args for high and low, for example, 6 sided
** die would be sent as dieRoll(6, 1).
*********************************************************************/
int Die::dieRollHeight() {
    //rand() % (max_number - minimum_number) + minimum_number
    return rand() % height + 1;
}

int Die::dieRollWidth() {
    //rand() % (max_number - minimum_number) + minimum_number
    return rand() % width + 1;               // Return roll value
}

int Die::randPosition(int axisConstraint) {
    return rand() % axisConstraint + 1;
}

void Die::setHeightWidth(int aHeight, int aWidth) {
    height = aHeight;
    width = aWidth;
}

int Die::dieRoll100() {
    return rand() % 100 + 1;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Die::~Die() {

}
