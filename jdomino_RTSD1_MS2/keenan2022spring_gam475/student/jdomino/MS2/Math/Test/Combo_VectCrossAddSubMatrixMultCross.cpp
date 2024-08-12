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

TEST( Combo_VectCrossAddSubMatrixMultCross, TestConfig::ALL)
{
#if Combo_VectCrossAddSubMatrixMultCross
	Vect A(1.0f, 2.0f, 3.0f, 5.0f);
	Vect B(10.0f, 11.0f, 12.0f, 13.0f);
	Vect C;

	CHECK(A[x] == 1.0f);
	CHECK(A[y] == 2.0f);
	CHECK(A[z] == 3.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 10.0f);
	CHECK(B[y] == 11.0f);
	CHECK(B[z] == 12.0f);
	CHECK(B[w] == 13.0f);

	C = A + (A - B).cross(B);
	Vect D = C.dot(A) * B;

	CHECK(D[x] == 140.0f);
	CHECK(D[y] == 154.0f);
	CHECK(D[z] == 168.0f);
	CHECK(D[w] == 1.0f);

	CHECK(C[x] == -8.0f);
	CHECK(C[y] == 20.0f);
	CHECK(C[z] == -6.0f);
	CHECK(C[w] == 1.0f);

	CHECK(A[x] == 1.0f);
	CHECK(A[y] == 2.0f);
	CHECK(A[z] == 3.0f);
	CHECK(A[w] == 5.0f);

	CHECK(B[x] == 10.0f);
	CHECK(B[y] == 11.0f);
	CHECK(B[z] == 12.0f);
	CHECK(B[w] == 13.0f);

	Matrix M(A, B, C, D);

	A = Vect(1.0f, 0.0f, 4.0f, 1.0f).cross(B * M);

	CHECK(A[x] == -9532.0f);
	CHECK(A[y] == 5102.0f);
	CHECK(A[z] == 2383.0f);
	CHECK(A[w] == 1.0f);

#endif
} TEST_END

// ---  End of File ---
