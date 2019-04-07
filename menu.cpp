/*******************************************************************************
 * Program: General Menu
 * Author: Dean Branaman
 * Date: 01-20-2019
 * Description: Definitions for class Menu. An object of class Menu is built 
 * using user defined strings. This strings are displayed and user selection is
 * given back to the calling function.
 * ****************************************************************************/
#include "menu.hpp"
#include <iostream>
/*************************** Constructor **************************************/
Menu::Menu(){ //Sets default options if none are given
	numOpt = 0;
	menuPtr = NULL;
	name = "a";
}

Menu::Menu(std::string* sPtr, int num, std::string inName){
	menuPtr = sPtr; //Sets variables to parameters
	numOpt = num;
	name = inName;
}

/************************** Destructor ****************************************/
Menu::~Menu(){}
/************************** Set Functions *************************************/
void Menu::set_numOpt(int num){
	numOpt = num;
}

void Menu::set_menuPtr(string* ptr){
	menuPtr = ptr;
}

void Menu::set_name(string n){
	name = n;
}

/**************************** Display *****************************************/
int Menu::display(){ //Prints menu options to screen
	std::cout << name << std::endl;
	for (int i = 0; i < numOpt; i++){
		std::cout << i+1 << ": " << menuPtr[i] << std::endl;
	}
	
	int selection = this->valInput(); // Checks input for validity
	
	return selection; //Returns menu selection to caller
}

/******************************** valInput ************************************/
int Menu::valInput(){
	int input;
	std::string inString;

	while(true){ //Loop repeats until valid input is returned
		//User prompt
		std::cout <<"Please select an option by entering the number.\n"; 
		//Stores user input in inString
		std::getline(std::cin, inString); 
		std::stringstream convert(inString); //Converst inString to int
		//If the converted string is an integer,
		// and is not a string (i.e any other input)
		// and is an option displayed
		if (convert >> input && !(convert >> inString) 
		 && (input > 0 && input < (numOpt + 1))){
			return input; //Return chosen option
		}
		std::cin.clear();//Clears buffer for next input
		//Prints a corrective prompt;
		std::cout << "Input must be a valid option. Please try again.\n";
	}
	/* Function adapted from post by Cuddlebuddie928 on 
 	* www.cplusplus.com/forum/beginner/58833/ */
}
