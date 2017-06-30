/****************************************************************************
** File name: Key.hpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This class contains the declaration of the Key class.
**				This class inherits from the Item class. The key item functions
**				to unlock doors that it is matched to.
*****************************************************************************/

#ifndef KEY_HPP
#define KEY_HPP


#include "Item.hpp"
class Key : public Item
{

private:

	int doorID;

public:

	virtual int useItem() override;

	Key(int doorID, std::string name, int idNum, int weight, bool keyItem, std::string description);
	~Key();
};



#endif

