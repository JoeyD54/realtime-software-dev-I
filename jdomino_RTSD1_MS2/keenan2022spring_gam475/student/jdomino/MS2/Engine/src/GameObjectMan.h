//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GAME_OBJECT_MAN_H
#define GAME_OBJECT_MAN_H

#include "GameObject.h"
#include "PCSTree.h"
#include "Texture.h"

namespace Azul
{

	// Singleton
	class GameObjectMan
	{
	public:
		static void Add(GameObject *pObj);
		static void Remove(GameObject* pObj);
		static void Draw(void);
		static void Update(float currentTime);
		static void DeleteMesh(Mesh::Name name);
		static void DeleteTexture(Texture::Name name);

		static void Destroy();
		~GameObjectMan();

	private:
		GameObjectMan();

		static GameObjectMan *privGetInstance();

		// data
		PCSTree *poRootTree;
	};

}

#endif


// --- End of File ---
