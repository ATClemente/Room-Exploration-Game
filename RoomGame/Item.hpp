/****************************************************************************
** File name: Item.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the declaration of the Item class. Note
**				this class is an abstract class. It contains member variables
**				necessary for representing an working with an item. 
*****************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{

private:

	std::string name;
	int idNum;
	int weight;
	bool keyItem;
	std::string description;

public:
	Item(std::string name, int idNum, int weight, bool keyItem, std::string description);
	virtual ~Item();

	std::string getName();
	int getIdNum();
	int getWeight();
	bool isKeyItem();
	void setKeyItemStatus(bool);
	std::string getDescription();
	virtual int useItem() = 0;
};


#endif