#include <Windows.h>
#include "Includes.h"
#include "Player.h"
#include "Zombie.h"
#include "Trap.h"


using namespace std;

static HANDLE hConsole;
static HWND console;

int main()
{

	Zombie ZObj;
	Zombie ZObj2;
	Zombie ZObj3;
	Trap TObj;
	Trap TObj2;
	Trap TObj3;
	Player PObj;

	int ZomCount = 3;
	int TrapCount = 3; //Variables used to hold the number of zombies and traps - varable to allow for different dificulties - used in a for loop (hopefully)

	int xAxis;
	int yAxis; //Variables used to change the size of the board

	int InpMove; //holds the value for player input
	bool InpPress = false; //True if a user inputs a value - used for input validation 
	int PLocX;
	int PLocY; // Holds the current location for the player on the board - used for hit detection and to prevent the player from moving out of the board
	int OldPLocX;
	int OldPLocY;

	int zombX = 0;//holds the current zombies location
	int zombY = 0;
	int OldZombX = 0; //old zombie location - used to ensure return zombie to old location if moves out of bound etc. 
	int OldZombY = 0;
	bool ZombOne = true;//true if the zombie is still alive, used in while loops to tell which ones are dead
	bool ZombTwo = false;
	bool ZombThr = false;

	int dif = 1; //used for difficulty selection

	int TrapX = 0;
	int TrapY = 0;

	int CompX = 0; //xy variable for comparisons to ensure no initial overlap
	int CompY = 0;
	int CompX2 = 0; 
	int CompY2 = 0;

	bool loop = true;
	bool win = false;
	
	cout << "please enter your name" << endl;
	string name;
	cin >> name;

	cout << "Please Enter The Size of The Board's X Axis" << endl;
	cin >> xAxis;
	cout << "Please Enter The Size of The Board's Y Axis" << endl;
	cin >> yAxis;

	cout << "Please Select difficulty 1/2/3" << endl;
	cin >> dif;

	std::vector<char> Row(yAxis, '0');
	std::vector<vector<char>> Grid(xAxis, Row); //2d array used to set the board. Sets the rows and collums to '0'

	ZObj.StartRand();
	TObj.StartRand();

	PLocX = PObj.SetX(xAxis); //creating player spawn location
	PLocY = PObj.SetY(yAxis);
	Grid[PLocY][PLocX] = 'P'; //shows the player on the grid

//This whole section will check if a space is occupied 
	CompX = 0;
	CompY = 0;


	zombX = ZObj.SetX(xAxis);
	zombY = ZObj.SetY(yAxis);
	CompX = zombX;
	CompY = zombY;
	
	Console::setColour(Console::GREEN);
	Grid[zombY][zombX] = 'Z'; //shows the zombie on the grid note: Works from the top down
	
	
	zombX = ZObj2.SetX(xAxis);
	zombY = ZObj2.SetY(yAxis);
	CompX = zombX;
	CompY = zombY;
	if ((dif == 2) or (dif == 3)) {
		ZombTwo = true;
		Grid[zombY][zombX] = 'Z'; //shows the zombie on the grid note: Works from the top down
	};

	
	zombX = ZObj3.SetX(xAxis);
	zombY = ZObj3.SetY(yAxis);
	CompX = zombX;
	CompY = zombY;
	if (dif == 3) {
		ZombThr = true;
		Grid[zombY][zombX] = 'Z';
	};

	
	
	TrapX = TObj.SetX(xAxis);
	TrapY = TObj.SetY(yAxis);
	CompX = TrapX;
	CompY = TrapY;
	Grid[TrapY][TrapX] = 'T'; //shows the Trap on the grid
	
	
	TrapX = TObj2.SetX(xAxis);
	TrapY = TObj2.SetY(yAxis);
	CompX = TrapX;
	CompY = TrapY;
	if ((dif == 2) or (dif == 3)) {
		Grid[TrapY][TrapX] = 'T'; //shows the Trap on the grid
	};

	
	TrapX = TObj3.SetX(xAxis);
	TrapY = TObj3.SetY(yAxis);
	CompX = TrapX;
	CompY = TrapY;
	if (dif == 3) {
		Grid[TrapY][TrapX] = 'T'; //shows the Trap on the grid
	};

	for (int i = 0; i < Grid.size(); i++) { //Outputs the grid
		for (int j = 0; j < Grid[i].size(); j++)
			cout << Grid[i][j] << " ";
		cout << endl;

	};
//end of section
	cout << endl;

	while (loop == true) {
		
		//Moves the player
		do { //Checks for user input, then checks if the numpad keys have been pressed

			if (GetKeyState(VK_NUMPAD8) & 0x8000) {
				InpMove = 4;
				PObj.PlayerMove(InpMove);
				InpPress = true;
				Sleep(50);
			};
			if (GetKeyState(VK_NUMPAD2) & 0x8000) {
				InpMove = 3;
				PObj.PlayerMove(InpMove);
				InpPress = true;
				Sleep(50);
			};
			if (GetKeyState(VK_NUMPAD4) & 0x8000) {
				InpMove = 2;
				PObj.PlayerMove(InpMove);
				InpPress = true;
				Sleep(50);
			};
			if (GetKeyState(VK_NUMPAD6) & 0x8000) {
				InpMove = 1;
				PObj.PlayerMove(InpMove);
				InpPress = true;
				Sleep(50);
			};
			

		} while (InpPress == false);
		Console::clear();
		InpPress = false;

		PLocX = PObj.GetX(); //updates player movement
		PLocY = PObj.GetY();
		OldPLocX = PObj.GetOldX();
		OldPLocY = PObj.GetOldY();
		Grid[OldPLocY][OldPLocX] = '0'; //shows player movement on grid
		if ((Grid[PLocY][PLocX] == 'Z') or (Grid[PLocY][PLocX] == 'T')) {
			loop = false;
		}
		else {
		
			Grid[PLocY][PLocX] = 'P';
			
		};

		//zombie movement
		if (ZombOne == true) {
			ZObj.ZMove(xAxis, yAxis, PLocX, PLocY); //moves the zombie
			zombX = ZObj.GetX();
			zombY = ZObj.GetY();
			OldZombX = ZObj.GetOldX();
			OldZombY = ZObj.GetOldY();
			Grid[OldZombY][OldZombX] = '0';
			if (Grid[zombY][zombX] == 'T') {
				ZombOne = false;
			}
			else {
				Grid[zombY][zombX] = 'Z'; //shows the zombie on the grid note: Works from the top down
			};
		};

		if (ZombTwo == true) {
			ZObj2.ZMove(xAxis, yAxis, PLocX, PLocY); //moves the zombie
			zombX = ZObj2.GetX();
			zombY = ZObj2.GetY();
			OldZombX = ZObj2.GetOldX();
			OldZombY = ZObj2.GetOldY();
			Grid[OldZombY][OldZombX] = '0';
			if (Grid[zombY][zombX] == 'T') {
				ZombTwo = false;
			}
			else {
				Grid[zombY][zombX] = 'Z'; //shows the zombie on the grid note: Works from the top down
			};
		};

		if (ZombThr == true) {
			ZObj3.ZMove(xAxis, yAxis, PLocX, PLocY); //moves the zombie
			zombX = ZObj3.GetX();
			zombY = ZObj3.GetY();
			OldZombX = ZObj3.GetOldX();
			OldZombY = ZObj3.GetOldY();
			Grid[OldZombY][OldZombX] = '0';
			if (Grid[zombY][zombX] == 'T') {
				ZombThr = false;
			}
			else {
				Grid[zombY][zombX] = 'Z'; //shows the zombie on the grid note: Works from the top down
			};
		};

		if ((ZombOne == false) and (ZombTwo == false) and (ZombThr == false)) {
			loop = false;
			win = true;
		};

		//Showing the grid
		for (int i = 0; i < Grid.size(); i++) { //Outputs the grid
			for (int j = 0; j < Grid[i].size(); j++)
				cout << Grid[i][j] << " ";
			cout << endl;

		};

		cout << endl;


	};

	if (win == true) {
		cout << "well done you win" << endl;
		fstream Results;//Outputs to a txt file
		Results.open("Results.txt", fstream::app);
		Results << name << " " << "WIN" << endl;
		Results.close();
	}
	else {
		cout << "You lose" << endl;
		fstream Results;//Outputs to a txt file
		Results.open("Results.txt", fstream::app);
		Results << name << " " << "LOSE" << endl;
		Results.close();
	};

};