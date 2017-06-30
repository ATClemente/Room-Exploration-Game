/****************************************************************************
** File name: Kitchen.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Kitchen class.
**				This class inherits from the Space class.
*****************************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP


#include "Space.hpp"

#include "Fridge.hpp"


class Kitchen : public Space
{
private:

	Door* doorToBasement;
	Door* doorToDiningRoom;
	Door* doorToBedRoom;
	Door* doorToLivingRoom;

	WorldObject* kitchenTable;
	WorldObject* kitchenCabinets;
	WorldObject* kitchenStove;

	Fridge* kitchenFridge;

	Player* currentPlayer;




public:

	virtual void printInteractionMenu() override;

	virtual void interactWithRoom(int) override;

	Kitchen(Player*);
	~Kitchen();

	bool checkDoorToBasement();
	bool checkDoorToDiningRoom();
	bool checkDoorToBedRoom();
	bool checkDoorToLivingRoom();
};




#endif