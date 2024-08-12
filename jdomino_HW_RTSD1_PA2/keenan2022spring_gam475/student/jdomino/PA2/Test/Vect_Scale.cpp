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


TEST(Vect_scale_Vect, TestConfig::ALL)
{
#if Vect_scale_Vect

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	const float s = 5.0f;
	Vect C;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	C = s * A;

	CHECK(C[x] == 10.0f);
	CHECK(C[y] == 15.0f);
	CHECK(C[z] == 20.0f);
	CHECK(C[w] == 1.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

#endif
} TEST_END



TEST(Vect_times_Scale, TestConfig::ALL)
{
#if Vect_times_Scale

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	const float s = 5.0f;
	Vect C;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	C = A * s;

	CHECK(C[x] == 10.0f);
	CHECK(C[y] == 15.0f);
	CHECK(C[z] == 20.0f);
	CHECK(C[w] == 1.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

#endif
} TEST_END



TEST(Vect_ScaleEquals, TestConfig::ALL)
{
#if Vect_ScaleEquals

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	const float s = 5.0f;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	A *= s;

	CHECK(A[x] == 10.0f);
	CHECK(A[y] == 15.0f);
	CHECK(A[z] == 20.0f);
	CHECK(A[w] == 1.0f);

#endif
} TEST_END


// ---  End of File ---------------
