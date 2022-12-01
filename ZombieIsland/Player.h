#pragma once
#include <Windows.h>
#include "Includes.h"
#include "Entity.h"


class Player : public Entity
{
public:

	void PlayerMove(int Val);
	void SameSpace();
};