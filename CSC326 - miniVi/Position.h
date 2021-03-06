#pragma once

#ifndef _POSITION
#define _POSITION

#include <iostream>

using namespace std;

class Position {
public:
	Position();
	Position(int mX, int mY);
	void setX(int x);
	void setY(int y);
	const int getX();
	const int getY();
	double distance(const Position& p2);
	
private:
	int mX;
	int mY;
};

#endif