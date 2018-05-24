// CubeSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "CubeFace.h"
#include "Cube.h"
using namespace std;

enum  COLOR {WHITE = 0x57, YELLOW = 0x59, RED = 0x52, ORANGE = 0x4F, BLUE = 0x42, GREEN = 0x47};

Cube Erno =  Cube::Cube(WHITE, GREEN, ORANGE, BLUE,  RED, YELLOW);

void print_cube_to_cmd()
{
	system("CLS");
	Erno.import_all_faces_to_facemap(Erno.ptr_UP_, Erno.ptr_LEFT_, Erno.ptr_FRONT_, Erno.ptr_RIGHT_, Erno.ptr_BACK_, Erno.ptr_DOWN_);
	Erno.print_cube();
}

void print_help_to_cmd()
{
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
		Erno.reset_cube(WHITE, GREEN, ORANGE, BLUE, RED, YELLOW);
		system("CLS");
		print_cube_to_cmd();
	}
	else if (input == "help")
	{
		Erno.reset_cube(WHITE, GREEN, ORANGE, BLUE, RED, YELLOW);
		print_help_to_cmd();
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
	//Erno.F();
	//Erno.R();
	Erno.B();
	Erno.import_all_faces_to_facemap(Erno.ptr_UP_, Erno.ptr_LEFT_, Erno.ptr_FRONT_, Erno.ptr_RIGHT_, Erno.ptr_BACK_, Erno.ptr_DOWN_);

	Erno.print_cube();


	
	getchar();

	return 0;
}



