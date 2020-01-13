/*******************************************************************
** Project Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Implementation file to define the BlueMen class
**               that was declared in the header file.
*******************************************************************/

#include "BlueMen.hpp"

BlueMen::BlueMen()
{
	name = "Blue Men";
	type = "Blue Men";
	characteristic = "They are small, 6 inches tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies' armor or clothing.";
	armor = 3;
	strength = 12;
	deathStatus = false;
}

BlueMen::BlueMen(string newName)
{
	name = newName;
	type = "Blue Men";
	characteristic = "They are small, 6 inches tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies' armor or clothing.";
	armor = 3;
	strength = 12;
	deathStatus = false;
}

int BlueMen::attack()
{
	int damage = rollAttack();

	cout << getName() << " attack their target! They generate " << damage << " attack." << endl << endl;

	return damage;
}

void BlueMen::defense(int damageTaken)
{
	int defend = rollDefense();
	int damageInflicted = 0;

	//To account for Medusa's Glare.
	if (damageTaken == 1000)
	{
		cout << getName() << " are hit with Medusa's Glare ability and turned to stone!" << endl;
		cout << "Remaining strength: 0" << endl << endl;
	
		deathStatus = true;

		return;
	}
	else if (damageTaken != 1000)
	{
		cout << getName() << " attempt to defend the attack. They generate " << defend << " defense and have 3 armor." << endl;
		damageInflicted = damageTaken - defend - armor;

		if (damageInflicted <= 0)
			damageInflicted = 0;
	}
	
	strength = strength - damageInflicted;

	if (strength > 0)
	{
		cout << getName() << " survive the attack after taking " << damageInflicted << " damage!" << endl;
		cout << "Remaining strength: " << strength << endl << endl;
	}
	else if (strength <= 0)
	{
		cout << getName() << "'s efforts are not enough. They take " << damageInflicted << " damage and die." << endl << endl;

		deathStatus = true;
	}
}

bool BlueMen::getDeathStatus()
{
	return deathStatus;
}

int BlueMen::rollAttack()
{
	int roll;
	
	roll = rand() % 10 + 1;

	roll = roll + rand() % 10 + 1;

	return roll;
}

int BlueMen::rollDefense()
{
	int roll;

	//Rolls differently based on how many Blue Men are still alive.
	if (getStrength() <= 4 && getStrength() > 0)
		roll = rand() % 6 + 1;
	else if (getStrength() > 4 && getStrength() <= 8)
	{
		roll = rand() % 6 + 1;
		roll = roll + rand() % 6 + 1;
	}
	else if (getStrength() > 8 && getStrength() <= 12)
	{
		roll = rand() % 6 + 1;
		roll = roll + rand() % 6 + 1;
		roll = roll + rand() % 6 + 1;
	}

	return roll;
}

string BlueMen::getName()
{
	return name;
}

string BlueMen::getType()
{
	return type;
}

int BlueMen::getArmor()
{
	return armor;
}

int BlueMen::getStrength()
{
	return strength;
}

string BlueMen::getCharacteristic()
{
	return characteristic;
}

void BlueMen::heal()
{
	strength = strength * 1.3;

	if (strength >= 12)
		strength = 12;
}
