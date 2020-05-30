/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
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
    setChar("ф");
	setType(Entity::EntityType::Bystander);	// Initialize type Bystander
	infected = true;
	setHealthDecline(10);
	setInfectionRadius(2);
}

/*********************************************************************
** Description: Set function sets infection true/false
*********************************************************************/
void Bystander::setInfection(bool infect) {

	infected = infect;

}
/*********************************************************************
 ** Description: return infected or not
*********************************************************************/
bool Bystander::isInfected() {

    return infected;

}


/*********************************************************************
** Description: Class destructor
*********************************************************************/
Bystander::~Bystander() {

}

/*********************************************************************
** Description: Penalty
** Penalize player for being within radius
*********************************************************************/
void Bystander::penalty(Player* player){

	if(isInfected()){

		int currentHealth = player->getHealth();
		int newHealth = currentHealth - healthDecline;

		if(newHealth < 0){
			newHealth = 0;
		}

		player->updateHealth(newHealth);
	}
	
}

/*********************************************************************
** Description: Set Health Decline
** set deduction to health for infected Bystanders
*********************************************************************/

void Bystander::setHealthDecline(int deduction){
	healthDecline = deduction;
}

/*********************************************************************
** Description: Get Health Decline
** get deduction to health for infected Bystanders
*********************************************************************/
int Bystander::getHealthDecline(){
	return healthDecline;
}

