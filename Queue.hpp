/******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/26/2019
** Description:  Header file to declare the Queue class that will
**               be defined in the Queue.cpp file.
******************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<cstdlib>
#include<iostream>
#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;

struct QueueNode
{
	QueueNode* next;
	QueueNode* prev;
	Character* val;
};

class Queue
{
	private:
		QueueNode* head;

	public:
		Queue();
		~Queue();
		bool isEmpty();
		void addBack(Character* newCharacter);
		Character* getFront();
		void removeFront();
		void printQueue();
		void printBackwards();
		QueueNode* getNodeHead();
};

#endif
