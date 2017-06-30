/****************************************************************************
** File name: Basement.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Basement class.
**				This class inherits from the Space class.
*****************************************************************************/

#ifndef BASEMENT_HPP
#define BASEMENT_HPP

#include "Space.hpp"
#include "Door.hpp"
#include "Safe.hpp"

class Basement : public Space
{
private:

	Door* doorToKitchen;

	WorldObject* foodPantryOlives;
	WorldObject* foodPantryBeans;
	WorldObject* foodPantryCorn;


	Menu foodChoices;
	bool gaveBeans;
	bool gaveCorn;
	bool gaveOlives;

	Safe* basementSafe;

	WorldObject* workStation;

	WorldObject* stuffedAnimals;

	Player* currentPlayer;

public:

	void printInteractionMenu() override;

	void interactWithRoom(int) override;

	Basement(Player*);
	~Basement();
};
#endif