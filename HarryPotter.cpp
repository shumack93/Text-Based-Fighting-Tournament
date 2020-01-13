/*********************************************************************
** Project Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Implementation file to define the HarryPotter class
**               that was declared in the header file.
*********************************************************************/

#include "HarryPotter.hpp"

HarryPotter::HarryPotter()
{
	name = "Harry Potter";
	type = "Harry Potter";
	characteristic = "He's a wizard.";
	armor = 0;
	strength = 10;
	deathStatus = false;
	Hogwarts = true;
}

HarryPotter::HarryPotter(string newName)
{
	name = newName;
	type = "Harry Potter";
	characteristic = "He's a wizard.";
	armor = 0;
	strength = 10;
	deathStatus = false;
	Hogwarts = true;
}

int HarryPotter::attack()
{
	int damage = rollAttack();

	cout << getName() << " attacks their target! They generate " << damage << " attack." << endl << endl;

	return damage;
}

void HarryPotter::defense(int damageTaken)
{
	int defend = rollDefense();
	int damageInflicted = 0;

	//If-else if statements that go through the different scenarios of Medusa using Glare
	//and Harry Potter having or not having Hogwarts.
	if (damageTaken == 1000 && Hogwarts == false)
	{	
		cout << getName() << " is hit with Medusa's Glare ability and turned to stone!" << endl;
		cout << "Remaining strength: 0" << endl << endl;
	
		deathStatus = true;

		return;
	}
	else if (damageTaken == 1000 && Hogwarts == true)
	{
		cout << getName() << " is hit with Medusa's Glare ability and turned to stone!" << endl;
		cout << "Hogwarts is activated and " << getName() << " returns to life with 20 strength!" << endl;
		
		strength = 20;
		Hogwarts = false;
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
	else if (strength <= 0 && Hogwarts == false)
	{
		cout << getName() << "'s efforts are not enough. They take " << damageInflicted << " damage and die." << endl << endl;

		deathStatus = true;
	}
	else if (strength <= 0 && Hogwarts == true)
	{
		cout << "Harry Potter takes " << damageInflicted << " damage and is killed." << endl;
		cout << "Hogwarts is activated and Harry Potter returns to life with 20 strength!" << endl;

		strength = 20;
		Hogwarts = false;
		
		cout << "Remaining strength: " << strength << endl << endl;
	}
}

bool HarryPotter::getDeathStatus()
{
	return deathStatus;
}

int HarryPotter::rollAttack()
{
	int roll;
	
	roll = rand() % 6 + 1;

	roll = roll + rand() % 6 + 1;

	return roll;
}

int HarryPotter::rollDefense()
{
	int roll;

	roll = rand() % 6 + 1;

	roll = roll + rand() % 6 + 1;

	return roll;
}

string HarryPotter::getName()
{
	return name;
}

string HarryPotter::getType()
{
	return type;
}

int HarryPotter::getArmor()
{
	return armor;
}

int HarryPotter::getStrength()
{
	return strength;
}

string HarryPotter::getCharacteristic()
{
	return characteristic;
}

void HarryPotter::heal()
{
	strength = strength * 1.3;

	if (strength >= 10)
		strength = 10;
}
