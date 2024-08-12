//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Mem.h"
#include "Heap.h"
#include "Block.h"

namespace Azul
{
	static Mem* pInstance = nullptr;

	// Create the heap.
	Mem::Code Mem::NormalHeap(Heap*& newHeap, unsigned int heapSize, const char* const Name)
	{
		if (pInstance != nullptr)
		{
			HANDLE winHeapHandle = HeapCreate(0, heapSize, 0);

			//Take some of the heap for the heap header
			void* s = HeapAlloc(winHeapHandle, 0, sizeof(Heap));

			//Placement new header
			newHeap = new(s) Heap(winHeapHandle, heapSize, Name, Heap::Type::NORMAL);



			if (pInstance->poHeapHead != nullptr)
			{
				pInstance->poHeapHead->SetPrevHeap(newHeap);
				newHeap->SetNextHeap(pInstance->poHeapHead);
			}

			pInstance->poHeapHead = newHeap;

			pInstance->mInfo.CurrHeapCount++;
			pInstance->CheckHeapPeak(pInstance->mInfo.CurrHeapCount);

			return Mem::Code::OK;
		}

		newHeap = nullptr;
		return Mem::Code::ERROR_Mem_Not_Initialized;
	}

	Mem::Code Mem::FixedHeap(Heap*& newHeap, unsigned int numBlocks, int sizePerBlock, const char* const Name)
	{
		Mem::Code memCode = Mem::Code::ERROR_Mem_Not_Initialized;

		if (pInstance != nullptr)
		{
			//Get the size of the heap
			unsigned int heapSize = numBlocks * (sizePerBlock + sizeof(Block));

			//Create the heap, but make it so it can't grow
			HANDLE winHeapHandle = HeapCreate(0, heapSize, heapSize);

			//Take some of the heap for the heap header
			void* s = HeapAlloc(winHeapHandle, 0, sizeof(Heap));

			//Placement new header
			newHeap = new(s) Heap(winHeapHandle, heapSize, Name, Heap::Type::FIXED);

			if (pInstance->poHeapHead != nullptr)
			{
				pInstance->poHeapHead->SetPrevHeap(newHeap);
				newHeap->SetNextHeap(pInstance->poHeapHead);
			}

			pInstance->poHeapHead = newHeap;

			pInstance->mInfo.CurrHeapCount++;
			pInstance->CheckHeapPeak(pInstance->mInfo.CurrHeapCount);

			return Mem::Code::OK;

		}

		return memCode;
	}

	// Initialize the memory system  (Public method)
	Mem::Code Mem::Create(void)
	{
		privGetInstance();
		//pInstance = privGetInstance();
		pInstance->privInitialize();

		if (pInstance->mInitialized == true)
		{
			return Mem::Code::OK;
		}
		else
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

	/*	if (pInstance == nullptr)
		{
			pInstance = new Mem();
		}*/


	}

	Mem::Code Mem::Destroy(void)
	{
		//Destroy EVERYTHING in the memory system. Clear it all

		Mem::Code memCode = Mem::Code::ERROR_Mem_Not_Initialized;

		if (pInstance != nullptr)
		{
			if (pInstance->mInitialized == true)
			{
				//clear everything in pInstance
				
				Heap* heapWalk = pInstance->poHeapHead;

				while (heapWalk != nullptr)
				{
					Heap* heapToDestroy = heapWalk;

					heapWalk = heapWalk->DebugGetNext();
					HeapDestroy(heapToDestroy->GetHeapHandle());
				}

				//Then clear itself
				//pInstance->poHeapHead = nullptr;
				pInstance = nullptr;
				memCode = Mem::Code::OK;
			}
		}
		return memCode;
	}

	Mem::Code Mem::GetInfo(Mem::Info& retInfo)
	{
		Mem::Code memCode = Mem::Code::ERROR_Mem_Not_Initialized;

		if (pInstance != nullptr)
		{
			retInfo = pInstance->mInfo;
			memCode = Mem::Code::OK;
		}
		return memCode;
	}

	Heap* Mem::DebugGetHeapHead()
	{
		return pInstance->poHeapHead;
	}

	Mem* Mem::GetInstance()
	{
		return pInstance;
	}

	void Mem::AddBytes(size_t blockBytes)
	{
		if (pInstance != nullptr)
		{
			pInstance->mInfo.CurrBytesUsed += blockBytes;
			
			if (pInstance->mInfo.PeakBytesUsed < pInstance->mInfo.CurrBytesUsed)
			{
				pInstance->mInfo.PeakBytesUsed = pInstance->mInfo.CurrBytesUsed;
			}

			pInstance->mInfo.CurrNumAlloc++;
			pInstance->mInfo.CurrAllocIndex++;

			if (pInstance->mInfo.PeakNumAlloc < pInstance->mInfo.CurrNumAlloc)
			{
				pInstance->mInfo.PeakNumAlloc = pInstance->mInfo.CurrNumAlloc;
			}
		}
	}

	void Mem::SetGlobal(Block* newBlock)
	{
		if (pInstance->pGlobalHead == nullptr)
		{
			pInstance->pGlobalHead = newBlock;
		}
		else
		{
			pInstance->pGlobalHead->SetPrevInGlobal(newBlock);
			newBlock->SetNextInGlobal(pInstance->pGlobalHead);
			pInstance->pGlobalHead = newBlock;
		}

	}

	void Mem::RemoveBlock(Block* blockToRemove)
	{
		if (pInstance != nullptr)
		{
			if (blockToRemove != nullptr)
			{
				//Just update global pointers

				
				if (pInstance->pGlobalHead == blockToRemove)
				{
					pInstance->pGlobalHead = blockToRemove->GetGlobalNext();
				}

				//
				//Block* nextGlobal = blockToRemove->GetGlobalNext();
				//Block* prevGlobal = blockToRemove->GetGlobalPrev();

				////Update neighbor pointers
				//nextGlobal->SetPrevInGlobal(prevGlobal);
				//prevGlobal->SetNextInGlobal(nextGlobal);

				////Clear removed block's pointers
				//blockToRemove->SetNextInGlobal(nullptr);
				//blockToRemove->SetPrevInGlobal(nullptr);
			}
		}
		
	}

	Block* Mem::DebugGetGlobalTrackingHead()
	{
		return pInstance->pGlobalHead;
	}

	Mem::Code Mem::RemoveHeap(Heap* pInHeap)
	{
		if (pInstance != nullptr)
		{
			//Heap* heapHead = pInstance->poHeapHead;
			Heap* foundHeap = pInstance->privFindHeap(pInHeap);

			if (pInHeap == nullptr || foundHeap != pInHeap)
			{
				return Mem::Code::ERROR_Illegal_Heap;
			}
			else
			{
				//First w no siblings
				if (pInHeap->DebugGetNext() == nullptr && pInHeap->DebugGetPrev() == nullptr)
				{
					pInstance->poHeapHead = nullptr;
				}
				//first w siblings
				else if (pInHeap->DebugGetNext() != nullptr && pInHeap->DebugGetPrev() == nullptr)
				{
					pInHeap->DebugGetNext()->SetPrevHeap(nullptr);
					pInstance->poHeapHead = pInHeap->DebugGetNext();
				}
				//Middle
				else if(pInHeap->DebugGetNext() != nullptr && pInHeap->DebugGetPrev() != nullptr)
				{
					pInHeap->DebugGetPrev()->SetNextHeap(pInHeap->DebugGetNext());
					pInHeap->DebugGetNext()->SetPrevHeap(pInHeap->DebugGetPrev());

				}
				//Last
				else if(pInHeap->DebugGetPrev() != nullptr && pInHeap->DebugGetNext() == nullptr)
				{
					pInHeap->DebugGetPrev()->SetNextHeap(nullptr);
				}

				pInstance->mInfo.CurrHeapCount--;

				pInHeap->Destroy();
				return Mem::Code::OK;
			}
		}

		return Mem::Code::ERROR_Mem_Not_Initialized;
	}

	Mem::Code Mem::RemoveBytes(Block* inBlock)
	{
		if (pInstance != nullptr)
		{
			if (inBlock != nullptr)
			{
				//Update instance block head if we're removing the current.
				//if (inBlock == pInstance->pGlobalHead)
				//{
				//	//We do prev because the global head should hold the last created block.
				//	if (inBlock->GetGlobalNext() != nullptr)
				//	{
				//		//Update pointers
				//		Block* nextGlobal = inBlock->GetGlobalNext();
				//		nextGlobal->SetPrevInGlobal(inBlock->GetGlobalPrev());
				//		inBlock->SetNextInGlobal(nullptr);
				//		inBlock->SetPrevInGlobal(nullptr);

				//		//Clearing head to set with new block
				//		pInstance->pGlobalHead = nullptr;

				//		//Set new global head to the next in list.
				//		pInstance->SetGlobal(nextGlobal);
				//		
				//	}
				//	pInstance->pGlobalHead = inBlock->GetGlobalNext();
				//	
				//}

				//Update mem's info
				pInstance->mInfo.CurrBytesUsed -= inBlock->GetAllocSize();
				pInstance->mInfo.CurrNumAlloc--;
				
				//If we are removing the latest block
				//if (pInstance->mInfo.CurrAllocIndex == inBlock->GetAllocIndex())
				//{
				//	//Is there a lower index in the list?
				//	if (inBlock->GetGlobalNext() != nullptr)
				//	{
				//		//pInstance->mInfo.CurrAllocIndex = inBlock->GetGlobalNext()->GetAllocIndex();
				//	}
				//	else
				//	{
				//		//There is no lower global pointer. Our index is 0
				//		//pInstance->mInfo.CurrAllocIndex = 0;
				//	}
				//}

				return Mem::Code::OK;
			}
		}

		return Mem::Code::ERROR_Mem_Not_Initialized;
	}

	Mem::Code Mem::GetHeapByAddr(Heap*& pHeap, void* p)
	{
		//Search through heap list
		//Find heap of the given pointer address

		Mem::Code memCode = Mem::Code::ERROR_Mem_Not_Initialized;
		if (pInstance != nullptr)
		{
			//Store found heap INTO pHeap
			Heap* pHeapWalk = pInstance->poHeapHead;

			while (pHeapWalk != nullptr)
			{
				if (pHeapWalk == (Heap*)p)
				{
					pHeap = pHeapWalk;

					return Mem::Code::OK;
				}

				pHeapWalk = pHeapWalk->DebugGetNext();
			}
			memCode = Mem::Code::ERROR_Invalid_Addr;
		}
		return memCode;
	}

	//Singleton creator
	Mem *Mem::privGetInstance(void)
	{
		if (pInstance == nullptr)
		{
			//static Mem *instance;
			//pInstance = instance;
			pInstance = new Mem();
		}
	
		return pInstance;
	}

	void Mem::getInfo(Info& info)
	{
		info.CurrAllocIndex = this->mInfo.CurrAllocIndex;
		info.CurrBytesUsed = this->mInfo.CurrBytesUsed;
		info.CurrHeapCount = this->mInfo.CurrHeapCount;
		info.CurrNumAlloc = this->mInfo.CurrNumAlloc;
		info.PeakBytesUsed = this->mInfo.PeakBytesUsed;
		info.PeakHeapCount = this->mInfo.PeakHeapCount;
		info.PeakNumAlloc = this->mInfo.PeakNumAlloc;
	}

	void Mem::CheckHeapPeak(int temp)
	{
		if (pInstance->mInfo.PeakHeapCount < (size_t) temp)
		{
			pInstance->mInfo.PeakHeapCount = (size_t) temp;
		}
	}

	void Mem::privInitialize(void)
	{
		pInstance->poHeapHead = nullptr;
		pInstance->mInitialized = true;
		pInstance->pGlobalHead = nullptr;

		pInstance->mInfo.CurrAllocIndex = 0;
		pInstance->mInfo.CurrBytesUsed = 0;
		pInstance->mInfo.CurrHeapCount = 0;
		pInstance->mInfo.CurrNumAlloc = 0;
		pInstance->mInfo.PeakBytesUsed = 0;
		pInstance->mInfo.PeakHeapCount = 0;
		pInstance->mInfo.PeakNumAlloc = 0;
	}
	
	//Go through entire heap list. Return found heap
	Heap* Mem::privFindHeap(Heap* toFind)
	{
		Heap* pHeapWalk = pInstance->poHeapHead;
		while (pHeapWalk != nullptr)
		{
			if (pHeapWalk->CompareNames(toFind))
			{
				return pHeapWalk;
			}

			pHeapWalk = pHeapWalk->DebugGetNext();
		}

		return nullptr;
	}

	//Might not be needed.
	Block* Mem::privFindBlock(Block* toFind)
	{
		//This is bs so there's no warnings
		if (toFind == nullptr)
		{

		}
		return nullptr;
	}


}

// --- End of File ---
