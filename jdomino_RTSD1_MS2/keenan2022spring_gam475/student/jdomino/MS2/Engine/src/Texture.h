//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef TEXTURE_H
#define TEXTURE_H

#include "sb7.h"
#include "DLink.h"

class Texture : public DLink
{
public:
	static const unsigned int TEXTURE_ASSET_NAME_SIZE = 64;

public:
	enum class Name
	{
		STONES,
		RED_BRICK,
		DUCKWEED,
		ROCKS,
		KT_STONE_1,
		KT_STONE_2,
		NOT_INITIALIZED
	};

public:
	Texture();
	virtual ~Texture() override;

	void Set(const char *const _assetName,
		Name _name,
		GLuint _TextureID,
		GLenum minFilter,
		GLenum magFilter,
		GLenum wrapMode);


	virtual char *GetName() override;
	virtual bool Compare(DLink *pTarget) override;
	virtual void Dump() override;
	virtual void Wash() override;

	int TextureCount = 0;

private:
	char assetName[TEXTURE_ASSET_NAME_SIZE];

public:
	Name name;
	GLuint textureID;
	GLenum minFilter;
	GLenum magFilter;
	GLenum wrapMode;
};

#endif

