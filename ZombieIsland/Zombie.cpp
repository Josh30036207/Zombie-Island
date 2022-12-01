#include "Includes.h"
#include "Zombie.h"

void Zombie::ZMove(int xAxis, int yAxis, int playPosX, int playPosY){

	

	if (LocX > playPosX) {
		SwitchVal = 2;
	}
	else if (LocX < playPosX) {
		SwitchVal = 1;
	}
	else if (LocY > playPosY) {
		SwitchVal = 4;
	}
	else {
		SwitchVal = 3;
	};

	OldX = LocX;
	OldY = LocY;

	do {

		LocX = OldX;
		LocY = OldY;

		switch (SwitchVal) {//switch to select which direction to move the zombie
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
	} while((LocX <! 0 )and (LocX >! xAxis) and (LocY <! 0) and (LocY >! yAxis));
	

};