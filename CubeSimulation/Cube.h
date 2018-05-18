#pragma once
#include "CubeFace.h"
#include <iostream>
class Cube
{
public:
	Cube(CubeFace &UP, CubeFace &FRONT, CubeFace &LEFT, CubeFace &BACK, CubeFace &RIGHT, CubeFace &DOWN);


	void import_all_faces(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN);
	void import_d_face(CubeFace & DOWN);
	void import_b_face(CubeFace & BACK);
	void import_r_face(CubeFace & RIGHT);
	void import_f_face(CubeFace & FRONT);
	void import_l_face(CubeFace & LEFT);
	void import_u_face(CubeFace & UP);

	void print_cube();
	void U(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN);

	void refresh_all_faces(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN);

	void refresh_u_face(CubeFace & UP);
	void refresh_d_face(CubeFace & UP);
	void refresh_f_face(CubeFace & DOWN);
	void refresh_l_face(CubeFace & FRONT);
	void refresh_r_face(CubeFace & LEFT);
	void refresh_b_face(CubeFace & RIGHT);

	void U_prime(CubeFace & UP);

	void R(CubeFace &UP, CubeFace &LEFT, CubeFace &FRONT, CubeFace &RIGHT, CubeFace &BACK, CubeFace &DOWN);

	void R_prime(CubeFace & RIGHT);

	void F(CubeFace & RIGHT);

	void F_prime(CubeFace & FRONT);

	void fill_temp_x_arr(int x);

	void fill_temp_z_arr(int x);

	void fill_temp_y_arr(int y);
	

	~Cube();

private:
	int face_Map_[9][12];
	int temp_arr_[12];
};

