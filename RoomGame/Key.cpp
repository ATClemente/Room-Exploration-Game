/****************************************************************************
** File name: Key.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Key class.
*****************************************************************************/

#include "Key.hpp"

//The key constructor takes in the necessary parameters for an Item as well as
//an int for the Door it is intended for. This member variable is set by the constructor while the
//rest are handed off to the Item constructor
Key::Key(int doorID, std::string name, int idNum, int weight, bool keyItem, std::string description) : Item(name, idNum, weight, keyItem, description)
{
	this->doorID = doorID;
}

Key::~Key()
{
}

//The key item returns the ID for the Door
//it is intended for when it is used
int Key::useItem()
{
	return this->doorID;
}

