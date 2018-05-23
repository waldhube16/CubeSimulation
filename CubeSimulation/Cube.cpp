#include "stdafx.h"
#include "Cube.h"
/*

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
*/
Cube::Cube(int UP, int FRONT, int LEFT, int BACK, int RIGHT, int DOWN)
{
	/*
	North_ = CubeSlice(UP, FRONT, RIGHT, BACK, LEFT);
	Ordinate_ = CubeSlice(-1, FRONT, RIGHT, BACK, LEFT);
	South_ = CubeSlice(DOWN, FRONT, RIGHT, BACK, LEFT);
	West_ = CubeSlice(LEFT, FRONT, DOWN, BACK, UP);
	Abscissa_ = CubeSlice(-1, FRONT, DOWN, BACK, UP);
	East_ = CubeSlice(RIGHT, FRONT, DOWN, BACK, UP);
	Near_ = CubeSlice(FRONT, DOWN, RIGHT, UP, LEFT);
	Applicate_ = CubeSlice(-1, DOWN, RIGHT, UP, LEFT);
	Far_ = CubeSlice(BACK, DOWN, RIGHT, UP, LEFT);
	*/

	WHITE_ = CubeFace::CubeFace(UP);
	GREEN_ = CubeFace::CubeFace(FRONT);
	RED_ = CubeFace::CubeFace(RIGHT);
	BLUE_ = CubeFace::CubeFace(BACK);
	ORANGE_ = CubeFace::CubeFace(LEFT);
	YELLOW_ = CubeFace::CubeFace(DOWN);

	ptr_UP_ = &WHITE_;
	ptr_FRONT_ = &GREEN_;
	ptr_RIGHT_ = &RED_;
	ptr_BACK_ = &BLUE_;
	ptr_LEFT_ = &ORANGE_;
	ptr_DOWN_ = &YELLOW_;

	import_all_faces_to_facemap(ptr_UP_, ptr_LEFT_, ptr_FRONT_, ptr_RIGHT_, ptr_BACK_, ptr_DOWN_);

	
}

void Cube::import_all_faces_to_facemap(CubeFace * ptr_UP_, CubeFace * ptr_LEFT_, CubeFace * ptr_FRONT_, CubeFace * ptr_RIGHT_, CubeFace * ptr_BACK_, CubeFace * ptr_DOWN_)
{
	for (int i = 0; i < 9; i++) //initialize the whole array
	{
		for (int j = 0; j < 12; j++)
		{
			face_Map_[i][j] = 0x20;
			temp_arr_[i] = 0x20;
		}
	}

	for (int i = 0; i < 3; i++) //initialize up face
	{
		for (int j = 3; j < 6; j++)
		{
			face_Map_[i][j] = ptr_UP_->face_[i][j-3];
		}
	}

	for (int i = 3; i < 6; i++) //initialize left face
	{
		for (int j = 0; j < 3; j++)
		{
			face_Map_[i][j] = ptr_LEFT_->face_[i-3][j];
		}
	}

	for (int i = 3; i < 6; i++)  //initialize front face
	{
		for (int j = 3; j < 6; j++)
		{
			face_Map_[i][j] = ptr_FRONT_->face_[i-3][j-3];
		}
	}

	for (int i = 3; i < 6; i++)  //initialize right face
	{
		for (int j = 6; j < 9; j++)
		{
			face_Map_[i][j] = ptr_RIGHT_->face_[i-3][j-6];
		}
	}

	for (int i = 3; i < 6; i++)  //initialize back face
	{
		for (int j = 9; j < 12; j++)
		{
			face_Map_[i][j] = ptr_BACK_->face_[i-3][j-9];
		}
	}

	for (int i = 6; i < 9; i++)  //initialize down face
	{
		for (int j = 3; j < 6; j++)
		{
			face_Map_[i][j] = ptr_DOWN_->face_[i-6][j-3];
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

void Cube::R()
{
	rotate_z_prime();
	U();
	rotate_z();
		
}

void Cube::R_prime()
{
	rotate_z_prime();
	U_prime();
	rotate_z();
}

void Cube::F()
{
	rotate_x();
	U();
	rotate_x_prime();
}

void Cube::F_prime()
{
	rotate_x();
	U_prime();
	rotate_x_prime();
}

void Cube::L()
{
	rotate_z();
	U();
	rotate_z_prime();
}

void Cube::L_prime()
{
	rotate_z();
	U_prime();
	rotate_z_prime();
}

void Cube::B()
{
	rotate_x_prime();
	U();
	rotate_x();
}

void Cube::B_prime()
{
	rotate_x_prime();
	U_prime();
	rotate_x();
}

void Cube::D()
{
	rotate_x_prime();
	rotate_x_prime();
	U();
	rotate_x();
	rotate_x();
}

void Cube::D_prime()
{
	rotate_x_prime();
	rotate_x_prime();
	U_prime();
	rotate_x();
	rotate_x();
}



void Cube::U()
{
	int temp_arr_left[3];
	int temp_arr_front[3];
	int temp_arr_right[3];
	int temp_arr_back[3];

	//rotate tiles on vertical faces - direction : <---
	for (int i = 0; i < 3; i++)
	{
		temp_arr_left[i] = ptr_LEFT_->face_[0][i];
		temp_arr_front[i] = ptr_FRONT_->face_[0][i];
		temp_arr_right[i] = ptr_RIGHT_->face_[0][i];
		temp_arr_back[i] = ptr_BACK_->face_[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		ptr_LEFT_->face_[0][i] = temp_arr_front[i];
		ptr_FRONT_->face_[0][i] = temp_arr_right[i];
		ptr_RIGHT_->face_[0][i] = temp_arr_back[i];
		ptr_BACK_->face_[0][i] = temp_arr_left[i];
	}
	
	ptr_UP_->rotate_Face(); 

}

void Cube::U_prime()
{
	int temp_arr_left[3];
	int temp_arr_front[3];
	int temp_arr_right[3];
	int temp_arr_back[3];

	//rotate tiles on vertical faces - direction : --->
	for (int i = 0; i < 3; i++)
	{
		temp_arr_left[i] = ptr_LEFT_->face_[0][i];
		temp_arr_front[i] = ptr_FRONT_->face_[0][i];
		temp_arr_right[i] = ptr_RIGHT_->face_[0][i];
		temp_arr_back[i] = ptr_BACK_->face_[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		ptr_LEFT_->face_[0][i] = temp_arr_back[i];
		ptr_FRONT_->face_[0][i] = temp_arr_left[i];
		ptr_RIGHT_->face_[0][i] = temp_arr_front[i];
		ptr_BACK_->face_[0][i] = temp_arr_right[i];
	}

	ptr_UP_->prime_Face();



}


void Cube::rotate_y()
{
	CubeFace* temp_ptr_left = ptr_LEFT_;
	CubeFace* temp_ptr_front = ptr_FRONT_;
	CubeFace* temp_ptr_right = ptr_RIGHT_;
	CubeFace* temp_ptr_back = ptr_BACK_;


	ptr_UP_->rotate_Face();
	ptr_DOWN_->prime_Face();

	ptr_LEFT_ = temp_ptr_front;
	ptr_FRONT_ = temp_ptr_right;
	ptr_RIGHT_ = temp_ptr_back;
	ptr_BACK_ = temp_ptr_left;
}

void Cube::rotate_y_prime()
{
	CubeFace* temp_ptr_left = ptr_LEFT_;
	CubeFace* temp_ptr_front = ptr_FRONT_;
	CubeFace* temp_ptr_right = ptr_RIGHT_;
	CubeFace* temp_ptr_back = ptr_BACK_;


	ptr_UP_->prime_Face();
	ptr_DOWN_->rotate_Face();

	ptr_LEFT_ = temp_ptr_back;
	ptr_FRONT_ = temp_ptr_left;
	ptr_RIGHT_ = temp_ptr_front;
	ptr_BACK_ = temp_ptr_right;
}

void Cube::rotate_x()
{
	CubeFace* temp_ptr_up = ptr_UP_;
	CubeFace* temp_ptr_front = ptr_FRONT_;
	CubeFace* temp_ptr_back = ptr_BACK_;
	CubeFace* temp_ptr_down = ptr_DOWN_;

	ptr_RIGHT_->rotate_Face();
	ptr_LEFT_->prime_Face();
	ptr_UP_->rotate_Face();
	ptr_UP_->rotate_Face();
	ptr_BACK_->rotate_Face();
	ptr_BACK_->rotate_Face();
	
	ptr_BACK_ = temp_ptr_up;
	ptr_UP_ = temp_ptr_front;
	ptr_FRONT_ = temp_ptr_down;
	ptr_DOWN_ = temp_ptr_back;


}

void Cube::rotate_x_prime()
{
	CubeFace* temp_ptr_up = ptr_UP_;
	CubeFace* temp_ptr_front = ptr_FRONT_;
	CubeFace* temp_ptr_back = ptr_BACK_;
	CubeFace* temp_ptr_down = ptr_DOWN_;

	ptr_RIGHT_->prime_Face();
	ptr_LEFT_->rotate_Face();
	ptr_UP_->prime_Face();
	ptr_UP_->prime_Face();
	ptr_BACK_->prime_Face();
	ptr_BACK_->prime_Face();

	ptr_BACK_ = temp_ptr_down;
	ptr_UP_ = temp_ptr_back;
	ptr_FRONT_ = temp_ptr_up;
	ptr_DOWN_ = temp_ptr_front;


}

void Cube::rotate_z()
{
	CubeFace* temp_ptr_up = ptr_UP_;
	CubeFace* temp_ptr_right = ptr_RIGHT_;
	CubeFace* temp_ptr_down = ptr_DOWN_;
	CubeFace* temp_ptr_left = ptr_LEFT_;

	ptr_UP_->rotate_Face();
	ptr_FRONT_->rotate_Face();
	ptr_RIGHT_->rotate_Face();
	ptr_DOWN_->rotate_Face();
	ptr_LEFT_->rotate_Face();
	ptr_BACK_->prime_Face();



	ptr_RIGHT_ = temp_ptr_up;
	ptr_DOWN_ = temp_ptr_right;
	ptr_LEFT_ = temp_ptr_down;
	ptr_UP_ = temp_ptr_left;
	

}

void Cube::rotate_z_prime()
{
	CubeFace* temp_ptr_up = ptr_UP_;
	CubeFace* temp_ptr_right = ptr_RIGHT_;
	CubeFace* temp_ptr_down = ptr_DOWN_;
	CubeFace* temp_ptr_left = ptr_LEFT_;

	ptr_UP_->prime_Face();
	ptr_FRONT_->prime_Face();
	ptr_RIGHT_->prime_Face();
	ptr_DOWN_->prime_Face();
	ptr_LEFT_->prime_Face();
	ptr_BACK_->rotate_Face();



	ptr_RIGHT_ = temp_ptr_down;
	ptr_DOWN_ = temp_ptr_left;
	ptr_LEFT_ = temp_ptr_up;
	ptr_UP_ = temp_ptr_right;


}



Cube::~Cube()
{
}
