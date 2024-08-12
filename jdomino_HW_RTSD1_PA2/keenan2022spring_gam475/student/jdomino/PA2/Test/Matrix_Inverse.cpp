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

TEST( Matrix_inverse, TestConfig::ALL)
{
#if Matrix_inverse

	Matrix Rx(Matrix::Rot1::X, 0.23f);
	Matrix Ry(Matrix::Rot1::Y, -1.23f);
	Matrix T(Matrix::Trans::XYZ, 3.4f, 2.9f, -9.0f);

	Matrix M = Rx * Ry * T;
	Matrix N(M);

	M.inv();

	Matrix C;
	C = N * M;

	// verify C is identity

	const bool flag = C.isIdentity(MATH_TOLERANCE);

	CHECK(flag == true);

#endif
} TEST_END

// ---  End of File ---
