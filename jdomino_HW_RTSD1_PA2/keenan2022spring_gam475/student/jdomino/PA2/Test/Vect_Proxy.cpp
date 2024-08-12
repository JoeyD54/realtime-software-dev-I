//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
#include "CDM.h"

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

	CDM::ResetSqrtCount();

	CHECK(CDM::GetSqrtCount() == 0);
	val = A.mag();
	CHECK(UnitUtility::AreEqual(val, 3.7416f));
	CHECK(CDM::GetSqrtCount() == 1);

	val = B.mag();
	CHECK(UnitUtility::AreEqual(val, 7.0710f));
	CHECK(CDM::GetSqrtCount() == 2);

	val = C.mag();
	CHECK(UnitUtility::AreEqual(val, 7.0710f));
	CHECK(CDM::GetSqrtCount() == 3);


	if (B.mag() > A.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}

	if (B.mag() < A.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}

	if (B.mag() == A.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}

	if (B.mag() == C.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}


	if (B.mag() >= A.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}

	if (B.mag() >= C.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}

	if (B.mag() <= A.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}

	if (B.mag() <= C.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}


	if (B.mag() != C.mag())
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(false);
	}
	else
	{
		CHECK(CDM::GetSqrtCount() == 3);
		CHECK(true);
	}


	// These mag need to converted to float before multiplication
	val = A.mag() * B.mag();
	CHECK(UnitUtility::AreEqual(val, 26.4575f))

	CHECK(CDM::GetSqrtCount() == 5);

#endif
} TEST_END



// ---  End of File ---------------
