#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char * args[])
{
  //The window
  SDL_Window * window = NULL;

  //The surface contained by the window
  SDL_Surface * screenSurface = NULL;

  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! Error: %s\n", SDL_GetError());
  }
  else
  {
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      printf("Window could not be created! Error: %s\n", SDL_GetError());
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }
}
