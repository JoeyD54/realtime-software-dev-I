//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Block.h"
#include "Heap.h"
#include "Mem.h"
#include "shlwapi.h"

namespace Azul
{
	Block::Block(void* s, size_t inSize, Azul::Heap* const pHeap, const char* inName, size_t lineNum, size_t align)
	{
		this->pHeap = pHeap;
		this->pUserBlock = s;
		this->mLineNum = lineNum;
		//this->mAlign = align;

		//To shut up warnings
		if (align == 0)
		{

		}
		this->pSecret = this;

		this->pNextBlockInHeap = nullptr;
		this->pPrevBlockInHeap = nullptr;

		this->pNextGlobalBlock = nullptr;
		this->pPrevGlobalBlock = nullptr;

		//Need to somehow get mem's currAlloc

		Mem* instance = Mem::GetInstance();

		Mem::Info info;

		instance->GetInfo(info);

		this->mAllocIndex = info.CurrAllocIndex + 1;
		this->mAllocSize = inSize;

		unsigned int len = strlen(inName);

		//assert(len < NameLength);

		if (len > NameLength)
		{
			len = NameLength;
		}

		memset(this->mFileName, 0x0, NameLength);
		memcpy(this->mFileName, PathFindFileNameA(inName), len);
	}

	//Next block in heap
	Block* Block::GetHeapNext() const
	{
		return this->pNextBlockInHeap;
	}

	//Prev block in heap
	Block* Block::GetHeapPrev() const
	{
		return this->pPrevBlockInHeap;
	}

	//Next GLOBAL block (order of creation)
	Block* Block::GetGlobalNext() const
	{
		return this->pNextGlobalBlock;
	}

	//Prv GLOBAL block (order of creation)
	Block* Block::GetGlobalPrev() const
	{
		return this->pPrevGlobalBlock;
	}

	char* Block::GetFileName()
	{
		return this->mFileName;
	}

	size_t Block::GetLineNum() const
	{
		return this->mLineNum;
	}

	size_t Block::GetAllocIndex() const
	{
		return this->mAllocIndex;
	}

	size_t Block::GetAllocSize() const
	{
		return this->mAllocSize;
	}

	size_t Block::GetAlignSize() const
	{
		return 0;// this->mAlign;
	}

	Heap * Block::GetHeap() const
	{
		return this->pHeap;
	}

	void *Block::GetUserBlock() const
	{
		return this->pUserBlock;
	}

	void Block::SetUserBlock(void * userBlock)
	{
		this->pUserBlock = userBlock;
	}

	void Block::SetNextInHeap(Block* tmp)
	{
		this->pNextBlockInHeap = tmp;
	}

	void Block::SetPrevInHeap(Block* tmp)
	{
		this->pPrevBlockInHeap = tmp;
	}

	void Block::SetNextInGlobal(Block* tmp)
	{
		if (this != nullptr)
		{
			this->pNextGlobalBlock = tmp;
		}
	}

	void Block::SetPrevInGlobal(Block* tmp)
	{
		if (this != nullptr)
		{
			this->pPrevGlobalBlock = tmp;
		}
	}

	void Block::RemoveBlock()
	{
		//This is called from the delete override.
		
		//Need to:
		//	Update pointers
		//		Global and Heap
		//	Clear data

		//Check Heads
		if (this->pHeap->GetBlockHead() == this)
		{
			this->pHeap->SetBlockHead(this->pNextBlockInHeap);
		}


		//Heap next and prev
		if (this->pNextBlockInHeap != nullptr)
		{
			this->pNextBlockInHeap->pPrevBlockInHeap = this->pPrevBlockInHeap;
		}
		if (this->pPrevBlockInHeap != nullptr)
		{
			this->pPrevBlockInHeap->pNextBlockInHeap = this->pNextBlockInHeap;
		}

		this->pNextBlockInHeap = nullptr;
		this->pPrevBlockInHeap = nullptr;

		//Global next and prev
		if (this->pNextGlobalBlock != nullptr)
		{
			this->pNextGlobalBlock->pPrevGlobalBlock = this->pPrevGlobalBlock;			
		}
		if (this->pPrevGlobalBlock != nullptr)
		{
			this->pPrevGlobalBlock->pNextGlobalBlock = this->pNextGlobalBlock;
		}

		this->pNextGlobalBlock = nullptr;
		this->pPrevGlobalBlock = nullptr;
		 
		////	Clear data
		//this->pHeap = nullptr;
		//this->mAllocIndex = 0;
		//this->mAllocSize = 0;
		//this->mLineNum = 0;

		////Clear heap pointers
		//this->pNextBlockInHeap = nullptr;
		//this->pPrevBlockInHeap = nullptr;

		////Clear global pointers
		//this->pNextGlobalBlock = nullptr;
		//this->pPrevGlobalBlock = nullptr;

		////Clear the file name
		//memset(this->mFileName, 0x0, NameLength);
		//memcpy(this->mFileName, "", NameLength);
	}

}

// --- End of File ---