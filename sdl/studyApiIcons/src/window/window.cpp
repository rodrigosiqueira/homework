#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "Window.hpp"
#include "Log.hpp"

//TODO: SHOULD BE TEMPORARY
#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 420

Window::Window()
{
  this->initialize();
}

// TODO: Refactor it
Window::Window(int pWidth, int pHeight)
{
  this->initialize();
}

Window::Window(int pWidth, int pHeight, int pX, int pY)
{
  this->initialize();
}

Window::~Window()
{
}

// FIXME: Refactore it later, things here should not be hardcoded
int Window::initialize()
{
  int status = this->initializeSDL();
  if (status == -1)
  {
    std::cout << "Without SDL, it is not possible to initialize" << std::endl;
    return status;
  }

  this->window = SDL_CreateWindow(this->windowTitle.c_str(),
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!this->window)
  {
    std::cout << "Cannot create window: " << SDL_GetError() << std::endl;
    return -1;
  }

  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  if (!this->renderer)
  {
    std::cout << "Cannot create renderer: " << SDL_GetError() << std::endl;
    return -1;
  }

  SDL_Rect rect;
  rect.x = rect.y = 0;
  rect.w = SCREEN_WIDTH;
  rect.h = SCREEN_HEIGHT;

  Log::d("Drawing a dummy rect");
  SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 255);
  SDL_RenderFillRect(this->renderer, &rect);

  return status;
}

int Window::initializeSDL()
{
  int success = 0;
  int imageFlags = IMG_INIT_PNG;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL cannot init: " << SDL_GetError() << std::endl;
    return -1;
  }
  if (!(IMG_Init(imageFlags) & imageFlags))
  {
    std::cout << "Alert: cannot load images: " << IMG_GetError() << std::endl;
    success--;
  }
  if (TTF_Init() < 0)
  {
    std::cout << "Alert: cannot load ttf: " << TTF_GetError() << std::endl;
    success--;
  }
  return success;
}

//TODO
int Window::updatedScreen(int pScreenId)
{
  return 0;
}

SDL_Renderer * Window::getRenderer()
{
  return this->renderer;
}
