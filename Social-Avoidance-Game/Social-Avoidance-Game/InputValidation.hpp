/******************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin: This contains the function declaration for InputValidation
** source code. This function takes in a pointer to a string loops through
** the characters to validate that each character is an integer. It returns
** a bool value; true if all are integers, false if not.
**This contains the function declaration for InputValidationChar
** source code. This function takes in a pointer to a string loops through
** the characters to validate that each character is a char. It returns
** a bool value; true if one char, false if not.
******************************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP
#include <iostream>
#include <string>
using std::string;

int inputValidation();
char inputValidationChar();
string inputValidationString();
char inputValidationEnter();

#endif

