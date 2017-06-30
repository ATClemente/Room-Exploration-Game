/****************************************************************************
** File name: LivingRoom.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the LivingRoom class.
*****************************************************************************/

#include "LivingRoom.hpp"

#include <iostream>
#include "UserInputValidation.hpp"

#include "TextItem.hpp"

#include "Match.hpp"

LivingRoom::LivingRoom(Player* currentPlayer) : Space(nullptr, nullptr, nullptr, nullptr)
{
	this->currentPlayer = currentPlayer;

	name = "Living Room";

	doorToKitchen = new Door(true, 202, true, true, "The door to the kitchen is unlocked");
	doorToPorch = new Door(true, 201, true, true, "Probably shouldn't leave just yet");

	lightSwitch = new WorldObject(903, true, true, "Its the light switch for the living room. It doesn't do anything... Electric must be out", nullptr);
	sideTable = new WorldObject(904, false, true, "There is a picture on the side table.", new TextItem("Its a picture of a woman. Probably somewhere around age 30.", "Picture of woman", 801, 1, true, "The picture that was on the side table."));
	firePlace = new WorldObject(905, false, true, "The fireplace. No need to light it up tonight, but there are some matches here still...", new Match(3, "Matches", 301, 1, false, "Matches found by the fire place"));

	interactionMenu.addOption("Try the light switch");
	interactionMenu.addOption("Check the side table");
	interactionMenu.addOption("Check the fireplace");
	interactionMenu.addOption("Try the door to the kitchen");
	interactionMenu.addOption("Try the door to the porch");
	interactionMenu.addOption("Use your flashlight");

}




LivingRoom::~LivingRoom()
{
	delete doorToKitchen;
	delete doorToPorch;
	delete lightSwitch;
	delete sideTable;
	delete firePlace;
}

void LivingRoom::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void LivingRoom::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:

		std::cout << lightSwitch->getInteractText() << std::endl;

		break;
	case 2:
	{
		if (sideTable->isInteractable() && sideTable->isVisible())
		{
			std::cout << sideTable->getInteractText() << std::endl;
			std::cout << "Take the picture?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (sideTable->giveItem(currentPlayer)) 
				{
					sideTable->setInteractable(false);
				}
				
			}
		}
		else if (!sideTable->isInteractable() && sideTable->isVisible())
		{
			std::cout << "Its the side table you took the picture from." << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 3:
	{
		if (firePlace->isInteractable() && firePlace->isVisible())
		{
			std::cout << firePlace->getInteractText() << std::endl;
			std::cout << "Take the matches?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (firePlace->giveItem(currentPlayer))
				{
					firePlace->setInteractable(false);
				}
			
			}
		}
		else if (!firePlace->isInteractable() && firePlace->isVisible())
		{
			std::cout << "You took the matches from here." << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 4:
	{
		std::cout << doorToKitchen->getInteractText() << std::endl;
		std::cout << "Move to the kitchen?" << std::endl;
		std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
		char charChoice = getChar("");
		while (charChoice != 'y' && charChoice != 'n')
		{
			charChoice = getChar("");
		}

		if (charChoice == 'y')
		{
			firePlace->setVisibility(false);
			sideTable->setVisibility(false);
			currentPlayer->setCurrentRoom(getUp());
		}
	}
		break;
	case 5:

		std::cout << doorToPorch->getInteractText() << std::endl;

		break;
	case 6:




		if (!firePlace->isVisible() && !sideTable->isVisible())
		{
			int flashLightSpot = currentPlayer->findItemPosInInv(888);

			int currentCharge = currentPlayer->getInvItem(flashLightSpot)->useItem();



			std::cout << "Turning on the flashlight." << std::endl;

			switch (currentCharge)
			{
			case 0:
				std::cout << "Batteries are dead..." << std::endl;
				break;
			case 1:

			case 2:
				std::cout << "Batteries seem to be getting low..." << std::endl;
			case 3:

			case 4:

			case 5:
				//sideTable->setInteractable(true);
				sideTable->setVisibility(true);

				//firePlace->setInteractable(true);
				firePlace->setVisibility(true);
				break;
			}

		}
		else
		{
			std::cout << "You already have the flashlight on." << std::endl;
		}


		break;
	default:
		break;
	}

}

bool LivingRoom::checkDoorToKitchen()
{
	return doorToKitchen->checkIfUnlocked();
}

bool LivingRoom::checkDoorToPorch()
{
	return doorToPorch->checkIfUnlocked();
}
