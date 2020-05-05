/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Bystander.cpp is the class implementation file for the
** Bystander class.  Bystander is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Bystander.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Bystander::Bystander() {

	Cpu::setType("Bystander");	// Initialize type Bystander
	infected = false;
}

/*********************************************************************
** Description: Set function sets infection true/false
*********************************************************************/
void Bystander::setInfection(bool infect) {

	infected = infect;

}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Bystander::~Bystander() {

}