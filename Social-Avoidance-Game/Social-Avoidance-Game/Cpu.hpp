/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Cpu.hpp is the class specification for the
** Cpu class.  Cpu is a base class for all cpu characters.
** Member methods defined in separate implementation file.
*********************************************************************/

#ifndef Cpu_hpp
#define Cpu_hpp

#include <string>

class Cpu
{

public:
	Cpu();
	~Cpu();

	int dieRoll(int high, int low);

	void setType(std::string name);		// Set character type

private:
	std::string type;					// Character type

};

#endif