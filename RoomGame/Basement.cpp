/****************************************************************************
** File name: Basement.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Basement class.
*****************************************************************************/

#include "Basement.hpp"

#include "TextItem.hpp"

#include "UserInputValidation.hpp"
#include <iostream>

void Basement::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void Basement::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:
	{
		if (foodPantryOlives->isInteractable() && foodPantryOlives->isVisible())
		{
			std::cout << "Theres some canned food on a pantry shelf. No one would miss it..." << std::endl;
			std::cout << "Take something?" << std::endl;
			foodChoices.printMenu();

			int userFoodChoice = getInt("");
			while (!foodChoices.validUserChoice(userFoodChoice))
			{
				userFoodChoice = getInt("");
			}

			switch (userFoodChoice)
			{
			case 1:

				if (!gaveBeans)
				{
					if (foodPantryBeans->giveItem(currentPlayer))
					{
						gaveBeans = true;
					}
				}
				else
				{
					std::cout << "Beans were already taken" << std::endl;
				}

				break;
			case 2:

				if (!gaveCorn)
				{
					if (foodPantryCorn->giveItem(currentPlayer))
					{
						gaveCorn = true;
					}
				}
				else
				{
					std::cout << "Corn was already taken" << std::endl;
				}

				break;
			case 3:

				if (!gaveOlives)
				{
					if (foodPantryOlives->giveItem(currentPlayer))
					{
						gaveOlives = true;
					}
				}
				else
				{
					std::cout << "Olives were already taken" << std::endl;
				}

				break;
			default:
				break;
			}

			if (gaveBeans && gaveCorn && gaveOlives)
			{
				foodPantryOlives->setInteractable(false);
			}
		}
		else if (!foodPantryOlives->isInteractable() && foodPantryOlives->isVisible())
		{
			std::cout << "You took all the food!" << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 2:
	{
		if (workStation->isVisible())
		{
			std::cout << workStation->getInteractText() << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 3:
	{
		if (stuffedAnimals->isVisible())
		{
			std::cout << stuffedAnimals->getInteractText() << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 4:
	{
		if (basementSafe->isInteractable() && basementSafe->isVisible())
		{
			std::cout << "Looks like it takes a combination" << std::endl;
			if (basementSafe->attemptToOpen(getInt("Enter the combination: ")))
			{
				std::cout << "The safe opens!" << std::endl;
				std::cout << "There's an assortment of old savings bonds, and other documents. But in the corner there looks like a key? Should you take it?" << std::endl;
				std::cout << "Enter \'y\' for yes and \'n\' for no" << std::endl;
				char charChoice = getChar("");
				while (charChoice != 'y' && charChoice != 'n')
				{
					charChoice = getChar("");
				}

				if (charChoice == 'y')
				{
					if (basementSafe->giveItem(currentPlayer))
					{
						std::cout << "You take the key" << std::endl;
						basementSafe->setInteractable(false);
					}
				}
			}
			else
			{
				std::cout << "That's not the right combination..." << std::endl;
			}
		}
		else if(!basementSafe->isInteractable() && basementSafe->isVisible())
		{
			std::cout << "The safe you took a key from" << std::endl;
		}
		else
		{
			std::cout << "You can't see much in here right now" << std::endl;
		}
	}
		break;
	case 5:
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
			foodPantryOlives->setVisibility(false);
			basementSafe->setVisibility(false);
			workStation->setVisibility(false);
			stuffedAnimals->setVisibility(false);

			currentPlayer->setCurrentRoom(getRight());
		}
	}
		break;
	case 6:
	{
		if (!foodPantryOlives->isVisible())
		{
			int flashLightSpot = currentPlayer->findItemPosInInv(888);

			int currentCharge = currentPlayer->getInvItem(flashLightSpot)->useItem();

			if (currentCharge > 5)
			{
				currentCharge = 5;
			}

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
				//foodPantryOlives->setInteractable(true);
				foodPantryOlives->setVisibility(true);

				//basementSafe->setInteractable(true);
				basementSafe->setVisibility(true);

				//workStation->setInteractable(true);
				workStation->setVisibility(true);

				//stuffedAnimals->setInteractable(true);
				stuffedAnimals->setVisibility(true);

				break;
			}

		}
		else
		{
			std::cout << "You already have the flashlight on." << std::endl;
		}
	}
		break;
	default:
		break;
	}
}

Basement::Basement(Player* currentPlayer) : Space(nullptr, nullptr, nullptr, nullptr)
{
	this->currentPlayer = currentPlayer;

	name = "Basement";

	doorToKitchen = new Door(true, 203, true, true, "This door leads to the kitchen.");

	foodPantryBeans = new WorldObject(910, false, true, "Its a can of green beans", new TextItem("A can of green beans.", "Green Beans", 804, 2, false, "A can found from the basement"));
	foodPantryCorn = new WorldObject(911, false, true, "Its a can of corn", new TextItem("A can of corn.", "Corn", 805, 2, false, "A can found from the basement"));
	foodPantryOlives = new WorldObject(912, false, true, "Its a can of olives", new TextItem("A can of olives.", "Olives", 806, 2, true, "A can found from the basement"));

	basementSafe = new Safe(456, 913, false, true, "Its a safe. Wonder what's in it?", new Key(206, "Worn Key", 106, 1, true, "It looks like another door key"));

	workStation = new WorldObject(914, false, true, "A workbench. What kind of projects got done here?", nullptr);

	stuffedAnimals = new WorldObject(915, false, true, "A stuffed animal collection sits on a shelf. Thats odd. There's a gap where another one could probably fit...", nullptr);

	interactionMenu.addOption("Check the pantry shelf");
	interactionMenu.addOption("Check the workstation");
	interactionMenu.addOption("Check the stuffed animal collection");
	interactionMenu.addOption("Check the safe");
	interactionMenu.addOption("Try the door to the kitchen");
	interactionMenu.addOption("Use your flashlight");


	foodChoices.addOption("Take beans");
	foodChoices.addOption("Take corn");
	foodChoices.addOption("Take olives");

	gaveBeans = false;
	gaveCorn = false;
	gaveOlives = false;
}


Basement::~Basement()
{
	delete doorToKitchen;
	delete foodPantryBeans;
	delete foodPantryCorn;
	delete foodPantryOlives;
	delete basementSafe;
	delete workStation;
	delete stuffedAnimals;
}
