//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Texture.h"
#include "StringThis.h"

Texture::Texture()
	: name(Name::NOT_INITIALIZED),
	textureID(0),
	minFilter(GL_LINEAR),
	magFilter(GL_LINEAR),
	wrapMode(GL_CLAMP_TO_EDGE)
{
	memset(this->assetName, 0, TEXTURE_ASSET_NAME_SIZE);
}


Texture::~Texture()
{

}


void Texture::Set(const char *const _assetName,
	Name _name,
	GLuint _TextureID,
	GLenum _minFilter,
	GLenum _magFilter,
	GLenum _wrapMode)
{
	memcpy(this->assetName, _assetName, TEXTURE_ASSET_NAME_SIZE - 1);
	this->name = _name;
	this->magFilter = _magFilter;
	this->minFilter = _minFilter;
	this->wrapMode = _wrapMode;
	this->textureID = _TextureID;
}

bool Texture::Compare(DLink *pTarget)
{
	// This is used in ManBase.Find() 
	assert(pTarget != nullptr);

	Texture *pDataB = (Texture *)pTarget;

	bool status = false;

	if (this->name == pDataB->name)
	{
		status = true;
	}

	return status;
}

void Texture::Dump()
{
	Trace::out("      Texture(%p)\n", this);

	// Data:
	Trace::out("      Name: %s \n", StringMe(this->name));
	//Trace::out("         x: %d \n", this->x);

	DLink::Dump();
}

void Texture::Wash()
{

}

char *Texture::GetName()
{
	// todo - Hack understand why is this needed for print and fix...
	static char pTmp[128];
	strcpy_s(pTmp, 128, StringMe(this->name));
	return pTmp;
}

// --- End of File ---