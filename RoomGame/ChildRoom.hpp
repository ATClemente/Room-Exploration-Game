/****************************************************************************
** File name: ChildRoom.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the ChildRoom class.
**				This class inherits from the Space class. Note this class
**				is somewhat different from the other Space derived classes in
**				that it does not need to have any objects to function properly
*****************************************************************************/

#ifndef CHILD_ROOM_HPP
#define CHILD_ROOM_HPP

#include "Space.hpp"
#include "Door.hpp"
#include "Ghost.hpp"

class ChildRoom : public Space
{
private:

	Ghost* childGhost;

	Player* currentPlayer;

public:
	ChildRoom(Player*);
	~ChildRoom();

	void printInteractionMenu() override;

	void interactWithRoom(int) override;

};
#endif