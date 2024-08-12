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

TEST(MatrixRotAxisAngle, TestConfig::ALL)
{
#if MatrixRotAxisAngle	

	// Axis and Angle Type Constructor:
	Vect  v11(2.0f, 53.0f, 24.0f);
	Matrix m54(Matrix::Rot::AxisAngle, v11, MATH_PI3);

	// => Vect  v11( 2.0f, 53.0f, 24.0f); \n"););
	// => Matrix m54(ROT_AXIS_ANGLE, v11, MATH_PI3 );\n"););
	CHECK(eq(m54[m0], 0.5005f, MATH_TOLERANCE));
	CHECK(eq(m54[m1], 0.3726f, MATH_TOLERANCE));
	CHECK(eq(m54[m2], -0.7813f, MATH_TOLERANCE));
	CHECK(m54[m3] == 0.0f);
	CHECK(eq(m54[m4], -0.3413f, MATH_TOLERANCE));
	CHECK(eq(m54[m5], 0.9144f, MATH_TOLERANCE));
	CHECK(eq(m54[m6], 0.2174f, MATH_TOLERANCE));
	CHECK((m54[m7] == 0.0f));
	CHECK(eq(m54[m8], 0.7955f, MATH_TOLERANCE));
	CHECK(eq(m54[m9], 0.1579f, MATH_TOLERANCE));
	CHECK(eq(m54[m10], 0.5849f, MATH_TOLERANCE));
	CHECK((m54[m11] == 0.0f));
	CHECK((m54[m12] == 0.0f));
	CHECK((m54[m13] == 0.0f));
	CHECK((m54[m14] == 0.0f));
	CHECK((m54[m15] == 1.0f));

#endif
} TEST_END

// --- End of File ---
