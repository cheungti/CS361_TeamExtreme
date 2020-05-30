/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Police.cpp is the class implementation file for the
** Police class.  Police is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Police.hpp"


#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
	#define PLATFORM_NAME "windows" // Windows
#elif defined(__APPLE__) || defined(__linux__)
	#define PLATFORM_NAME "apple" // apple
#endif


/***************************************************************************
 *						      Police Constructor						   *
 *	The default Police class constructor will initialize the Polices'      *
 *      default values                                                     *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa                                       *
 ***************************************************************************/
Police::Police() {
	setType(Entity::EntityType::Police);	// Initialize type Police
    if(PLATFORM_NAME == "windows")
		setChar("P");
	else
		setChar("₱");
	setInfectionRadius(6);
}


/***************************************************************************
 *						        Police Ticket						       *
 *	This function gives the player a ticket value whenever interacted with *
 *      a police or too close to a bystander                               *
 *                                                                         *
 *	Params: Player pointer to change ticket status                         *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa                                       *
 ***************************************************************************/
void Police::penalty(Player* player) {
	player->setTickets(true);
}