#include "Includes.h"
#include "Player.h"

void Player::PlayerMove(int Val){

	OldX = LocX;
	OldY = LocY;

	switch (Val) {
	case 1:
		LocX = LocX + 1;
		break;
	case 2:
		LocX = LocX - 1;
		break;
	case 3:
		LocY = LocY + 1;
		break;
	case 4:
		LocY = LocY - 1;
		break;
	};

};