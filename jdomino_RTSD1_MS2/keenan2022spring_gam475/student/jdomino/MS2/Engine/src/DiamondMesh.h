//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef DIAMOND_MESH_H
#define DIAMOND_MESH_H

#include "Mesh.h"

class DiamondMesh : public Mesh
{
public:
	DiamondMesh(const char* const pMeshFileName);

	DiamondMesh() = delete;
	DiamondMesh(const DiamondMesh&) = delete;
	DiamondMesh& operator = (DiamondMesh&) = delete;
	virtual ~DiamondMesh();

private:
	virtual void privCreateVAO(const char* const pMeshFileName) override;

	// Data

};

#endif

// --- End of File ---
