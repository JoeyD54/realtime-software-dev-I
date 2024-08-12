//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "CDM.h"

namespace Azul
{
	//Construct
	Vect::Vect()
	{
		this->_vx = 0;
		this->_vy= 0;
		this->_vz= 0;
		this->_vw= 1;
	}

	//Copy Constructor
	Vect::Vect(const Vect& inVect)
	{
		this->_mv = inVect._mv;
		this->_vx = inVect._vx;
		this->_vy = inVect._vy;
		this->_vz = inVect._vz;
		this->_vw = inVect._vw;

		//Matrix::SetMs(this);
	}

	//Specialized Constructor
	Vect::Vect(const float x, const float y, const float z, const float w)
	{		
		this->_vx = x;
		this->_vy = y;
		this->_vz = z;
		this->_vw = w;
	}

	//Destructor
	Vect::~Vect()
	{
	}

	void Vect::set(float x, float y, float z, float w)
	{
		this->_vx = x;
		this->_vy = y;
		this->_vz = z;
		this->_vw = w;
	}

	void Vect::set(Vect inVect)
	{
		this->_mv = inVect._mv;
		this->_vx = inVect._vx;
		this->_vy = inVect._vy;
		this->_vz = inVect._vz;
	}

	//Assignment Operator
	const Vect Vect::operator=(const Vect& inVect)
	{
		this->_mv = inVect._mv;
		this->_vx = inVect._vx;
		this->_vy = inVect._vy;
		this->_vz = inVect._vz;

		return *this;
	}

	// + Operator Overloader
	Vect Vect::operator+(Vect inVect)
	{
		Vect newVect;

		newVect._vx = this->_vx + inVect._vx;
		newVect._vy = this->_vy + inVect._vy;
		newVect._vz = this->_vz + inVect._vz;

		return newVect;
	}

	// - Operator Overloader
	Vect Vect::operator-(Vect inVect)
	{
		Vect newVect;

		newVect._vx = this->_vx - inVect._vx;
		newVect._vy = this->_vy - inVect._vy;
		newVect._vz = this->_vz - inVect._vz;

		return newVect;
	}

	// Vect - Float Operator Overloader
	Vect Vect::operator-(float inFloat)
	{
		Vect newVect;

		newVect._vx = this->_vx - inFloat;
		newVect._vy = this->_vy - inFloat;
		newVect._vz = this->_vz - inFloat;

		return newVect;
	}

	// Vect + Float Operator Overloader
	Vect Vect::operator+(float inFloat)
	{
		Vect newVect;

		newVect._vx = this->_vx + inFloat;
		newVect._vy = this->_vy + inFloat;
		newVect._vz = this->_vz + inFloat;

		return newVect;
	}

	// Float + Vect Operator Overloader
	Vect operator+(float inFloat, Vect inVect)
	{
		Vect newVect;

		newVect._vx = inFloat + inVect._vx;
		newVect._vy = inFloat + inVect._vy;
		newVect._vz = inFloat + inVect._vz;

		return newVect;
	}

	// Float - Vect Operator Overloader
	Vect operator-(float inFloat, Vect inVect)
	{
		Vect newVect;

		newVect._vx = inFloat - inVect._vx;
		newVect._vy = inFloat - inVect._vy;
		newVect._vz = inFloat - inVect._vz;

		return newVect;
	}

	// Vect * Vect Operator Overloader
	Vect Vect::operator*(Vect inVect)
	{
		Vect newVect;

		newVect._vx = this->_vx * inVect._vx;
		newVect._vy = this->_vy * inVect._vy;
		newVect._vz = this->_vz * inVect._vz;

		return newVect;
	}

	// Vect * Float Operator Overloader
	Vect Vect::operator*(float inFloat)
	{
		Vect newVect;

		newVect._vx = this->_vx * inFloat;
		newVect._vy = this->_vy * inFloat;
		newVect._vz = this->_vz * inFloat;

		return newVect;
	}

	Vect Vect::operator*=(float inFloat)
	{
		this->_vx *= inFloat;
		this->_vy *= inFloat;
		this->_vz *= inFloat;
		this->_vw = 1.0f;

		return *this;
	}

	Vect Vect::operator+=(const Vect inVect)
	{
		this->_vx += inVect._vx;
		this->_vy += inVect._vy;
		this->_vz += inVect._vz;
		this->_vw = 1;

		return *this;
	}

	Vect Vect::operator-=(const Vect inVect)
	{
		this->_vx -= inVect._vx;
		this->_vy -= inVect._vy;
		this->_vz -= inVect._vz;
		this->_vw = 1;

		return *this;
	}

	Vect Vect::operator-()
	{
		Vect newVect;

		newVect._vx = -this->_vx;
		newVect._vy = -this->_vy;
		newVect._vz = -this->_vz;

		return newVect;
	}

	Vect Vect::operator+()
	{
		Vect newVect;

		newVect._vx = this->_vx;
		newVect._vy = this->_vy;
		newVect._vz = this->_vz;

		return newVect;
	}

	// Float * Vect Operator Overloader
	Vect operator*(float inFloat, Vect inVect)
	{
		Vect newVect;

		newVect._vx = inFloat * inVect._vx;
		newVect._vy = inFloat * inVect._vy;
		newVect._vz = inFloat * inVect._vz;

		return newVect;
	}

	//Cross Product
	Vect Vect::cross(Vect inVect)
	{
		Vect newVect;

		newVect._vx = this->_vy * inVect._vz - this->_vz * inVect._vy;
		newVect._vy = -(this->_vx * inVect._vz - this->_vz * inVect._vx);
		newVect._vz = this->_vx * inVect._vy - this->_vy * inVect._vx;

		return newVect;
	}

	//Dot Product
	float Vect::dot(Vect inVect)
	{
		float dotProduct;

		dotProduct = this->_vx * inVect._vx + this->_vy * inVect._vy + this->_vz * inVect._vz;

		return dotProduct;
	}

	float Vect::getAngle(Vect inVect)
	{
		return acos(this->dot(inVect) / (this->mag() * inVect.mag()));
	}

	Vect Vect::norm()
	{
		float mag;

		mag = CDM::sqrt(this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz);

		this->_vx /= mag;
		this->_vy /= mag;
		this->_vz /= mag;

		return *this;
	}

	Vect Vect::getNorm()
	{
		Vect newVector = *this;
		return newVector.norm();
	}

	/*VectProxy Vect::mag()
	{
		return VectProxy();
	}*/

	//float Vect::mag()
	//{
	//	float val = this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz;
	//	return CDM::sqrt(val);
	//}

	VectProxy Vect::mag()
	{
		float val = this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz;
		return VectProxy(this->_vx, this->_vy, this->_vz);
		//return 1;
	}



	//Vect * Matrix Operator Overloader
	Vect& operator*(Vect inVect, Matrix inMatrix)
	{
		Vect newVector;

		Vect v0 = inMatrix.GetV0();
		Vect v1 = inMatrix.GetV1();
		Vect v2 = inMatrix.GetV2();
		Vect v3 = inMatrix.GetV3();

		newVector._vx = inVect._vx * v0._vx + inVect._vy * v1._vx + inVect._vz * v2._vx + inVect._vw * v3._vx;
		newVector._vy = inVect._vx * v0._vy + inVect._vy * v1._vy + inVect._vz * v2._vy + inVect._vw * v3._vy;
		newVector._vz = inVect._vx * v0._vz + inVect._vy * v1._vz + inVect._vz * v2._vz + inVect._vw * v3._vz;
		newVector._vw = inVect._vx * v0._vw + inVect._vy * v1._vw + inVect._vz * v2._vw + inVect._vw * v3._vw;

		return newVector;
	}

	Vect Vect::operator*=(Matrix inMatrix)
	{
		Vect newVect;

		Vect v0 = inMatrix.GetV0();
		Vect v1 = inMatrix.GetV1();
		Vect v2 = inMatrix.GetV2();
		Vect v3 = inMatrix.GetV3();

		newVect._vx = this->_vx * v0._vx + this->_vy * v1._vx + this->_vz * v2._vx + this->_vw * v3._vx;
		newVect._vy = this->_vx * v0._vy + this->_vy * v1._vy + this->_vz * v2._vy + this->_vw * v3._vy;
		newVect._vz = this->_vx * v0._vz + this->_vy * v1._vz + this->_vz * v2._vz + this->_vw * v3._vz;
		newVect._vw = this->_vx * v0._vw + this->_vy * v1._vw + this->_vz * v2._vw + this->_vw * v3._vw;

		*this = newVect;

		return *this;
	}

	// [] x Overloader
	const float Vect::operator[](const x_enum) const
	{
		return this->_vx;
	}

	// [] y Overloader
	const float Vect::operator[](const y_enum) const
	{
		return this->_vy;
	}

	// [] z Overloader
	const float Vect::operator[](const z_enum) const
	{
		return this->_vz;
	}

	// [] w Overloader
	const float Vect::operator[](const w_enum) const
	{
		return this->_vw;
	}

	float& Vect::operator[](const x_enum)
	{
		return this->_vx;
	}

	float& Vect::operator[](const y_enum)
	{
		return this->_vy;
	}

	float& Vect::operator[](const z_enum)
	{
		return this->_vz;
	}

	float& Vect::operator[](const w_enum)
	{
		return this->_vw;
	}



	const float& Vect::x() const
	{
		return this->_vx;
	}
	const float& Vect::y() const
	{
		return this->_vy;
	}
	const float& Vect::z() const
	{
		return this->_vz;
	}
	const float& Vect::w() const
	{
		return this->_vw;
	}

	float& Vect::x()
	{
		return this->_vx;
	}

	float& Vect::y()
	{
		return this->_vy;
	}

	float& Vect::z()
	{
		return this->_vz;
	}

	float& Vect::w()
	{
		return this->_vw;
	}

	bool Vect::isEqual(Vect inVect, float epsilon)
	{
		bool result = false;

		if (abs(this->_vx - inVect._vx) < epsilon || abs(this->_vx - inVect._vx) < epsilon)
		{
			if (abs(this->_vy - inVect._vy) < epsilon || abs(this->_vy - inVect._vy) < epsilon)
			{
				if (abs(this->_vz - inVect._vz) < epsilon || abs(this->_vz - inVect._vz) < epsilon)
				{
					result = true;
				}
			}
		}
		return result;
	}

	bool Vect::isZero(float epsilon)
	{
		bool result = false;

		if (epsilon != 0)
		{
			if (this->_vx == 0 || this->_vx - epsilon == 0 || this->_vx + epsilon == 0)
			{
				if (this->_vy == 0 || this->_vy - epsilon == 0 || this->_vy + epsilon == 0)
				{
					if (this->_vz == 0 || this->_vz - epsilon == 0 || this->_vz + epsilon == 0)
					{
						result = true;
					}
				}
			}
		}
		return result;
	}
}

//--- End of File ---
