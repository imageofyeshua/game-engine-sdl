#include "Text.h"

const int screenWidth = 700;
const int screenHeight = 350;

Text::Text()
	:mWindow(nullptr)
	, mRenderer(nullptr)
	, mTicksCount(0)
	, mIsRunning(true)
{
	myDouble = 123.45678;
}

bool Text::Initialize()
{
	// Initialize SDL
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// Initialize Font
	if (TTF_Init() < 0) {
		printf("Could not initialize font! (%s)\n", TTF_GetError());
		return false;
	}

	// Create an SDL Window
	mWindow = SDL_CreateWindow(
		"Text Display", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		screenWidth,	// Width of window
		screenHeight,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(
		mWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
}

void Text::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Text::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			// If we get an SDL_QUIT event, end loop
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	// Get state of keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
}

void Text::UpdateGame()
{

}

void Text::GenerateOutput()
{
	// Set draw color to blue
	SDL_SetRenderDrawColor(
		mRenderer,
		0,		// R
		0,		// G 
		0,	// B
		255		// A
	);

	// Clear back buffer
	SDL_RenderClear(mRenderer);

	TTF_Font* font = TTF_OpenFont("C:\\Users\\inthe\\Dev\\CPlusPlusExe\\GameDesignSDL\\resources\\fonts\\NanumGothic-Regular.ttf", 12);
	if (font == NULL) {
		printf("Could not open font! (%s)\n", TTF_GetError());
		exit(1);
	}

	// Pixels from our text
	SDL_Surface* surfaceText = TTF_RenderText_Solid(font, "Daniel Park", { 255,255,255 });

	// Setup the texture
	SDL_Texture* textureText = SDL_CreateTextureFromSurface(mRenderer, surfaceText);

	// Free the surface
	// We are done with it after we have uploaded to
	// the texture
	SDL_FreeSurface(surfaceText);

	// Create a rectangle to draw on
	SDL_Rect rectangle;
	rectangle.x = 10;
	rectangle.y = 10;
	rectangle.w = 300;
	rectangle.h = 50;

	// Render our text on a rectangle
	SDL_RenderCopy(mRenderer, textureText, NULL, &rectangle);

	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);
}

void Text::returnData()
{
		
}

void Text::Shutdown()
{
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

