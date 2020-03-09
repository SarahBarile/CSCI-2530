// CSCI 2530
// Assignment: 3
// Author:     Sarah Barile
// File:       hailstone.cpp
// Tab stops:  4

//This program runs through the hailstone sequence for given values
//and returns the sequence along with its length, the largest number 
//and some other statistics

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

// Next(n) returns the number that follows n
// in a hailstone sequence.  For example, 
// next(7) = 22 and next(8) = 4.
//
// Next requires n > 1, since there is no number
// that follows 1.
int next(int n)
{
	int nextNum;
	if ((n % 2) == 0)
	{
		return (n / 2);
	}
	else
	{
		return ((n * 3) + 1);
	}
	return nextNum;
}

//The writeHS(n) prints the hailstone sequence for 'n'
void writeHS(int n)
{
	printf("%d ", n);
	while (n > 1)
	{
		n = next(n);
		printf("%d ", n);
	}
}

//The int lengthHailstone(int n) returns l 
//the sequence until it reaches 1. It will not print or scan any information.
int lengthHS(int n)
{
	int length;
	for (length = 1; n > 1; length++)
	{
		n = next(n);
	}
	return length;
}

//The largestHailstone(n) funtion uses a loop to find the biggest
//number in the hailstone sequence.

int largestInHS(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int largest = n;
		int length = lengthHS(n);
		for (int i = 0; i < length; i++)
		{
			if (largest < next(n))
			{
				largest = next(n);
			}
			n = next(n);
		}
		return largest;
	}
}

//bool bigHailstone(int n) returns true if a hailstone
//sequence contains a value that is greater than 1000
//and false otherwise
bool bigHailstone(int n)
{
	for (int i = 0; i < lengthHS(n); i++)
	{
		if (n > 1000)
		{
			return true;
		}
		n = next(n);
	}
	return false;
}

//The longestHailstoneLength(n) returns the amount of numbers
//in the largest sequence up to n.
int longestHS(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int longestSequence = lengthHS(n);
		for (int i = 1; i < n; i++)
		{
			if (lengthHS(i) > longestSequence)
			{
				longestSequence = lengthHS(i);
			}
		}
		return longestSequence;
	}
}

//The longestHailstoneSequence(n) function will go through each
//hailstone sequence up to 'n' and returns the starting number 
//of the largest sequence.
int startOfLongestHS(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (lengthHS(i) == longestHS(n))
			{
				return i;
			}
		}
	}
}

////The largestHailstoneValue(n) function will go through every
//hailstone sequence to 'n' returns
//and the starting number of the largest sequence.
int largestInAnyHS(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int largestInAny = largestInHS(n);
		for (int i = 1; i < n; i++)
			if (largestInAny < largestInHS(i))
			{
				largestInAny = largestInHS(i);
			}
		return largestInAny;
	}
}

// int startHSWithLargest(int n) return the starting value of the
//sequence that contains the largest
int startHSWithLargest(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (largestInAnyHS(n) == largestInHS(i))
			{
				return i;
			}
		}
	}
}

int main()
{
	int n;
	printf("What number shall I start with? ");
	scanf("%d", &n);
	printf("\nThe hailstone sequence starting at %d is:\n", n);
	writeHS(n);
	printf("\nSequence length:\t\t\t\t\t%d\n", lengthHS(n));
	printf("Largest Number:\t\t\t\t\t\t%d\n", largestInHS(n));
	printf("Contains a number >1000?\t\t\t\t");
	if (bigHailstone(n) == true)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	printf("Greatest length starting with 1 to %d:\t\t\t%d\n",
		n, longestHS(n));
	printf("Start value of sequence of length %d:\t\t\t%d\n",
		n, startOfLongestHS(n));
	printf("Largest value in a sequence starting with 1 to %d:\t%d\n",
		n, largestInAnyHS(n));
	printf("Start value of sequence containing %d:\t\t  %d\n",
		largestInAnyHS(n), startHSWithLargest(n));
	return 0;
}