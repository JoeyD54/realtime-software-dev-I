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

TEST(Special_RotX, TestConfig::ALL)
{
#if Special_RotX

	// Rot_X Type Constructor:
	Matrix Rx(Matrix::Rot1::X, 1.0471975512f);

	CHECK(Rx[m0] == 1.0f);
	CHECK(Rx[m1] == 0.0f);
	CHECK(Rx[m2] == 0.0f);
	CHECK(Rx[m3] == 0.0f);
	CHECK(Rx[m4] == 0.0f);
	CHECK(eq(Rx[m5], 0.5f, MATH_TOLERANCE));
	CHECK(eq(Rx[m6], 0.866f, MATH_TOLERANCE));
	CHECK(Rx[m7] == 0.0f);
	CHECK(Rx[m8] == 0.0f);
	CHECK(eq(Rx[m9], -0.866f, MATH_TOLERANCE));
	CHECK(eq(Rx[m10], 0.5f, MATH_TOLERANCE));
	CHECK(Rx[m11] == 0.0f);
	CHECK(Rx[m12] == 0.0f);
	CHECK(Rx[m13] == 0.0f);
	CHECK(Rx[m14] == 0.0f);
	CHECK(Rx[m15] == 1.0f);

#endif
} TEST_END

// --- End of File ---
