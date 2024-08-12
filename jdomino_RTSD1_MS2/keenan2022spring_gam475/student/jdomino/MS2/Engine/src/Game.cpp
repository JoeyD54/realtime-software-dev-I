//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "sb7.h"
#include "MathEngine.h"
#include "Game.h"
#include "GameObject.h"
#include "ShaderObject.h"
#include "CubeMesh.h"
#include "PyramidMesh.h"
#include "TriPyramidMesh.h"
#include "DiamondMesh.h"
#include "GraphicsObject.h"
#include "GraphicsObject_ColorByPosition.h"
#include "GraphicsObject_Wireframe.h"
#include "GraphicsObject_FlatTexture.h"
#include "GraphicsObject_TextureLight.h"
#include "GraphicsObject_ConstColor.h"
#include "TextureMan.h"
#include "InputMan.h"
#include "InputTest.h"
#include "Camera.h"
#include "GameObjectMan.h"
#include "MeshNodeMan.h"
#include "ShaderMan.h"
#include "CameraMan.h"

using namespace Azul;

// Todo: ----------------------------------

// Get rid of globals
Camera *pCam = nullptr;

// Demo
	Vect Orig_up;
	Vect Orig_tar;
	Vect Orig_pos;
	Vect Orig_upNorm;
	Vect Orig_forwardNorm;
	Vect Orig_RightNorm;

bool keyPressed = false;
GraphicsObject* pGraphicsObj = nullptr;

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char *const pWindowName, const int Width, const int Height)
	:Engine(pWindowName, Width, Height)
{
	assert(pWindowName);
}

//-----------------------------------------------------------------------------
//  Game::~Game()
//		Game Engine destructor
//-----------------------------------------------------------------------------
Game::~Game()
{
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{

}


//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	// Start the managers
	InputMan::Create();
	TextureMan::Create();
	MeshNodeMan::Create();
	ShaderMan::Create();
	CameraMan::Create();

	// Camera setup
	pCam = CameraMan::SetCamera(1);
	pCam->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
	pCam->setPerspective(50.0f, float(pCam->getScreenWidth()) / float(pCam->getScreenHeight()), 0.10f, 1000.0f);
	pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 4.5f));
	pCam->updateCamera();

	// Load the Mesh
	Mesh* pNullMesh = MeshNodeMan::CreateMesh(Mesh::Name::NULL_MESH);
	AZUL_UNUSED_VAR(pNullMesh);

	Mesh* pCubeMesh = MeshNodeMan::CreateMesh(Mesh::Name::CUBE);
	Mesh* pPyramidMesh = MeshNodeMan::CreateMesh(Mesh::Name::PYRAMID);
	Mesh* pTriPyramidMesh = MeshNodeMan::CreateMesh(Mesh::Name::TRI_PYRAMID);
	Mesh* pDiamondMesh = MeshNodeMan::CreateMesh(Mesh::Name::DIAMOND);

	// Create/Load Shader 
	ShaderObject* pShaderObject_color = ShaderMan::Add(ShaderObject::Name::COLOR_POSITION, "colorRender");
	assert(pShaderObject_color);

	ShaderObject* pShaderObject_texture = ShaderMan::Add(ShaderObject::Name::TEXTURE_SIMPLE, "textureRender");
	assert(pShaderObject_texture);

	ShaderObject* pShaderObject_textureLight = ShaderMan::Add(ShaderObject::Name::TEXTURE_POINT_LIGHT, "texturePointLightDiff");
	assert(pShaderObject_textureLight);

	ShaderObject* pShaderObject_constColor = ShaderMan::Add(ShaderObject::Name::CONST_COLOR, "constcolorRender");
	assert(pShaderObject_constColor);

	// Textures
	TextureMan::Add("Rocks.tga", Texture::Name::ROCKS);
	TextureMan::Add("Stone.tga", Texture::Name::STONES);
	TextureMan::Add("RedBrick.tga", Texture::Name::RED_BRICK);
	TextureMan::Add("Duckweed.tga", Texture::Name::DUCKWEED);
	TextureMan::Add("kt_stone_1.tga", Texture::Name::KT_STONE_1);
	TextureMan::Add("Kt_Stone1.tga", Texture::Name::KT_STONE_2);


	// Create GameObject
	GameObject* pGameObj = nullptr;

	// Middle Row

	Vect color(1.50f, 1.50f, 1.50f, 1.0f);
	Vect pos(1, 1, 1);
	
	//4 cubes

	pGraphicsObj = new GraphicsObject_TextureLight(pCubeMesh, pShaderObject_textureLight, Texture::Name::KT_STONE_1, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(1.0f, 1.0f, 1.0f));
	pGameObj->SetPos(Vect(2.0f, 1.0f, 0.0f));
	pGameObj->SetDeltaRot(0.0152f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_TextureLight(pCubeMesh, pShaderObject_textureLight, Texture::Name::DUCKWEED, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(1.0f, 1.0f, 1.0f));
	pGameObj->SetPos(Vect(1.0f, 1.0f, 0.0f));
	pGameObj->SetDeltaRot(0.0152f);
	GameObjectMan::Add(pGameObj);

	/*pGraphicsObj = new GraphicsObject_FlatTexture(pCubeMesh, pShaderObject_texture, Texture::Name::RED_BRICK);*/
	pGraphicsObj = new GraphicsObject_Wireframe(pCubeMesh, pShaderObject_color);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(1.0f, 1.0f, 1.0f));
	pGameObj->SetPos(Vect(0.0f, 1.0f, 0.0f));
	pGameObj->SetDeltaRot(0.0152f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_FlatTexture(pCubeMesh, pShaderObject_texture, Texture::Name::ROCKS);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(1.0f, 1.0f, 1.0f));
	pGameObj->SetPos(Vect(3.0f, 1.0f, 0.0f));
	pGameObj->SetDeltaRot(0.0152f);
	GameObjectMan::Add(pGameObj);



	//----------------------------------------------------------

	//4 Pyramids

	pGraphicsObj = new GraphicsObject_TextureLight(pPyramidMesh, pShaderObject_textureLight, Texture::Name::ROCKS, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(2.0f, 2.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.0165f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_FlatTexture(pPyramidMesh, pShaderObject_texture, Texture::Name::KT_STONE_2);
	//pGraphicsObj = new GraphicsObject_ConstColor(pPyramidMesh, pShaderObject_color, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(3.0f, 2.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.0165f);
	GameObjectMan::Add(pGameObj);

	/*pGraphicsObj = new GraphicsObject_FlatTexture(pPyramidMesh, pShaderObject_texture, Texture::Name::ROCKS);*/
	pGraphicsObj = new GraphicsObject_Wireframe(pPyramidMesh, pShaderObject_color);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(1.0f, 2.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.0165f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_ConstColor(pPyramidMesh, pShaderObject_constColor, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(0.0f, 2.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.0165f);
	GameObjectMan::Add(pGameObj);

	//----------------------------------------------------------

	//Other shape 1

	pGraphicsObj = new GraphicsObject_FlatTexture(pTriPyramidMesh, pShaderObject_texture, Texture::Name::ROCKS);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(0.0f, 3.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.05f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_Wireframe(pTriPyramidMesh, pShaderObject_color);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(1.0f, 3.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.05f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_ColorByPosition(pTriPyramidMesh, pShaderObject_color);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(2.0f, 3.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.05f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_TextureLight(pTriPyramidMesh, pShaderObject_textureLight, Texture::Name::KT_STONE_2, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.25f, 0.25f, 0.25f));
	pGameObj->SetPos(Vect(3.0f, 3.0f, 0.0f));
	pGameObj->SetDeltaRot(-0.05f);
	GameObjectMan::Add(pGameObj);


	//----------------------------------------------------------

	//Other shape 2

	pGraphicsObj = new GraphicsObject_FlatTexture(pDiamondMesh, pShaderObject_texture, Texture::Name::ROCKS);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.5f, 0.5f, 0.5f));
	pGameObj->SetPos(Vect(0.0f, 4.0f, 0.0f));
	pGameObj->SetDeltaRot(0.005f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_Wireframe(pDiamondMesh, pShaderObject_color);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.5f, 0.5f, 0.5f));
	pGameObj->SetPos(Vect(1.0f, 4.0f, 0.0f));
	pGameObj->SetDeltaRot(0.005f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_FlatTexture(pDiamondMesh, pShaderObject_texture, Texture::Name::DUCKWEED);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.5f, 0.5f, 0.5f));
	pGameObj->SetPos(Vect(2.0f, 4.0f, 0.0f));
	pGameObj->SetDeltaRot(0.005f);
	GameObjectMan::Add(pGameObj);

	pGraphicsObj = new GraphicsObject_TextureLight(pDiamondMesh, pShaderObject_textureLight, Texture::Name::RED_BRICK, color, pos);
	pGameObj = new GameObject(pGraphicsObj);
	pGameObj->SetScale(Vect(0.5f, 0.5f, 0.5f, 0.5f));
	pGameObj->SetPos(Vect(3.0f, 4.0f, 0.0f));
	pGameObj->SetDeltaRot(0.005f);
	GameObjectMan::Add(pGameObj);

	//----------------------------------------------------------

	// squirrel for reset
	pCam->updateCamera();
	pCam->GetHelper(Orig_up, Orig_tar, Orig_pos, Orig_upNorm, Orig_forwardNorm, Orig_RightNorm);

	Trace::out("Z, I,O,  R,G \n");
}


//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------

Vect obj(0.0f, 0.0f, 0.0f);

void Game::Update(float currentTime)
{
	Keyboard* pKey = InputMan::GetKeyboard();

	if (pKey->GetKeyState(Keyboard::KEY_9))
	{
		keyPressed = true;
	}

	if (pKey->GetKeyState(Keyboard::KEY_DELETE) && keyPressed)
	{
		keyPressed = false;
		GameObjectMan::DeleteMesh(Mesh::Name::CUBE);
	}

	if (pKey->GetKeyState(Keyboard::KEY_C) && keyPressed)
	{
		keyPressed = false;
		GameObjectMan::DeleteTexture(Texture::Name::ROCKS);
	}


	//Camera 1
	if (pKey->GetKeyState(Keyboard::KEY_1))
	{
		if (CameraMan::CameraExists(1))
		{
			pCam = CameraMan::SetCamera(1);
		}
		else
		{
			//Camera does not exist, make a new one
			pCam = CameraMan::SetCamera(1);
			pCam->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
			pCam->setPerspective(50.0f, float(pCam->getScreenWidth()) / float(pCam->getScreenHeight()), 0.10f, 1000.0f);
			pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 4.5f));
			pCam->updateCamera();			
		}
	}

	//Camera 2
	if (pKey->GetKeyState(Keyboard::KEY_2))
	{
		if (CameraMan::CameraExists(2))
		{
			pCam = CameraMan::SetCamera(2);
		}
		else
		{
			//Camera does not exist, make a new one
			pCam = CameraMan::SetCamera(2);
			pCam->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
			pCam->setPerspective(50.0f, float(pCam->getScreenWidth()) / float(pCam->getScreenHeight()), 0.10f, 1000.0f);
			pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 4.5f));
			pCam->updateCamera();
		}
	}

	//Camera 3
	if (pKey->GetKeyState(Keyboard::KEY_3))
	{
		if (CameraMan::CameraExists(3))
		{
			pCam = CameraMan::SetCamera(3);
		}
		else
		{
			//Camera does not exist, make a new one
			pCam = CameraMan::SetCamera(3);
			pCam->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
			pCam->setPerspective(50.0f, float(pCam->getScreenWidth()) / float(pCam->getScreenHeight()), 0.10f, 1000.0f);
			pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 4.5f));
			pCam->updateCamera();			
		}
	}

	//Camera 4
	if (pKey->GetKeyState(Keyboard::KEY_4))
	{
		if (CameraMan::CameraExists(4))
		{
			pCam = CameraMan::SetCamera(4);
		}
		else
		{
			//Camera does not exist, make a new one
			pCam = CameraMan::SetCamera(4);
			pCam->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
			pCam->setPerspective(50.0f, float(pCam->getScreenWidth()) / float(pCam->getScreenHeight()), 0.10f, 1000.0f);
			pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 4.5f));
			pCam->updateCamera();
		}
	}
	
	//Camera 5
	if (pKey->GetKeyState(Keyboard::KEY_5))
	{
		if (CameraMan::CameraExists(5))
		{
			pCam = CameraMan::SetCamera(5);
		}
		else
		{
			//Camera does not exist, make a new one
			pCam = CameraMan::SetCamera(5);
			pCam->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
			pCam->setPerspective(50.0f, float(pCam->getScreenWidth()) / float(pCam->getScreenHeight()), 0.10f, 1000.0f);
			pCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, 0.0f), Vect(0.0f, 0.0f, 4.5f));
			pCam->updateCamera();
		}
	}

	//Delete the current camera, go to next
	if (pKey->GetKeyState(Keyboard::KEY_TAB) && keyPressed)
	{
		pCam = CameraMan::RemoveCamera(pCam);
		keyPressed = false;
	}

	if (pKey->GetKeyState(Keyboard::KEY_Z))
	{
		// Reset	
		obj.set(0, 0, 0);
		pCam->SetHelper(Orig_up, Orig_tar, Orig_pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_I))
	{

		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//	tar = obj;

		pos = pos + 0.03f * forwardNorm;
		//tar = tar + 0.03f * forwardNorm;
		up = up + 0.03f * forwardNorm;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_O))
	{

		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//tar = obj;

		pos = pos - 0.03f * forwardNorm;
		up = up - 0.03f * forwardNorm;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_P))
	{
		Vect newObj(-2, 0, 0);
		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);


		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

		Vect delta = newObj - obj;

		up += delta;
		tar += delta;
		pos += delta;

		obj = newObj;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_R))
	{
		Vect newObj(2, 0, 0);
		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);


		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		
		Vect delta = newObj - obj;

		up += delta;
		tar += delta;
		pos += delta;

		obj = newObj;
		
		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_G))
	{

		Vect newObj(0, 0, 0);
		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		Vect delta = newObj - obj;

		up += delta;
		tar += delta;
		pos += delta;

		obj = newObj;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_ARROW_RIGHT))
	{

		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
	//	tar = obj;

		Matrix Trans(Matrix::Trans::XYZ, tar);
		Matrix NegTrans(Matrix::Trans::XYZ, -tar);

		Matrix Rot;
		Rot.set(Matrix::Rot::AxisAngle, upNorm, +0.03f);

		Matrix M = NegTrans * Rot * Trans;

		up = up * M;
		pos = pos * M;
		tar = tar * M;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_ARROW_LEFT))
	{

		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

	//	tar = obj;

		Matrix Trans(Matrix::Trans::XYZ, tar);
		Matrix NegTrans(Matrix::Trans::XYZ, -tar);

		Matrix Rot;
		Rot.set(Matrix::Rot::AxisAngle, upNorm, -0.03f);

		Matrix M = NegTrans * Rot * Trans;

		up = up * M;
		pos = pos * M;
		tar = tar * M;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_ARROW_DOWN))
	{
		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

	//	tar = obj;
	

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

		Matrix Trans(Matrix::Trans::XYZ, tar);
		Matrix NegTrans(Matrix::Trans::XYZ, -tar);
		Matrix Rot;
		Rot.set(Matrix::Rot::AxisAngle, rightNorm, 0.03f);

		Matrix M = NegTrans * Rot * Trans;

		up = up * M;
		pos = pos * M;
		tar = tar * M;

		pCam->SetHelper(up, tar, pos);
	}

	if (pKey->GetKeyState(Keyboard::KEY_ARROW_UP))
	{
		Vect pos;
		Vect tar;
		Vect up;
		Vect upNorm;
		Vect forwardNorm;
		Vect rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//tar = obj;

		Matrix Trans(Matrix::Trans::XYZ, tar);
		Matrix NegTrans(Matrix::Trans::XYZ, -tar);
		Matrix Rot;
		Rot.set(Matrix::Rot::AxisAngle, rightNorm, -0.03f);

		Matrix M = NegTrans * Rot * Trans;

		up = up * M;
		pos = pos * M;
		tar = tar * M;

		pCam->SetHelper(up, tar, pos);
	}


	// Needs to be updated once a frame
	pCam->updateCamera();

	// Update the game objects
	GameObjectMan::Update(currentTime);
}


//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	GameObjectMan::Draw();
}


//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	// Todo fix this - verify OpenGL removal

	//  glDeleteVertexArrays(1, &vao);
	//  glDeleteProgram(pShaderObject->programObject);
	//  glDeleteBuffers(1, &buffer);

	InputMan::Destroy();
	GameObjectMan::Destroy();
	MeshNodeMan::Destroy();
	ShaderMan::Destroy();
	CameraMan::Destroy();
	TextureMan::Destroy();
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
#ifdef _DEBUG
	const GLfloat color[] = { 0.7f, 0.8f, 0.7f, 1.0f };
#else
	const GLfloat color[] = { 0.95f, 0.7f, 0.7f, 1.0f };
#endif
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, color);
	glClearBufferfv(GL_DEPTH, 0, &one);
}


// --- End of File ---
