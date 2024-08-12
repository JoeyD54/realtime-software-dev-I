//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef CDM_H
#define CDM_H

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

class CDM
{
public:
	CDM(const CDM &) = delete;
	CDM &operator = (const CDM &) = delete;
	~CDM() = default;

	static int GetSqrtCount();
	static void ResetSqrtCount();

	// USE this in Trig::sqrt() class... to verify proxy
	static float sqrt(float x);


	// ------------------------------------------
	// Data:  (do not add or modify the data)
	// ------------------------------------------
private:
	int sqrtCount;

	CDM();

	static CDM *psInstance;
	static CDM *GetInstance();

};

#endif

// ---  End of File ---

