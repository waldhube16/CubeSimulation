// CubeSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CubeFace.h"
#include "Cube.h"

enum  COLOR {WHITE = 0x57, YELLOW = 0x59, RED = 0x52, ORANGE = 0x4F, BLUE = 0x42, GREEN = 0x47};

CubeFace UP = CubeFace::CubeFace(WHITE);
CubeFace DOWN = CubeFace::CubeFace(YELLOW);
CubeFace RIGHT = CubeFace::CubeFace(RED);
CubeFace LEFT = CubeFace::CubeFace(ORANGE);
CubeFace BACK = CubeFace::CubeFace(BLUE);
CubeFace FRONT = CubeFace::CubeFace(GREEN);

Cube Specimen = Cube::Cube(UP, FRONT, LEFT, BACK, RIGHT, DOWN);

int main()
{
	for (int i = 0; i < 1; i++)
	{
		//Specimen.U(UP, LEFT, FRONT, RIGHT, BACK, DOWN);
		Specimen.R(UP, LEFT, FRONT, RIGHT, BACK, DOWN);

		
	}

	//Specimen.U(UP);

	Specimen.print_cube();

	/* //print seperate Faces 
	White.print_Face();
	Green.print_Face();
	Orange.print_Face();
	Blue.print_Face();
	Red.print_Face();
	Yellow.print_Face();
	*/
	
	
	getchar();

	return 0;
}



