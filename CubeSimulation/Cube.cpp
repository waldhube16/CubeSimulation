#include "stdafx.h"
#include "Cube.h"

Cube::Cube(CubeFace &UP, CubeFace &FRONT, CubeFace &LEFT, CubeFace &BACK, CubeFace &RIGHT, CubeFace &DOWN)
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			face_Map_[i][j] = 0x20; 
			temp_arr_[i] = 0x20;
		}
	}

	import_all_faces(UP, LEFT, FRONT, RIGHT, BACK, DOWN);


}

void Cube::import_all_faces(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN)
{
	import_u_face(UP);
	import_l_face(LEFT);
	import_f_face(FRONT);
	import_r_face(RIGHT);
	import_b_face(BACK);
	import_d_face(DOWN);
}

void Cube::import_d_face(CubeFace & DOWN)
{
	//set Down Face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i + 6][j + 3] = DOWN.get_Faceval(i, j);
		}
	}
}

void Cube::import_b_face(CubeFace & BACK)
{
	//set Back Face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i + 3][j + 9] = BACK.get_Faceval(i, j);
		}
	}
}

void Cube::import_r_face(CubeFace & RIGHT)
{
	//set Right Face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i + 3][j + 6] = RIGHT.get_Faceval(i, j);
		}
	}
}

void Cube::import_f_face(CubeFace & FRONT)
{
	//set Front Face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i + 3][j + 3] = FRONT.get_Faceval(i, j);
		}
	}
}

void Cube::import_l_face(CubeFace & LEFT)
{
	//set Left Face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i + 3][j] = LEFT.get_Faceval(i, j);
		}
	}
}

void Cube::import_u_face(CubeFace & UP)
{
	//set Upper Face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i][j + 3] = UP.get_Faceval(i, j);
		}
	}
}

void Cube::refresh_all_faces(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN)
{
	refresh_u_face(UP);
	refresh_l_face(LEFT);
	refresh_f_face(FRONT);
	refresh_r_face(RIGHT);
	refresh_b_face(BACK);
	refresh_d_face(DOWN);
}

void Cube::refresh_u_face(CubeFace & UP)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			UP.set_Faceval(i, j, face_Map_[i][j + 3]);
		}

	}
	

}

void Cube::refresh_d_face(CubeFace & DOWN)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			DOWN.set_Faceval(i, j, face_Map_[i+6][j + 3]);
		}

	}

	
}

void Cube::refresh_f_face(CubeFace & FRONT)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			FRONT.set_Faceval(i, j, face_Map_[i + 3][j + 3]);
		}

	}


}

void Cube::refresh_l_face(CubeFace & LEFT)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			LEFT.set_Faceval(i, j, face_Map_[i + 3][j]);
		}

	}


}

void Cube::refresh_r_face(CubeFace & RIGHT)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			RIGHT.set_Faceval(i, j, face_Map_[i + 3][j + 6]);
		}

	}

}

void Cube::refresh_b_face(CubeFace & BACK)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			BACK.set_Faceval(i, j, face_Map_[i + 3][j + 6]);
		}

	}
}

void Cube::print_cube()
{
	for (int i = 0; i < 9; i++)
	{
		std::cout	<< (char) face_Map_[i][0] << (char)face_Map_[i][1] << (char)face_Map_[i][2] << (char)face_Map_[i][3] << (char)face_Map_[i][4] << (char)face_Map_[i][5]
					<< (char)face_Map_[i][6] << (char)face_Map_[i][7] << (char)face_Map_[i][8] << (char)face_Map_[i][9] << (char)face_Map_[i][10] << (char)face_Map_[i][11] << std::endl;
	}
 }

void Cube::U(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN)
{
	fill_temp_x_arr(3);
	//rotate tiles on vertical faces - direction : --->
	for (int i = 0; i < 9; i++)
	{
		face_Map_[3][i]  = temp_arr_[i+3];
	}
	for (int i = 9; i < 12; i++)
	{
		face_Map_[3][i] = temp_arr_[i-9];
	}
	//update Class face for rotation
	import_u_face(UP);
	UP.rotate_Face(); //rotate face
	refresh_all_faces(UP, LEFT, FRONT, RIGHT, BACK, DOWN);

	
}

void Cube::U_prime(CubeFace & UP)
{
	fill_temp_x_arr(3);
	//rotate tiles on vertical faces - direction : <---
	for (int i = 11; i > 2; i--)
	{
		face_Map_[3][i] = temp_arr_[i - 3];
	}
	for (int i = 2; i > -1; i--)
	{
		face_Map_[3][i] = temp_arr_[i + 9];
	}

	//rotate tiles on horizontal faces
	import_u_face(UP);
	UP.prime_Face();
	import_u_face(UP);
	

	
}

void Cube::R(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN)
{
	fill_temp_y_arr(5);

	//rotate tiles on vertical faces - direction : <---
	for (int i = 0; i < 9; i++)
	{
		face_Map_[i][5] = temp_arr_[i + 3]; //tay [3:11]
	}
	for (int i = 9; i < 12; i++)
	{
		face_Map_[i-6][5 + 6] = temp_arr_[i - 9]; //tay [0:2]
	}



	//rotate tiles on horizontal faces
	import_r_face(RIGHT);
	RIGHT.rotate_Face();
	refresh_all_faces(UP, LEFT, FRONT, RIGHT, BACK, DOWN);


	
}

void Cube::R_prime(CubeFace & RIGHT)
{
	fill_temp_y_arr(5);

	//rotate tiles on vertical faces - direction : --->
	for (int i = 0; i < 3 ; i++)
	{
		face_Map_[i][5] = temp_arr_[i + 9]; //tay [9:11]
	}
	for (int i = 3; i < 9; i++)
	{
		face_Map_[i][5] = temp_arr_[i - 3]; //tay [0:5]
	}
	for (int i = 6; i < 9; i++)
	{
		face_Map_[i-3][5+6] = temp_arr_[i]; //tay [6:8]
	}
	
	//rotate tiles on horizontal faces
	import_r_face(RIGHT);
	RIGHT.prime_Face();
	import_r_face(RIGHT);

}

void Cube::F(CubeFace & FRONT)
{
	fill_temp_z_arr(2);

	//rotate tiles on adjacent faces - direction : --->
	for (int i = 0; i < 3; i++)
	{
		face_Map_[2][5 - i] = temp_arr_[i]; //use  taz [0:2]
	}
	for (int i = 3; i < 6; i++)
	{
		face_Map_[i][2] = temp_arr_[i];//use taz [3:5]
	}
	for (int i = 6; i < 9; i++)
	{
		face_Map_[6][i-3] = temp_arr_[i]; //use taz [6:8]
	}
	for (int i = 9; i < 12; i++)
	{
		face_Map_[14 - i][6] = temp_arr_[i]; //use taz [9:11]
	}

	//rotate tiles on horizontal faces
	refresh_f_face(FRONT);
	FRONT.rotate_Face();
	refresh_f_face(FRONT);


}

void Cube::F_prime(CubeFace & FRONT)
{
	fill_temp_z_arr(2);

	//rotate tiles on adjacent faces - direction : --->
	for (int i = 0; i < 3; i++)
	{
		face_Map_[6][i + 3] = temp_arr_[i]; //use  taz [0:2]
	}
	for (int i = 3; i < 6; i++)
	{
		face_Map_[8 - i][6] = temp_arr_[i];//use taz [3:5]
	}
	for (int i = 6; i < 9; i++)
	{
		face_Map_[2][11 - i ] = temp_arr_[i]; //use taz [6:8]
	}
	for (int i = 9; i < 12; i++)
	{
		face_Map_[i-6][2] = temp_arr_[i]; //use taz [9:11]
	}

	//rotate tiles on horizontal faces
	refresh_f_face(FRONT);
	FRONT.prime_Face();
	refresh_f_face(FRONT);
}



void Cube::fill_temp_x_arr(int x)
{
	for (int i = 0; i < 12; i++)
	{
		temp_arr_[i] = face_Map_[x][i]; //fill tax [0:11]
	}
	
}


void Cube::fill_temp_y_arr(int y)
{
	for (int i = 0; i < 9; i++)
	{
		temp_arr_[i] = face_Map_[i][y];//fill tay [0:8]
	}
	for (int i = 9; i < 12; i++)
	{
		temp_arr_[i] = face_Map_[14-i][y+3];//fill tay [9:11]
	}
	

}


void Cube::fill_temp_z_arr(int z)
{

	for (int i = 0; i < 3; i++)
	{
		temp_arr_[i] = face_Map_[i+3][z];//fill taz [0:2]
	}
	for (int i = 3; i < 6; i++)
	{
		temp_arr_[i] = face_Map_[8-z][i];//fill taz [3:5]
	}
	for (int i = 6; i < 9; i++)
	{
		temp_arr_[i] = face_Map_[11 - i][8-z]; //fill taz [6:8]
	}
	for (int i = 9; i < 12; i++)
	{
		temp_arr_[i] = face_Map_[z][14-i]; //fill taz [9:11]
	}
}

Cube::~Cube()
{
}
