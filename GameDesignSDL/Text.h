#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class Text
{
public:
	Text();
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void returnData();

private:
	// Helper functions for the game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	// Window created by SDL
	SDL_Window* mWindow;
	// Renderer for 2D drawing
	SDL_Renderer* mRenderer;
	// Number of ticks since start of game
	Uint32 mTicksCount;
	// Game should continue to run
	bool mIsRunning;

	short myShort;
	int myInt;
	long myLong;
	float myFloat;
	double myDouble;

};
