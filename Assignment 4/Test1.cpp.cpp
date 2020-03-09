// CSCI 2530
// Assignment: 3
// Author:     Sarah Barile
// File:       equiv.cpp
// Tab stops:  4

// ***SAY WHAT THE MODULE PROVIDES HERE

#include <cstdio>
#include "equiv.h"
using namespace std;

void main()
{
	int n;
	scanf_s("%d", &n);
	ER R = newER(n);
	showER(R, n);
}
\