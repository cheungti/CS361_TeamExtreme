/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Cpu.cpp is the class implementation file for
** the Cpu base class.  Member methods are defined within.
*********************************************************************/
#include "Die.hpp"

/*********************************************************************
** Description: Default constructor for Die class
*********************************************************************/
Die::Die() {
    srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
    height = 5;
    width = 5;
}

int Die::dieRollHeight() {

    return rand() % height + 1;

}

int Die::dieRollWidth() {

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
