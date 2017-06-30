/****************************************************************************
** File name: Fridge.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Fridge class.
**				This class inherits from the WorldObject class. The fridge
**				has a door so it can either be locked or unlocked.
*****************************************************************************/

#ifndef FRIDGE_HPP
#define FRIDGE_HPP

#include "Door.hpp"

class Fridge : public WorldObject
{

private:

	Door* fridgeDoor;

public:

	void unlockFridgeDoor(Item* key);

	bool canGiveItem();

	Fridge(int idNum, bool visible, bool interactable, std::string interactText, Item* objectItem);

	~Fridge();
};
#endif
