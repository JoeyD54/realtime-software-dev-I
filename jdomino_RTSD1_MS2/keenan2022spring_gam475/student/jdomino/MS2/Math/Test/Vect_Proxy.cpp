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

TEST(Vect_Proxy_Mag, TestConfig::ALL)
{
#if Vect_Proxy_Mag


	Vect A(1, 2, 3);
	Vect B(3, 4, 5);
	Vect C(3, 4, 5);

	float val;

	val = A.mag();
	CHECK(UnitUtility::AreEqual(val, 3.7416f));

	val = B.mag();
	CHECK(UnitUtility::AreEqual(val, 7.0710f));

	val = C.mag();
	CHECK(UnitUtility::AreEqual(val, 7.0710f));

	if (B.mag() > A.mag())
	{
		CHECK(true);
	}
	else
	{
		CHECK(false);
	}

	if (B.mag() < A.mag())
	{
		CHECK(false);
	}
	else
	{
		CHECK(true);
	}

	if (B.mag() == A.mag())
	{
		CHECK(false);
	}
	else
	{
		CHECK(true);
	}

	if (B.mag() == C.mag())
	{
		CHECK(true);
	}
	else
	{
		CHECK(false);
	}


	if (B.mag() >= A.mag())
	{
		CHECK(true);
	}
	else
	{
		CHECK(false);
	}

	if (B.mag() >= C.mag())
	{
		CHECK(true);
	}
	else
	{
		CHECK(false);
	}

	if (B.mag() <= A.mag())
	{
		CHECK(false);
	}
	else
	{
		CHECK(true);
	}

	if (B.mag() <= C.mag())
	{
		CHECK(true);
	}
	else
	{
		CHECK(false);
	}

	if (B.mag() != C.mag())
	{
		CHECK(false);
	}
	else
	{
		CHECK(true);
	}


	// These mag need to converted to float before multiplication
	val = A.mag() * B.mag();
	CHECK(UnitUtility::AreEqual(val, 26.4575f))


#endif
} TEST_END



// ---  End of File ---------------
