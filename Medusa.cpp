/*******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Implementation file to define the Medusa class
**               that was declared in the header file.
*******************************************************************/

#include "Medusa.hpp"

Medusa::Medusa()
{
	name = "Medusa";
	type = "Medusa";
	characteristic = "Scrawny lady with snakes for hair which help her during combat. Just don't look at her!";
	armor = 3;
	strength = 8;
	deathStatus = false;
}

Medusa::Medusa(string newName)
{
	name = newName;
	type = "Medusa";
	characteristic = "Scrawny lady with snakes for hair which help her during combat. Just don't look at her!";
	armor = 3;
	strength = 8;
	deathStatus = false;
}	

int Medusa::attack()
{
	int damage = rollAttack();

	cout << getName() << " attacks their target! They generate " << damage << " attack." << endl << endl;

	//Returns 1000 damage if Medusa rolls a 12 and activates Glare, since no other
	//character would possibly have any combination of 1000 strength/armor/defense.
	if (damage == 12)
	{
		cout << getName() << "'s Glare ability has been activated!" << endl << endl;

		return 1000;
	}
	else
		return damage;
}

void Medusa::defense(int damageTaken)
{
	int defend = rollDefense();
	int damageInflicted = 0;

	//Added in case player 1 and player 2 both choose a Medusa.
	if (damageTaken == 1000)
	{
		cout << getName() << " is hit with another Medusa's Glare ability and turned to stone!" << endl;
		cout << "Remaining strength: 0" << endl << endl;
	
		deathStatus = true;

		return;
	}
	else if (damageTaken != 1000)
	{
		cout << getName() << " attempts to defend the attack. They generate " << defend << " defense and have 3 armor." << endl;
		damageInflicted = damageTaken - defend - armor;

		if (damageInflicted <= 0)
			damageInflicted = 0;
	}
	
	strength = strength - damageInflicted;

	if (strength > 0)
	{
		cout << getName() << " survives the attack after taking " << damageInflicted << " damage!" << endl;
		cout << "Remaining strength: " << strength << endl << endl;
	}
	else if (strength <= 0)
	{
		cout << getName() << "'s efforts are not enough. They take " << damageInflicted << " damage and die." << endl << endl;

		deathStatus = true;
	}
}

bool Medusa::getDeathStatus()
{
	return deathStatus;
}

int Medusa::rollAttack()
{
	int roll;
	
	roll = rand() % 6 + 1;

	roll = roll + rand() % 6 + 1;

	return roll;
}

int Medusa::rollDefense()
{
	int roll;

	roll = rand() % 6 + 1;

	return roll;
}

string Medusa::getName()
{
	return name;
}

string Medusa::getType()
{
	return type;
}

int Medusa::getArmor()
{
	return armor;
}

int Medusa::getStrength()
{
	return strength;
}

string Medusa::getCharacteristic()
{
	return characteristic;
}

void Medusa::heal()
{
	strength = strength * 1.3;

	if (strength >= 8)
		strength = 8;
}
