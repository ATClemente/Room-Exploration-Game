/****************************************************************************
** File name: Flashlight.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the definition of the Flashlight class.
*****************************************************************************/

#include "Flashlight.hpp"


//The flashlight constructor takes in the necessary parameters for an Item and passes them to the Item constructor.
//The charge int is set by the Flashlight constructor
Flashlight::Flashlight(int charge, std::string name, int idNum, int weight, bool keyItem, std::string description) : Item(name, idNum, weight, keyItem, description)
{
	this->charge = charge;
}


Flashlight::~Flashlight()
{
}

//This function allows for the flashlight to be "used"
//It takes no parameters and returns an int. This integer
//that is returned infomrs how the caller will respond
int Flashlight::useItem()
{
	//If the charge is greater than zero than the score is decremented
	if (charge > 0)
	{
		charge--;
	}

	//If after decrementing, the charge is less than or equal to zero,
	//then the key item status f the flashlight is changed to false
	if (charge <=0)
	{
		setKeyItemStatus(false);
	}

	//Return the charge of the flashlight
	return charge;
}

