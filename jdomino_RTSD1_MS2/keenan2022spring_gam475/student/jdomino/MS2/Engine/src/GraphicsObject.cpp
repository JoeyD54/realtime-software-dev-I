//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "GraphicsObject.h"
#include "MathEngine.h"
#include "Mesh.h"

using namespace Azul;

GraphicsObject::GraphicsObject(const Mesh *const _pMesh, const ShaderObject *const _pShaderObj)
	: pMesh(_pMesh),
	pShaderObj(_pShaderObj)
{
	this->poWorld = new Matrix(Matrix::Special::Identity);
	this->hasTexture = false;
	assert(this->poWorld);
	assert(_pMesh);
	assert(_pShaderObj);
}

GraphicsObject::~GraphicsObject()
{
	delete this->poWorld;
}

void GraphicsObject::Render()
{
	this->SetState();
	this->SetDataGPU();
	this->Draw();
	this->RestoreState();
}

const Mesh *GraphicsObject::GetMesh() const
{
	return this->pMesh;
}

Matrix &GraphicsObject::GetWorld()
{
	return *this->poWorld;
}

void GraphicsObject::SetWorld(Matrix &_world)
{
	*this->poWorld = _world;
}

// --- End of File ---