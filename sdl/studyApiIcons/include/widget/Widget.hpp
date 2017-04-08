#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <SDL2/SDL.h>

class Widget
{
  public:

    virtual void setSize(int pWidth, int pHeight) = 0;
    void setWidth(int pWidth);
    void setHeight(int pHeight);
    void setPosition(int pX, int pY);
    void setColor(SDL_Color pColor);
    void setRendererReference(SDL_Renderer * pRenderer);

    SDL_Color getColor();
    int getWidth();
    int getHeight();
    int getX();
    int getY();

    SDL_Texture * getTexture();

    virtual bool render() = 0;
    virtual void clean() = 0;

  protected:

    SDL_Renderer * renderer;
    SDL_Texture * texture;
    SDL_Color color;
    int width;
    int height;
    int x;
    int y;

    SDL_Texture * surfaceToTexture(SDL_Surface * pSurface);
};

#endif
