/****************************************************************************
** File name: Kitchen.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Kitchen class.
*****************************************************************************/

#include "Kitchen.hpp"
#include "TextItem.hpp"

#include "UserInputValidation.hpp"

#include <iostream>


Kitchen::Kitchen(Player* currentPlayer) :Space(nullptr, nullptr, nullptr, nullptr)
{
	this->currentPlayer = currentPlayer;

	name = "Kitchen";

	doorToBasement = new Door(true, 203, true, true, "This door leads to the basement.");
	doorToDiningRoom = new Door (true, 205, true, true, "The dining room isn't locked up");
	doorToBedRoom = new Door (true, 204, true, true, "This must be the bedroom...");
	doorToLivingRoom = new Door(true, 202, true, true, "This way goes back to the living room");


	std::string obituaryText = "Its an obituary it looks like.\nThe paper is torn and some of the words are unreadable from smudging\n"
								"It reads:\n"
								"\"19 October 1991:\n"
								"Mrs. Kathryn Miller, 31, was found dead in her home\nby her brother-in-law on the 10th of October\n"
								"She has left the earth too early and with circumstances\ntoo painful for her family to understand\n"
								"Her *ILLEGIBLE* goes with her. She is survived by her\ntwo sisters and two brothers and her mother and\n"
								"father. Services will be held at *ILLEGIBLE* \"\n"
								"The rest of the page is ripped off... \n"
								"\"too early\"... \"circumstances too painful\"? What happened here...";

	kitchenTable = new WorldObject(906, true, true, "There is a newspaper on the table.", new TextItem(obituaryText, "Obituary", 802, 1, false, "A piece of a newspaper from the kitchen table"));
	kitchenCabinets = new WorldObject (907, true, true, "Nothing left in the cabinets", nullptr);
	kitchenStove = new WorldObject (908, true, true, "I could really go for some spaghetti right now...", nullptr);

	kitchenFridge = new Fridge (909, true, true, "Wonder if there would be anything in here.", new TextItem("This was a child's stuffed bunny.", "Stuffed Bunny", 803, 1, true, "A stuffed animal bunny"));

	interactionMenu.addOption("Check the table");
	interactionMenu.addOption("Check the cabinets");
	interactionMenu.addOption("Check the stove");
	interactionMenu.addOption("Check the fridge");
	interactionMenu.addOption("Try the door to the basement");
	interactionMenu.addOption("Try the door to the bedroom");
	interactionMenu.addOption("Try the door to the dining room");
	interactionMenu.addOption("Try the door to the living room");

}


Kitchen::~Kitchen()
{
	delete doorToBasement;
	delete doorToBedRoom;
	delete doorToDiningRoom;
	delete doorToLivingRoom;

	delete kitchenTable;
	delete kitchenCabinets;
	delete kitchenStove;

	delete kitchenFridge;
}

bool Kitchen::checkDoorToBasement()
{
	return doorToBasement->checkIfUnlocked();
}

bool Kitchen::checkDoorToDiningRoom()
{
	return doorToDiningRoom->checkIfUnlocked();
}

bool Kitchen::checkDoorToBedRoom()
{
	return doorToBedRoom->checkIfUnlocked();
}

bool Kitchen::checkDoorToLivingRoom()
{
	return doorToLivingRoom->checkIfUnlocked();
}

void Kitchen::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void Kitchen::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:
	{
		if (kitchenTable->isInteractable())
		{
			std::cout << kitchenTable->getInteractText() << std::endl << std::endl;
			std::cout << "Take the paper?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (kitchenTable->giveItem(currentPlayer))
				{
					kitchenTable->setInteractable(false);
				}
			}
		}
		else
		{
			std::cout << "You took the newspaper from this table" << std::endl;
		}
	}
		break;
	case 2:

		std::cout << kitchenCabinets->getInteractText() << std::endl;

		break;
	case 3:

		std::cout << kitchenStove->getInteractText() << std::endl;

		break;
	case 4:
	{
		if (kitchenFridge->isInteractable())
		{
			std::cout << kitchenFridge->getInteractText() << std::endl;
			if (kitchenFridge->canGiveItem())
			{
				std::cout << "Its... a stuffed animal bunny... A child's..." << std::endl;
				std::cout << "Take the stuffed animal?" << std::endl;
				std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
				char charChoice = getChar("");
				while (charChoice != 'y' && charChoice != 'n')
				{
					charChoice = getChar("");
				}

				if (charChoice == 'y')
				{
					if (kitchenFridge->giveItem(currentPlayer))
					{
						kitchenFridge->setInteractable(false);
					}
				}
			}
			else
			{
				std::cout << "Someone has put a lock on the fridge." << std::endl;
				int index = currentPlayer->findItemPosInInv(107);
				if (index > -1)
				{
					std::cout << "You have the key!" << std::endl;
					kitchenFridge->unlockFridgeDoor(currentPlayer->getInvItem(index));
					std::cout << "The fridge unlocks!" << std::endl;
				}
				else
				{
					std::cout << "You will need to find the key to the fridge first" << std::endl;
				}

			}
		}
		else
		{
			std::cout << "This is where the stuffed animal was found" << std::endl;
		}
	}
		break;
	case 5:
	{
		std::cout << doorToBasement->getInteractText() << std::endl;
		std::cout << "Would you like to go to the basement?" << std::endl;
		std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
		char charChoice = getChar("");
		while (charChoice != 'y' && charChoice != 'n')
		{
			charChoice = getChar("");
		}

		if (charChoice == 'y')
		{
			currentPlayer->setCurrentRoom(getLeft());
		}
	}
		break;
	case 6:
	{
		std::cout << doorToBedRoom->getInteractText() << std::endl;

		if (checkDoorToBedRoom())
		{
			std::cout << "Would you like to go into the bedroom?" << std::endl;
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
		/*else
		{
			int index = currentPlayer->findItemPosInInv(103);
			if (index > -1)
			{
				std::cout << "You have the key!" << std::endl;
				doorToBedRoom->attemptToUnlock(currentPlayer->getInvItem(index));
				std::cout << "The fridge unlocks!" << std::endl;
			}
			else
			{
				std::cout << "You will need to find the key to the bedroom first" << std::endl;
			}
		}*/
	}
		break;
	case 7:
	{
		std::cout << doorToDiningRoom->getInteractText() << std::endl;
		std::cout << "Would you like to go to the dining room?" << std::endl;
		std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
		char charChoice = getChar("");
		while (charChoice != 'y' && charChoice != 'n')
		{
			charChoice = getChar("");
		}

		if (charChoice == 'y')
		{
			currentPlayer->setCurrentRoom(getRight());
		}
	}
		break;
	case 8:
	{
		std::cout << doorToLivingRoom->getInteractText() << std::endl;
		std::cout << "Would you like to go to the living room?" << std::endl;
		std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
		char charChoice = getChar("");
		while (charChoice != 'y' && charChoice != 'n')
		{
			charChoice = getChar("");
		}

		if (charChoice == 'y')
		{
			currentPlayer->setCurrentRoom(getDown());
		}
	}
		break;
	default:
		break;
	}
}
