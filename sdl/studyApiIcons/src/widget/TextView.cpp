#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include "Widget.hpp"
#include "TextView.hpp"
#include "Log.hpp"

TextView::TextView(SDL_Renderer * pRenderer)
{
  this->setRendererReference(pRenderer);
  this->loadFont(DEFAULT_FONT, MINIMUN_FONT_SIZE);
  this->setText(DEFAULT_TEXT);
}

TextView::TextView(SDL_Renderer * pRenderer, std::string pText)
{
  this->setRendererReference(pRenderer);
  this->loadFont(DEFAULT_FONT, MINIMUN_FONT_SIZE);
  this->setText(pText);
}

TextView::TextView(SDL_Renderer * pRenderer, std::string pText,
                    std::string pFontPath)
{
  this->setRendererReference(pRenderer);
  this->loadFont(pFontPath, MINIMUN_FONT_SIZE);
  this->setText(pText);
}

TextView::TextView(SDL_Renderer * pRenderer, std::string pText,
                   std::string pFontPath, SDL_Color pColor)
{
  this->setRendererReference(pRenderer);
  this->loadFont(pFontPath, MINIMUN_FONT_SIZE);
  this->setText(pText);
  this->setColor(pColor);
}

TextView::~TextView()
{

}

bool TextView::loadFont(std::string pPath, unsigned int pSize)
{
  if (pPath.empty() && pSize <= MINIMUN_FONT_SIZE)
  {
    pPath = DEFAULT_FONT;
    pSize = 10;
  }

  this->font = TTF_OpenFont(pPath.c_str(), pSize);
  if (!this->font)
  {
    Log::e("Error on font load: ");
    Log::e(TTF_GetError());

    return false;
  }
  return true;
}

void TextView::setText(std::string pText)
{
  if (!this->font)
  {
    Log::e("Font is not set, cannot create font");
    return;
  }

  SDL_Surface * textSurface = TTF_RenderText_Solid(this->font, pText.c_str(),
                                                   this->color);
  if (!textSurface)
  {
    Log::e("Cannot convert text to surface.");
    return;
  }

  this->texture = this->surfaceToTexture(textSurface);
  if (!this->texture)
  {
    Log::e("Error when trying to convert surface to texture");
    return;
  }

  this->text = pText; 
}

bool TextView::render()
{
  Log::d("TextView::render");
  if (!this->renderer || !this->texture)
  {
    Log::e("Render or texture inside TextView is null");
    return false;
  }

  SDL_Rect renderArea = {this->x, this->y, this->width, this->height};
  SDL_RenderCopy(this->renderer, this->texture, nullptr, &renderArea);

  return true;
}

void TextView::setSize(int pWidth, int pHeight)
{
  // TODO: For now, nothing. Thing more about it later
  return;
}

void TextView::clean()
{
  if (this->texture)
  {
    SDL_DestroyTexture(this->texture);
    this->texture = nullptr;
    this->setWidth(0);
    this->setHeight(0);
  }
}
