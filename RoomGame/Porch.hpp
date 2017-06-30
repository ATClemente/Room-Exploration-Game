/****************************************************************************
** File name: Porch.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Porch class. This
**				class inherits from the Space class. 
*****************************************************************************/

#ifndef PORCH_HPP
#define PORCH_HPP


#include "Space.hpp"
#include "Door.hpp"

class Porch : public Space
{

private: 

	Door* doorToLivingRoom;
	WorldObject* welcomeMat;
	WorldObject* plantPot;

	Player* currentPlayer;

public:


	void printInteractionMenu() override;

	void interactWithRoom(int) override;

	bool checkDoorToLivingRoom();


	Porch(Player*);
	~Porch();

};
#endif