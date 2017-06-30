/****************************************************************************
** File name: ChildRoom.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the ChildRoom class.
*****************************************************************************/

#include "ChildRoom.hpp"
#include "UserInputValidation.hpp"

#include <iostream>

ChildRoom::ChildRoom(Player* currentPlayer) : Space(nullptr, nullptr, nullptr, nullptr)
{
	this->currentPlayer = currentPlayer;

	name = "Unknown Room";

	childGhost = new Ghost();

	interactionMenu.addOption("The room is eerily quiet...");
}


ChildRoom::~ChildRoom()
{
	delete childGhost;
}

void ChildRoom::printInteractionMenu()
{
	interactionMenu.printMenu();
}

void ChildRoom::interactWithRoom(int choice)
{
	while (!interactionMenu.validUserChoice(choice))
	{
		choice = getInt("");
	}

	switch (choice)
	{
	case 1:
	{
		std::cout << "Suddenly a glowing figure appears above a small bed against the wall.\nIts a child... Or at least, was a child. She looks at you longingly." << std::endl;
		std::cout << "You fight the urge to run from the room and rummage through \nyour bag as you try to find something for it..." << std::endl;
		std::cout << std::endl;
		childGhost->checkPlayerForItems(currentPlayer);



		if (!childGhost->getHasPicture())
		{
			std::cout << "The child still looks lonely..." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "The child accepts the picture of the woman you took from the living room. \nA smile briefly appears on its face. \nIs that... the child's mother? What must it have been like, to wait for your mother this long? \nA mother that never returned." << std::endl;
			std::cout << std::endl;
		}
		if (!childGhost->getHasOlives())
		{
			std::cout << "The child looks hungry..." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "You pop open the can of olives and lay several on the bed. \nThe child picks one up and eats it. \nThen she appears to laugh briefly as it puts one on the tip of her finger. \nThe laughter fades quickly." << std::endl;
			std::cout << std::endl;
		}
		if (!childGhost->getHasStuffedAnimal())
		{
			std::cout << "The child looks... cold. It looks around as if for something it has lost." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "You hand the child the stuffed bunny you found in the refrigerator. \nIt smiles as if it has seen a long lost friend. \nOh god... He... put you both in there didn't he? \nYou and your stuffed bunny. What a monster..." << std::endl;
			std::cout << std::endl;
		}

		if (!childGhost->getHasPicture() || !childGhost->getHasOlives() || !childGhost->getHasStuffedAnimal())
		{
			std::cout << "What you have done has not satisfied the child. \nIt begins to wail loudly. \nThe walls shake and the air becomes cold." << std::endl;
			std::cout << "In terror, you leave the room and shut the door. \nThe wailing stops and the air feels warm again." << std::endl;
			std::cout << std::endl;
			currentPlayer->setCurrentRoom(getDown());
		}
		else
		{
			currentPlayer->setGameOver(true);

			std::cout << std::endl;
			std::cout << "The child seems content and looks as if there is nothing left this world can offer it." << std::endl;
			std::cout << "She smiles at you and slowly fades away." << std::endl;
			std::cout << "You leave the room and shut the door before taking a deep breath. \nShe must have been so scared for all these years. All alone here." << std::endl;
			std::cout << "As you walk toward the front door you feel content \nknowing that her spirit has been put to rest finally." << std::endl;
			std::cout << "Maybe she'll get to see her mother again,\nyou think as you close the front door..." << std::endl;
			std::cout << "\"I hope she does\" you whisper." << std::endl;
			std::cout << std::endl;

		}
	}
		break;
	default:
		break;
	}
}
