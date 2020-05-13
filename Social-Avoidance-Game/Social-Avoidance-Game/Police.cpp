/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Police.cpp is the class implementation file for the
** Police class.  Police is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Police.hpp"

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Police::Police() {
	dice = new Die();
	updateLocation(dice->randPosition(100), dice->randPosition(100));
	setType(Entity::EntityType::Police);	// Initialize type Police
	setFine(50);
}

/*********************************************************************
** Description: Return fine amount
*********************************************************************/
int Police::getFine() {
	return fine;
}

/*********************************************************************
** Description: set fine amount
*********************************************************************/
void Police::setFine(int anAmount) {
	fine = anAmount;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Police::~Police() {

}