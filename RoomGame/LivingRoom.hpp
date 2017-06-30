/****************************************************************************
** File name: LivingRoom.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the LivingRoom class.
**				This class inherits from the Space class.
*****************************************************************************/

#ifndef LIVING_ROOM_HPP
#define LIVING_ROOM_HPP

#include "Space.hpp"
#include "Door.hpp"

class LivingRoom : public Space
{
private:

	Door* doorToKitchen;
	Door* doorToPorch;

	WorldObject* lightSwitch;
	WorldObject* sideTable;
	WorldObject* firePlace;

	Player* currentPlayer;


public:
	LivingRoom(Player*);
	~LivingRoom();

	void printInteractionMenu() override;

	void interactWithRoom(int) override;

	bool checkDoorToKitchen();
	bool checkDoorToPorch();
};




#endif