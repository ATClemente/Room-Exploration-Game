/****************************************************************************
** File name: Match.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Match class.
*****************************************************************************/

#include "Match.hpp"

//If the matches have any uses left, return 1,
//otherwise return 0. The caller then decides how to deal with this
//return value.
int Match::useItem()
{
	if (uses > 0)
	{
		uses--;
		return 1;
	}
	return 0;
}

//The match constructor takes in the necessary parameters for an Item and passes them along to the
//Item constructor. An additional parameter of the uses is set by the amtch constructor
Match::Match(int uses, std::string name, int idNum, int weight, bool keyItem, std::string description) : Item(name, idNum, weight, keyItem, description)
{
	this->uses = uses;
}


Match::~Match()
{
}
