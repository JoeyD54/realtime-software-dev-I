//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_VECT_H
#define ENGINE_MATH_VECT_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Constants.h"
#include "Debug.h"
#include "VectProxy.h"

// This file assumes Framework.h is included in executable for Align16

namespace Azul
{
	// forward declare
	class Matrix;

	class Vect final : public Align16
	{
	public:

	// Do your magic here
	// 
	// 
	
		//Big 4
		Vect();
		Vect(const Vect& inVect);
		Vect(const float x, const float y, const float z, const float w = 1);
		const Vect operator = (const Vect& inVect);
		~Vect();

		void set(float x, float y, float z, float w = 1);
		void set(Vect inVect);

		// Add
		Vect operator + (Vect inVect);
		Vect operator + (float inFloat);
		friend Vect operator + (float inFloat, Vect inVect);

		// Subtract
		Vect operator - (Vect inVect);
		Vect operator - (float inFloat);
		friend Vect operator - (float inFloat, Vect inVect);
		
		// Multiply
		Vect operator * (Vect inVect);
		Vect operator * (float inFloat);
		friend Vect operator * (float inFloat, Vect inVect);
		Vect operator *=(float inFloat);

		Vect operator += (const Vect inVect);
		Vect operator -= (const Vect inVect);

		
		//Unary Minus Overload
		Vect operator-();

		//Unary Plus Overload
		Vect operator+();


		//Cross Product
		Vect cross(Vect inVect);

		//Dot Product
		float dot(Vect inVect);

		//Angle
		float getAngle(Vect inVect);

		//Normalized Vector
		Vect norm();
		Vect getNorm();
		//float mag();
		VectProxy mag();

		

		//friend bool operator==(float inFloat1, float inFloat2);

		//Vect * Matrix operator overloader
		friend Vect& operator *(Vect inVect, Matrix inMatrix);

		Vect operator *=(Matrix inMatrix);

		//[] overloads GET
		const float operator[](const x_enum inX) const;
		const float operator[](const y_enum inY) const;
		const float operator[](const z_enum inZ) const;
		const float operator[](const w_enum inW) const;

		//[] overloads SET
		float& operator[](const x_enum);
		float& operator[](const y_enum);
		float& operator[](const z_enum);
		float& operator[](const w_enum);


		//XYZW GET
		const float& x() const;
		const float& y() const;
		const float& z() const;
		const float& w() const;

		//XYZW SET
		float& x();
		float& y();
		float& z();
		float& w();

		bool isEqual(Vect inVect, float epsilon = 0);
		bool isZero(float epsilon = 0);

		// 
		// for printing
		friend void Debug::Print(const char *pName, const Vect &r);

	private:

		union
		{
			__m128	_mv;

			// anonymous struct
			struct
			{
				float _vx;
				float _vy;
				float _vz;
				float _vw;
			};
		};
	};
}

#endif

//--- End of File ---
