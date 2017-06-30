/****************************************************************************
** File name: Safe.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Safe class.
*****************************************************************************/

#include "Safe.hpp"


//The safe contructor takes in the necessary parameters to assemble a WorldObject and passes
//these onto the WorldObject constructor. The additional combination integer parameter is set by the
//Safe parameter
Safe::Safe(int combination, int idNum, bool visible, bool interactable, std::string interactText, Item* objectItem) : WorldObject(idNum, visible, interactable, interactText, objectItem)
{
	this->combination = combination;
}

Safe::~Safe()
{
}

//This function returns true if the paramater integer is
//equal to the combination of the safe this function is being
//called on
bool Safe::attemptToOpen(int attempt)
{
	return attempt == combination;
}
