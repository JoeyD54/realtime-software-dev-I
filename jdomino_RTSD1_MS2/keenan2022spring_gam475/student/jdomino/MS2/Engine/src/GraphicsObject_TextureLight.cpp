//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
#include "GraphicsObject_TextureLight.h"
#include "Mesh.h"
#include "TextureMan.h"
#include "Camera.h"
#include "ShaderObject.h"

using namespace Azul;

extern Camera *pCam;


GraphicsObject_TextureLight::GraphicsObject_TextureLight(Mesh *_pMesh, ShaderObject *_pShaderObj, Texture::Name _name, Vect &LightColor, Vect &LightPos)
	: GraphicsObject(_pMesh, _pShaderObj),
	textName(_name)
{
	TextureMan::IncrementTextureCount(_name);
	this->poLightColor = new Vect(LightColor);
	this->poLightPos = new Vect(LightPos);
	assert(poLightColor);
	assert(poLightPos);
	this->hasTexture = true;
}

GraphicsObject_TextureLight::~GraphicsObject_TextureLight()
{
	TextureMan::DecrementTextureCount(this->textName);
	delete this->poLightColor;
	delete this->poLightPos;
}

void GraphicsObject_TextureLight::SetState()
{
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture
	GLuint textureID = TextureMan::FindID(this->textName);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}

void GraphicsObject_TextureLight::SetDataGPU()
{
	// use this shader
	this->pShaderObj->SetActive();

	// set the vao
	glBindVertexArray(this->GetMesh()->vao);

	Matrix world = this->GetWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *) &proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *) &view);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *) &world);

	Vect light = *this->poLightPos;
	Vect color = *this->poLightColor;
	glUniform3fv(this->pShaderObj->GetLocation("vLightPos"), 1, (float *) &light);
	glUniform4fv(this->pShaderObj->GetLocation("vColor"), 1, (float *) &color);
}

void GraphicsObject_TextureLight::Draw()
{
	////The draw triangles 
	//glDrawArrays(GL_TRIANGLES, 0, (3 * this->GetMesh()->numTris));

	//The starting point of the IBO
	glDrawElements(GL_TRIANGLES, 3 * this->GetMesh()->numTris, GL_UNSIGNED_INT, 0);
}

void GraphicsObject_TextureLight::RestoreState()
{
	// undo the states you corrupted
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
}



// ---  End of File ---