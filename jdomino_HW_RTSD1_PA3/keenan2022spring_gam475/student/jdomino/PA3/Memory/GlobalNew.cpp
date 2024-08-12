//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Mem.h"
#include "Block.h"
#include "GlobalNew.h"

//-------------------------------------------------------------------------
// Namespace Weird thing:
//   Don't use namespace here...
//   Since new/delete isn't allowed namespace
//   do all declaraton with full name Azul::Heap... or Azul::Mem::Align...
//-------------------------------------------------------------------------

// --------------------------------------------
// For Normal Heap
// --------------------------------------------

	void* operator new(size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum)
	{
		size_t alignSize = 0;

		switch (align)
		{
			case Azul::Mem::Align::Byte_4:
				alignSize = 4;
				break;
			case Azul::Mem::Align::Byte_8:
				alignSize = 8;
				break;
			case Azul::Mem::Align::Byte_16:
				alignSize = 16;
				break;
			case Azul::Mem::Align::Byte_32:
				alignSize = 32;
				break;
			case Azul::Mem::Align::Byte_64:
				alignSize = 64;
				break;
			case Azul::Mem::Align::Byte_128:
				alignSize = 128;
				break;
			case Azul::Mem::Align::Byte_256:
				alignSize = 256;
				break;
			default:
				alignSize = 4;
				break;
		}

		void* p = HeapAlloc(pHeap->GetHeapHandle(), 0, inSize + sizeof(Azul::Block) + alignSize);

		unsigned int s = (unsigned int)p;
		s += sizeof(Azul::Block);

		

		Azul::Block * newBlock = new(p) Azul::Block((void*)s, inSize, pHeap, inName, lineNum, alignSize);	
		Azul::Mem * instance = Azul::Mem::GetInstance();

		

		pHeap->InsertBlock(newBlock);
		pHeap->AddToInfo(newBlock);

		instance->SetGlobal(newBlock);

		instance->AddBytes(inSize);

		return (void*)s;
	}

	void operator delete(void* p, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum)
	{
		// -----------------------------------------
		// You don't need to implement this... 
		// its here to shut up compiler warnings
		// just this function
		//------------------------------------------
		AZUL_REPLACE_ME(p);
		AZUL_REPLACE_ME(pHeap);
		AZUL_REPLACE_ME(align);
		AZUL_REPLACE_ME(inName);
		AZUL_REPLACE_ME(lineNum);
	}

	void* operator new[](size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum)
	{
		/*
		* Same as normal new, but do it as many times as is indicated in array
		* 
		*/
		
		size_t alignSize = 0;

		switch (align)
		{
		case Azul::Mem::Align::Byte_4:
			alignSize = 4;
			break;
		case Azul::Mem::Align::Byte_8:
			alignSize = 8;
			break;
		case Azul::Mem::Align::Byte_16:
			alignSize = 16;
			break;
		case Azul::Mem::Align::Byte_32:
			alignSize = 32;
			break;
		case Azul::Mem::Align::Byte_64:
			alignSize = 64;
			break;
		case Azul::Mem::Align::Byte_128:
			alignSize = 128;
			break;
		case Azul::Mem::Align::Byte_256:
			alignSize = 256;
			break;
		default:
			alignSize = 4;
			break;
		}

		void* p = HeapAlloc(pHeap->GetHeapHandle(), 0, inSize + sizeof(Azul::Block) + alignSize);

		unsigned int s = (unsigned int)p;
		s += sizeof(Azul::Block);

		Azul::Block* newBlock = new(p) Azul::Block((void*)s, inSize, pHeap, inName, lineNum, alignSize);
		Azul::Mem* instance = Azul::Mem::GetInstance();

		pHeap->InsertBlock(newBlock); 
		pHeap->AddToInfo(newBlock);

		instance->SetGlobal(newBlock);

		instance->AddBytes(inSize);

		return (void*)s;
	}

	void operator delete[](void* p, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum)
	{
		// -----------------------------------------
		// You don't need to implement this... 
		// its here to shut up compiler warnings
		// just this function
		//------------------------------------------
		AZUL_REPLACE_ME(p);
		AZUL_REPLACE_ME(pHeap);
		AZUL_REPLACE_ME(align);
		AZUL_REPLACE_ME(inName);
		AZUL_REPLACE_ME(lineNum);
	}

// --------------------------------------------
// For Fixed Heap
// --------------------------------------------

	void* operator new(size_t inSize, Azul::Heap* const pHeap, const char* inName, size_t lineNum)
	{
		AZUL_REPLACE_ME(inSize);
		AZUL_REPLACE_ME(pHeap);
		AZUL_REPLACE_ME(inName);
		AZUL_REPLACE_ME(lineNum);
		return (void*)AZUL_REPLACE_ME_STUB(77);
	}

	void operator delete(void* p, Azul::Heap* const pHeap, const char* inName, size_t lineNum)
	{
		// -----------------------------------------
		// You don't need to implement this... 
		// its here to shut up compiler warnings
		// just this function
		//------------------------------------------
		AZUL_REPLACE_ME(p);
		AZUL_REPLACE_ME(pHeap);
		AZUL_REPLACE_ME(inName);
		AZUL_REPLACE_ME(lineNum);
	}

// --------------------------------------------
// For Global Standard new/delete
// --------------------------------------------

	void* operator new(size_t inSize)
	{
		void* p = malloc(inSize);
		return p;
	}

	void operator delete(void* p)
	{
		//Delete a block

		Azul::Mem* instance = Azul::Mem::GetInstance();

		//size_t alignSize = 4;

		Azul::Block* blockPointer = (Azul::Block*)p - 1;

		//If the data is correct, we can delete it.
		if (blockPointer->GetHeap() != nullptr)
		{
			HANDLE heapHandle = blockPointer->GetHeap()->GetHeapHandle();

			Azul::Heap* pHeap = blockPointer->GetHeap();

			pHeap->SubFromInfo(blockPointer);

			//Void pointer is a block. Remove it
			instance->RemoveBytes(blockPointer);
			instance->RemoveBlock(blockPointer);
			blockPointer->RemoveBlock();
			//blockPointer->GetHeap()->RemoveBlockHead(blockPointer);

			//Actually free the data
			HeapFree(heapHandle, 0, blockPointer);

			blockPointer = nullptr;
		}
		else
		{
			//Normal free
			free(p);
		}
	}

	void* operator new[](size_t inSize)
	{
		void* p = malloc(inSize);
		return p;
	}

	void operator delete[](void* p)
	{
		//This will delete a block of memory

		Azul::Mem* instance = Azul::Mem::GetInstance();

		//Look above user data to find block header
		Azul::Block* blockPointer = (Azul::Block*)p-1;
		
		//If the data is correct, we can delete it.
		if (blockPointer->GetHeap() != nullptr)
		{
			HANDLE heapHandle = blockPointer->GetHeap()->GetHeapHandle();

			Azul::Heap* pHeap = blockPointer->GetHeap();

			pHeap->SubFromInfo(blockPointer);
			//Void pointer is a block. Remove it
			instance->RemoveBytes(blockPointer);
			instance->RemoveBlock(blockPointer);
			blockPointer->RemoveBlock();
			//blockPointer->GetHeap()->RemoveBlockHead(blockPointer);

			//Actually free the data
			HeapFree(heapHandle, 0, blockPointer);

			blockPointer = nullptr;
		}
		else
		{
			//Normal Free
			free(p);
		}
	}


// --- End of File ---
