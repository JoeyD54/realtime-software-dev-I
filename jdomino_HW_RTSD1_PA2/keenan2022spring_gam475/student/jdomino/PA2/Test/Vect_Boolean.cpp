//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Vect_IsEqualFalse, TestConfig::ALL)
{
#if Vect_IsEqualFalse

	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2(9.0f, -3.0f, 5.0f);
	bool bvalue1;

	bvalue1 = v1.isEqual(v2, 0.1f);

	CHECK(bvalue1 == false);

#endif
} TEST_END



TEST(Vect_IsEqualTrue, TestConfig::ALL)
{
#if Vect_IsEqualTrue

	bool bvalue1;
	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2(1.0f, 2.0f, 3.05f);

	bvalue1 = v1.isEqual(v2, 0.1f);

	CHECK(bvalue1 == true);

#endif
} TEST_END



TEST(Vect_IsZeroFalse, TestConfig::ALL)
{
#if Vect_IsZeroFalse

	bool bvalue1;
	Vect v1(0.023f, 0.0f, 0.0f, 1.05f);

	bvalue1 = v1.isZero(0.0f);

	CHECK(bvalue1 == false);

#endif
} TEST_END



TEST(Vect_IsZeroTrue_True, TestConfig::ALL)
{
#if Vect_IsZeroTrue_True

	bool bvalue1;
	Vect v1(0.0f, 0.0f, 0.0f, 1.05f);

	bvalue1 = v1.isZero(0.1f);

	CHECK(bvalue1 == true);

#endif
} TEST_END



TEST(Vect_IsEqualFalse_default, TestConfig::ALL)
{
#if Vect_IsEqualFalse_default

	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2(9.0f, -3.0f, 5.0f);
	bool bvalue1;

	bvalue1 = v1.isEqual(v2);

	CHECK(bvalue1 == false);

#endif
} TEST_END



TEST(Vect_IsEqualTrue_default, TestConfig::ALL)
{
#if Vect_IsEqualTrue_default

	bool bvalue1;
	Vect v1(1.0f, 2.0f, 3.0f);
	Vect v2(1.0f, 2.0f, 3.05f);

	bvalue1 = v1.isEqual(v2);

	CHECK(bvalue1 == false);

#endif
} TEST_END



TEST(Vect_IsZeroFalse_default, TestConfig::ALL)
{
#if Vect_IsZeroFalse_default

	bool bvalue1;
	Vect v1(0.023f, 0.0f, 0.0f, 1.05f);

	bvalue1 = v1.isZero();

	CHECK(bvalue1 == false);

#endif
} TEST_END



TEST(Vect_IsZeroTrue_default, TestConfig::ALL)
{
#if Vect_IsZeroTrue_default

	bool bvalue1;
	Vect v1(0.0f, 0.0f, 0.0f, 1.05f);

	bvalue1 = v1.isZero();

	CHECK(bvalue1 == false);

#endif
} TEST_END


// ---  End of File ---------------
