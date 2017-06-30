/****************************************************************************
** File name: Space.cpp
** Author: Anthony Clemente
** Date: 6/10/17
** Description: This file contains the definition of the Space class.
*****************************************************************************/

#include "Space.hpp"

//Set the member variable pointers using the parameters given to the constructor
//The menu and name member variables are handled by each derived class constructor
Space::Space(Space* left, Space* up, Space* right, Space* down)
{
	this->left = left;
	this->up = up;
	this->right = right;
	this->down = down;
}

Space::~Space()
{

}

void Space::setLeft(Space* left)
{
	this->left = left;
}

void Space::setUp(Space* up)
{
	this->up = up;
}

void Space::setRight(Space* right)
{
	this->right = right;
}

void Space::setDown(Space* down)
{
	this->down = down;
}

Space* Space::getLeft()
{
	return left;
}

Space* Space::getUp()
{
	return up;
}

Space* Space::getRight()
{
	return right;
}

Space* Space::getDown()
{
	return down;
}

std::string Space::getName()
{
	return name;
}
