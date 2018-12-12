// CubeSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "CubeFace.h"
#include "Cube.h"
using namespace std;

//enum  COLOR {WHITE = 0x57, YELLOW = 0x59, RED = 0x52, ORANGE = 0x4F, BLUE = 0x42, GREEN = 0x47};
//enum  FACE { UP = 0x55, RIGHT = 0x52, FRONT = 0x46, DOWN = 0x44, LEFT = 0x4C, BACK = 0x42 };

//enum  FACE { UP = 'U', RIGHT = 'R', FRONT = 'F', DOWN = 'D', LEFT = 'L', BACK = 'B' };
std::string UP = "U", FRONT = "F", LEFT = "L", BACK = "B", RIGHT = "R", DOWN = "D";
//Cube Erno =  Cube::Cube(WHITE, GREEN, ORANGE, BLUE,  RED, YELLOW);

Cube Erno = Cube::Cube(UP, FRONT, LEFT, BACK, RIGHT, DOWN);

void clear_screen(char fill = ' ') 
{
//source: https://stackoverflow.com/questions/5866529/how-do-we-clear-the-console-in-assembly/5866648#5866648
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

void print_cube_to_cmd()
{
	clear_screen(); 
	//system("CLS");
	Erno.import_all_faces_to_facemap(Erno.ptr_UP_, Erno.ptr_LEFT_, Erno.ptr_FRONT_, Erno.ptr_RIGHT_, Erno.ptr_BACK_, Erno.ptr_DOWN_);
	Erno.print_cube();

}

void print_cubestring_to_cmd()
{
	//clear_screen();
	//system("CLS");
	Erno.import_all_faces_to_facemap(Erno.ptr_UP_, Erno.ptr_LEFT_, Erno.ptr_FRONT_, Erno.ptr_RIGHT_, Erno.ptr_BACK_, Erno.ptr_DOWN_);
	cout << Erno.generate_cubestring() << endl;

}



void print_help_to_cmd()
{
	clear_screen();
	cout << "l - Left inverted	; L - Left \n"
		"f - Front inverted	; F - Front \n" 
		"r - Right inverted	; R - Right \n" 
		"b - Back inverted	; B - Back \n" 
		"u - Up inverted		; U - Up \n" 
		"d - Down inverted	; D - Down \n" 
		"reset	- Reset Cube \n" 
		"help	- Show commands \n" 
		"x	- Stop Simulation \n" << endl;
}

void determine_user_input(string input, char& flag)
{
	if(input == "R")
	{
		Erno.R();
		print_cube_to_cmd();
	}
	else if (input == "r")
	{
		Erno.R_prime();
		print_cube_to_cmd();
	}
	else if (input == "U")
	{
		Erno.U();
		print_cube_to_cmd();
	}
	else if (input == "u")
	{
		Erno.U_prime();
		print_cube_to_cmd();
	}
	else if (input == "L")
	{
		Erno.L();
		print_cube_to_cmd();
	}
	else if (input == "l")
	{
		Erno.L_prime();
		print_cube_to_cmd();
	}
	else if (input == "D")
	{
		Erno.D();
		print_cube_to_cmd();
	}
	else if (input == "d")
	{
		Erno.D_prime();
		print_cube_to_cmd();
	}
	else if (input == "F")
	{
		Erno.F();
		print_cube_to_cmd();
	}
	else if (input == "f")
	{
		Erno.F_prime();
		print_cube_to_cmd();
	}
	else if (input == "B")
	{
		Erno.B();
		print_cube_to_cmd();
	}
	else if (input == "b")
	{
		Erno.B_prime();
		print_cube_to_cmd();

	}
	else if (input == "p")
	{
		print_cube_to_cmd();
	}
	else if (input == "x")
	{
		flag = 0;
	}
	else if (input == "reset")
	{
		//Erno.reset_cube(WHITE, GREEN, ORANGE, BLUE, RED, YELLOW);
		Erno.reset_cube(UP, FRONT, LEFT, BACK, RIGHT, DOWN);
		clear_screen();
		//system("CLS");
		print_cube_to_cmd();
	}
	else if (input == "help")
	{
		//Erno.reset_cube(WHITE, GREEN, ORANGE, BLUE, RED, YELLOW);
		Erno.reset_cube(UP, FRONT, LEFT, BACK, RIGHT, DOWN);
		print_help_to_cmd();
	}
	else if (input == "rotx")
	{
		Erno.rotate_x();
		print_cube_to_cmd();	
	}
	else if (input == "rotxp")
	{
		Erno.rotate_x_prime();
		print_cube_to_cmd();
	}
	else if (input == "roty")
	{
		Erno.rotate_y();
		print_cube_to_cmd();
	}
	else if (input == "rotyp")
	{
		Erno.rotate_y_prime();
		print_cube_to_cmd();
	}
	else if (input == "rotz")
	{
		Erno.rotate_z();
		print_cube_to_cmd();
	}
	else if (input == "rotzp")
	{
		Erno.rotate_z_prime();
		print_cube_to_cmd();
	}
	else if (input == "string")
	{
		print_cubestring_to_cmd();
	}
	else
	{
		cout << "This was not a valid input!" << endl;


	}
}

int main()
{
	cout << "Hello! Enter the move you want to perform:" << endl;
	print_help_to_cmd();

	string input;
	char flag = 1;

	while (flag)
	{
		getline(cin, input); // read user input from cin into variable input - dealing with newline and cin is a bit messy
		stringstream in_str{ input }; // create a string stream to process the input

		if (in_str) { // process input and check if it was ok

			determine_user_input(input, flag);
		}
		else {
			cout << "This was not a valid input!" << endl;
		}


	}
	cout << "You have terminated the program!" << endl;
	getchar(); // just so the debugger does not close our application immediately
	return 0;


}



