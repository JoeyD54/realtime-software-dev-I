//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef BLOCK_H
#define BLOCK_H

namespace Azul
{
	class Heap;  // forward declare

	//-------------------------------------------------------------------------
	// Weird thing
	//   Please declare your forward declarations INSIDE namespace
	//   Outside the namespace cause all kinds of hell
	//-------------------------------------------------------------------------

	class Block
	{
	public:
		// defines for the heap name length
		static const uint32_t NameLength = 64;
		static const uint32_t NameNumChar = (Block::NameLength - 1);

	public:
		//Block constructor
		Block(void* s, size_t inSize, Azul::Heap* const pHeap, const char* inName, size_t lineNum, size_t align);

		// Public methods
		Block *GetHeapNext() const;
		Block *GetHeapPrev() const;
		Block *GetGlobalNext() const;
		Block *GetGlobalPrev() const;
		char *GetFileName();
		size_t  GetLineNum() const;
		size_t  GetAllocIndex() const;
		size_t  GetAllocSize() const;
		size_t GetAlignSize() const;
		Heap *  GetHeap() const;
		void *GetUserBlock() const;
		void SetUserBlock(void * userBlock);

		void SetNextInHeap(Block* tmp);
		void SetPrevInHeap(Block* tmp);

		void SetNextInGlobal(Block* tmp);
		void SetPrevInGlobal(Block* tmp);

		void RemoveBlock();

	private:
		// Add tracking links 
		Block *pNextBlockInHeap;
		Block *pPrevBlockInHeap;
		Block *pNextGlobalBlock;
		Block *pPrevGlobalBlock;

		// stats
		Heap   *pHeap;		
		void *pUserBlock;

		size_t	mLineNum;
		size_t	mAllocIndex;
		size_t	mAllocSize;		
		//size_t  mAlign;
		
		char	mFileName[Block::NameLength];

		// back pointer
		Block *pSecret;   // back pointer to the top of the trackingblock
	};

}

#endif

// ---  End of File ---------------
