// CubeSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CubeFace.h"
#include "Cube.h"

enum  COLOR {WHITE = 0x57, YELLOW = 0x59, RED = 0x52, ORANGE = 0x4F, BLUE = 0x42, GREEN = 0x47};



Cube Erno =  Cube::Cube(WHITE, GREEN, ORANGE, BLUE,  RED, YELLOW);

int main()
{

	Erno.F();
	Erno.R();
	Erno.U();
	Erno.import_all_faces_to_facemap(Erno.ptr_UP_, Erno.ptr_LEFT_, Erno.ptr_FRONT_, Erno.ptr_RIGHT_, Erno.ptr_BACK_, Erno.ptr_DOWN_);

	Erno.print_cube();


	
	getchar();

	return 0;
}



