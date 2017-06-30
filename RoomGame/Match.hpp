/****************************************************************************
** File name: Match.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Match class.
**				This class inherits from the Item class. The match item is used
**				in the dining room the light up the room
*****************************************************************************/

#ifndef MATCH_HPP
#define MATCH_HPP


#include "Item.hpp"
class Match : public Item
{
private:

	int uses;

public:

	int useItem() override;

	Match(int uses, std::string name, int idNum, int weight, bool keyItem, std::string description);
	~Match();
};


#endif