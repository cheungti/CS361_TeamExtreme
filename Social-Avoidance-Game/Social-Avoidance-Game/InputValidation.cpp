/******************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description: One function called InputValidation that takes in a pointer
** to a string loops through the characters to validate that each character
** is an integer. It returns a bool value; true if all are integers,
** false if not.
** One function called InputValidationChar that takes in a pointer
** to a string loops through the characters to validate that each character
** is of type char. It returns a bool value; true if one char,
** false if not.
*****************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <string>
#include "InputValidation.hpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::getline;


int inputValidation()
{
    string string;
    bool bValid = true;
    
    getline(cin, string);
    

    
    do{
        bValid = true;
        int size = string.length();
        
        //loop through each character
        for (int k = 0; k < size ; k++)
        {
            //determine if each character is a digit
            //through the isdigit function.
            if(! isdigit(string[k]))
            {
                //if isdigit returns false (not a digit)
                //change bool value to false
                bValid = false;

            }
            
        }
        
        
        if(!bValid)
        {
            cout << "Please enter a valid integer. ";
            cin.clear();
            getline(cin, string);
        }
    }
    while(!bValid);
    
    stringstream strStream;
    strStream << string;
    int checkPositive = -1 ;
    strStream >> checkPositive;
    return checkPositive;
}

char inputValidationChar()
{
    string string;
    bool bValid = true;
    static int functionCounter = 0;
    
    getline(cin, string);
    
    
    
    
    do{
        bValid = true;
        int size = string.length();
        
        
        
        //loop through each character
        for (int k = 0; k < size ; k++)
        {
            if(size != 1)
            {
                bValid = false;
            }
            //determine if each character is a digit
            //through the isdigit function.
            if(! isalpha(string[k]))
            {
                //if isdigit returns false (not a digit)
                //change bool value to false
                bValid = false;
            }
            
        }
        
        if(!bValid)
        {
            cout << "Please enter a valid character. ";
            cin.clear();
            getline(cin, string);
        }
    }
    while(!bValid);
    
    //from string to char
    stringstream strStream;
    strStream << string;
    char isChar = 'x' ;
    strStream >> isChar;
    functionCounter++;
    return isChar;
}

string inputValidationString()
{
    string string;
    bool bValid = true;
    
    getline(cin, string);
    
    
    
    
    do{
        bValid = true;
        int size = string.length();
        
        
        
        //loop through each character
        for (int k = 0; k < size ; k++)
        {

            //determine if each character is a digit
            //through the isdigit function.
            if(! isalpha(string[k]))
            {
                //if isdigit returns false (not a digit)
                //change bool value to false
                bValid = false;
            }
            
        }
        
        if(!bValid)
        {
            cout << "Please enter a valid string. ";
            cin.clear();
            getline(cin, string);
        }
    }
    while(!bValid);
    
    return string;
}


char inputValidationEnter()
{
    string string;
    bool bValid = true;
    static int functionCounter = 0;
    
    getline(cin, string);
    

    
    do{
        bValid = true;
        int size = string.length();
        
        
        
        //loop through each character
        for (int k = 0; k < size ; k++)
        {
            if(size != 1)
            {
                bValid = false;
            }
            //determine if each character is a digit
            //through the isdigit function.
            if(string[k] != '10')
            {
                //if isdigit returns false (not a digit)
                //change bool value to false
                bValid = false;
            }
            
        }
        
        if(!bValid)
        {
            cout << "Please press enter to continue: ";
            cin.clear();
            getline(cin, string);
        }
    }
    while(!bValid);
    
    //from string to char
    stringstream strStream;
    strStream << string;
    char isChar = 'x' ;
    strStream >> isChar;
    functionCounter++;
    return isChar;
}
