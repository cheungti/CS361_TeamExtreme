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
	setType(Entity::EntityType::Police);	// Initialize type Police
	if (PLATFORM_NAME == "windows")
		setChar("P");
	else
		setChar("₱");
	setInfectionRadius(6);
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Police::~Police() {

}

/*********************************************************************
** Description: Penalty
** Penalize player for being within radius
*********************************************************************/
void Police::penalty(Player* player){

	player->setTickets(true);

}
