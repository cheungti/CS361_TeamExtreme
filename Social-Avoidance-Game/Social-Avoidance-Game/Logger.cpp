#include "Logger.h"

Logger::Logger(bool debug) {
	this->debug = debug;
}

/***************************************************************************
 *								Debug Print							       *
 *	Print a styalized message of an unspecified number of string messages  *
 *		to stdout IF and ONLY IF the player started the game in debug mode *
 *																		   *
 *	Params: message ... as a list of Variadic string arguments to          *
 *				represent a single message to output					   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn													   *
 ***************************************************************************/
void Logger::Debugs(string message, ...) {
	if (this->debug) {
		va_list args;
		string msg = message;
		//start sorting through message arguments
		va_start(args, message);

		msg = msg + va_arg(args, string); //concatenate messages together

		va_end(args); //we reached the end of the list

		printf("[DEBUG] - %s", message);
	}
}

void Logger::Debug(string message) {
    if (this->debug) {
        printf("[DEBUG] - %s\n", message);
    }
}

/***************************************************************************
 *								Error Print							       *
 *	Print a styalized error with an optional error causation argument to   *
 *      stdout.                                                            *
 *																		   *
 *	Params: error to represent the Error type, reason to represent the     *
 *              optional explanation for the error.                        *
 *	Return: N/A															   *
 *	Author: Bryce Hahn													   *
 ***************************************************************************/
void Logger::Error(string error, string reason) {
	if (reason == "") { //default error output, no need for reason
		printf("[ERROR] - %s", error);
	} else {
		printf("[ERROR] - %s\n\tCausation: %s\n", error, reason);
	}
}

/***************************************************************************
 *								  Set Debug							       *
 *	Alter the boolean value of the debug mode in order to show or hide     *
 *      debug print messages.                                              *
 *																		   *
 *	Params: d as the new value for the debug bool    					   *
 *	Return: N/A															   *
 *	Author: Bryce Hahn													   *
 ***************************************************************************/
void Logger::setDebug(bool d) {
	this->debug = d;
}
