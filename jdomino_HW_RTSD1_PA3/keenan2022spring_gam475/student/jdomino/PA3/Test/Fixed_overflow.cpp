//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MemEngine.h"
#include "Dog.h"

using namespace Azul;

//--------------------------------------------------------------------------
// MACROS Test
//--------------------------------------------------------------------------

#define TEST_4_BYTE(ptr)      ( ((size_t)ptr & 0x3) == 0 )
#define TEST_8_BYTE(ptr)      ( ((size_t)ptr & 0x7) == 0 )
#define TEST_16_BYTE(ptr)     ( ((size_t)ptr & 0xF) == 0 )
#define TEST_32_BYTE(ptr)     ( ((size_t)ptr & 0x1F) == 0 )
#define TEST_64_BYTE(ptr)     ( ((size_t)ptr & 0x3F) == 0 )
#define TEST_128_BYTE(ptr)    ( ((size_t)ptr & 0x7F) == 0 )
#define TEST_256_BYTE(ptr)    ( ((size_t)ptr & 0xFF) == 0 )

//---------------------------------------------------------------------------
// Test Files:
// Single step, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(fixed_overflow1, TestConfig::VERSION_CHECK)
{
#if fixed_overflow1

	// Initialize the memory system
	Mem::Create();

	// create heap
	Heap* heap_A;
	Mem::Code memResult;
	memResult = Mem::FixedHeap(heap_A, 10, 512, "HEAP_A_FIXBLOCK");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::FIXED);

	// create heap
	Heap* heap_Overflow;
	memResult = Mem::NormalHeap(heap_Overflow, 200 * 1024, "HEAP_OVERFLOW");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_Overflow);
	CHECK(heap_Overflow->GetHeapType() == Heap::Type::NORMAL);

	// Set overflow
	heap_A->SetOverflowHeap(heap_Overflow);
	CHECK(heap_Overflow == heap_A->GetOverflowHeap());

	Mem::Info info;

	char* pA0 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA1 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA2 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA3 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA4 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA5 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA6 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA7 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA8 = new(heap_A, __FILE__, __LINE__) char[512];
	char* pA9 = new(heap_A, __FILE__, __LINE__) char[512];

	CHECK(TEST_4_BYTE(pA0));
	CHECK(TEST_4_BYTE(pA1));
	CHECK(TEST_4_BYTE(pA2));
	CHECK(TEST_4_BYTE(pA3));
	CHECK(TEST_4_BYTE(pA4));
	CHECK(TEST_4_BYTE(pA5));
	CHECK(TEST_4_BYTE(pA6));
	CHECK(TEST_4_BYTE(pA7));
	CHECK(TEST_4_BYTE(pA8));
	CHECK(TEST_4_BYTE(pA9));

	// datum - pA0
	CHECK(pA0);

	// Make sure they are next to each other
	CHECK((size_t)pA1 == ((size_t)pA0 + (512 + sizeof(Block))));
	CHECK((size_t)pA2 == ((size_t)pA0 + 2 * (512 + sizeof(Block))));
	CHECK((size_t)pA3 == ((size_t)pA0 + 3 * (512 + sizeof(Block))));
	CHECK((size_t)pA4 == ((size_t)pA0 + 4 * (512 + sizeof(Block))));
	CHECK((size_t)pA5 == ((size_t)pA0 + 5 * (512 + sizeof(Block))));
	CHECK((size_t)pA6 == ((size_t)pA0 + 6 * (512 + sizeof(Block))));
	CHECK((size_t)pA7 == ((size_t)pA0 + 7 * (512 + sizeof(Block))));
	CHECK((size_t)pA8 == ((size_t)pA0 + 8 * (512 + sizeof(Block))));
	CHECK((size_t)pA9 == ((size_t)pA0 + 9 * (512 + sizeof(Block))));

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 10 * (512));
	CHECK(info.CurrHeapCount == 2);
	CHECK(info.CurrNumAlloc == 10);
	CHECK(info.PeakBytesUsed == 10 * (512));
	CHECK(info.PeakHeapCount == 2);
	CHECK(info.PeakNumAlloc == 10);

	char* pB0 = new(heap_A, __FILE__, __LINE__) char[512];

	CHECK(TEST_4_BYTE(pA0));

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 11);
	CHECK(info.CurrBytesUsed == 11 * (512));
	CHECK(info.CurrHeapCount == 2);
	CHECK(info.CurrNumAlloc == 11);
	CHECK(info.PeakBytesUsed == 11 * (512));
	CHECK(info.PeakHeapCount == 2);
	CHECK(info.PeakNumAlloc == 11);

	// Check the overflow heap
	Heap* pTmp = nullptr;
	memResult = Mem::GetHeapByAddr(pTmp, pB0);
	CHECK(memResult == Mem::Code::OK);
	CHECK(pTmp != nullptr);

	Heap::Info heapInfo;
	pTmp->GetInfo(heapInfo);

	CHECK(strcmp(heapInfo.Name, "HEAP_OVERFLOW") == 0);

	delete pB0;

	Mem::GetInfo(info);
	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 11);
	CHECK(info.CurrBytesUsed == 10 * (512));
	CHECK(info.CurrHeapCount == 2);
	CHECK(info.CurrNumAlloc == 10);
	CHECK(info.PeakBytesUsed == 11 * (512));
	CHECK(info.PeakHeapCount == 2);
	CHECK(info.PeakNumAlloc == 11);

	memResult = Mem::RemoveHeap(heap_A);

	Mem::GetInfo(info);
	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 11);
	CHECK(info.CurrBytesUsed == 0);
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 0);
	CHECK(info.PeakBytesUsed == 11 * (512));
	CHECK(info.PeakHeapCount == 2);
	CHECK(info.PeakNumAlloc == 11);

	Mem::Destroy();

#endif
} TEST_END

//--- End of File ---
