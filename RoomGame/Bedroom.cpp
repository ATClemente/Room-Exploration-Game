/****************************************************************************
** File name: Bedroom.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Bedroom class.
*****************************************************************************/

#include "Bedroom.hpp"

#include "TextItem.hpp"
#include "Flashlight.hpp"

#include <iostream>

#include "UserInputValidation.hpp"

Bedroom::Bedroom(Player* currentPlayer) : Space (nullptr, nullptr, nullptr, nullptr)
{
	this->currentPlayer = currentPlayer;
	name = "Bedroom";

	doorToKitchen = new Door(true, 204, true, true, "This goes back to the kitchen");
	doorToChildRoom = new Door(false, 206, false, true, "A door decorated with children's drawings");

	bedroomDresser = new WorldObject(919, false, true, "The bedroom dresser has a photo on top of it", new TextItem("Its a photo of a young child.", "Child Photo", 809, 1, false, "A photo of a child found on a dresser"));
	bedroomBed = new WorldObject(920, false, true, "A large bed takes up a good portion of the room", nullptr);
	bedsideTable = new WorldObject(921, false, true, "A small side table sits next to the bed", new Key(207, "Small key", 107, 1, true, "A small key with unknown purpose"));
	bedroomCloset = new WorldObject(922, true, true, "A small closet with a sliding door.", new Flashlight(9999, "LED Flashlight", 888, 1, true, "The batteries on this thing will probably last forever."));

	interactionMenu.addOption("Check the dresser");
	interactionMenu.addOption("Check the bed");
	interactionMenu.addOption("Check the closet");
	interactionMenu.addOption("Try the door to the kitchen");
	interactionMenu.addOption("Try the other door");
	interactionMenu.addOption("Use your flashlight");
}


Bedroom::~Bedroom()
{
	delete doorToKitchen;
	delete doorToChildRoom;

	delete bedroomDresser;
	delete bedroomBed;
	delete bedsideTable;
	delete bedroomCloset;
}

void Bedroom::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void Bedroom::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:
	{
		if (bedroomDresser->isInteractable() && bedroomDresser->isVisible())
		{
			std::cout << bedroomDresser->getInteractText() << std::endl;
			std::cout << "Take the picture?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (bedroomDresser->giveItem(currentPlayer))
				{
					bedroomDresser->setInteractable(false);
				}

			}
		}
		else if (!bedroomDresser->isInteractable() && bedroomDresser->isVisible())
		{
			std::cout << "It's the dresser you took the picture from." << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now." << std::endl;
		}
	}
		break;
	case 2:
	{
		if (bedroomBed->isInteractable() && bedroomBed->isVisible())
		{
			std::cout << bedroomBed->getInteractText() << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 3:
	{
		if (bedroomCloset->isInteractable())
		{
			std::cout << bedroomCloset->getInteractText() << std::endl;
			std::cout << "There's a bunch of stuff in here..." << std::endl;
			std::cout << "On the side you see a flashlight. Take it?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (currentPlayer->removeItemFromInv(1))
				{
					if (bedroomCloset->giveItem(currentPlayer))
					{
						std::cout << "You replaced you flashlight" << std::endl;
						bedroomCloset->setInteractable(false);
					}
				}
				else
				{
					std::cout << "Actually... No reason to take a new flashlight if the other is still working..." << std::endl;
				}

			}
		}
		else
		{
			std::cout << "You took the flashlight from the closet. Probably nothing good left in there" << std::endl;
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
			bedroomDresser->setVisibility(false);
			bedroomBed->setVisibility(false);
			bedsideTable->setVisibility(false);
			doorToChildRoom->setVisibility(false);
			if (interactionMenu.validUserChoice(7))
			{
				interactionMenu.removeOption(7);
			}
			currentPlayer->setCurrentRoom(getDown());
		}
	}
		break;
	case 5:
	{
		std::cout << doorToChildRoom->getInteractText() << std::endl;
		if (!doorToChildRoom->checkIfUnlocked() && currentPlayer->findItemPosInInv(106) > -1)
		{
			doorToChildRoom->attemptToUnlock(currentPlayer->getInvItem(currentPlayer->findItemPosInInv(106)));
			if (!doorToChildRoom->checkIfUnlocked())
			{
				std::cout << "That was the wrong key!" << std::endl;
			}
			else
			{
				std::cout << "The door opens with the key you have!" << std::endl;
			}
		}
		else if (!doorToChildRoom->checkIfUnlocked())
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
				bedroomDresser->setVisibility(false);
				bedroomBed->setVisibility(false);
				bedsideTable->setVisibility(false);
				doorToChildRoom->setVisibility(false);
				if (interactionMenu.validUserChoice(7))
				{
					interactionMenu.removeOption(7);
				}
				currentPlayer->setCurrentRoom(getUp());
			}

		}
	}
		break;
	case 6:
	{
		if (!bedroomBed->isVisible())
		{
			int flashLightSpot = currentPlayer->findItemPosInInv(888);

			int currentCharge = currentPlayer->getInvItem(flashLightSpot)->useItem();

			std::cout << "Turning on the flashlight." << std::endl;

			if (currentCharge > 5)
			{
				currentCharge = 5;
			}

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
				//bedroomBed->setInteractable(true);
				bedroomBed->setVisibility(true);

				//bedroomDresser->setInteractable(true);
				bedroomDresser->setVisibility(true);

				//bedsideTable->setInteractable(true);
				bedsideTable->setVisibility(true);
				interactionMenu.addOption("Check the bedside table");

				//doorToChildRoom->setInteractable(true);
				doorToChildRoom->setVisibility(true);


				break;
			}

		}
		else
		{
			std::cout << "You already have the flashlight on." << std::endl;
		}
	}
		break;
	case 7:
	{
		if (bedsideTable->isInteractable())
		{
			std::cout << bedsideTable->getInteractText() << std::endl;
			std::cout << "You go to it and open it and find a key. Take it?" << std::endl;
			std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
			char charChoice = getChar("");
			while (charChoice != 'y' && charChoice != 'n')
			{
				charChoice = getChar("");
			}

			if (charChoice == 'y')
			{
				if (bedsideTable->giveItem(currentPlayer))
				{
					bedsideTable->setInteractable(false);
				}
				 
			}
		}
		else
		{
			std::cout << "The side table you took the key from." << std::endl;
		}
	}
		break;
	default:
		break;
	}
}
