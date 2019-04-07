/*******************************************************************************
 * Program: General Menu
 * Author: Dean Branaman
 * Date: 01-20-2019
 * Description: Data members and member functions for class Menu. Menu class 
 * will display prompts to user that are defined at the start of a main file.
 * ****************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <sstream>

using std::string;

class Menu{
	private:
		int numOpt;
		std::string* menuPtr;
		std::string name;
	public:
		Menu();
		Menu(std::string*, int, std::string);
		~Menu();
		void set_numOpt(int);
		void set_menuPtr(string*);
		void set_name(string);	
		int display();
		int valInput();
};
#endif
