/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
** Date: 05-05-2020
** Description: Bystander.cpp is the class implementation file for the
** Bystander class.  Bystander is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Bystander.hpp"


/***************************************************************************
 *						    Bystander Constructor						   *
 *	The default Bystander class constructor will initialize the Bystander  *
 *      character symbol, and entity type, with an infected value of false *
 *                                                                         *
 *	Params: N/A															   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Bystander::Bystander() {
    setChar("ф");
	setType(Entity::EntityType::Bystander);	// Initialize type Bystander
    setInfection(false);
}


/***************************************************************************
 *						    Bystander Deconstructor						   *
 *	The Bystander class deconstructor will destroy all of the bystander    *
 *      values.                                                            *
 *                                                                         *
 *	Params: N/A                                                            *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Bystander::~Bystander() {

}


/***************************************************************************
 *						    Bystander Infection                            *
 *	Modify the Bystander's infection status                                *
 *                                                                         *
 *	Params: the new infection value										   *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Bystander::setInfection(bool infect) {
	this->infected = infect;
}


/***************************************************************************
 *						    Bystander Infection                            *
 *	Get the Bystander's infection status                                   *
 *                                                                         *
 *	Params: N/A                                                            *
 *	Return: the current infection value								       *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
bool Bystander::isInfected() {
    return this->infected;
}