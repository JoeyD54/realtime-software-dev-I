//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "PCSNode.h"
using namespace Azul;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(GetNextSibling_Check, TestConfig::ALL)
{
#if GetNextSibling_Check

	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetNextSibling(&nodeB);
	nodeC = nodeA.GetNextSibling();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

#endif
} TEST_END

// ---  End of File ---
