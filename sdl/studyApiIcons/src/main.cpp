#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "Window.hpp"
#include "Layout.hpp"
#include "TextView.hpp"
#include "Log.hpp"

int main (int argc, char * argv[])
{
  Log::i("Initializing GameKiosk");

  //Initialize
  Window  mainWindow;

  //Build elements
 // TextView text(mainWindow.getRenderer(), "Lalala");

 // Layout simpleLayout(mainWindow.getRenderer());
 // simpleLayout.add(&text);

 // //Main loop
 // SDL_RenderClear(mainWindow.getRenderer());

 // simpleLayout.update();

  SDL_RenderPresent(mainWindow.getRenderer());
  SDL_Delay(5000);

  Log::i("Reached the end of GameKiosk");
  return 0;
}

