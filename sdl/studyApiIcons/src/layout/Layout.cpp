#include <string>
#include <vector>
#include <iostream>

#include <SDL2/SDL.h>

#include "Widget.hpp"
#include "Layout.hpp"

Layout::Layout()
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
    std::cout << "Parameter is null" << std::endl;
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
    item->render();
  }

  return 0;
}
