/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Bystander.cpp is the class implementation file for the
** Bystander class.  Bystander is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Bystander.hpp"

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Bystander::Bystander() {
	dice = new Die();
	updateLocation(dice->randPosition(100), dice->randPosition(100));
	setType(Entity::EntityType::Bystander);	// Initialize type Bystander
	infected = false;
}

/*********************************************************************
** Description: Set function sets infection true/false
*********************************************************************/
void Bystander::setInfection(bool infect) {

	infected = infect;

}
/***************************************************************************
 ** Description: return infected or not								   *
 ***************************************************************************/
bool Bystander::isInfected() {
    return infected;
}


/*********************************************************************
** Description: Class destructor
*********************************************************************/
Bystander::~Bystander() {

}