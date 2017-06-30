/****************************************************************************
** File name: Fridge.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the defintion of the Fridge class.
*****************************************************************************/

#include "Fridge.hpp"


//The fridge object contructor takes all the necessary parameters needed to make a WorldObject and passes them along
Fridge::Fridge(int idNum, bool visible, bool interactable, std::string interactText, Item* objectItem) : WorldObject(idNum, visible, interactable, interactText, objectItem)
{
	//The fridge door is allocated dynamically in the constructor
	fridgeDoor = new Door(false, 207, true, true, "The door to the fridge");
}

//The destructor simply needs to deallocate the memory used for the fridge door
Fridge::~Fridge()
{
	delete fridgeDoor;
}

//This funtion allows for trying to unlock the fridge door
//It takes an Item* and returns nothing. This function 
//essentially takes in a parameter and passes it along to the 
//Door member fucntion used for unlocking
void Fridge::unlockFridgeDoor(Item* key)
{
	fridgeDoor->attemptToUnlock(key);
}

bool Fridge::canGiveItem()
{
	return fridgeDoor->checkIfUnlocked();
}
