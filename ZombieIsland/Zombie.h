#pragma once
#include "Entity.h"
class Zombie : public Entity
{
	int SwitchVal;

public:
	void ZMove(int xAxis, int yAxis, int playPosX, int playPosY);

};