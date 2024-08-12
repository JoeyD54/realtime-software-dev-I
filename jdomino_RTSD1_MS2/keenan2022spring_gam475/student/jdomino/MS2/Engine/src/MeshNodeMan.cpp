//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "MeshNodeMan.h"
#include "NullMesh.h"
#include "CubeMesh.h"
#include "PyramidMesh.h"
#include "TriPyramidMesh.h"
#include "DiamondMesh.h"

MeshNodeMan *MeshNodeMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
MeshNodeMan::MeshNodeMan(int reserveNum, int reserveGrow)
	: ManBase(reserveGrow)
{
	// Preload the reserve
	this->proFillReservedPool(reserveNum);

	// initialize derived data here
	Mesh *pMesh = new NullMesh();
	assert(pMesh);
	this->poNodeCompare = new MeshNode();
	assert(this->poNodeCompare);
	this->poNodeCompare->Set(Mesh::Name::NULL_MESH, pMesh);
}

MeshNodeMan::~MeshNodeMan()
{
	delete this->poNodeCompare;
	this->poNodeCompare = nullptr;

	// iterate through the list and delete
	Iterator *pIt = this->baseGetActiveIterator();

	DLink *pNode = pIt->First();

	// Walk through the nodes
	while (!pIt->IsDone())
	{
		MeshNode *pDeleteMe = (MeshNode *)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}

	pIt = this->baseGetReserveIterator();

	pNode = pIt->First();

	// Walk through the nodes
	while (!pIt->IsDone())
	{
		MeshNode *pDeleteMe = (MeshNode *)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void MeshNodeMan::Create(int reserveNum, int reserveGrow)
{
	// make sure values are ressonable 
	assert(reserveNum >= 0);
	assert(reserveGrow > 0);

	// initialize the singleton here
	assert(posInstance == nullptr);

	// Do the initialization
	if (posInstance == nullptr)
	{
		posInstance = new MeshNodeMan(reserveNum, reserveGrow);
	}

}

void MeshNodeMan::Destroy()
{
	MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
	assert(pMan != nullptr);
	AZUL_UNUSED_VAR(pMan);

	delete MeshNodeMan::posInstance;
	MeshNodeMan::posInstance = nullptr;
}

MeshNode *MeshNodeMan::Add(Mesh::Name name, Mesh *pMesh)
{
	MeshNodeMan *pMan = MeshNodeMan::privGetInstance();

	assert(pMesh);

	MeshNode *pNode = (MeshNode *)pMan->baseAddToFront();
	assert(pNode != nullptr);

	// Initialize the date
	pNode->Set(name, pMesh);

	return pNode;
}

MeshNode *MeshNodeMan::Find(Mesh::Name _name)
{
	MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
	assert(pMan != nullptr);

	// Compare functions only compares two Nodes

	// So:  Use the Compare Node - as a reference
	//      use in the Compare() function
	Mesh *pMesh = pMan->poNodeCompare->GetMesh();
	assert(pMesh);

	pMesh->name = _name;

	MeshNode *pData = (MeshNode *)pMan->baseFind(pMan->poNodeCompare);
	return pData;
}

void MeshNodeMan::Remove(MeshNode *pNode)
{
	assert(pNode != nullptr);

	MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseRemove(pNode);
}

void MeshNodeMan::Dump()
{
	MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseDump();
}

Mesh* MeshNodeMan::CreateMesh(Mesh::Name name)
{
	Mesh* tmp = nullptr;

	if (name == Mesh::Name::NULL_MESH) //load from the files
	{
		tmp = new NullMesh();
		Add(Mesh::Name::NULL_MESH, tmp);
	}
	if (name == Mesh::Name::CUBE) //load from the files
	{
		tmp = new CubeMesh("cubeMesh.azul");
		Add(Mesh::Name::CUBE, tmp);
	}
	if (name == Mesh::Name::PYRAMID)
	{
		tmp = new PyramidMesh("pyramidMesh.azul");
		Add(Mesh::Name::PYRAMID, tmp);
	}
	if (name == Mesh::Name::TRI_PYRAMID)
	{
		tmp = new TriPyramidMesh("tripyramidMesh.azul");
		Add(Mesh::Name::TRI_PYRAMID, tmp);
	}
	if (name == Mesh::Name::DIAMOND)
	{
		tmp = new DiamondMesh("diamondMesh.azul");
		Add(Mesh::Name::DIAMOND, tmp);
	}

	return tmp;

}

void MeshNodeMan::DeleteMesh(Mesh::Name name)
{
	MeshNodeMan* pMan = MeshNodeMan::privGetInstance();
	assert(pMan != nullptr);

	MeshNode* tmp = MeshNodeMan::Find(name);

	DLink* meshDLink = (DLink*) tmp;

	pMan->baseRemove(meshDLink);
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
MeshNodeMan *MeshNodeMan::privGetInstance()
{
	// Safety - this forces users to call Create() first before using class
	assert(posInstance != nullptr);

	return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink *MeshNodeMan::derivedCreateNode()
{
	DLink *pNodeBase = new MeshNode();
	assert(pNodeBase != nullptr);

	return pNodeBase;
}







