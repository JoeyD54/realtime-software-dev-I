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


TEST(Vect_Add_Vect, TestConfig::ALL)
{
#if Vect_Add_Vect

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	Vect B(21.0f, 31.0f, 41.0f, 51.0f);
	Vect C;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

	C = A + B;

	CHECK(C[x] == 23.0f);
	CHECK(C[y] == 34.0f);
	CHECK(C[z] == 45.0f);
	CHECK(C[w] == 1.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

#endif
} TEST_END



TEST(Vect_plusEqual_Vect, TestConfig::ALL)
{
#if Vect_plusEqual_Vect

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	Vect B(21.0f, 31.0f, 41.0f, 51.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

	A += B;

	CHECK(A[x] == 23.0f);
	CHECK(A[y] == 34.0f);
	CHECK(A[z] == 45.0f);
	CHECK(A[w] == 1.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

#endif
} TEST_END



TEST(Vect_Sub_Vect, TestConfig::ALL)
{
#if Vect_Sub_Vect

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	Vect B(21.0f, 31.0f, 41.0f, 51.0f);
	Vect C;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

	C = B - A;

	CHECK(C[x] == 19.0f);
	CHECK(C[y] == 28.0f);
	CHECK(C[z] == 37.0f);
	CHECK(C[w] == 1.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

#endif
} TEST_END



TEST(Vect_SubEqual_Vect, TestConfig::ALL)
{
#if Vect_SubEqual_Vect

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);
	Vect B(21.0f, 31.0f, 41.0f, 51.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);
	CHECK(B[w] == 51.0f);

	B -= A;

	CHECK(B[x] == 19.0f);
	CHECK(B[y] == 28.0f);
	CHECK(B[z] == 37.0f);
	CHECK(B[w] == 1.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

#endif

} TEST_END

// ---  End of File ---------------