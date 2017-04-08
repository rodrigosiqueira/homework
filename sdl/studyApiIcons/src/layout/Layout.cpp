#include <string>
#include <vector>
#include <iostream>

#include <SDL2/SDL.h>

#include "Widget.hpp"
#include "Layout.hpp"
#include "Log.hpp"

Layout::Layout(SDL_Renderer * pRenderer)
{
  //TODO
}

Layout::~Layout()
{
  //TODO
}

bool Layout::add(Widget * pWidget)
{
  if (!pWidget)
  {
    Log::w("Parameter is null");
    return false;
  }

  this->widgets.push_back(pWidget);
  return true;
}

// TODO
int Layout::update()
{
  for (auto item : this->widgets)
  {
Log::d("Rendering item");
    item->render();
  }

  return 0;
}
