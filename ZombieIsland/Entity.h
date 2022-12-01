#pragma once
#include "Includes.h"
#include <cstdlib>
#include <ctime>

class Entity
{
public:
	int LocX;
	int LocY;
	int OldX;
	int OldY;
	
	void StartRand();
	int SetX(int XAxis); 
	int SetY(int YAxis);
	int GetX();
	int GetY();
	int GetOldX();
	int GetOldY();



};