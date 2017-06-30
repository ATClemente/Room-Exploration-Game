/****************************************************************************
** File name: TextItem.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the TextItem class.
*****************************************************************************/

#include "TextItem.hpp"
#include <iostream>

//The TextItem prints out a string member variable
//when it is used in the game. It then simply returns zero
int TextItem::useItem()
{
	std::cout << itemText << std::endl;
	return 0;
}

//The TextItem constructor takes in a ll the proper parameters to make an Item and passes them to the Item
//constructor. The additional string member varaible is set by the TextItem constructor
TextItem::TextItem(std::string itemText, std::string name, int idNum, int weight, bool keyItem, std::string description) : Item(name, idNum, weight, keyItem, description)
{
	this->itemText = itemText;
}

TextItem::~TextItem()
{

}
