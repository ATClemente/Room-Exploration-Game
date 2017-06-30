/****************************************************************************
** File name: Safe.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Safe class.
**				This class inherits from the WorldObject class. The safe objects
**				accepts a combination and gives an item if the combination
**				was correct
*****************************************************************************/

#ifndef SAFE_HPP
#define SAFE_HPP



#include "WorldObject.hpp"
class Safe : public WorldObject
{
private:

	int combination;


public:
	Safe(int combination, int idNum, bool visible, bool interactable, std::string interactText, Item* objectItem);
	~Safe();

	bool attemptToOpen(int);

};
#endif