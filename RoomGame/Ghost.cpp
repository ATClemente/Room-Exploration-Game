/****************************************************************************
** File name: Ghost.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Ghost class.
*****************************************************************************/

#include "Ghost.hpp"

//This function helps determine if the game has been won.
//It takes a parameter of a pointer to a player object and
//returns nothing
void Ghost::checkPlayerForItems(Player* currentPlayer)
{
	//If the picture has not been seen yet, and the picture is in the player's
	//inventory, then set the boolean to true
	if (!hasPicture && currentPlayer->findItemPosInInv(PIC_ID) > -1)
	{
		hasPicture = true;
	}

	//If the stuffed animal has not been seen yet, and the stuffed animal is in the player's
	//inventory, then set the boolean to true
	if (!hasStuffedAnimal && currentPlayer->findItemPosInInv(STUFFED_ID) > -1)
	{
		hasStuffedAnimal = true;
	}

	//If the olives have not been seen yet, and the olives are in the player's
	//inventory, then set the boolean to true
	if (!hasOlives && currentPlayer->findItemPosInInv(OLIVE_ID) > -1)
	{
		hasOlives = true;
	}
}

bool Ghost::getHasPicture()
{
	return hasPicture;
}

bool Ghost::getHasOlives()
{
	return hasOlives;
}

bool Ghost::getHasStuffedAnimal()
{
	return hasStuffedAnimal;
}

Ghost::Ghost()
{
	hasOlives = false;
	hasPicture = false;
	hasStuffedAnimal = false;
}


Ghost::~Ghost()
{
}
