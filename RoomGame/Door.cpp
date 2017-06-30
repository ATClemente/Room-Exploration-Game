/****************************************************************************
** File name: Door.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Door class.
*****************************************************************************/

#include "Door.hpp"

//This function tries to "unlock" the door object
//It takes an item* as a parameter and returns nothing
void Door::attemptToUnlock(Item* key)
{
	//If the integer returned by the useItem function
	//is equal to the ID number of the door, then unlock the door
	if (key->useItem() == this->getIdNum())
	{
		isUnlocked = true;
	}
}

bool Door::checkIfUnlocked()
{
	return isUnlocked;
}

//Constructor simply takes in parameters and passed them along to the WordlObject contructor for most of them.
//The door specific member variable is set by the Door constructor
Door::Door(bool isUnlocked, int idNum, bool visible, bool interactable, std::string interactText) : WorldObject(idNum, visible, interactable, interactText, nullptr)
{
	this->isUnlocked = isUnlocked;
}


Door::~Door()
{

}
