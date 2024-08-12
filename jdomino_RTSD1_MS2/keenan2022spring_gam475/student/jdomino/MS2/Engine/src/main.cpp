//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Game.h"

Game *pGame = nullptr;

int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	pGame = new Game("Monkey", 800, 600);
	assert(pGame);

	pGame->Run();
	delete pGame;

	return 0;
}

// ---  End of File ---


