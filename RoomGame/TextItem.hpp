/****************************************************************************
** File name: TextItem.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the TextItem class.
**				This class inherits from the Item class. The TextItem item 
**				functions to display text for the user when used/inspected.
**				All of the items needed for winning the game are this kind of
**				Item.
*****************************************************************************/

#ifndef TEXT_ITEM_HPP 
#define TEXT_ITEM_HPP


#include "Item.hpp"

class TextItem : public Item
{
private:

	std::string itemText;

public:

	virtual int useItem() override;

	TextItem(std::string itemText, std::string name, int idNum, int weight, bool keyItem, std::string description);
	~TextItem();
};

#endif