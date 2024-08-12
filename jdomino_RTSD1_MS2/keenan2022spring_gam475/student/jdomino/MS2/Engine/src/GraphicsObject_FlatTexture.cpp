//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "GraphicsObject_FlatTexture.h"
#include "TextureMan.h"
#include "Mesh.h"
#include "Camera.h"

using namespace Azul;

extern Camera *pCam;

GraphicsObject_FlatTexture::GraphicsObject_FlatTexture(const Mesh *const _pMesh, const ShaderObject *const _pShaderObj, Texture::Name _name)
	: GraphicsObject(_pMesh, _pShaderObj), textName(_name)
{
	// check the base class
	TextureMan::IncrementTextureCount(_name);
	this->hasTexture = true;
	assert(this->pMesh);
	assert(this->pShaderObj);
	assert(this->poWorld);
}

void GraphicsObject_FlatTexture::SetState()
{
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture
	GLuint textureID = TextureMan::FindID(this->textName);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}

void GraphicsObject_FlatTexture::SetDataGPU()
{
	// use this shader
	this->pShaderObj->SetActive();

	// set the vao
	glBindVertexArray(this->GetMesh()->vao);

	Matrix world = this->GetWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *) &view);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *) &world);
}

void GraphicsObject_FlatTexture::Draw()
{
	//// draw
	//glDrawArrays(GL_TRIANGLES, 0, (3 * this->GetMesh()->numTris));

	//The starting point of the IBO
	glDrawElements(GL_TRIANGLES, 3 * this->GetMesh()->numTris, GL_UNSIGNED_INT, 0);
}

void GraphicsObject_FlatTexture::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}

void GraphicsObject_FlatTexture::SwapTexture(Texture::Name name)
{
	TextureMan::DecrementTextureCount(this->textName);

	this->textName = name;

	TextureMan::IncrementTextureCount(this->textName);

	this->SetState();
}

GraphicsObject_FlatTexture::~GraphicsObject_FlatTexture()
{
	TextureMan::DecrementTextureCount(this->textName);
}

//--- End of File -------------------------------------------------------------

