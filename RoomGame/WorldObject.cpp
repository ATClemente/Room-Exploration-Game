/****************************************************************************
** File name: WorldObject.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the definition of the WorldObject class.
*****************************************************************************/

#include "WorldObject.hpp"
#include <iostream>

//Constructor takes in the parameters and sets the member variables appropriately
WorldObject::WorldObject(int idNum, bool visible, bool interactable, std::string interactText, Item* objectItem)
{
	this->idNum = idNum;
	this->visible = visible;
	this->interactable = interactable;
	this->interactText = interactText;
	this->objectItem = objectItem;
}

//The constructor must make sure to free the Item*
//since in all uses here it is allocated via new operator
//in derived class
WorldObject::~WorldObject()
{
	delete objectItem;
}

int WorldObject::getIdNum()
{
	return idNum;
}

void WorldObject::setVisibility(bool vis)
{
	visible = vis;
}

void WorldObject::setInteractable(bool inter)
{
	interactable = inter;
}

bool WorldObject::isVisible()
{
	return visible;
}

bool WorldObject::isInteractable()
{
	return interactable;
}

std::string WorldObject::getInteractText()
{
	return interactText;
}

//This function adds the item in the WorldObject to the Player inventory.
//It returns a bool to indicate success or failure and takes as a parameter the pointer
//to the Player
bool WorldObject::giveItem(Player* currentPlayer)
{
	//If the Item pointer is not null, this means there is an item to give
	if(objectItem != nullptr)
	{
		//If the weight of the item to give the player plus the current weight of items the player is carrying,
		//is NOT greater than the defined max carry weight for the player, then the item is added
		if (!(currentPlayer->getPlayerCurrentCarryWeight() + objectItem->getWeight() > MAX_CARRY_WEIGHT))
		{
			//Use proper Player class member function to add the item pointer to the inventory
			currentPlayer->addItemToInventory(objectItem);

			//Set the Item* pointer member variable to null pointer
			objectItem = nullptr;

			//Indicate success to the caller
			return true;
		}
		else
		{
			//Otherwise, print a warning to the player
			std::cout << "You can not carry all of these items!" << std::endl;

			//Indicate failure
			return false;
		}
		
	}
	else
	{
		//If the function is accidentally called on a WorldObject that has no item,
		//print a warning.
		std::cout << "This object has nothing to give!" << std::endl;
		return false;
	}
}
