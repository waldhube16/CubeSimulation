#pragma once
#include "CubeTriplet.h"

class CubeFace
{
public:
	CubeFace(int COLOR);
	CubeFace();
	void rotate_Face();
	void prime_Face();
	void print_Face();
	int get_Faceval(int, int);
	void set_Faceval(int i, int j, int value);
	~CubeFace();


	int face_[3][3];
	int faceCache_[3][3];
};

