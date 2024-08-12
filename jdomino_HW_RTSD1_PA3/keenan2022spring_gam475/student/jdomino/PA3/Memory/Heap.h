//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef HEAP_H
#define HEAP_H

#include "Mem.h"

namespace Azul
{

	//-------------------------------------------------------------------------
	// Namespace Weird thing
	//   Please declare your forward declarations INSIDE namespace
	//   Outside the namespace cause all kinds of hell
	//-------------------------------------------------------------------------

	// Forward declaration
	class Block;

	// Heap class
	class Heap
	{
	public:
		// Constants 
		static const uint32_t NameLength = 64;
		static const uint32_t NameNumChar = (NameLength - 1);

		// -----------------------------------------------------------------
		// When declaring a fixed heap... need space for overhead
		//    initial size = numAlloc*sizeBlock+sizeof(Heap)+FreeHeapExtra
		// -----------------------------------------------------------------
		static const uint32_t FreeHeapExtra = 4 * 1024;

		// Heap Types
		enum class Type : size_t
		{
			NORMAL,
			FIXED
		};

		// Info structure
		struct Info
		{
			char Name[Heap::NameLength];
			size_t    TotalSize;
			size_t	  PeakNumAlloc;
			size_t	  CurrNumAlloc;
			size_t	  PeakBytesUsed;
			size_t	  CurrBytesUsed;
		};

	public:
		// Prevent from calling
		Heap() = delete;		
		Heap(HANDLE heapHandle, unsigned int heapSize, const char* const _Name, Heap::Type hType);
		Heap(const Heap&) = delete;
		const Heap& operator = (const Heap& tmp) = delete;
		~Heap() = default;

		void Destroy();

		// Public Interface (For Customers)
		void GetInfo(Info& info) const;

		// Tracking block 
		Block* GetTrackingHead() const;
		Heap::Type GetHeapType() const;

		// Overflow Heap
		void SetOverflowHeap(Heap*);
		Heap* GetOverflowHeap() const;

		// Needed for Testings (Not for Customers)
		Heap* DebugGetNext() const;
		Heap* DebugGetPrev() const;

		bool CompareNames(Heap* tmp);
		
		//Set pointers
		void SetPrevHeap(Heap* tmp);
		void SetNextHeap(Heap* tmp);

		Heap* GetHeapNext();
		Heap* GetHeapPrev();

		//Set block head
		void SetBlockHead(Block* tmp);
		void InsertBlock(Block* tmp);

		//Get block head
		Block* GetBlockHead();
		void RemoveBlockHead(Block* temp);

		void AddToInfo(Block* newBlock);
		void SubFromInfo(Block* blockToRemove);

		HANDLE GetHeapHandle();
		

	private:
		void privSetHeapName(const char* const hName);
		//Heap* privCreateHeap(unsigned int heapSize);

		// data ------------------------------------------------
		Block* pBlkHead;
		Type	mType;
		HANDLE  mWinHeapHandle;
		Info	mInfo;

		Heap* pNextHeap;
		Heap* pPrevHeap;

		// null for Normal, used only in FixedHeap
		Block* pFixedFreeHead;

		// Overflow heap
		Heap* pOverflow;

		// Back link to the memory system
		Mem* pMem;
	};

}

#endif

// --- End of File ---
