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

#define C_RED     "\x1b[31m"
#define C_RESET   "\x1b[0m"


class Police : public Entity {

public:
	Police();				// Default constructor
	~Police();				// Destructor
	void penalty(Player* player);

private:

};

#endif
