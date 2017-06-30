/****************************************************************************
** File name: Player.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the declaration of the Player class. The
**				player class keeps track of a collection of Items and a pointer
**				to the room currently being accessed.
*****************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Item.hpp"
#include "Space.hpp"

const int MAX_CARRY_WEIGHT = 15;


class Player
{
private:

	std::vector<Item*> inventory;
	int currentCarryWeight;
	bool gameIsOver;
	Space* currentRoom;

public:

	Player(Space*);
	~Player();

	void setCurrentRoom(Space*);
	Space* accessRoom();

	void addItemToInventory(Item*);
	bool removeItemFromInv(int);

	bool getGameIsOver();
	void setGameOver(bool);

	Item* getInvItem(int);

	int findItemPosInInv(int);

	int getPlayerCurrentCarryWeight();

	void showInventory();

	void interactWithInventory(int);
};
#endif