#include <Game.h>

bool Game::Initialize()
{
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // Create the window
    mWindow = SDL_CreateWindow("Game Programming in C++ Chapter 1", 100, 100, 1024, 768, 0);
    if (!mWindow)

    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    // Create the renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!mRenderer)

    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::Shutdown()
{
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    SDL_Quit();
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        // UpdateGame();
        // GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            mIsRunning = false;
            break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
}