//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef TEXTURE_MAN_H
#define TEXTURE_MAN_H 

#include "ManBase.h"
#include "Texture.h"

class TextureMan : public ManBase
{
	//----------------------------------------------------------------------
	// Static Methods
	//----------------------------------------------------------------------
public:
	static void Create(int reserveNum = 0, int reserveGrow = 1);
	static void Destroy();
	static Texture *Add(const char *const pName, Texture::Name name);
	static Texture *Find(Texture::Name name);
	static GLuint FindID(Texture::Name name);
	static void IncrementTextureCount(Texture::Name name);
	static void DecrementTextureCount(Texture::Name name);
	static void Remove(Texture *pNode);
	static void Dump();
	static void DeleteTexture(Texture::Name name);
	static Texture* FindNext(Texture::Name _name);

	//----------------------------------------------------------------------
	// Private methods
	//----------------------------------------------------------------------
private:
	static TextureMan *privGetInstance();

	~TextureMan();
	TextureMan(int reserveNum, int reserveGrow);

	void privLoadTexture(const char *const pName, GLuint *&textureID);
	bool privLoadTGATexture(const char *szFileName, GLint minFilter, GLint magFilter, GLint wrapMode);
	GLbyte *gltReadTGABits(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat);

	//----------------------------------------------------------------------
	// Override Abstract methods
	//----------------------------------------------------------------------
protected:
	DLink *derivedCreateNode() override;


	//----------------------------------------------------------------------
	// Data: unique data for this manager 
	//----------------------------------------------------------------------
private:
	Texture *poNodeCompare;
	static TextureMan *posInstance;

};


#endif