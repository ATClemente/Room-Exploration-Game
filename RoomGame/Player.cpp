/****************************************************************************
** File name: Player.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the definition of the Player class.
*****************************************************************************/

#include "Player.hpp"
#include "Key.hpp"
#include "Flashlight.hpp"

#include <iostream>

//The contructor for the player takes a pointer to a space which indicates
//the starting room. Note that this can be set to nullptr but must be changed using a
//member function before working with the player
Player::Player(Space* startingRoom)
{
	//Set the starting carry weight to 0
	currentCarryWeight = 0;

	//Set the room with the pointer used as a parameter
	currentRoom = startingRoom;

	//Set the member variable boolean to false
	gameIsOver = false;

	//Add a starting item to the player's inventory
	inventory.push_back(new Flashlight(5, "Your trusty flashlight", 888, 1, true, "You've had this flashlight since you were a kid. Maybe it's almost time for a new one."));
}

//The destructor must make sure to delete the Item* in the player's inventory
Player::~Player()
{
	//Loop through the vector and call delete for each pointer
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		delete inventory.at(i);
	}
}

void Player::setCurrentRoom(Space* currentRoom)
{

	this->currentRoom = currentRoom;

}

Space* Player::accessRoom()
{
	return currentRoom;
}

//This function adds an item to the player's inventory.
//It takes a parameter of an Item* to the item that will be added
//and it return nothing
void Player::addItemToInventory(Item* newItem)
{
	//Push the item into the vector
	inventory.push_back(newItem);

	//Add the weight of the object to the carry weight.
	//Note that the setup of the program is such that
	//by this point it has already been verified the user
	//has enough "weight" left to take on the item
	currentCarryWeight += newItem->getWeight();
}

//This function allows for an item to be removed form the player's inventory.
//It returns a boolean to indicate whether or not the process was successful
//(it can fail if the item is a key item that the user wants to remove). It
//takes an int as a parameter that represents the users choice from the list
//of inventory items
bool Player::removeItemFromInv(int index)
{
	//If the user entered an index higher than the indices in the vector,
	//return false.
	if (index > inventory.size())
	{
		return false;
	}

	//The loswest valid input is 1, and the item must not be a key item
	if (index - 1 > -1 && !inventory.at(index - 1)->isKeyItem())
	{
		//Subtract the weight of the item from the current carry weight
		currentCarryWeight -= inventory.at(index - 1)->getWeight();

		//Delete the memory pointed to by the item*
		delete inventory.at(index - 1);

		//Erase the pointer form the vector
		inventory.erase(inventory.begin() + index - 1);

		return true;
	}
	else
	{
		return false;
	}

}

bool Player::getGameIsOver()
{
	return gameIsOver;
}

void Player::setGameOver(bool gameOver)
{
	gameIsOver = gameOver;
}

Item* Player::getInvItem(int index)
{
	return inventory.at(index);
}

//This function finds the index of an item based upon its ID number.
//It takes an int that will represent the ID num, and returns an int that is
//the index the item was found at
int Player::findItemPosInInv(int itemId)
{
	//Loop through the vector and return the index of the first item that
	//matches the ID.
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i)->getIdNum() == itemId)
		{
			return i;
		}
	}

	//If the loop does not find the item, then it is not in the vector and
	//a value of -1 is returned
	return -1;
}

int Player::getPlayerCurrentCarryWeight()
{
	return currentCarryWeight;
}

//This function simply prints the inventory of the player and numbers each item
//It needs no parameters and returns nothing
void Player::showInventory()
{
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		std::cout << i + 1 << "." << std::endl;
		std::cout << inventory.at(i)->getName() << std::endl;
		std::cout << "Weight: " << inventory.at(i)->getWeight() << std::endl;
		std::cout << "Description: " << inventory.at(i)->getDescription() << std::endl;
		std::cout << std::endl;
	}
}

//This function allows the player to "interact" with their inventory in a
//limited way. It take an integer that is the players choice of item the want
//to interact with. The function returns nothing.
void Player::interactWithInventory(int index)
{
	//Make sure the choice is in a valid range
	//If not print a warning
	if (index - 1 <= -1 || index > inventory.size())
	{
		std::cout << "There is no item at this position" << std::endl;
	}

	//If the choice is in a good range, then check if the ID number is greater than 800. 
	//(All items this game defines as interactable from the invetory has an ID in the 800s)
	//The only item that meets this description but is not usable from the inventory menu is the
	//flashlight. The ID number of the flashlight is 888. 
	else if (inventory.at(index - 1)->getIdNum() >= 800 && inventory.at(index - 1)->getIdNum() != 888)
	{
		//Call the useItem function on the item
		inventory.at(index - 1)->useItem();
	}
	else
	{
		//Print a warning to the user
		std::cout << "You can't use that here!" << std::endl;
	}
}




