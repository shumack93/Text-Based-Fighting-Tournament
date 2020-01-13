/*******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Header file to declare the HarryPotter class that
**               will be defined in the HarryPotter.cpp file.
*******************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Character.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class HarryPotter: public Character
{
	private: 
		bool Hogwarts;

	public:
		HarryPotter();
		HarryPotter(string newName);
		int attack();
		void defense(int damageTaken);
		bool getDeathStatus();
		int rollAttack();
		int rollDefense();
		string getName();
		string getType();
		int getArmor();
		int getStrength();
		string getCharacteristic();
		void heal();
};

#endif
