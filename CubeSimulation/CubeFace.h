#pragma once
class CubeFace
{
public:
	CubeFace(int COLOR);
	void rotate_Face();
	void prime_Face();
	void print_Face();
	int get_Faceval(int, int);
	void set_Faceval(int i, int j, int value);
	~CubeFace();

private:
	int face_[3][3];
	int faceCache_[3][3];
};

