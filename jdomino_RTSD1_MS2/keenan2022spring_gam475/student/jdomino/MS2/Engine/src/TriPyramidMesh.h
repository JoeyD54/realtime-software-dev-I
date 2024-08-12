#ifndef TRIPYRAMID_MESH_H
#define TRIPYRAMID_MESH_H

#include "Mesh.h"

class TriPyramidMesh : public Mesh
{
public:
    //PyramidMesh() = default;
    TriPyramidMesh(const char* const pMeshFileName);

    TriPyramidMesh() = delete;
    TriPyramidMesh(const TriPyramidMesh&) = delete;
    TriPyramidMesh& operator = (TriPyramidMesh&) = delete;
    virtual ~TriPyramidMesh();

private:
    virtual void privCreateVAO(const char* const pMeshFileName) override;

    // Data

};

#endif