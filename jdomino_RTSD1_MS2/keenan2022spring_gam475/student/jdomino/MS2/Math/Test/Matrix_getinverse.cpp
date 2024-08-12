//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
#define eq	Util::isEqual 
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Matrix_getinverse, TestConfig::ALL)
{
#if Matrix_getinverse

	Matrix Rx(Matrix::Rot1::X, 0.23f);
	Matrix Ry(Matrix::Rot1::Y, -1.23f);
	Matrix S(Matrix::Scale::XYZ, 4.0f, 5.0f, 2.0f);
	Matrix T(Matrix::Trans::XYZ, -2.3f, 7.9f, 9.03f);

	Matrix M = S * T * Rx * Ry * S;
	Matrix N;

	N = M.getInv();

	Matrix C;
	C = N * M;

	// verify C is identity
	const bool flag = C.isIdentity(MATH_TOLERANCE);

	CHECK(flag == true);

#endif
} TEST_END

// ---  End of File ---
