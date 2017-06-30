/****************************************************************************
** Program name: Room Exploration Game
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This program is a game that has a player explore the rooms
**				of a house. They collect items in hope of having the correct
**				ones for the final room.
*****************************************************************************/

//This comment is to indicate this project was committed to GitHub
//on 29 June 2017 at 10:47 PM

#include "Player.hpp"
#include "WorldObject.hpp"
#include "Space.hpp"
#include "Porch.hpp"
#include "LivingRoom.hpp"
#include "Kitchen.hpp"
#include "Basement.hpp"
#include "DiningRoom.hpp"
#include "Bedroom.hpp"
#include "ChildRoom.hpp"

#include "UserInputValidation.hpp"

#include <iostream>


int main()
{

	//Create a menu that the player will choose options throughout the game
	Menu gameMenu;

	gameMenu.addOption("Interact with the room");
	gameMenu.addOption("Check inventory");
	gameMenu.addOption("Inspect inventory item");
	gameMenu.addOption("Drop inventory item");

	//Declare a player and set their current room to nullptr
	Player mainPlayer(nullptr);

	//Create the seven rooms for the house, giving them a pointer to the player for this game
	Porch* housePorch = new Porch(&mainPlayer);
	LivingRoom* houseLivingRoom = new LivingRoom(&mainPlayer);
	Kitchen* houseKitchen = new Kitchen(&mainPlayer);
	Basement* houseBasement = new Basement(&mainPlayer);
	DiningRoom* houseDiningRoom = new DiningRoom(&mainPlayer);
	Bedroom* houseBedroom = new Bedroom(&mainPlayer);
	ChildRoom* houseChildRoom = new ChildRoom(&mainPlayer);

	//Using the appropriate member functions, set the pointers for the
	//rooms to assemble the house properly. Note that the calls to functions
	//with the nullptr parameter is not strictly necessary, but helps
	//demonstrate what is happening and makes this explicit.
	housePorch->setDown(nullptr);
	housePorch->setLeft(nullptr);
	housePorch->setRight(nullptr);
	housePorch->setUp(houseLivingRoom);

	houseLivingRoom->setDown(housePorch);
	houseLivingRoom->setLeft(nullptr);
	houseLivingRoom->setRight(nullptr);
	houseLivingRoom->setUp(houseKitchen);

	houseKitchen->setDown(houseLivingRoom);
	houseKitchen->setLeft(houseBasement);
	houseKitchen->setRight(houseDiningRoom);
	houseKitchen->setUp(houseBedroom);

	houseBasement->setDown(nullptr);
	houseBasement->setLeft(nullptr);
	houseBasement->setRight(houseKitchen);
	houseBasement->setUp(nullptr);

	houseDiningRoom->setDown(nullptr);
	houseDiningRoom->setLeft(houseKitchen);
	houseDiningRoom->setRight(nullptr);
	houseDiningRoom->setUp(nullptr);

	houseBedroom->setDown(houseKitchen);
	houseBedroom->setLeft(nullptr);
	houseBedroom->setRight(nullptr);
	houseBedroom->setUp(houseChildRoom);

	houseChildRoom->setDown(houseBedroom);
	houseChildRoom->setLeft(nullptr);
	houseChildRoom->setRight(nullptr);
	houseChildRoom->setUp(nullptr);

	//Set the player's starting room to the porch
	mainPlayer.setCurrentRoom(housePorch);

	//Declare a boolean to control flow of the program
	//and an int to hold the player's choice each round
	bool exitProgram = false;
	int playerChoice;

	//This is a note for the TA to make the goal of the game clear.
	std::cout << "Welcome! The goal of the game is as follows: " << std::endl;
	std::cout << "Collect three items and have them when you enter the Child's Room." << std::endl;
	std::cout << "1. A photo from the living room" << std::endl;
	std::cout << "2. The olives from the basement pantry" << std::endl;
	std::cout << "3. A stuffed animal from the kitchen fridge" << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//Intro text for game is output here
	std::cout << "The following is a work of fiction. All names, dates, and settings are ficticious." << std::endl;
	std::cout << "Any similarity to any real persons or events is purely coincidental" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Why does it have to be raining, you think as you park the car." << std::endl;
	std::cout << "And why did they send me at night! Couldn't this wait until morning?" << std::endl;
	std::cout << "You get out of the car and run to the house." << std::endl;
	std::cout << "This is the house they wanted me to check right? You check the address again." << std::endl;
	std::cout << "Yep this is it." << std::endl;
	std::cout << "A few hours ago you parent's neighbors called you since your parents are out of town." << std::endl;
	std::cout << "They said there was some weird sounds coming from the old house on the street." << std::endl;
	std::cout << "Apparently Dad usually checks on it but hes not around so lucky you!" << std::endl;
	std::cout << "Crazy old neighbors are probably just hearing things anyway." << std::endl;
	std::cout << "Whatever... You'll take a look and get out of here." << std::endl;
	std::cout << "Oh... doors locked... Well Dad gets in somehow..." << std::endl;
	std::cout << "You start looking around the porch." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "(Note: Before beginning please scroll up if necessary to read disclaimer as well as game goal. Thank you.)" << std::endl;

	//The program will continue to loop until the boolean is changed to true
	while (!exitProgram)
	{
		//Ask the player what they would like to do and print out the game menu
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << std::endl;
		gameMenu.printMenu();

		//Get an option from the player an validate it before moving on
		playerChoice = getInt("Select option: ");
		while (!gameMenu.validUserChoice(playerChoice))
		{
			playerChoice = getInt("Select option: ");
		}

		//Take different action based upon the user option
		switch (playerChoice)
		{
		case 1:
		{
			//Show the user what room they are in
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << mainPlayer.accessRoom()->getName() << ":" << std::endl;
			std::cout << std::endl;

			//Print the menu specific for the current room
			mainPlayer.accessRoom()->printInteractionMenu();
			std::cout << std::endl;

			//Get a choice from the user and pass this as an argument to the room's interaction function
			mainPlayer.accessRoom()->interactWithRoom(getInt("What do you do in this room?"));
			std::cout << std::endl;
			std::cout << std::endl;

			//Set the control boolean
			//If the player has just won, the boolean will change to true, and the loop will end
			exitProgram = mainPlayer.getGameIsOver();

		}
			break;
		case 2:
		{
			//Print out the user's inventory
			std::cout << std::endl;
			std::cout << std::endl;
			mainPlayer.showInventory();
			std::cout << std::endl;
			std::cout << std::endl;
		}
			break;
		case 3:
		{
			//Print out the user's inventory
			std::cout << std::endl;
			std::cout << std::endl;
			mainPlayer.showInventory();
			std::cout << std::endl;
			std::cout << std::endl;

			//Use the appropriate member function to interact with the user's inventory
			mainPlayer.interactWithInventory(getInt("Which item do you wish to inspect? "));
			std::cout << std::endl;
			std::cout << std::endl;
		}
			break;
		case 4:
		{
			//Print out the user's inventory
			std::cout << std::endl;
			std::cout << std::endl;
			mainPlayer.showInventory();
			std::cout << std::endl;
			std::cout << std::endl;

			//Use the appropriate member function to drop item from the user's inventory
			if (mainPlayer.removeItemFromInv(getInt("Which item do you wish to drop? ")))
			{
				std::cout << "Item dropped!" << std::endl;
				std::cout << std::endl;
			}
			else
			{
				std::cout << "That item does not exist or is too important to drop!" << std::endl;
				std::cout << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
			break;
		default:
			break;
		}
	}

	//Delete the memory allocated for each of the rooms
	delete houseChildRoom;

	delete houseBedroom;

	delete houseDiningRoom;

	delete houseBasement;

	delete houseKitchen;

	delete houseLivingRoom;

	delete housePorch;

	//Just a note the game is over!
	std::cout << std::endl;
	std::cout << "You have completed the game! Congratulations! (exiting now...)" << std::endl;

    return 0;
}

