#pragma once
#include "CubeTriplet.h"
#include "CubeFace.h"

class CubeSlice
{
public:
	CubeSlice(int COLOR, int COLOR_T1, int COLOR_T2, int COLOR_T3, int COLOR_T4);
	CubeSlice();
	~CubeSlice();

private:
	CubeFace SliceFace_;
	CubeTriplet T1_;
	CubeTriplet T2_;
	CubeTriplet T3_;
	CubeTriplet T4_;

};

