/*********************************************************************
** Author: William Dam, Daniel Mesa
** Date: 05-05-2020
** Description: Cpu.hpp is the class specification for the
** Cpu class.  Cpu is a base class for all cpu characters.
** Member methods defined in separate implementation file.
*********************************************************************/
#ifndef Die_hpp
#define Die_hpp

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

class Die {
    
private:
    int height;
    int width;

public:
	Die();
	~Die();

	int dieRollHeight();
    int dieRollWidth();
	int randPosition(int);
    void setHeightWidth(int aHeight, int aWidth);
    int dieRoll100();
};

#endif
