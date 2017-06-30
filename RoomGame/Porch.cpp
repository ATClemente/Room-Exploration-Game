/****************************************************************************
** File name: Porch.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the defintion of the Porch class.
*****************************************************************************/

#include "Porch.hpp"

#include "UserInputValidation.hpp"

#include <iostream>


void Porch::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void Porch::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:
	{

		if (!doorToLivingRoom->checkIfUnlocked() && currentPlayer->findItemPosInInv(101) > - 1)
		{
			doorToLivingRoom->attemptToUnlock(currentPlayer->getInvItem(currentPlayer->findItemPosInInv(101)));
			if (!doorToLivingRoom->checkIfUnlocked())
			{
				std::cout << "That was the wrong key!" << std::endl;
			}
			else
			{
				std::cout << "The door opens!" << std::endl;
			}
		}
		else if (!doorToLivingRoom->checkIfUnlocked())
		{
			std::cout << "You try the door but find it will not budge. You will need the key..." << std::endl;
		}
		else
		{
			std::cout << "The door is open!" << std::endl;
			std::cout << "Move to next room?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				currentPlayer->setCurrentRoom(getUp());
			}

		}
	}
		break;
	case 2:

		std::cout << welcomeMat->getInteractText() << std::endl;

		break;
	case 3:
	{
		std::cout << plantPot->getInteractText() << std::endl;
		std::cout << "Its a key! Would you like to take it?" << std::endl;
		std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
		char charChoice = getChar("");
		while (charChoice != 'y' && charChoice != 'n')
		{
			charChoice = getChar("");
		}

		if (charChoice == 'y')
		{
			plantPot->giveItem(currentPlayer);
			interactionMenu.removeOption(3);
		}

		

	}
		break;
	default:
		break;
	}

}

bool Porch::checkDoorToLivingRoom()
{
	return doorToLivingRoom->checkIfUnlocked();
}

Porch::Porch(Player* currentPlayer) : Space (nullptr, nullptr, nullptr, nullptr)
{

	name = "Porch";

	doorToLivingRoom = new Door(false, 201, true, true, "This is the front door text.");
	welcomeMat = new WorldObject(901, true, true, "You check under the welcome mat. But you find nothing there", nullptr);

	plantPot = new WorldObject(902, true, true, "You see something shiny under the dirt.", new Key(201, "Front Door Key", 101, 1, true, "This is probably the front door key"));

	interactionMenu.addOption("Try the door");
	interactionMenu.addOption("Inspect the welcome mat");
	interactionMenu.addOption("Inspect the hanging plant basket");

	this->currentPlayer = currentPlayer;

}

Porch::~Porch()
{
	delete doorToLivingRoom;
	delete welcomeMat;
	delete plantPot;
}
