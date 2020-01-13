/*******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Header file to declare the Medusa class that
**               will be defined in the Medusa.cpp file.
*******************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Character.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Medusa: public Character
{
	public:
		Medusa();
		Medusa(string newName);
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
