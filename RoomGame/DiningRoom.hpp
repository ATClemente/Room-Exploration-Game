/****************************************************************************
** File name: DiningRoom.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the DiningRoom class.
**				This class inherits from the Space class.
*****************************************************************************/

#ifndef DINING_ROOM_HPP
#define DINING_ROOM_HPP

#include "Space.hpp"
#include "Door.hpp"

class DiningRoom : public Space
{
private:

	Door* doorToKitchen;

	WorldObject* trashCan;
	WorldObject* diningRoomTable;
	WorldObject* tableCandles;

	Player* currentPlayer;

public:
	DiningRoom(Player*);
	~DiningRoom();

	void printInteractionMenu() override;

	void interactWithRoom(int) override;


};
#endif