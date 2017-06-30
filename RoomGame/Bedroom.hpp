/****************************************************************************
** File name: Bedroom.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Bedroom class.
**				This class inherits from the Space class.
*****************************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Space.hpp"
#include "Door.hpp"

class Bedroom : public Space
{
private:

	Door* doorToChildRoom;
	Door* doorToKitchen;

	WorldObject* bedroomDresser;
	WorldObject* bedsideTable;
	WorldObject* bedroomBed;
	WorldObject* bedroomCloset;

	Player* currentPlayer;

public:
	Bedroom(Player*);
	~Bedroom();

	void printInteractionMenu() override;

	void interactWithRoom(int) override;

};
#endif