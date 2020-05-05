#ifndef LOGGER_H
#define LOGGER_H
//includes
#include <cstdio>
#include <stdio.h>
#include <cstdarg>
#include <string>

using namespace std;


#pragma once
class Logger {
public:
	//constructor & deconstructor
	Logger(bool);

	void Debugs(string, ...);
	void Debug(string);
	void Error(string, string = "");
	void setDebug(bool);

	bool debug = false;
};

#endif