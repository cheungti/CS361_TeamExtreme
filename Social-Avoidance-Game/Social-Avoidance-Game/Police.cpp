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
	#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
		setChar(C_RED "P" C_RESET);
	#elif defined(__APPLE__) || defined(__linux__)
		setChar(C_RED "₱" C_RESET);
	#endif

	setType(Entity::EntityType::Police);	// Initialize type Police
	setInfectionRadius(6);
}


/*********************************************************************
** Description: Penalty
** Penalize player for being within radius
*********************************************************************/
void Police::penalty(Player* player){

	player->setTickets(true);

}
