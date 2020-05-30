/*********************************************************************
** Author: William Dam, Daniel Mesa, Tinron Cheung
** Date: 05-05-2020
** Description: Bystander.cpp is the class implementation file for the
** Bystander class.  Bystander is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Bystander.hpp"

#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS_)
	#define PLATFORM_NAME "windows" // Windows
#elif defined(__APPLE__) || defined(__linux__)
	#define PLATFORM_NAME "apple" // apple
#endif

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Bystander::Bystander() {
    if(PLATFORM_NAME == "windows")
		setChar("B");
	else
		setChar("ф");
	setType(Entity::EntityType::Bystander);	// Initialize type Bystander
	setInfection(true);
	setHealthDecline(10);
	setInfectionRadius(2);
}

/*********************************************************************
** Description: Set function sets infection true/false
*********************************************************************/
void Bystander::setInfection(bool infect) {
	this->infected = infect;
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

