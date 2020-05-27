/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Police.cpp is the class implementation file for the
** Police class.  Police is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Police.hpp"


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
    setChar("₱");
	setFine(50);
}


/***************************************************************************
 *						    Police Deconstructor						   *
 *	The Police class deconstructor will destroy all of the Police values   *
 *                                                                         *
 *	Params: N/A                                                            *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
Police::~Police() {

}


/***************************************************************************
 *						        Get Police Fine				     		   *
 *	Return a value for the fine                                            *
 *                                                                         *
 *	Params: N/A                                                            *
 *	Return: The current fine value										   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
int Police::getFine() {
	return this->fine;
}


/***************************************************************************
 *						        Set Police Fine				     		   *
 *	Modify a new value for the fine                                        *
 *                                                                         *
 *	Params: The new fine value                                             *
 *	Return: N/A															   *
 *	Author: William Dam, Daniel Mesa, Tinron Cheung                  	   *
 ***************************************************************************/
void Police::setFine(int anAmount) {
	this->fine = anAmount;
}