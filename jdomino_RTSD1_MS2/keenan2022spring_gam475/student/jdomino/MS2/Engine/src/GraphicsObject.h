//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "MathEngine.h"
#include "ShaderObject.h"
#include "RenderMaterial.h"

class Mesh;

class GraphicsObject : public RenderMaterial
{
public:
	GraphicsObject(const Mesh *const _pMesh, const ShaderObject *const pShaderObj);

	GraphicsObject() = delete;
	GraphicsObject(const GraphicsObject &) = delete;
	GraphicsObject &operator = (const GraphicsObject &) = delete;
	virtual ~GraphicsObject();

	void Render();
	void SetWorld(Azul::Matrix &_world);

	const Mesh *GetMesh() const;
	Azul::Matrix &GetWorld();

	bool hasTexture;

protected:
	const Mesh *pMesh;
	Azul::Matrix *poWorld;
	const ShaderObject *pShaderObj;
};

#endif

// --- End of File ---
