#include "stdafx.h"
#include "CubeSlice.h"


CubeSlice::CubeSlice(int COLOR, int COLOR_T1, int COLOR_T2, int COLOR_T3, int COLOR_T4)
{
	SliceFace_ = CubeFace(COLOR);
	T1_ = CubeTriplet(COLOR_T1);
	T2_ = CubeTriplet(COLOR_T2);
	T3_ = CubeTriplet(COLOR_T3);
	T4_ = CubeTriplet(COLOR_T4);
}

CubeSlice::CubeSlice()
{
	SliceFace_ = CubeFace();
	T1_ = CubeTriplet();
	T2_ = CubeTriplet();
	T3_ = CubeTriplet();
	T4_ = CubeTriplet();
}


CubeSlice::~CubeSlice()
{
}
