//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
using namespace Azul;

//---------------------------------------------------------------------------
// Sample TESTS:
//---------------------------------------------------------------------------

TEST(Vect_SampleTest, TestConfig::ALL)
{
#if Vect_SampleTest

	const float x(5.0f);

	CHECK(x == 5.0f);

#endif
} TEST_END



TEST(Vect_ConstantCheck, TestConfig::ALL)
{
#if Vect_ConstantCheck

	CHECK(Util::isEqual(MATH_PI2, 1.570796f, MATH_TOLERANCE) == true);

#endif
} TEST_END



// ---  End of File ---------------
