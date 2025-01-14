//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_ConstColor.h"
#include "Camera.h"
#include "ShaderObject.h"
#include "MathEngine.h"

using namespace Azul;

extern Camera* pCam;


	GraphicsObject_ConstColor::GraphicsObject_ConstColor(Mesh * _pMesh, ShaderObject* _pShaderObj, Vect& LightColor, Vect& LightPos)
		: GraphicsObject(_pMesh, _pShaderObj)
	{
		this->poLightColor = new Vect(LightColor);
		this->poLightPos = new Vect(LightPos);
	}

	GraphicsObject_ConstColor::~GraphicsObject_ConstColor()
	{
		delete this->poLightColor;
		delete this->poLightPos;
	}

	void GraphicsObject_ConstColor::SetState()
	{
		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CW);
	}

	void GraphicsObject_ConstColor::SetDataGPU()
	{
		// set the vao
		glBindVertexArray(this->GetMesh()->vao);

		// use this shader
		this->pShaderObj->SetActive();

		Matrix world = this->GetWorld();
		Matrix view = pCam->getViewMatrix();
		Matrix proj = pCam->getProjMatrix();

		glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)&proj);
		glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float*)&view);
		glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float*)&world);

		Vect light = *this->poLightPos;
		Vect color = *this->poLightColor;
		glUniform3fv(this->pShaderObj->GetLocation("vLightPos"), 1, (float*)&light);
		glUniform4fv(this->pShaderObj->GetLocation("vColor"), 1, (float*)&color);

	}

	void GraphicsObject_ConstColor::Draw()
	{
		// draw
	//	glDrawArrays(GL_TRIANGLES, 0, (3 * this->GetMesh()->numVerts));

		//The starting point of the IBO
		glDrawElements(GL_TRIANGLES, 3 * this->GetMesh()->numTris, GL_UNSIGNED_INT, 0);

	}

	void GraphicsObject_ConstColor::RestoreState()
	{
		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CW);
	}



// ---  End of File ---
