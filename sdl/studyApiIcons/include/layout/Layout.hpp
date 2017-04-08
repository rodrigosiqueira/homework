#ifndef __LAYOUT_HPP__
#define __LAYOUT_HPP__

#include <string>
#include <iostream>
#include <vector>

#include "widget/Widget.hpp"

class Layout
{
  public:

    Layout();
    ~Layout();

    bool add(Widget * pWidget);
    int update();

  private:

    std::vector<Widget *> widgets;
};

#endif
