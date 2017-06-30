/****************************************************************************
** File name: UserInputValidation.hpp
** Author: Anthony Clemente
** Date: 3/26/17 ---- Updated: 4/25/17
** Description: This file contains the function declarations for separate 
**				functions designed to get and validate user input for ints
**				and doubles as well as a function for returning a string that 
**				does not consist of only "blank" characters.
**
**				For integers and doubles, one allows for a value to be returned from
**				the function (note it will not exit until the user enters
**				an appropriate value), and another version that modifies a
**				reference variable and returns a boolean to indicate success
**				or failure. Two versions for now since I'm not sure what is
**				better necessarily. Functions will likely continue to be
**				updated.
*****************************************************************************/


#ifndef USER_INPUT_VALIDATION_HPP
#define USER_INPUT_VALIDATION_HPP

#include <string>

int getInt(std::string promptForUser = "Enter an integer:");
bool getInt(int &userInt, std::string promptForUser = "Enter an integer:");

double getDouble(std::string promptForUser = "Enter a double:");
bool getDouble(double &userDouble, std::string promptForUser = "Enter a double:");

char getChar(std::string promptForUser = "Enter a char:");
bool getChar(char &userChar, std::string promptForUser = "Enter a char:");

std::string getNonBlankString(std::string promptForUser = "Enter a string:");


#endif
