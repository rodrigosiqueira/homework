#ifndef __LAYOUT_HPP__
#define __LAYOUT_HPP__

#include <string>
#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "widget/Widget.hpp"

class Layout
{
  public:

    Layout(SDL_Renderer * pRenderer);
    ~Layout();

    bool add(Widget * pWidget);
    int update();

  private:

    SDL_Renderer * renderer;
    std::vector<Widget *> widgets;
};

#endif
