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

TEST(Vect_Get_Brackets, TestConfig::ALL)
{
#if Vect_Get_Brackets

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

#endif
}  TEST_END


#if Vect_Get_Brackets_const
float constTest(const Vect &t)
{
	return (t[x] + t[y] + t[z] + t[w]);
}
#endif

TEST(Vect_Get_Brackets_const, TestConfig::ALL)
{
#if Vect_Get_Brackets_const
	Vect A(2.0f, 3.0f, 4.0f, 5.0f);

	const float sum = constTest(A);

	CHECK(sum == 14.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

#endif
}  TEST_END



TEST(Vect_Set_Brackets, TestConfig::ALL)
{
#if Vect_Set_Brackets

	Vect A(0.0f, 0.0f, 0.0f, 0.0f);

	CHECK(A[x] == 0.0f);
	CHECK(A[y] == 0.0f);
	CHECK(A[z] == 0.0f);
	CHECK(A[w] == 0.0f);

	A[x] = 2.0f;
	A[y] = 3.0f;
	A[z] = 4.0f;
	A[w] = 5.0f;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

#endif
}  TEST_END



TEST(Vect_Set_Brackets_get, TestConfig::ALL)
{
#if Vect_Set_Brackets_get

	Vect A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	float tx, ty, tz, tw;

	tx = A[x];
	ty = A[y];
	tz = A[z];
	tw = A[w];

	CHECK(tx == 2.0f);
	CHECK(ty == 3.0f);
	CHECK(tz == 4.0f);
	CHECK(tw == 5.0f);

#endif
}  TEST_END

// ---  End of File ---------------
