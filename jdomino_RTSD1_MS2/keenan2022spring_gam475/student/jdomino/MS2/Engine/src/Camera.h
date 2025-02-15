//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef CAMERA_H
#define CAMERA_H

#include "Matrix.h"

namespace Azul
{
	class Camera final : public Align16
	{

	public:
		// Default constructor
		Camera();
		Camera(const Camera &) = delete;
		Camera &operator = (const Camera &) = delete;
		~Camera();

		// Setup on single camera
		void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
		void setViewport(const int inX, const int inY, const int width, const int height);
		void setOrientAndPosition(const Vect &Up_vect, const Vect &inLookAt_pt, const Vect &pos_pt);

		// update camera system
		void updateCamera(void);

		// Get the matrices for rendering
		Matrix &getViewMatrix();
		Matrix &getProjMatrix();

		// accessors
		void getPos(Vect &outPos) const;
		void getDir(Vect &outDir) const;
		void getUp(Vect &outUp) const;
		void getLookAt(Vect &outLookAt) const;
		void getRight(Vect &outRight) const;

		int getScreenWidth() const;
		int getScreenHeight() const;

		// Why no SETS?  Pos,Dir,Up,LookAt, Right
		//   They have to be adjust together in setOrientAndPosition()

		void getFieldOfView(float &Value) const;
		void setFieldOfView(const float Value);

		void getNearDist(float &Value) const;
		void setNearDist(const float Value);

		// helper functions
		void GetHelper(Vect& up, Vect& tar, Vect& pos, Vect& upNorm, Vect& forwardNorm, Vect& rightNorm);
		void SetHelper(Vect& up, Vect& tar, Vect& pos);

		void getNearTopLeft(Vect &vOut) const;
		void getNearTopRight(Vect &vOut) const;
		void getNearBottomLeft(Vect &vOut) const;
		void getNearBottomRight(Vect &vOut) const;
		void getFarTopLeft(Vect &vOut) const;
		void getFarTopRight(Vect &vOut) const;
		void getFarBottomLeft(Vect &vOut) const;
		void getFarBottomRight(Vect &vOut) const;


	private:  // methods should never be public
		void privSetViewState(void);
		void privCalcPlaneHeightWidth(void);
		void privCalcFrustumVerts(void);
		void privCalcFrustumCollisionNormals(void);
		void privUpdateProjectionMatrix(void);
		void privUpdateViewMatrix(void);


	private:  // data  (Keep it private)

		// -------------------------------------------------------
		// 16-bit aligned data below this point:
		// -------------------------------------------------------

		// Projection Matrix
		Matrix	projMatrix;
		Matrix	viewMatrix;

		// camera unit vectors (up, dir, right)
	
		Vect	vDir;
		Vect	vRight;  // derived by up and dir



		Vect	vUp;      // Up vector
		Vect	vPos;     // pos pt
		Vect	vLookAt;  // target pt



		// world space coords for viewing frustum
		Vect	nearTopLeft;
		Vect	nearTopRight;
		Vect	nearBottomLeft;

		Vect	nearBottomRight;
		Vect	farTopLeft;
		Vect	farTopRight;
		Vect	farBottomLeft;

		Vect	farBottomRight;

		// Normals of the frustum
		Vect	frontNorm;
		Vect	backNorm;
		Vect	rightNorm;

		Vect	leftNorm;
		Vect	topNorm;
		Vect	bottomNorm;

		// -------------------------------------------------------
		// unaligned data below this point:
		// -------------------------------------------------------

		// Define the frustum inputs
		float	nearDist;
		float	farDist;
		float	fovy;
		float	aspectRatio;

		// Screen size in world space
		float	near_height;
		float	near_width;
		float	far_height;
		float	far_width;

		// viewports
		int		viewport_x;
		int		viewport_y;
		int		viewport_width;
		int		viewport_height;

	};

}

#endif

// --- End of File ---
