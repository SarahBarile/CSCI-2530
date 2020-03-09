// CSCI 2530
// Assignment: 6
// Author:     Sarah Barile
// File:       pqueue.h
// Tab stops:  4

typedef const char* ItemType;
typedef double      PriorityType;
struct PQCell;
struct PriorityQueue;

//structure PriorityQueue just holds a pointer that points
//to the linked list
struct PriorityQueue {
	PQCell* linkedList;
	PriorityQueue()
	{
		linkedList = NULL;
	}
};


bool isEmpty(const PriorityQueue& q);
void insert(PriorityQueue& q, ItemType x, PriorityType p);
void remove(PriorityQueue& q, ItemType& x, PriorityType& p);

typedef void (*ItemPrinter)(ItemType);
typedef void (*PriorityPrinter)(PriorityType);
void printPriorityQueue(const PriorityQueue& q,
	ItemPrinter printItem,
	PriorityPrinter printPriority);