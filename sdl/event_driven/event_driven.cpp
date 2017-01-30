#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 770;
const int SCREEN_HEIGHT = 520;

bool init();

bool loadMedia();

void close();

SDL_Window * gWindow = NULL;
SDL_Surface * gScreenSurface = NULL;
SDL_Surface * gHelloWorld = NULL;

bool init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! %s\n", SDL_GetError());
  }
  else
  {
    gWindow = SDL_CreateWindow("SDL Tuto", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
      printf("Window cound not be created! Error: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }
  return success;
}

bool loadMedia()
{
  bool success = true;

  gHelloWorld = SDL_LoadBMP("simple_back.bmp");
  if (gHelloWorld == NULL)
  {
    printf("Unable to load image. Error: %s\n", SDL_GetError());
    success = false;
  }
  return success;
}

void close()
{
  SDL_FreeSurface(gHelloWorld);
  gHelloWorld = NULL;

  SDL_DestroyWindow(gWindow);
  SDL_Quit();
}

int main (int argc, char * argv[])
{
  if (!init())
  {
    printf("Failed\n");
  }
  else
  {
    if(!loadMedia())
    {
      printf("Failed\n");
    }
    else
    {
      bool quit = false;
      SDL_Event e;

      while(!quit)
      {
        while(SDL_PollEvent(&e) != 0)
        {
          if(e.type == SDL_QUIT)
          {
            quit = true;
          }
        }
      }

      SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
      SDL_UpdateWindowSurface(gWindow);
      SDL_Delay(2000);
    }
  }
  close();
  return 0;
}
