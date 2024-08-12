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

TEST(MatrixDestructor_constuctor, TestConfig::ALL)
{
#if MatrixDestructor_constuctor

	Vect V0(1.0f, 2.0f, 3.0f, 4.0f);
	Vect V1(7.0f, 6.0f, 5.0f, 3.0f);
	Vect V2(-4.0f, -2.0f, -1.0f, -4.0f);
	Vect V3(9.0f, -7.0f, -2.0f, 5.0f);

	Matrix M(V0, V1, V2, V3);

	Matrix *pM = &M;
	pM->~Matrix();
	CHECK(1);

#endif
} TEST_END

// --- End of File ---
