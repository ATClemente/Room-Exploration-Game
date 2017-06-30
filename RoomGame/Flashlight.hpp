/****************************************************************************
** File name: Flashlight.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Flashlight class.
**				This class inherits from the Item class. A flashlight object
**				is accessed in the player's inventory to light up a room. It
**				returns an int to the caller and based upon the int returned
**				indicates if it is out of batteries or not.
*****************************************************************************/

#ifndef FLASHLIGHT_HPP
#define FLASHLIGHT_HPP


#include "Item.hpp"
class Flashlight : public Item
{
private:

	int charge;

public:

	Flashlight(int charge, std::string name, int idNum, int weight, bool keyItem, std::string description);
	~Flashlight();

	virtual int useItem() override;

};
#endif