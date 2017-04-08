#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <SDL2/SDL.h>

#include <string>

class Window
{
  public:

    Window();
    Window(int pWidth, int pHeight);
    Window(int pWidth, int pHeight, int pX, int pY);
    ~Window();

    int initialize();

    int updatedScreen(int pScreenId = 0);

    SDL_Renderer * getRenderer();

  private:

    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Rect bounds;
    std::string windowTitle;

    int width;
    int height;
    int x;
    int y;

    int initializeSDL();
};

#endif
