#include <string.h>
#include <SDL_Image.h>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();

bool loadMedia();

void close();

SDL_Texture * loadTexture(std::string path);

SDL_Window * gWindow = nullptr;

SDL_Renderer * gRender = nullptr;

SDL_Texture * gTexture = nullptr;

bool init()
{
  bool success = true;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    if(!SDL_Hint(SDL_
  }
}

SDL_Texture * loadTexture(std::string path)
{
  SDL_Texture * newTexture = nullptr;
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == nullptr)
  {
    printf("Unable to load image: %s! %s!", path.c_str(), IMG_GetError());
  }
  else
  {
    newTexture = SDL_CreateTextureFromSurface(gRender, loadedSurface);
    if (newTexture == nullptr)
    {
      printf("Error: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(loadedSurface);
  }
  return newTexture;
}

bool loadMedia()
{
  bool success = true;

  gTexture = loadTexture("texture.png");
  if (gTexture == nullptr)
  {
    printf("Failed");
    success = false;
  }
  return true;
}

void close()
{
  SDL_DestroyTexture(gTexture);
  gTexture = nullptr;
  SDL_DestroyRenderer(gRender);
  SDL_DestroyWindow(gWindow);
  gWindow == nullptr;
  gRender == nullptr;
  IMG_Quit();
  SDL_Quit();
}

int main (int argc, char ** argv)
{
  gWindow = SDL_CreateWindow("SDL tuto", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                             SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (gWindow == nullptr)
  {
    printf("Window could no be created: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    gRender = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRender == nullptr)
    {
      printf("Renderer problem: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      SDL_SetRenderDrawColor(gRender, 0xFF, 0xFF, 0xFF, 0xFF);
      int imgFlags = IMG_INIT_PNG;
      if (!(IMG_Init(imgFlags) & imgFlags))
      {
        printf("SDL_Image Error: %s", IMG_GetError());
        success = false;
      }
    }
  }

  return 0;
}
