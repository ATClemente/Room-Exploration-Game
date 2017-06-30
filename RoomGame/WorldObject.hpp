/****************************************************************************
** File name: WorldObject.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the declaration of the WorldObject class. Note
**				this class is an abstract class. It contains member variables
**				necessary for representing an working with a WorldObject.
**				WorldObjects are found as parts of spaces
*****************************************************************************/

#ifndef WORLD_OBJECT_HPP
#define WORLD_OBJECT_HPP

#include <string>
#include "Player.hpp"

class WorldObject
{

private:

	int idNum;
	bool visible;
	bool interactable;
	std::string interactText;
	Item* objectItem;

public:

	WorldObject(int idNum, bool visible, bool interactable, std::string interactText, Item* objectItem);
	virtual ~WorldObject();

	int getIdNum();
	void setVisibility(bool);
	void setInteractable(bool);
	bool isVisible();
	bool isInteractable();
	std::string getInteractText();

	virtual bool giveItem(Player*);

};
#endif