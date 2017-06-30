/****************************************************************************
** File name: DiningRoom.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the DiningRoom class.
*****************************************************************************/

#include "DiningRoom.hpp"

#include "TextItem.hpp"

#include <iostream>

#include "UserInputValidation.hpp"


DiningRoom::DiningRoom(Player* currentPlayer) : Space(nullptr, nullptr, nullptr, nullptr)
{
	this->currentPlayer = currentPlayer;

	name = "Dining Room";

	doorToKitchen = new Door(true, 205, true, true, "This door leads back to the kitchen");

	std::string newStory =		"Its a newspaper article.\nThe paper is torn and some of the words are unreadable from smudging\n"
								"It reads:\n"
								"\"15 August 2006:\n"
								"A man was put to death today for the 1991 murders\nof Kathyrn Miller and *ILLEGIBLE*\n"
								"Todd Miller never stated why he committed the murders\nbut did admit to commiting them after turning himself in\n"
								"on the 15 of October 1991, after meeting with a priest.\nSeveral Miller family members were present at the execution.\n"
								"Kathyn's aunt, who was not one of the family members who\nchose to witness the death, smiles as she remember's memories of Kathryn\n"
								"\"She would always grab olive from a salad and put them on\nher finger tips and run around!\" she says\n"
								"\"Then she would do the same with her daughter!\" Kathyrn's\ndaughter, Chelsea, was only 4 when the crime was committed.\n"
								"\"Its just so sad that she\"... *ILLEGIBLE*\""
								"The rest of the page is ripped off... \n"
								"so there was more than one victim. And she had a daughter?";

	trashCan = new WorldObject(916, false, false, "Its a trash can tucked into the corner. There's a single piece of paper at the bottom.", new TextItem("456", "Scrap paper", 807, 1, true, "A piece of paper with some number on it"));
	diningRoomTable = new WorldObject(917, false, false, "The dining room table. There's a paper on it", new TextItem(newStory, "Newspaper Article", 808, 1, false, "A newspaper article found on the dining room table"));
	tableCandles = new WorldObject(918, true, true, "There are some candles here on the table.", nullptr);

	interactionMenu.addOption("Check the dining room table");
	interactionMenu.addOption("Light the candles");
	interactionMenu.addOption("Try the door to the kitchen");


}



DiningRoom::~DiningRoom()
{
	delete doorToKitchen;
	delete trashCan;
	delete diningRoomTable;
	delete tableCandles;
}

void DiningRoom::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void DiningRoom::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:
	{
		if (diningRoomTable->isInteractable() && diningRoomTable->isVisible())
		{
			std::cout << diningRoomTable->getInteractText() << std::endl;
			std::cout << "Take the paper?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (diningRoomTable->giveItem(currentPlayer))
				{
					diningRoomTable->setInteractable(false);
				}

			}
		}
		else if (!diningRoomTable->isInteractable() && diningRoomTable->isVisible())
		{
			std::cout << "Its the side table you took the newspaper from" << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 2:
	{
		if (tableCandles->isInteractable())
		{
			std::cout << tableCandles->getInteractText() << std::endl;
			std::cout << "Light the candles?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (currentPlayer->findItemPosInInv(301) > -1 && currentPlayer->getInvItem(currentPlayer->findItemPosInInv(301))->useItem() > 0)
				{
					tableCandles->setInteractable(false);

					trashCan->setInteractable(true);
					trashCan->setVisibility(true);

					diningRoomTable->setInteractable(true);
					diningRoomTable->setVisibility(true);
					std::cout << "The candles light up the room!" << std::endl;
					interactionMenu.addOption("Check the trash can");
				}
				else
				{
					std::cout << "You have nothing to light them with..." << std::endl;
				}
			}
		}
		else
		{
			std::cout << "The candles are already lit" << std::endl;
		}
	}
		break;
	case 3:
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
			diningRoomTable->setVisibility(false);
			trashCan->setVisibility(false);
			if (interactionMenu.validUserChoice(4))
			{
				interactionMenu.removeOption(4);
			}
			currentPlayer->setCurrentRoom(getLeft());
		}
	}
		break;
	case 4:
	{
		if (trashCan->isInteractable() && trashCan->isVisible())
		{
			std::cout << trashCan->getInteractText() << std::endl;
			std::cout << "Take the scrap paper?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (trashCan->giveItem(currentPlayer))
				{
					trashCan->setInteractable(false);
				}

			}
		}
		else if (!trashCan->isInteractable() && trashCan->isVisible())
		{
			std::cout << "Its the side table you took the newspaper from" << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	default:
		break;
	}
}
