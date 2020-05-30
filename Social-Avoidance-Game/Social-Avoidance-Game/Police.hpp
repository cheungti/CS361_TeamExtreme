/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Police.hpp is the class specification file for the
** Police class.  Police is a derived class of the Cpu base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Police_hpp
#define Police_hpp
#include "Entity.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>

class Police : public Entity {

public:
	Police();				// Default constructor
	void penalty(Player* player);
};

#endif