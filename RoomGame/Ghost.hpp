/****************************************************************************
** File name: Ghost.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Ghost class.
**				This class is only used in the final room and helps determine
**				if the player has the correct items needed to win the game.
*****************************************************************************/

#ifndef GHOST_HPP 
#define GHOST_HPP

#include "Player.hpp"


const int PIC_ID = 801;
const int STUFFED_ID = 803;
const int OLIVE_ID = 806;

class Ghost
{
private:

	bool hasPicture;
	bool hasOlives;
	bool hasStuffedAnimal;

public:

	void checkPlayerForItems(Player*);

	bool getHasPicture();
	bool getHasOlives();
	bool getHasStuffedAnimal();

	Ghost();
	~Ghost();
};
#endif