//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

#include "Vect.h"
#include "Debug.h"

namespace Azul
{

	class Matrix final : public Align16
	{
	public:
		enum class Special
		{
			Zero,
			Identity
		};

		enum class Rot1
		{
			X,
			Y,
			Z
		};

		enum class Trans
		{
			XYZ
		};

		enum class Scale
		{
			XYZ
		};

		enum class Rot
		{
			AxisAngle,
		};

		enum class Orient
		{
			LocalToWorld,
			WorldToLocal
		};

		enum class Row
		{
			i0,
			i1,
			i2,
			i3
		};

		enum class Rot3
		{
			XYZ
			// future combos... here
		};

	public:

		// Do your magic here
		//big 4
		Matrix();
		Matrix(const Matrix& inMatrix);
		//Specialized Constructor
		Matrix(Vect vA, Vect vB, Vect vC, Vect vD);
		const Matrix& operator = (const Matrix& inMatrix);
		~Matrix();

		//Transpose Constructors
		Matrix T();
		Matrix getT();

		//Special Constructor
		Matrix(Matrix::Special special);

		//Trans Constructor
		Matrix(Matrix::Trans tran, float in1, float in2, float in3);
		Matrix(Matrix::Trans tran, Vect inVect);

		//Scale Constructor
		Matrix(Matrix::Scale scale, float in1, float in2, float in3);
		Matrix(Matrix::Scale scale, Vect inVect);

		//Rot Constructor
		Matrix(Matrix::Rot rot);
		Matrix(Matrix::Rot rot, Vect& inVect, float inFloat);
		Matrix(Matrix::Rot1 rot, float inFloat);
		Matrix(Matrix::Rot3 rot, float inFloatX, float inFloatY, float inFloatZ);


		//M*M
		Matrix operator* (Matrix inMatrix);
		Matrix operator *= (Matrix inMatrix);

		//M+M
		Matrix operator+ (Matrix inMatrix);
		Matrix operator+=(Matrix inMatrix);

		//M-M
		Matrix operator- (Matrix inMatrix);
		Matrix operator-= (Matrix inMatrix);

		//Unary Plus
		Matrix operator+();

		//Unary Minus
		Matrix operator-();

		//Scale
		friend Matrix operator* (float inFloat, Matrix inMatrix);
		friend Matrix operator* (Matrix inMatrix, float inFloat);
		friend Matrix operator/ (Matrix inMatrix, float inFloat);
		Matrix operator*=(float inFloat);

		void SetMs(Vect& inVect);

		//Special Set
		void set(Matrix::Special type);
		
		//Trans Set
		void set(Matrix::Trans type, float in1, float in2, float in3);
		void set(Matrix::Trans type, Vect inVect);

		//Scale Set
		void set(Matrix::Scale type, float in1, float in2, float in3);
		void set(Matrix::Scale type, Vect inVect);

		//Row Set
		void set(Matrix::Row row, Vect inVect);

		//Row Get
		Vect get(Matrix::Row row);

		//Rot Set
		void set(Matrix::Rot rot, Vect& inVect, float inFloat);
		void set(Matrix::Rot1 rot, float inFloat);
		void set(Matrix::Rot3 rot, float in1, float in2, float in3);

		//Orient Set
		void set(Matrix::Orient orientType, Vect inVect1, Vect inVect2);

		//Determinant
		float det();

		//Inverse
		Matrix inv();

		//Orient
		Matrix(Matrix::Orient orientType, Vect inVect1, Vect inVect2);

		void privSetRotOrient(Vect& v1, Vect& v2);
		void privSetRotInverseOrient();

		//Vect Set
		void set(Vect inVect1, Vect inVect2, Vect inVect3, Vect inVect4);

		//M == M
		bool isEqual(Matrix inMatrix);

		//Identity bool
		bool isIdentity(float tolerance = 0);

		//Rotation bool
		bool isRotation();

		//Inverse Matrix
		Matrix getInv();
		Matrix getAdjoint();
		float subMDet(float inX1, float inX2, float inX3, float inY1, float inY2, float inY3, float inZ1, float inZ2, float inZ3);



		Vect& GetV0();
		Vect& GetV1();
		Vect& GetV2();
		Vect& GetV3();

		//Matrix GETs
		const float m0() const;
		const float m1() const;
		const float m2() const;
		const float m3() const;
		const float m4() const;
		const float m5() const;
		const float m6() const;
		const float m7() const;
		const float m8() const;
		const float m9() const;
		const float m10() const;
		const float m11() const;
		const float m12() const;
		const float m13() const;
		const float m14() const;
		const float m15() const;

		float& m0();
		float& m1();
		float& m2();
		float& m3();
		float& m4();
		float& m5();
		float& m6();
		float& m7();
		float& m8();
		float& m9();
		float& m10();
		float& m11();
		float& m12();
		float& m13();
		float& m14();
		float& m15();

		const float operator[](m0_enum) const;
		const float operator[](m1_enum) const;
		const float operator[](m2_enum) const;
		const float operator[](m3_enum) const;
		const float operator[](m4_enum) const;
		const float operator[](m5_enum) const;
		const float operator[](m6_enum) const;
		const float operator[](m7_enum) const;
		const float operator[](m8_enum) const;
		const float operator[](m9_enum) const;
		const float operator[](m10_enum) const;
		const float operator[](m11_enum) const;
		const float operator[](m12_enum) const;
		const float operator[](m13_enum) const;
		const float operator[](m14_enum) const;
		const float operator[](m15_enum) const;

		float& operator[](m0_enum);
		float& operator[](m1_enum);
		float& operator[](m2_enum);
		float& operator[](m3_enum);
		float& operator[](m4_enum);
		float& operator[](m5_enum);
		float& operator[](m6_enum);
		float& operator[](m7_enum);
		float& operator[](m8_enum);
		float& operator[](m9_enum);
		float& operator[](m10_enum);
		float& operator[](m11_enum);
		float& operator[](m12_enum);
		float& operator[](m13_enum);
		float& operator[](m14_enum);
		float& operator[](m15_enum);


		// For printing
		friend void Debug::Print(const char *pName, const Matrix &r);

	private:

		union
		{

			struct
			{
				Vect _rows[4];
			};


			struct
			{
				Vect _v0;
				Vect _v1;
				Vect _v2;
				Vect _v3;
			};

			struct
			{
				float _m0;
				float _m1;
				float _m2;
				float _m3;
				float _m4;
				float _m5;
				float _m6;
				float _m7;
				float _m8;
				float _m9;
				float _m10;
				float _m11;
				float _m12;
				float _m13;
				float _m14;
				float _m15;
			};
		};
	};
}

#endif

//--- End of File ---
