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

TEST(Matrix_default_constructor, TestConfig::ALL)
{
#if Matrix_default_constructor

	Matrix M;

	CHECK(M[m0] == 0.0f);
	CHECK(M[m1] == 0.0f);
	CHECK(M[m2] == 0.0f);
	CHECK(M[m3] == 0.0f);
	CHECK(M[m4] == 0.0f);
	CHECK(M[m5] == 0.0f);
	CHECK(M[m6] == 0.0f);
	CHECK(M[m7] == 0.0f);
	CHECK(M[m8] == 0.0f);
	CHECK(M[m9] == 0.0f);
	CHECK(M[m10] == 0.0f);
	CHECK(M[m11] == 0.0f);
	CHECK(M[m12] == 0.0f);
	CHECK(M[m13] == 0.0f);
	CHECK(M[m14] == 0.0f);
	CHECK(M[m15] == 0.0f);

#endif
} TEST_END

// --- End of File ---