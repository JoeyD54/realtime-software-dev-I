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

TEST(Vect_set_3_elements, TestConfig::ALL)
{
#if Vect_set_3_elements

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	A.set(10.0f, 20.0f, 30.0f);

	CHECK(A[x] == 10.0f);
	CHECK(A[y] == 20.0f);
	CHECK(A[z] == 30.0f);
	CHECK(A[w] == 1.0f);

#endif
} TEST_END



TEST(Vect_set_4_elements, TestConfig::ALL)
{
#if Vect_set_4_elements

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	A.set(10.0f, 20.0f, 30.0f, 40.0f);

	CHECK(A[x] == 10.0f);
	CHECK(A[y] == 20.0f);
	CHECK(A[z] == 30.0f);
	CHECK(A[w] == 40.0f);

#endif
} TEST_END


TEST(Vect_set_Vector, TestConfig::ALL)
{
#if Vect_set_Vector

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	Vect B(10.0f, 20.0f, 30.0f, 40.0f);

	CHECK(B[x] == 10.0f);
	CHECK(B[y] == 20.0f);
	CHECK(B[z] == 30.0f);
	CHECK(B[w] == 40.0f);

	A.set(B);

	CHECK(B[x] == 10.0f);
	CHECK(B[y] == 20.0f);
	CHECK(B[z] == 30.0f);
	CHECK(B[w] == 40.0f);

	CHECK(A[x] == 10.0f);
	CHECK(A[y] == 20.0f);
	CHECK(A[z] == 30.0f);
	CHECK(A[w] == 40.0f);

#endif
} TEST_END


// ---  End of File ---------------
