//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Heap.h"
#include "Block.h"

namespace Azul
{

	Heap::Heap(HANDLE heapHandle, unsigned int heapSize, const char* const _Name, Heap::Type hType)
	{
		//this->mWinHeapHandle = HeapCreate(0, heapSize, 0);

		//newHeap = privCreateHeap(heapSize);

		//newHeap = new() Heap(this->mWinHeapHandle, heapSize, _Name, hType);

		this->mWinHeapHandle = heapHandle;
		this->pMem = Mem::GetInstance();
		this->mType = hType;
		this->mInfo.TotalSize = heapSize;
		this->privSetHeapName(_Name);
		this->pBlkHead = nullptr;
	};

	//Heap* Heap::privCreateHeap(unsigned int heapSize)
	//{
	//	
	//	//return 
	//}

	void Heap::privSetHeapName(const char* const hName)
	{
		// Next couple lines, have safety to only copy a maximum of allowed characters
		assert(hName);

		unsigned int len = strlen(hName);

		assert(len < NameLength);

		if (len > NameLength)
		{
			len = NameLength;
		}

		memset(this->mInfo.Name, 0x0, NameLength);
		memcpy(this->mInfo.Name, hName, len);
	}

	Heap::Type Heap::GetHeapType() const
	{
		return this->mType;
	}

	// Overflow Heap
	void Heap::SetOverflowHeap(Heap* pHeap)
	{
		this->pOverflow = pHeap;
	}

	Heap* Heap::GetOverflowHeap() const
	{
		return this->pOverflow;
	}

	void Heap::Destroy()
	{
		Mem* instance = Mem::GetInstance();

		Block* bWalk = this->GetBlockHead();

		//Go through each block in heap
		while (bWalk != nullptr)
		{
			Block* removeBlock = bWalk;

			bWalk = bWalk->GetHeapNext();

			//Remove them from lists and update info
			instance->RemoveBytes(removeBlock);
			removeBlock->RemoveBlock();
		}

		//Remove it from memory
		HeapDestroy(this->GetHeapHandle());
	}


	void Heap::GetInfo(Info& retInfo) const
	{
		retInfo = this->mInfo;
	};

	Heap* Heap::DebugGetNext() const
	{
		return this->pNextHeap;
	};

	Heap* Heap::DebugGetPrev() const
	{
		return this->pPrevHeap;
	};

	Block* Heap::GetTrackingHead() const
	{
		return this->pBlkHead;
	}

	bool Heap::CompareNames(Heap * tmp)
	{
		if (this->mInfo.Name == tmp->mInfo.Name)
		{
			return true;
		}

		return false;
	}

	void Heap::SetPrevHeap(Heap* tmp)
	{
		this->pPrevHeap = tmp;
	}

	void Heap::SetNextHeap(Heap* tmp)
	{
		this->pNextHeap = tmp;
	}

	Heap* Heap::GetHeapNext()
	{
		return this->pNextHeap;
	}

	Heap* Heap::GetHeapPrev()
	{
		return this->pPrevHeap;
	}

	void Heap::SetBlockHead(Block* tmp)
	{
		this->pBlkHead = tmp;
	}

	void Heap::InsertBlock(Block* tmp)
	{
		Block* heapHead = this->GetBlockHead();

		if (heapHead == nullptr)
		{
			this->SetBlockHead(tmp);
		}
		else
		{
			////Get to EOL
			//while (heapHead->GetHeapNext() != nullptr)
			//{
			//	heapHead = heapHead->GetHeapNext();
			//}

			heapHead->SetPrevInHeap(tmp);
			tmp->SetNextInHeap(heapHead);
			this->SetBlockHead(tmp);
		}
	}

	Block* Heap::GetBlockHead()
	{
		return this->pBlkHead;
	}

	void Heap::RemoveBlockHead(Block* temp)
	{
		if (this->pBlkHead == temp)
		{
			this->pBlkHead = temp->GetHeapNext();
		}
	}

	void Heap::AddToInfo(Block * newBlock)
	{
		this->mInfo.CurrBytesUsed += newBlock->GetAllocSize();
		this->mInfo.TotalSize += sizeof(newBlock) - 4;//HeapSize(this->GetHeapHandle(), 0, newBlock);

		if (this->mInfo.PeakBytesUsed < this->mInfo.CurrBytesUsed)
		{
			this->mInfo.PeakBytesUsed = this->mInfo.CurrBytesUsed;
		}

		this->mInfo.CurrNumAlloc++;

		if (this->mInfo.PeakNumAlloc < this->mInfo.CurrNumAlloc)
		{
			this->mInfo.PeakNumAlloc = this->mInfo.CurrNumAlloc;
		}
	}

	void Heap::SubFromInfo(Block* blockToRemove)
	{
		this->mInfo.CurrBytesUsed -= blockToRemove->GetAllocSize();
		this->mInfo.TotalSize -= sizeof(blockToRemove) - 4;//HeapSize(this->GetHeapHandle(), 0, newBlock);

		this->mInfo.CurrNumAlloc--;
	}



	HANDLE Heap::GetHeapHandle()
	{
		return this->mWinHeapHandle;
	}

}

// --- End of File ---
