// CSCI 2530
// Assignment: 3
// Author:     Sarah Barile
// File:       equiv.cpp
// Tab stops:  6

//equiv.cpp provides functions to use with an
//equivalence relation

#include <cstdio>
#include "equiv.h"
using namespace std;

//newER(n) creates an equivalence relation that can 
//handle a set of {1, 2, .., n}

ER newER(const int n)
{
	ER R = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		R[i] = 0;
	}
	return R;
}

//showER(R, n) prints the entire contents of the
//equivalence relation from 1 to n

void showER(const ER R, const int n)
{
	printf("index\tboss\n");
	for (int i = 1; i < (n + 1); i++)
	{
		printf("  %i\t  %i\n", i, R[i]);
	}
}

//leader(R, x) returns the leader of x in
//equivalence relation R

int  leader(ER R, const int x)
{
	int y = x;
	while (R[y] != 0 && R[y] != y)
	{
		y = R[y];
	}
	return y;
}

//combine(R, x, y) combines the equivalence 
//classes of x and y in R.

void combine(ER R, const int x, const int y)
{
	if (leader(R, x) != leader(R, y))
	{
		if (R[x] == 0)
		{
			R[x] = y;
		}
		else
		{
			int i = x;
			int z;
			while (R[i] != 0)
			{
				z = R[i];
				R[i] = y;
				i = z;
			}
		}
	}
}

//Equivalent(R, x, y) returns true if x and
//y have the same leader in R. 

bool equivalent(ER R, const int x, const int y)
{
	if (leader(R, x) == leader(R, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//DestroyER(R) deallocates array R.

void destroyER(ER R)
{
	delete[] R;
}