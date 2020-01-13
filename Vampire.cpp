/*******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Implementation file to define the Vampire class
**               that was declared in the header file.
*******************************************************************/

#include "Vampire.hpp"

Vampire::Vampire()
{
	name = "Vampire";
	type = "Vampire";
	characteristic = "Suave, debonair, but vicious and surprisingly resilient";
	armor = 1;
	strength = 18;
	deathStatus = false;
}

Vampire::Vampire(string newName)
{
	name = newName;
	type = "Vampire";
	characteristic = "Suave, debonair, but vicious and surprisingly resilient";
	armor = 1;
	strength = 18;
	deathStatus = false;
}

int Vampire::attack()
{
	int damage = rollAttack();

	cout << getName() << " attacks their target! They generate " << damage << " attack." << endl << endl;

	return damage;
}

void Vampire::defense(int damageTaken)
{
	int charm;

	int defend = rollDefense();
	int damageInflicted = 0;

	charm = rand() % 2 + 1;

	//If-else if statement in the case Medusa rolls a 12 (Glare) and Vampire has Charm active so
	//that Charm overrides Glare.
	if (charm == 1)
	{
		cout << getName() << " uses charm! The attack on them fails!" << endl;
		cout << "Remaining strength: " << getStrength() << endl << endl;
	
		return;
	}	
	else if (damageTaken == 1000)
	{
		cout << getName() << " is hit with Medusa's Glare ability and turned to stone!" << endl;
		cout << "Remaining strength: 0" << endl << endl;
	
		deathStatus = true;

		return;
	}

	if (damageTaken != 1000)
	{
		cout << getName() << " attempts to defend the attack. They generate " << defend << " defense and have 1 armor." << endl;
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

bool Vampire::getDeathStatus()
{
	return deathStatus;
}

int Vampire::rollAttack()
{
	int roll;
	
	roll = rand() % 12 + 1;

	return roll;
}

int Vampire::rollDefense()
{
	int roll;

	roll = rand() % 6 + 1;

	return roll;
}

string Vampire::getName()
{
	return name;
}

string Vampire::getType()
{
	return type;
}

int Vampire::getArmor()
{
	return armor;
}

int Vampire::getStrength()
{
	return strength;
}

string Vampire::getCharacteristic()
{
	return characteristic;
}

void Vampire::heal()
{
	strength = strength * 1.3;

	if (strength >= 18)
		strength = 18;
}
