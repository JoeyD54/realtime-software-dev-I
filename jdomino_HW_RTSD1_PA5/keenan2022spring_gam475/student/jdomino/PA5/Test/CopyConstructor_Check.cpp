//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "PCSTree.h"
#include "PCSNode.h"

using namespace Azul;

static PCSNode *pn = nullptr;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(CopyConstructor_Check, TestConfig::ALL)
{
#if CopyConstructor_Check

	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	pn = new PCSNode();

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);

	CHECK(pn->GetChild() == nullptr);
	CHECK(pn->GetParent() == nullptr);
	CHECK(pn->GetNextSibling() == nullptr);
	CHECK(pn->GetPrevSibling() == nullptr);

	pn->SetParent(&nodeA);
	pn->SetChild(&nodeB);
	pn->SetNextSibling(&nodeC);
	pn->SetPrevSibling(&nodeD);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	PCSNode pn2(*pn);

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;
	returnCode = pn2.GetName(buff, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	char buff2[PCSNode::NAME_SIZE];
	returnCode = pn->GetName(buff2, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNode::NAME_SIZE) == 0);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	CHECK(pn2.GetPrevSibling() == &nodeD);
	CHECK(pn2.GetNextSibling() == &nodeC);
	CHECK(pn2.GetParent() == &nodeA);
	CHECK(pn2.GetChild() == &nodeB);

	delete pn;
	pn = nullptr;

#endif
} TEST_END

TEST_TEARDOWN(CopyConstructor_Check)
{
	delete pn;
	pn = nullptr;
} 


// ---  End of File ---
