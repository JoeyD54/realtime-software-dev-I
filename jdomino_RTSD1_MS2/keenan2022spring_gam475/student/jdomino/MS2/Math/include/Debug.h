//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef ENGINE_MATH_DEBUG_H
#define ENGINE_MATH_DEBUG_H

// This file assumes Framework.h is included in executable for Trace::Out

namespace Azul
{
	// Forward declarations:
	class Vect; 
	class Matrix;

	// ----------------------------------------------------------------------
	// Output Print for Vect and Matrix
	// ----------------------------------------------------------------------
	class Debug
	{
	public:
		static void Print(const char* pName, const Vect &r);
		static void Print(const char* pName, const Matrix& r);

	};

}

#endif

//--- End of File ---
