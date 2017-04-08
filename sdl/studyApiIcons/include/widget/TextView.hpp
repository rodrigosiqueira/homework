#ifndef __TEXT_VIEW__HPP__
#define __TEXT_VIEW__HPP__

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include <string.h>

#include "Widget.hpp"

#define DEFAULT_FONT "fonts/virgo.ttf"
#define MINIMUN_FONT_SIZE 9
#define DEFAULT_TEXT "default"

class TextView : public Widget
{
  public:

    TextView(SDL_Renderer * pRenderer);
    TextView(SDL_Renderer * pRenderer, std::string pText);
    TextView(SDL_Renderer * pRenderer, std::string pText,
             std::string pFontPath);
    TextView(SDL_Renderer * pRenderer, std::string pText, std::string pFontPath,
             SDL_Color pColor);

    ~TextView();

    bool loadFont(std::string pPath, unsigned int pSize);
    void setText(std::string pText);

    virtual bool render();
    virtual void setSize(int pWidth, int pHeight);
    virtual void clean();

  private:

    TTF_Font * font;
    std::string text;
};

#endif
