//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "GraphicsObject_Null.h"

GraphicsObject_Null::GraphicsObject_Null(const Mesh *const _pMesh, const ShaderObject *const pShaderObj)
	: GraphicsObject(_pMesh, pShaderObj)
{

}

void GraphicsObject_Null::SetState()
{

}

void GraphicsObject_Null::SetDataGPU()
{

}

void GraphicsObject_Null::Draw()
{

}

void GraphicsObject_Null::RestoreState()
{

}

// ---  End of File ---