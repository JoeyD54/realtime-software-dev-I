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

TEST(Fixed_Tracking, TestConfig::VERSION_CHECK)
{
#if Fixed_Tracking

	// Initialize the memory system
	Mem::Create();

	// Test the mem Info structures
	Mem::Info mem_Info;

	// Yes it works.
	Mem::GetInfo(mem_Info);

	// validate it
	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 0);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 0);
	CHECK(mem_Info.PeakHeapCount == 0);
	CHECK(mem_Info.PeakNumAlloc == 0);

	// create heap
	Heap* heap_A;
	Mem::Code memResult;
	memResult = Mem::FixedHeap(heap_A, 100, 200, "HEAP_A_FIXBLOCK");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::FIXED);

	Mem::Info info;

	char* pA0 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA1 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA2 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA3 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA4 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA5 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA6 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA7 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA8 = new(heap_A, __FILE__, __LINE__) char[200];
	char* pA9 = new(heap_A, __FILE__, __LINE__) char[200];

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
	CHECK((size_t)pA1 == ((size_t)pA0 + (200 + sizeof(Block))));
	CHECK((size_t)pA2 == ((size_t)pA0 + 2 * (200 + sizeof(Block))));
	CHECK((size_t)pA3 == ((size_t)pA0 + 3 * (200 + sizeof(Block))));
	CHECK((size_t)pA4 == ((size_t)pA0 + 4 * (200 + sizeof(Block))));
	CHECK((size_t)pA5 == ((size_t)pA0 + 5 * (200 + sizeof(Block))));
	CHECK((size_t)pA6 == ((size_t)pA0 + 6 * (200 + sizeof(Block))));
	CHECK((size_t)pA7 == ((size_t)pA0 + 7 * (200 + sizeof(Block))));
	CHECK((size_t)pA8 == ((size_t)pA0 + 8 * (200 + sizeof(Block))));
	CHECK((size_t)pA9 == ((size_t)pA0 + 9 * (200 + sizeof(Block))));

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 10 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 10);
	CHECK(info.PeakBytesUsed == 10 * (200));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 10);

	delete pA0;
	delete pA8;
	delete pA3;
	delete pA7;
	delete pA5;
	delete pA9;

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 4 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 4);
	CHECK(info.PeakBytesUsed == 10 * (200));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 10);

	// OK, now all 5 allocations are created, now look at track info from heap.
	Block* t0 = heap_A->GetTrackingHead();

	CHECK(t0 != nullptr);
	CHECK(t0->GetAllocIndex() == 7);
	CHECK(strcmp(t0->GetFileName(), "Fixed_Tracking.cpp") == 0);
	CHECK(t0->GetLineNum() == 64);
	CHECK(t0->GetHeapPrev() == 0);
	CHECK(t0->GetHeapNext() != 0);

	Block* t1 = t0->GetHeapNext();

	CHECK(t1 != nullptr);
	CHECK(t1->GetAllocIndex() == 5);
	CHECK(strcmp(t1->GetFileName(), "Fixed_Tracking.cpp") == 0);
	CHECK(t1->GetLineNum() == 62);
	CHECK(t1->GetHeapPrev() == t0);
	CHECK(t1->GetHeapNext() != 0);
	CHECK(t0->GetHeapNext() == t1);

	Block* t2 = t1->GetHeapNext();

	CHECK(t2 != nullptr);
	CHECK(t2->GetAllocIndex() == 3);
	CHECK(strcmp(t2->GetFileName(), "Fixed_Tracking.cpp") == 0);
	CHECK(t2->GetLineNum() == 60);
	CHECK(t2->GetHeapPrev() == t1);
	CHECK(t2->GetHeapNext() != 0);
	CHECK(t1->GetHeapNext() == t2);

	Block* t3 = t2->GetHeapNext();

	CHECK(t3 != nullptr);
	CHECK(t3->GetAllocIndex() == 2);
	CHECK(strcmp(t3->GetFileName(), "Fixed_Tracking.cpp") == 0);
	CHECK(t3->GetLineNum() == 59);
	CHECK(t3->GetHeapPrev() == t2);
	CHECK(t3->GetHeapNext() == 0);
	CHECK(t2->GetHeapNext() == t3);

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
