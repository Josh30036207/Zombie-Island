#include "Includes.h"
#include "Entity.h"
using namespace std;

void Entity::StartRand() {
	srand(static_cast<unsigned int>(time(0)));//initial random - uses time as a seed to avoid the same result each time
};

int Entity::SetX(int XAxis) {

	LocX = rand() % (XAxis) ;

	return(LocX);
};

int Entity::SetY(int YAxis) {

	LocY = rand() % (YAxis) ;

	return(LocY);
};

int Entity::GetX() {

	return(LocX);
};

int Entity::GetY() {

	return(LocY);
};

int Entity::GetOldX() {

	return(OldX);
};

int Entity::GetOldY() {

	return(OldY);
};