#pragma once
#include "CubeFace.h"
#include "CubeSlice.h"
#include <iostream>
class Cube
{
public:
	Cube(int UP, int FRONT, int RIGHT, int BACK, int LEFT, int DOWN);
	void reset_cube(int UP, int FRONT, int LEFT, int BACK, int RIGHT, int DOWN);

	void import_all_faces_to_facemap(CubeFace * ptr_UP_, CubeFace * ptr_LEFT_, CubeFace * ptr_FRONT_, CubeFace * ptr_RIGHT_, CubeFace * ptr_BACK_, CubeFace * ptr_DOWN_);






	void print_cube();
	



	void R();
	void R_prime();
	void F();
	void F_prime();
	void L();
	void L_prime();

	void B();

	void B_prime();

	void D();

	void D_prime();

	void U();
	void U_prime();

	void rotate_y();
	void rotate_y_prime();
	void rotate_x();
	void rotate_x_prime();
	void rotate_z();
	void rotate_z_prime();


	~Cube();


	
	CubeFace WHITE_;
	CubeFace GREEN_;
	CubeFace RED_ ;
	CubeFace BLUE_ ;
	CubeFace ORANGE_ ;
	CubeFace YELLOW_ ;
	

	CubeFace* ptr_UP_;
	CubeFace* ptr_FRONT_;
	CubeFace* ptr_RIGHT_;
	CubeFace* ptr_BACK_;
	CubeFace* ptr_LEFT_;
	CubeFace* ptr_DOWN_;
	

	int face_Map_[9][12];
	int temp_arr_[12];
};

