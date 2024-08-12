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

TEST(MatrixRotInverseOrient, TestConfig::ALL)
{
#if MatrixRotInverseOrient

	// Orientation Type Constructor:
	Vect  v17(2.0f, 53.0f, 24.0f);
	Vect  v18(0.0f, -24.0f, 53.0f);
	Matrix m57(Matrix::Orient::WorldToLocal, v17, v18);

	CHECK(eq(m57[m0], -0.9994f, MATH_TOLERANCE));
	CHECK(eq(m57[m1], 0.0000f, MATH_TOLERANCE));
	CHECK(eq(m57[m2], 0.0344f, MATH_TOLERANCE));
	CHECK((m57[m3] == 0.0f));
	CHECK(eq(m57[m4], 0.0313f, MATH_TOLERANCE));
	CHECK(eq(m57[m5], -0.4125f, MATH_TOLERANCE));
	CHECK(eq(m57[m6], 0.9104f, MATH_TOLERANCE));
	CHECK((m57[m7] == 0.0f));
	CHECK(eq(m57[m8], 0.0142f, MATH_TOLERANCE));
	CHECK(eq(m57[m9], 0.9110f, MATH_TOLERANCE));
	CHECK(eq(m57[m10], 0.4123f, MATH_TOLERANCE));
	CHECK((m57[m11] == 0.0f));
	CHECK((m57[m12] == 0.0f));
	CHECK((m57[m13] == 0.0f));
	CHECK((m57[m14] == 0.0f));
	CHECK((m57[m15] == 1.0f));

#endif
} TEST_END

// --- End of File ---
