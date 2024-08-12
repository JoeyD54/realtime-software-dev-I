//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "DiamondMesh.h"
#include "File.h"
#include "MeshFileHdr.h"

using namespace Azul;

#define WRITE_DATA_TO_FILE 0 //reading from azul

#if WRITE_DATA_TO_FILE

Tri_index trisDiamondList[] =
{
	{ 0, 1, 4 },
	{ 0, 2, 1 },
	{ 0, 3, 2 },
	{ 0, 4, 3 },
	{ 5, 4, 1 },
	{ 5, 1, 2 },
	{ 5, 2, 3 },
	{ 5, 3, 4 },
};

Vert_xyz diamondData_XYZ[] =
{
	{  0.000f,  0.000f,  0.50f },
	{ -0.125f, -0.125f,  0.00f },
	{  0.125f, -0.125f,  0.00f },
	{  0.125f,  0.125f,  0.00f },
	{ -0.125f,  0.125f,  0.00f },
	{  0.000f,  0.000f, -0.50f }
};

Vert_uv diamondData_UV[] =
{
	{ 0.5f, 0.5f },
	{ 0.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 0.0f },
	{ 0.0f, 0.0f },
	{ 0.5f, 0.5f }
};

Vert_NxNyNz diamondData_NxNyNz[] =
{
	{  0.0f,  0.0f,  1.0f },
	{ -1.0f, -1.0f, -0.0f },
	{  1.0f, -1.0f, -0.0f },
	{  1.0f,  1.0f, -0.0f },
	{ -1.0f,  1.0f, -0.0f },
	{  0.0f,  0.0f, -1.0f },
};

#define DIAMOND_DATA_NUM_VERTS (sizeof(diamondData_XYZ)/sizeof(Vert_xyz))
#define DIAMOND_TRILIST_NUM_TRIANGLES (sizeof(trisDiamondList)/sizeof(Tri_index))

#endif

void DiamondMesh::privCreateVAO(const char* const pMeshFileName)
{
	// future proofing it for a file
	assert(pMeshFileName);
	AZUL_UNUSED_VAR(pMeshFileName);

	// Create a VAO
	glGenVertexArrays(1, &this->vao);
	assert(this->vao != 0);
	glBindVertexArray(this->vao);   // <--- Active

	// Create a VBO
	glGenBuffers(1, &this->vbo_verts);
	assert(this->vbo_verts != 0);

	glGenBuffers(1, &this->vbo_texts);
	assert(this->vbo_texts != 0);

	glGenBuffers(1, &this->vbo_norms);
	assert(this->vbo_norms != 0);

	glGenBuffers(1, &this->vbo_index);
	assert(this->vbo_index != 0);

	// File stuff
	File::Handle fh;
	File::Error  ferror;

	// create a header
	MeshFileHdr meshHdr;

	// ----------------------------------------------
	// READ the data from the file ONLY
	// ----------------------------------------------

	ferror = File::Open(fh, pMeshFileName, File::Mode::READ);
	assert(ferror == File::Error::SUCCESS);

	// Read the Hdr
	ferror = File::Read(fh, &meshHdr, sizeof(MeshFileHdr));
	assert(ferror == File::Error::SUCCESS);

	// Using the hdr, allocate the space for the buffers
	this->numVerts = meshHdr.numVerts;
	this->numTris = meshHdr.numTriList;

	// allocate buffers
	Vert_xyz* pData_xyz = new Vert_xyz[(unsigned int)meshHdr.numVerts];
	assert(pData_xyz);

	Vert_uv* pData_uv = new Vert_uv[(unsigned int)meshHdr.numVerts];
	assert(pData_uv);

	Vert_NxNyNz* pData_NxNyNz = new Vert_NxNyNz[(unsigned int)meshHdr.numVerts];
	assert(pData_NxNyNz);

	Tri_index* pTriList = new Tri_index[(unsigned int)meshHdr.numTriList];
	assert(pTriList);

	// Read verts
	ferror = File::Seek(fh, File::Position::BEGIN, (int)meshHdr.vertBufferOffset);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Read(fh, pData_xyz, sizeof(Vert_xyz) * this->numVerts);
	assert(ferror == File::Error::SUCCESS);


	ferror = File::Seek(fh, File::Position::BEGIN, (int)meshHdr.textsBufferOffset);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Read(fh, pData_uv, sizeof(Vert_uv) * this->numVerts);
	assert(ferror == File::Error::SUCCESS);

	ferror = File::Seek(fh, File::Position::BEGIN, (int)meshHdr.normsBufferOffset);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Read(fh, pData_NxNyNz, sizeof(Vert_uv) * this->numVerts);
	assert(ferror == File::Error::SUCCESS);

	// Read trilist
	ferror = File::Seek(fh, File::Position::BEGIN, (int)meshHdr.triListBufferOffset);
	assert(ferror == File::Error::SUCCESS);
	ferror = File::Read(fh, pTriList, sizeof(Tri_index) * this->numTris);
	assert(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	assert(ferror == File::Error::SUCCESS);

	// --------------------------------------------------------------
	// Data is in RAM... Configure and send data to GPU
	// --------------------------------------------------------------

	// Load the verts data: ---------------------------------------------------------
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_verts);

	// load the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_xyz) * this->numVerts), pData_xyz, GL_STATIC_DRAW);

	// Vert data is location: 0  (used in vertex shader)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_xyz), 0);
	glEnableVertexAttribArray(0);

	// Load the texts data: ---------------------------------------------------------

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_texts);
	// load the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_uv) * this->numVerts), pData_uv, GL_STATIC_DRAW);

	// Texture data is location: 1  (used in vertex shader)
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vert_uv), 0);
	glEnableVertexAttribArray(1);

	// Load the norms data: ---------------------------------------------------------

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_norms);

	// load the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Vert_NxNyNz) * this->numVerts), pData_NxNyNz, GL_STATIC_DRAW);

	// normals data in location 2 (used in vertex shader
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vert_NxNyNz), 0);
	glEnableVertexAttribArray(2);

	// Load the index data: ---------------------------------------------------------

	// Bind our 2nd VBO as being the active buffer and storing index ) 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_index);

	// Copy the index data to our buffer 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(sizeof(Tri_index) * this->numTris), pTriList, GL_STATIC_DRAW);


	delete[] pData_xyz;
	delete[] pData_uv;
	delete[] pData_NxNyNz;
	delete[] pTriList;

}

DiamondMesh::DiamondMesh(const char* const pMeshFileName)
	: Mesh()
{
	assert(pMeshFileName);
	this->privCreateVAO(pMeshFileName);
}

DiamondMesh::~DiamondMesh()
{
	// remove anything dynamic here
}


// --- End of File ---
