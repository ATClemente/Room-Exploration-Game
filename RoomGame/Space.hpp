/****************************************************************************
** File name: Space.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the declaration of the Space class. Note
**				this class is an abstract class. The space class is used to
**				represent the various rooms of the house. It uses pointers
**				to determine what rooms are next to it in a given direction
*****************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Menu.hpp"
#include <string>

class Space
{

protected:

	Menu interactionMenu;

	Space* left;
	Space* up;
	Space* right;
	Space* down;

	std::string name;


public:

	Space(Space* left, Space* up, Space* right, Space* down);
	~Space();

	virtual void printInteractionMenu() = 0;

	//This function is overridden in each derived
	//class and allows for interaction with the room based upon
	//that class's interaction menu.
	virtual void interactWithRoom(int) = 0;

	virtual void setLeft(Space*);
	virtual void setUp(Space*);
	virtual void setRight(Space*);
	virtual void setDown(Space*);

	virtual Space* getLeft();
	virtual Space* getUp();
	virtual Space* getRight();
	virtual Space* getDown();

	std::string getName();

};
#endif