//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "MathEngine.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "PCSNode.h"

namespace Azul
{

	class GameObject : public PCSNode
	{
	public:
		GameObject() = delete;
		GameObject(const GameObject &) = delete;
		GameObject &operator = (const GameObject &) = delete;
		virtual ~GameObject();

		GameObject(GraphicsObject *graphicsObject);  // Keenan(20)

		void Update(float t);
		void Draw();

		// Set / Get:
		GraphicsObject *GetGraphicsObject();
		Matrix *GetWorld();

		void SetWorld(Matrix *pWorld);
		void SetPos(const Vect &pos);
		void SetScale(const Vect &scale);
		void SetDeltaRot(float delta);

	protected:
		Matrix *poWorld;
		Vect *poTrans;

	private:
		void privUpdate(float t);

		GraphicsObject *poGraphicsObject;
		Vect *poScale;

		float           deltaRot;
		float			rotY;
		float			rotZ;
	};
}

#endif


// --- End of File ---
