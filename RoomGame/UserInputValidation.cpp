/****************************************************************************
** File name: UserInputValidation.cpp
** Author: Anthony Clemente
** Date: 3/26/17 ---- Updated: 4/25/17
** Description: This file contains the function implementations for separate
**				functions designed to get and validate user input for ints,
**				as well as a function for returning a string that does not
**				consist of only "blank" characters.
**
**				For integers, one allows for a value to be returned from
**				the function (note it will not exit until the user enters
**				an appropriate value), and another version that modifies a
**				reference variable and returns a boolean to indicate success
**				or failure. Two versions for now since I'm not sure what is
**				better necessarily. Functions will likely continue to be
**				updated.
*****************************************************************************/


#include "UserInputValidation.hpp"
#include <iostream>
#include <sstream> //For using a stringstream object

int getInt(std::string promptForUser)
{
	//Declare an int that will hold the user's integer choice after
	//validation. This will be returned by the function.
	int userInt;

	//Boolean for loop control. Keeps track of whether or not the user
	//has succesfully entered an integer
	bool userEnteredInteger = true;

	//String variable to hold the user's raw input
	std::string userInt_Str;

	//Declare two integer varaibles for use with the string.substr() function.
	//This will be used to trim white space from the beginning and end of the string
	int startPos;
	int length;

	//Creates a string stream object that will give the userInt variable the
	//modified user input
	std::stringstream convertedUserInput;

	//Start a do while loop since this action will need to be completed at least once
	do
	{
		//Must set the boolean to true at the start everytime (note this is redundant for the first loop
		//since the bool is already true)
		userEnteredInteger = true;

		//Displays the prompt given to the function and puts a space after it
		std::cout << promptForUser << " ";

		//Gets the user input and stores it as a string
		std::getline(std::cin, userInt_Str);

		//Using two string functions the first non-whitespace character of the input,
		//and the last non-whitespace character is found.
		startPos = userInt_Str.find_first_not_of(' ');

		//The number of characters from the starting point is determined
		//by subtracting the index of the first non-whitespace character found
		//from the index of the last non-whitespace character found and adding 1
		length = userInt_Str.find_last_not_of(' ') - startPos + 1;
		
		//If the character is not found for either of the previous formula, the
		//"npos" constant will be returned (equal to -1). To prevent an error (out of bounds),
		//1 must be added to the startPos so it will be zero and the program will not crash.
		//Note that if the character is not found, length will already be greater than 0 so there is no
		//reason to increment this value as well
		if (startPos == std::string::npos )
		{
			startPos++;
		}

		//Returns the "sub string" that starts at index startPos and takes in "length"
		//number of characters (including the character at the start position). The user's
		//input string is set as this substring. At this point the user's input has been "trimmed"
		//of leading and trailing whitespace
		userInt_Str = userInt_Str.substr(startPos, length);

		//The "trimmed" string is set as the contents to the "convertedUserInput" string stream object
		convertedUserInput.str(userInt_Str);

		//String stream object is streamed to the userInt variable
		convertedUserInput >> userInt;

		//Check if the extraction failed or the extraction succeeded but there 
		//are ASCII characters left in the stream
		if (convertedUserInput.fail() || convertedUserInput.get() >= 0)
		{
			//Sets the control bool to false
			userEnteredInteger = false;

			//Clear any potential errors with the clear() function
			convertedUserInput.clear();
		}

	} while (!userEnteredInteger); //Loop will run if the user's input was not successfully validated
	
	//Returns validated integer
	return userInt;
}



bool getInt(int &userInt, std::string promptForUser)
{

	//String variable to hold the user's raw input
	std::string userInt_Str;

	//Declare two integer varaibles for use with the string.substr() function.
	//This will be used to trim white space from the beginning and end of the string
	int startPos;
	int length;

	//Creates a string stream object that will give the userInt variable the
	//modified user input
	std::stringstream convertedUserInput;
	
	//Displays the prompt given to the function and puts a space after it
	std::cout << promptForUser << " ";

	//Gets the user input and stores it as a string
	std::getline(std::cin, userInt_Str);

	//Using two string functions the first non-whitespace character of the input,
	//and the last non-whitespace character is found.
	startPos = userInt_Str.find_first_not_of(' ');

	//The number of characters from the starting point is determined
	//by subtracting the index of the first non-whitespace character found
	//from the index of the last non-whitespace character found and adding 1
	length = userInt_Str.find_last_not_of(' ') - startPos + 1;

	//If the character is not found for either of the previous formula, the
	//"npos" constant will be returned (equal to -1). To prevent an error (out of bounds),
	//1 must be added to the startPos so it will be zero and the program will not crash.
	//Note that if the character is not found, length will already be greater than 0 so there is no
	//reason to increment this value as well
	if (startPos == std::string::npos)
	{
		startPos++;
	}

	//Returns the "sub string" that starts at index startPos and takes in "length"
	//number of characters (including the character at the start position). The user's
	//input string is set as this substring. At this point the user's input has been "trimmed"
	//of leading and trailing whitespace
	userInt_Str = userInt_Str.substr(startPos, length);

	//The "trimmed" string is set as the contents to the "convertedUserInput" string stream object
	convertedUserInput.str(userInt_Str);

	//String stream object is streamed to the userInt variable
	convertedUserInput >> userInt;

	//Check if the extraction failed or the extraction succeeded but there 
	//are ASCII characters left in the stream
	if (convertedUserInput.fail() || convertedUserInput.get() >= 0)
	{
		//Tell the caller that the user did not enter an int
		//and let the caller decide what to do
		return false;
	}

	//If this line is reached then the user entered a valid int
	return true;
}


double getDouble(std::string promptForUser)
{
	//Declare a double that will hold the user's double choice after
	//validation. This will be returned by the function.
	double userDouble;

	//Boolean for loop control. Keeps track of whether or not the user
	//has succesfully entered a double
	bool userEnteredDouble = true;

	//String variable to hold the user's raw input
	std::string userDouble_Str;

	//Declare two integer varaibles for use with the string.substr() function.
	//This will be used to trim white space from the beginning and end of the string
	int startPos;
	int length;

	//Creates a string stream object that will give the userDouble variable the
	//modified user input
	std::stringstream convertedUserInput;

	//Start a do while loop since this action will need to be completed at least once
	do
	{
		//Must set the boolean to true at the start everytime (note this is redundant for the first loop
		//since the bool is already true)
		userEnteredDouble = true;

		//Displays the prompt given to the function and puts a space after it
		std::cout << promptForUser << " ";

		//Gets the user input and stores it as a string
		std::getline(std::cin, userDouble_Str);

		//Using two string functions the first non-whitespace character of the input,
		//and the last non-whitespace character is found.
		startPos = userDouble_Str.find_first_not_of(' ');

		//The number of characters from the starting point is determined
		//by subtracting the index of the first non-whitespace character found
		//from the index of the last non-whitespace character found and adding 1
		length = userDouble_Str.find_last_not_of(' ') - startPos + 1;

		//If the character is not found for either of the previous formula, the
		//"npos" constant will be returned (equal to -1). To prevent an error (out of bounds),
		//1 must be added to the startPos so it will be zero and the program will not crash.
		//Note that if the character is not found, length will already be greater than 0 so there is no
		//reason to increment this value as well
		if (startPos == std::string::npos)
		{
			startPos++;
		}

		//Returns the "sub string" that starts at index startPos and takes in "length"
		//number of characters (including the character at the start position). The user's
		//input string is set as this substring. At this point the user's input has been "trimmed"
		//of leading and trailing whitespace
		userDouble_Str = userDouble_Str.substr(startPos, length);

		//The "trimmed" string is set as the contents to the "convertedUserInput" string stream object
		convertedUserInput.str(userDouble_Str);

		//String stream object is streamed to the userDouble variable
		convertedUserInput >> userDouble;

		//Check if the extraction failed or the extraction succeeded but there 
		//are ASCII characters left in the stream
		if (convertedUserInput.fail() || convertedUserInput.get() >= 0)
		{
			//Sets the control bool to false
			userEnteredDouble = false;

			//Clear any potential errors with the clear() function
			convertedUserInput.clear();
		}

	} while (!userEnteredDouble); //Loop will run if the user's input was not successfully validated

								  //Returns validated double
	return userDouble;

}



bool getDouble(double &userDouble, std::string promptForUser)
{

	//String variable to hold the user's raw input
	std::string userDouble_Str;

	//Declare two integer varaibles for use with the string.substr() function.
	//This will be used to trim white space from the beginning and end of the string
	int startPos;
	int length;

	//Creates a string stream object that will give the userDouble variable the
	//modified user input
	std::stringstream convertedUserInput;


	//Displays the prompt given to the function and puts a space after it
	std::cout << promptForUser << " ";

	//Gets the user input and stores it as a string
	std::getline(std::cin, userDouble_Str);

	//Using two string functions the first non-whitespace character of the input,
	//and the last non-whitespace character is found.
	startPos = userDouble_Str.find_first_not_of(' ');

	//The number of characters from the starting point is determined
	//by subtracting the index of the first non-whitespace character found
	//from the index of the last non-whitespace character found and adding 1
	length = userDouble_Str.find_last_not_of(' ') - startPos + 1;

	//If the character is not found for either of the previous formula, the
	//"npos" constant will be returned (equal to -1). To prevent an error (out of bounds),
	//1 must be added to the startPos so it will be zero and the program will not crash.
	//Note that if the character is not found, length will already be greater than 0 so there is no
	//reason to increment this value as well
	if (startPos == std::string::npos)
	{
		startPos++;
	}

	//Returns the "sub string" that starts at index startPos and takes in "length"
	//number of characters (including the character at the start position). The user's
	//input string is set as this substring. At this point the user's input has been "trimmed"
	//of leading and trailing whitespace
	userDouble_Str = userDouble_Str.substr(startPos, length);

	//The "trimmed" string is set as the contents to the "convertedUserInput" string stream object
	convertedUserInput.str(userDouble_Str);

	//String stream object is streamed to the userDouble variable
	convertedUserInput >> userDouble;

	//Check if the extraction failed or the extraction succeeded but there 
	//are ASCII characters left in the stream
	if (convertedUserInput.fail() || convertedUserInput.get() >= 0)
	{
		//Tell the caller that the user did not enter a double
		//and let the caller decide what to do
		return false;
	}

	//If this line is reached then the user entered a valid double
	return true;

}




char getChar(std::string promptForUser)
{
	//Declares the char variable that will be returned
	char userChar;

	//Declares a boolean to keep track of whether or not the
	//user has provided a char
	bool userEnteredChar = true;

	//Declares a string that will hold the user's input
	std::string userChar_Str;

	//Start a do while loop since this action will need to be completed at least once
	do
	{
		//Sets boolean to true for the beginning of each loop
		userEnteredChar = true;

		//Displays the prompt to the user and then uses getline to grab everything the user has written
		std::cout << promptForUser << " ";
		std::getline(std::cin, userChar_Str);

		//If the string is longer than 1 character this means the user did not enter a valid char
		//Or if the user enters a non printable char this might be an issue 
		//(all ASCII values 32 (except for 127 )and up are printable. 32 is the space character)
		//For now let the caller deal with non printable characters or
		//character invalid for required purpose
		if (userChar_Str.length() > 1 || userChar_Str[0] < 33)
		{
			//Sets the boolean appropriately
			userEnteredChar = false;
		}

	} while (!userEnteredChar);	//Checks if the user has entered a char

								//Once the input is validated, declare a stringstream object
								//and set the validated string as its contents
	std::stringstream convertedUserInput;
	convertedUserInput.str(userChar_Str);

	//Stream this object into the char
	convertedUserInput >> userChar;

	//return the validated char
	//The caller should verify the char is suitable for
	//the purpose it is required for
	return userChar;
}



bool getChar(char &userChar, std::string promptForUser)
{

	//Declares a string that will hold the user's input
	std::string userChar_Str;

	//Displays the prompt to the user and then uses getline to grab everything the user has written
	std::cout << promptForUser << " ";
	std::getline(std::cin, userChar_Str);

	//If the string is longer than 1 character this means the user did not enter a valid char
	//Or if the user enters a non printable char this might be an issue 
	//(all ASCII values 32 (except for 127 )and up are printable. 32 is the space character)
	//For now let the caller deal with non printable characters or
	//character invalid for required purpose
	if (userChar_Str.length() > 1 || userChar_Str[0] < 33)
	{
		//Tell the caller that the user did not enter a char
		//and let the caller decide what to do
		return false;
	}

	//Once the input is validated, declare a stringstream object
	//and set the validated string as its contents
	std::stringstream convertedUserInput;
	convertedUserInput.str(userChar_Str);

	//Stream this object into the char
	convertedUserInput >> userChar;

	//If this line is reached then the user entered a valid char
	return true;
}

//The act of using getline to recieve a string from the user should not
//fail (unless there is something I am missing) but generally it might be 
//a good idea to make sure the user has entered at least 1 printable 
//ASCII character (besides spaces). Further validation could always be 
//done by the main program.
std::string getNonBlankString(std::string promptForUser)
{
	//Creates a string variable that will be returned
	std::string validatedString;

	//Declares a boolean to control the loop
	bool goodString = false;

	//Loop will not exit until the boolean is changed to true
	while (!goodString)
	{
		//Prompt the user and read in their input using 
		//the getline function
		std::cout << promptForUser << " ";
		std::getline(std::cin, validatedString);

		//Set up a for loop to check each character of the string
		for (int i = 0; i < validatedString.length(); i++)
		{
			//If any character in the string has an ASCII value greater than 32
			//(meaning it is printable and not a space)
			if (validatedString[i] > 32)
			{
				//Set the boolean to true which will cause the loop to exit
				goodString = true;
			}
		}
	}

	//Funtion returns the now validated string to the caller
	return validatedString;
}
