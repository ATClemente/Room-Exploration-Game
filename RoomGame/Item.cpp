/****************************************************************************
** File name: Item.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the definition of the Item class. 
*****************************************************************************/


#include "Item.hpp"


//Contructor simply takes the parameters and sets the member variables with them
Item::Item(std::string name, int idNum, int weight, bool keyItem, std::string description)
{
	this->name = name;
	this->idNum = idNum;
	this->weight = weight;
	this->keyItem = keyItem;
	this->description = description;
}


Item::~Item()
{

}

std::string Item::getName()
{
	return name;
}

int Item::getIdNum()
{
	return idNum;
}

int Item::getWeight()
{
	return weight;
}

bool Item::isKeyItem()
{
	return keyItem;
}

//Alows for the key item status of an item to be changed
void Item::setKeyItemStatus(bool newStatus)
{
	keyItem = newStatus;
}

std::string Item::getDescription()
{
	return description;
}
