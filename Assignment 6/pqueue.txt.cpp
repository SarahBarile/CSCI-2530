// CSCI 2530
// Assignment: 6
// Author:     Sarah Barile
// File:       pqueue.cpp
// Tab stops:  4

//This module looks at, and can insert and remove items
//within a priotrity queue
//It can also print the priority queue to the screen.

#include <cstdio>
#include <cstdlib>
#include "pqueue.h"
using namespace std;

struct PQCell {
	ItemType item;
	PriorityType priority;
	PQCell* nextCell;

	PQCell(ItemType x, PriorityType y, PQCell* z)
	{
		item = x;
		priority = y;
		nextCell = z;
	}
};

//isEmpty(const PriorityQueue& q) will look at a linked list and
//returns true if the list is empty and false otherwise
bool isEmpty(const PriorityQueue& q)
{
	if (q.linkedList != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//insertCell(PQCell*& L, ItemType x, PriorityType p) inserts
//item x with priority p into PriorityQueue object q
void insertCell(PQCell*& L, ItemType x, PriorityType p)
{
	if (L == NULL || L->priority > p)
	{
		L = new PQCell(x, p, L);
	}
	else
	{
		insertCell(L->nextCell, x, p);
	}
}

//insert(PriorityQueue& q, ItemType x, PriorityType p) inserts
//item x with priority p into linked list L
void insert(PriorityQueue& q, ItemType x, PriorityType p)
{
	insertCell(q.linkedList, x, p);
}

//printPriorityQueue(const PriorityQueue& q, ItemPrinter printItem, 
//PriorityPrinter printPriority) print the data from priority queue L
void printPriorityQueue(const PriorityQueue& q,
	ItemPrinter printItem,
	PriorityPrinter printPriority)
{
	PQCell* print = q.linkedList;
	while (print != NULL)
	{
		printItem(print->item);
		printf("\t");
		printPriority(print->priority);
		printf("\n");
		print = print->nextCell;
	}
}

//remove(PriorityQueue& q, ItemType& x, PriorityType& p) takes 
//the cell with the lowest priority and destroys it
void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
{
	x = q.linkedList->item;
	p = q.linkedList->priority;
	PQCell* cell = q.linkedList;
	q.linkedList = cell->nextCell;
	delete cell;
}


