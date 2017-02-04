#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class LTexture
{
  public:
    LTexture();
    ~LTexture();

    bool loadFromFile(std::string path);
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    void free();
    void render(int x, int y);
    int getWidth();
    int getHeight();
  private:
    SDL_Texture * mTexture;
    int mWidth;
    int mHeight;
};

bool init();

bool loadMedia();

void close();

SDL_Texture * loadTexture(std::string path);

SDL_Window * gWindow = NULL;

SDL_Renderer * gRenderer = NULL;

TTF_Font * gFont = NULL;

LTexture gTextTexture;

LTexture::LTexture()
{
  mTexture = NULL;
  mWidth = 0;
  mHeight = 0;
}

LTexture::~LTexture()
{
  free();
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
  free();
  SDL_Surface * textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
  if(textSurface == NULL)
  {
    printf("Error: %s\n", TTF_GetError());
  }
  else
  {
    mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
    if(mTexture == NULL)
    {
      printf("Error: %s\n", SDL_GetError());
    }
    else
    {
      mWidth = textSurface->w;
      mHeight = textSurface->h;
    }
    SDL_FreeSurface(textSurface);
  }
  return mTexture != NULL;
}

bool LTexture::loadFromFile(std::string path)
{
  free();
  SDL_Texture * newTexture = NULL;
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());
  if(loadedSurface == NULL)
  {
    printf("Error %s\n", SDL_GetError());
  }
  else
  {
    //SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x9F, 0x11, 0xEF));
    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if(newTexture == NULL)
    {
      printf("Error: %s\n", SDL_GetError());
    }
    else
    {
      mWidth = loadedSurface->w;
      mHeight = loadedSurface->h;
    }
    SDL_FreeSurface(loadedSurface);
  }
  mTexture = newTexture;
  return mTexture != NULL;
}

void LTexture::free()
{
  if(mTexture != NULL)
  {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
  }
}

void LTexture::render(int x, int y)
{
  SDL_Rect renderQuad = {x, y, mWidth, mHeight};
  SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth()
{
  return mWidth;
}

int LTexture::getHeight()
{
  return mHeight;
}

bool init()
{
  bool success = true;
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL cannot initialize. %s\n", SDL_GetError());
  }
  else
  {
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
      printf("Warinig: Linear texture!");
    }
    gWindow = SDL_CreateWindow("tuto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == NULL)
    {
      printf("Window could not be created! %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
      if (gRenderer == NULL)
      {
        printf("Renderer cannot be created! %s\n", SDL_GetError());
        success = false;
      }
      else
      {
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        int imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags) & imgFlags))
        {
          printf("SDL_image initialization. %s\n", IMG_GetError());
          success = false;
        }
        if(TTF_Init() == -1)
        {
          printf("Error: %s\n", TTF_GetError());
          success = false;
        }
      }
    }
  }
  return success;
}

bool loadMedia()
{
  bool success = true;
  gFont = TTF_OpenFont("virgo.ttf", 28);
  if(gFont == NULL)
  {
    printf("failed: %s\n", TTF_GetError());
    success = false;
  }
  else
  {
    SDL_Color textColor = {0xFF, 0xFF, 0xFF};
    if(!gTextTexture.loadFromRenderedText("lalallalalallalalallalalalla", textColor))
    {
      printf("Failed\n");
      success = false;
    }
  }
  return success;
}

void close()
{
  gTextTexture.free();

  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;

  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
}

SDL_Texture * loadTexture(std::string path)
{
  SDL_Texture * newTexture = NULL;
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());
  if(loadedSurface == NULL)
  {
    printf("Unable to load image %s!\n", IMG_GetError());
  }
  else
  {
    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (newTexture == NULL)
    {
      printf("Error %s\n", SDL_GetError());
    }
    SDL_FreeSurface(loadedSurface);
  }
  return newTexture;
}

int main(int argc, char * args[])
{
  if(!init())
  {
    printf("Failded\n");
  }
  else
  {
    if(!loadMedia())
    {
      printf("Failed!\n");
    }
    else
    {
        bool quit = false;
        SDL_Event e;
        while(!quit)
        {
          while(SDL_PollEvent(&e) != 0)
          {
            if(e.type == SDL_QUIT)
            {
              quit = true;
            }
          }
          //Clean
          SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
          SDL_RenderClear(gRenderer);

          gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );

          SDL_RenderPresent(gRenderer);
        }
      }
  }
  close();
  return 0;
}
