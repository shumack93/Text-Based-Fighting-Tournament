/*******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/26/2019
** Description:  Header file to declare the Barbarian class that
**               will be defined in the Barbarian.cpp file.
*******************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Character.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Barbarian: public Character
{
	public:
		Barbarian();
		Barbarian(string newName);
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
