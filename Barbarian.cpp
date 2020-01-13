/*******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/26/2019
** Description:  Implementation file to define the Barbarian class
**               that was declared in the header file.
*******************************************************************/

#include "Barbarian.hpp"

Barbarian::Barbarian()
{
	name = "Barbarian";
	type = "Barbarian";
	characteristic = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
	armor = 0;
	strength = 12;
	deathStatus = false;
}

Barbarian::Barbarian(string newName)
{
	name = newName;
	type = "Barbarian";
	characteristic = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
	armor = 0;
	strength = 12;
	deathStatus = false;	
}

int Barbarian::attack()
{
	int damage = rollAttack();

	cout << getName() << " attacks their target! They generate " << damage << " attack." << endl << endl;

	return damage;
}

void Barbarian::defense(int damageTaken)
{
	int defend = rollDefense();
	int damageInflicted = 0;

	//To account for Medusa's glare, which returns a 1000 if she rolls a 12.
	if (damageTaken == 1000)
	{
		cout << getName() << " is hit with Medusa's Glare ability and turned to stone!" << endl;
		cout << "Remaining strength: 0" << endl << endl;
	
		deathStatus = true;

		return;
	}
	else if (damageTaken != 1000)
	{
		cout << getName() << " attempts to defend the attack. They generate " << defend << " defense and have 0 armor." << endl;
		damageInflicted = damageTaken - defend;

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

bool Barbarian::getDeathStatus()
{
	return deathStatus;
}

int Barbarian::rollAttack()
{
	int roll;
	
	roll = rand() % 6 + 1;

	roll = roll + rand() % 6 + 1;

	return roll;
}

int Barbarian::rollDefense()
{
	int roll;

	roll = rand() % 6 + 1;

	roll = roll + rand() % 6 + 1;

	return roll;
}

string Barbarian::getName()
{
	return name;
}

string Barbarian::getType()
{
	return type;
}

int Barbarian::getArmor()
{
	return armor;
}

int Barbarian::getStrength()
{
	return strength;
}

string Barbarian::getCharacteristic()
{
	return characteristic;
}

void Barbarian::heal()
{
	strength = strength * 1.3;

	if (strength >= 12)
		strength = 12;
}
