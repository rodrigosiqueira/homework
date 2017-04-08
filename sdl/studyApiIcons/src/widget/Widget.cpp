#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include "Widget.hpp"

void Widget::setWidth(int pWidth)
{
  this->width = pWidth;
}

void Widget::setHeight(int pHeight)
{
  this->height = pHeight;
}

void Widget::setPosition(int pX, int pY)
{
  this->x = pX;
  this->y = pY;
}

void Widget::setColor(SDL_Color pColor)
{
  this->color = pColor;
}

void Widget::setRendererReference(SDL_Renderer * pRenderer)
{
  if (!pRenderer)
  {
    std::cout << "setRendererReference invoked with null" << std::endl;
    return;
  }

  this->renderer = pRenderer;
}

SDL_Color Widget::getColor()
{
  return this->color;
}

int Widget::getWidth()
{
  return this->height;
}

int Widget::getHeight()
{
  return this->width;
}

int Widget::getX()
{
  return this->x;
}

int Widget::getY()
{
  return this->y;
}

SDL_Texture * Widget::getTexture()
{
  return this->texture;
}

SDL_Texture * Widget::surfaceToTexture(SDL_Surface * pSurface)
{
  if (!this->renderer || !pSurface)
  {
    std::cout << "Parameter: Null pointer on surfaceToTexture" << std::endl;
    return nullptr;
  }

  this->texture = SDL_CreateTextureFromSurface(renderer, pSurface);
  if (!this->texture)
  {
    std::cout << "Error on texture convertion: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  this->setWidth(pSurface->w);
  this->setHeight(pSurface->h);
  SDL_FreeSurface(pSurface);

  return this->texture;
}
