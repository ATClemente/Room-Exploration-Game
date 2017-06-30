/****************************************************************************
** File name: Door.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Door class.
**				This class inherits from the WorldObject class. Doors function
**				to mark boundaries between rooms and are occasionally locked,
**				requiring a key item in order to open it.
*****************************************************************************/

#ifndef DOOR_HPP
#define DOOR_HPP




#include "WorldObject.hpp"
#include "Key.hpp"


class Door : public WorldObject
{
private:

	bool isUnlocked;

public:

	void attemptToUnlock(Item*);

	bool checkIfUnlocked();

	Door(bool isUnlocked, int idNum, bool visible, bool interactable, std::string interactText);
	~Door();
};

#endif





