/*********************************************************************
** Program Name: Project 3 - Fantasy Combat Game
** Author:       Cris Shumack
** Date:         02/17/2019
** Description:  Main function to run our fantasy combat game.
**
*********************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Character.hpp"
#include "Queue.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//So our rand() functions generate different numbers each time.
	srand(time(NULL));

	int choice, loserChoice, player1, player2, lineup1, lineup2, firstAttack, attackDmg;
	Character* fighter1;
	Character* fighter2;
	Queue team1;
	Queue team2;
	Queue losers;
	string newName;
	bool continueGame = true;

	cout << endl << "Welcome to the fantasy combat tournament!" << endl;
	
	//Gave the user the option to replay the game by using a do-while loop.
	do
	{
		int fightNumber = 1, team1points = 0, team2points = 0;

		cout << endl << "Select an option from the menu below." << endl;
		cout << "1. Play game" << endl;
		cout << "2. Exit game" << endl;
		cin >> choice;
		inputValidation(choice, 1, 2);

		if (choice == 1)
		{
			cout << "How many fighters would you like on Team 1? (max 100)" << endl;
			cin >> lineup1;
			inputValidation(lineup1, 1, 100);

			cout << "How many fighters would you like on Team 2? (max 100)" << endl;
			cin >> lineup2;
			inputValidation(lineup2, 1, 100);

			cout << endl << "Team 1's turn to pick fighters!" << endl;

			for (int i = 0; i < lineup1; i++)
			{
				cout << endl << "Select a fighter to add to Team 1." << endl;
				cout << "1. Vampire" << endl;
				cout << "2. Barbarian" << endl;
				cout << "3. Blue Men" << endl;
				cout << "4. Medusa" << endl;
				cout << "5. Harry Potter" << endl;
				cin >> player1;
				inputValidation(player1, 1, 5);
	
				cout << "Enter a new name for your character." << endl;
				cin.ignore(0, '\n');
				getline(cin, newName);
		
				//To create the correct character type based on user input.
				if (player1 == 1)
				{
					fighter1 = new Vampire(newName);

					team1.addBack(fighter1);
				}
				else if (player1 == 2)
				{
					fighter1 = new Barbarian(newName);

					team1.addBack(fighter1);
				}
				else if (player1 == 3)
				{
					fighter1 = new BlueMen(newName);

					team1.addBack(fighter1);
				}
				else if (player1 == 4)
				{
					fighter1 = new Medusa(newName);

					team1.addBack(fighter1);
				}
				else if (player1 == 5)
				{
					fighter1 = new HarryPotter(newName);

					team1.addBack(fighter1);
				}
			}

			cout << endl << "Team 2's turn to pick fighters!" << endl;

			for (int k = 0; k < lineup2; k++)
			{
				cout << endl << "Select a fighter to add to Team 2." << endl;
				cout << "1. Vampire" << endl;
				cout << "2. Barbarian" << endl;
				cout << "3. Blue Men" << endl;
				cout << "4. Medusa" << endl;
				cout << "5. Harry Potter" << endl;
				cin >> player2;
				inputValidation(player2, 1, 5);
		
				cout << "Enter a new name for your character." << endl;
				cin.ignore(0, '\n');
				getline(cin, newName);
				
				if (player2 == 1)
				{
					fighter2 = new Vampire(newName);

					team2.addBack(fighter2);
				}
				else if (player2 == 2)
				{
					fighter2 = new Barbarian(newName);

					team2.addBack(fighter2);
				}
				else if (player2 == 3)
				{
					fighter2 = new BlueMen(newName);

					team2.addBack(fighter2);
				}
				else if (player2 == 4)
				{
					fighter2 = new Medusa(newName);

					team2.addBack(fighter2);
				}
				else if (player2 == 5)
				{
					fighter2 = new HarryPotter(newName);

					team2.addBack(fighter2);
				}
			}

			//Randomly selects who attacks first.
			firstAttack = rand() % 2 + 1;

			if (firstAttack == 1)
				cout << "Team 1 was randomly selected to attack first!" << endl << endl;
			else
				cout << "Team 2 was randomly selected to attack first!" << endl << endl;

			while (team1.isEmpty() == false && team2.isEmpty() == false)
			{
				cout << endl << "------------------------------------------------------" << endl << "FIGHT " << fightNumber << endl << "------------------------------------------------------" << endl << endl;

				if (firstAttack == 1)
				{
					int round = 1;
	
					while (team1.getFront()->getDeathStatus() == false && team2.getFront()->getDeathStatus() == false)
					{
						cout << "------------------------------------------------------" << endl << "ROUND " << round << endl << "------------------------------------------------------" << endl;
		
						cout << "Team 1's " << team1.getFront()->getType() << " attacks:" << endl;
						attackDmg = team1.getFront()->attack();
	
						cout << "Team 2's " << team2.getFront()->getType() << " defends:" << endl;
						team2.getFront()->defense(attackDmg);
	
						if (team2.getFront()->getDeathStatus() == false)
						{
							cout << "Team 2's " << team2.getFront()->getType() << " attacks:" << endl;
							attackDmg = team2.getFront()->attack();
	
							cout << "Team 1's " << team1.getFront()->getType() << " defends:" << endl;
							team1.getFront()->defense(attackDmg);
						}
	
						round++;
					}
					
					if (team1.getFront()->getDeathStatus() == true)
					{
						team2.getFront()->heal();

						losers.addBack(team1.getFront());
						team1.removeFront();

						team2.addBack(team2.getFront());
						team2.removeFront();

						team2points++;
					}
					else if (team2.getFront()->getDeathStatus() == true)
					{
						team1.getFront()->heal();

						losers.addBack(team2.getFront());
						team2.removeFront();

						team1.addBack(team1.getFront());
						team1.removeFront();

						team1points++;
					}

					fightNumber++;
				}
				else if (firstAttack == 2)
				{
					int round = 1;
			
					while (team1.getFront()->getDeathStatus() == false && team2.getFront()->getDeathStatus() == false)
					{
						cout << "------------------------------------------------------" << endl << "ROUND " << round << endl << "------------------------------------------------------" << endl;
					
						cout << "Team 2's " << team2.getFront()->getType() << " attacks:" << endl;
						attackDmg = team2.getFront()->attack();
	
						cout << "Team 1's " << team1.getFront()->getType() << " defends:" << endl;
						team1.getFront()->defense(attackDmg);
	
						if (team1.getFront()->getDeathStatus() == false)
						{
							cout << "Team 1's " << team1.getFront()->getType() << " attacks:" << endl;
							attackDmg = team1.getFront()->attack();
		
							cout << "Team 2's " << team2.getFront()->getType() << " defends:" << endl;
							team2.getFront()->defense(attackDmg);
						}
		
						round++;
					}

					if (team1.getFront()->getDeathStatus() == true)
					{
						team2.getFront()->heal();

						losers.addBack(team1.getFront());
						team1.removeFront();

						team2.addBack(team2.getFront());
						team2.removeFront();

						team2points++;
					}
					else if (team2.getFront()->getDeathStatus() == true)
					{
						team1.getFront()->heal();

						losers.addBack(team2.getFront());
						team2.removeFront();

						team1.addBack(team1.getFront());
						team1.removeFront();

						team1points++;
					}

					fightNumber++;
				}
			

				if (team1.isEmpty() == true)
				{
					cout << "Team 1 is out of fighters!" << endl << endl;
					cout << "Final score:" << endl << "Team 1 fights won - " << team1points << endl << "Team 2 fights won - " << team2points << endl << endl;
				}
				else if (team2.isEmpty() == true)
				{
					cout << "Team 2 is out of fighters!" << endl << endl;
					cout << "Final score:" << endl << "Team 1 fights won - " << team1points << endl << "Team 2 fights won - " << team2points << endl << endl;
				}
			}

			if (team1points > team2points)
				cout << "Team 1 wins!" << endl;
			else if (team1points < team2points)
				cout << "Team 2 wins!" << endl;
			else if (team1points == team2points)
				cout << "It's a tie!" << endl;

			cout << "Would you like to print the list of fighters that lost? Enter 1 for yes or 2 for no." << endl;
			cin >> loserChoice;
			inputValidation(loserChoice, 1, 2);

			if (loserChoice == 1)
				losers.printBackwards();
			else
				cout << endl;

			//To free memory allocated to avoid memory leaks.
			while (team1.isEmpty() == false)
			{	
				delete team1.getFront();

				team1.removeFront();
			}
			while (team2.isEmpty() == false)
			{	
				delete team2.getFront();

				team2.removeFront();
			}
			while (losers.isEmpty() == false)
			{	
				delete losers.getFront();

				losers.removeFront();
			}
		}
		else if (choice == 2)
			continueGame = false;

	}
	while (continueGame == true);

	return 0;
}
