/******************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament
** Author:       Cris Shumack
** Date:         02/27/2019
** Description:  Implementation file to define the Queue class
**               that was declared in the header file.
******************************************************************/

#include "Queue.hpp"

Queue::Queue()
{
	head = NULL;
}

bool Queue::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void Queue::addBack(Character* newCharacter)
{
	if (isEmpty() == true) //If queue is empty, creates and sets the head node and sets next/prev to that node.
	{
		head = new QueueNode;
		head->val = newCharacter;
		head->next = head;
		head->prev = head;
	}
	else if (isEmpty() == false)
	{
		//If queue isn't empty, creates a new node and adds it to the back of the queue, and correctly 
		//adjusts the head/next/prev.
		QueueNode* holder = head->prev;

		QueueNode* newNode = new QueueNode;

		newNode->val = newCharacter;
		newNode->next = head;
		newNode->prev = holder;

		holder->next = newNode;
		head->prev = newNode;
	}
}

Character* Queue::getFront()
{
	if (head == NULL)
	{
		cout << "Queue is empty." << endl;
	}
	else
		return head->val;
}

void Queue::removeFront()
{
	if (head == NULL)
	{
		cout << "Queue is empty." << endl;
	
		return;
	}
	else if (head->next == head) //Included for case that head node is the only node in queue.
	{
		delete head;

		head = NULL;
	}
	else
	{
		QueueNode* holder = head; //Create a new node to hold the place of the head node.

		head = head->next;
		head->prev = holder->prev;
		head->prev->next = head;

		delete holder;
	}
}

void Queue::printQueue()
{
	if (head == NULL)
	{
		cout << "Queue is empty." << endl;

		return;
	}
	else
	{
		QueueNode* holder = head; //Create a new node to hold the place of the head node.

		while (holder->next != head)
		{
			cout << holder->val->getName() << " ";

			holder = holder->next; //To move to the next node in the queue.
		}
	
		cout << holder->val->getName() << " "; //Added so that the last value in the queue is printed.
	}

	cout << endl;
}

void Queue::printBackwards()
{
	QueueNode* holder = head->prev;

	cout << endl << "Losers (most recent to first): ";

	while (holder != head)
	{
		cout << holder->val->getName() << ", ";
		
		holder = holder->prev;
	}
	
	cout << holder->val->getName() << " " << endl;
}	

//Used in main for an if statement to determine if head node is NULL.
QueueNode* Queue::getNodeHead()
{
	return head;
}

//To free memory.
Queue::~Queue()
{
	if (isEmpty() == false)
	{
		while (head->next != head)
		{
			QueueNode* holder = head->next;

			delete head->val;

			removeFront();

			head = holder;
		}

		delete head->val;
		
		removeFront();
	}	
}
