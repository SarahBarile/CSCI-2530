// CSCI 2530
// Assignment: 1
// Author:     Sarah Barile
// File:       points.cpp
// Tab stops:  4

//=======================================================
// This program reads three points (x1,y1,z1), (x2,y2,z2)
// and (x3,y3,z3) from the standard input, in format
//
//   x1  y1  z1
//   x2  y2  z2
//   x3  y3  z3
//
// Then it writes, to the standard output, every pair of
// those points that are farthest apart, along with their
// distance.  (More than one pair is only shown if two
// or more pairs are equally far apart.)
//=======================================================

#include <cstdio>
#include <cmath>
using namespace std;

//=======================================================
// echo
//=======================================================
// Echo writes points (x1,y1,z1), (x2,y2,z2) and (x3,y3,z3)
// at the original three points.
//=======================================================

void echo(double x1, double y1, double z1,
	double x2, double y2, double z2,
	double x3, double y3, double z3)
{
	printf("The three points are:\n\t%10.3lf\t%10.3lf\t%10.3lf\n\t%10.3lf\t%10.3lf\t%10.3lf\n\t%10.3lf\t%10.3lf\t%10.3lf\n\n",
		x1, y1, z1, x2, y2, z2, x3, y3, z3);
}

//=======================================================
// distance
//=======================================================
// Distance returns the distance between the points 
// (x1,y1,z1) and (x2,y2,z2).
//=======================================================

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2)));
}

//=======================================================
// farthest
//=======================================================
// Farthest takes 3 points p1 = (x1,y1,z1), 
// p2 = (x2,y2,z2) and p3 = (x3,y3,z3).
//
// Farthest returns true if pair of points (p1, p2) is at
// least as far apart as pairs (p1,p3) and (p2,p3), and
// returns false otherwise.
//=======================================================

bool farthest(double x1, double y1, double z1,
	double x2, double y2, double z2,
	double x3, double y3, double z3)
{
	if (distance(x1, y1, z1, x2, y2, z2) >= distance(x1, y1, z1, x3, y3, z3)
		&& distance(x1, y1, z1, x2, y2, z2) >= distance(x2, y2, z2, x3, y3, z3))
	{
		return true;
	} else {
		return false;
	}
}

//=======================================================
// ShowFarthest
//=======================================================
// ShowFarthest writes that points (x1,y1,z1) and (x2,y2,z2)
// are a pair that are farthest apart.  It also shows the
// distance between them.
//=======================================================

void ShowFarthest(double x1, double y1, double z1,
	double x2, double y2, double z2)
{
	printf("The farthest points are:\n\t%10.3lf\t%10.3lf\t%10.3lf\n\t%10.3lf\t%10.3lf\t%10.3lf\n\nThe distance between them is:\t%10.3lf\n\n",
		x1, y1, z1, x2, y2, z2, distance(x1, y1, z1, x2, y2, z2));
}

//=======================================================
// ShowAllFarthest
//=======================================================
// ShowAllFarthest takes 3 points p1 = (x1,y1,z1),
// p2 = (x2,y2,z2) and p3 = (x3,y3,z3).
//
// ShowAllFarthest writes all pairs of farthest apart points
// among p1, p2 and p3.
//=======================================================

void ShowAllFarthest(double x1, double y1, double z1,
	double x2, double y2, double z2,
	double x3, double y3, double z3)
{
	if (farthest(x1, y1, z1, x2, y2, z2, x3, y3, z3) == true)
	{
		ShowFarthest(x1, y1, z1, x2, y2, z2);
	}
	if (farthest(x1, y1, z1, x3, y3, z3, x2, y2, z2) == true)
	{
		ShowFarthest(x1, y1, z1, x3, y3, z3);
	}
	if (farthest(x2, y2, z2, x3, y3, z3, x1, y1, z1) == true)
	{
		ShowFarthest(x2, y2, z2, x3, y3, z3);
	}
}

//=======================================================
// main
//=======================================================

int main()
{
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
	echo(x1, y1, z1, x2, y2, z2, x3, y3, z3);
	
	ShowAllFarthest(x1, y1, z1, x2, y2, z2, x3, y3, z3);
	
	return 0;
}