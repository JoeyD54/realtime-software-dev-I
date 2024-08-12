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

TEST(Vect_Dot, TestConfig::ALL)
{
#if Vect_Dot

	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2(4.0f, 5.0f, 6.0f);

	float value1;

	value1 = v1.dot(v2);
	CHECK(value1 == 32.0f);

#endif
} TEST_END



TEST(Vect_Cross, TestConfig::ALL)
{
#if Vect_Cross

	Vect v1(1.0f, 0.0f, 0.0f);
	Vect v2(0.0f, 1.0f, 0.0f);
	Vect out1;

	out1 = v1.cross(v2);

	CHECK((out1[x] == 0.0f));
	CHECK((out1[y] == 0.0f));
	CHECK((out1[z] == 1.0f));
	CHECK((out1[w] == 1.0f));

#endif
} TEST_END



TEST(Vect_Normalize, TestConfig::ALL)
{
#if Vect_Normalize

	Vect v1(1.0f, 2.0f, 3.0f);

	v1.norm();

	CHECK(eq(v1[x], 0.2672f, MATH_TOLERANCE));
	CHECK(eq(v1[y], 0.5345f, MATH_TOLERANCE));
	CHECK(eq(v1[z], 0.80174f, MATH_TOLERANCE));
	CHECK((v1[w] == 1.0f));

#endif
} TEST_END



TEST(Vect_GetNormalize, TestConfig::ALL)
{
#if Vect_GetNormalize

	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2;

	v2 = v1.getNorm();

	CHECK(eq(v2[x], 0.2672f, MATH_TOLERANCE));
	CHECK(eq(v2[y], 0.5345f, MATH_TOLERANCE));
	CHECK(eq(v2[z], .80174f, MATH_TOLERANCE));
	CHECK((v2[w] == 1.0f));
	CHECK((v1[x] == 1.0f));
	CHECK((v1[y] == 2.0f));
	CHECK((v1[z] == 3.0f));
	CHECK((v1[w] == 1.0f));

#endif
} TEST_END



TEST(Vect_Mag, TestConfig::ALL)
{
#if Vect_Mag

	Vect v1(1.0f, 2.0f, 3.0f);
	float value;

	value = v1.mag();

	CHECK(eq(value, 3.7416f, MATH_TOLERANCE));

#endif
} TEST_END

TEST(Vect_getAngle, TestConfig::ALL)
{
#if Vect_getAngle

	float value;
	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2(1.80f, -2.0f, 2.0f);

	value = v1.getAngle(v2);

	CHECK(eq(value, 1.263f, MATH_TOLERANCE));

#endif
} TEST_END


// ---  End of File ---------------
