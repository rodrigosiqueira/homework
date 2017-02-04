#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window * gWindow = NULL;
SDL_Renderer * gRenderer = NULL;

int showMenu(SDL_Renderer * screen, TTF_Font * font)
{
  Uint32 time;
  int x, y;
  const int NUMMENU = 2;
  const char * labels[NUMMENU] = {"Continue", "Exit"};
  SDL_Surface * menus[NUMMENU];
  bool selected[NUMMENU] = {0, 0};
  SDL_Color color[2] = {{255, 25, 255}, {255, 0, 0}};

  menus[0] = TTF_RenderText_Solid(font, labels[0], color[0]);
  menus[1] = TTF_RenderText_Solid(font, labels[1], color[1]);

  SDL_Rect pos[NUMMENU];
  SDL_Rect temp;
  SDL_RenderGetClipRect(screen, &temp);
  pos[0].x = temp.w / 2 - menus[0]->clip_rect.w/2;
  pos[0].y = temp.h / 2 - menus[0]->clip_rect.h;
  pos[1].x = temp.w / 2 - menus[1]->clip_rect.w/2;
  pos[1].y = temp.h / 2 - menus[1]->clip_rect.h;

  SDL_SetRenderDrawColor(screen, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(gRenderer);

  SDL_Event event;
  while(1)
  {
    time = SDL_GetTicks();
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          for(int i = 0; i < NUMMENU; i++)
            SDL_FreeSurface(menus[i]);
          return 1;
        case SDL_MOUSEMOTION:
          x = event.motion.x;
          y = event.motion.y;
          for(int i = 0; i < NUMMENU; i++)
          {
            if(x >= pos[i].x && x<=pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + y+pos[i].h)
            {
              if(!selected[i])
              {
                selected[i] = 1;
                SDL_FreeSurface(menus[i]);
                menus[i] = TTF_RenderText_Solid(font, labels[i], color[1]);
              }
            }
            else
            {
              if(!selected[i])
              {
                selected[i] = 0;
                SDL_FreeSurface(menus[i]);
                menus[i] = TTF_RenderText_Solid(font, labels[i], color[0]);
              }
            }
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          x = event.button.x;
          y = event.button.y;
          for(int i = 0; i < NUMMENU; i++)
          {
            if(x >= pos[i].x && x<=pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + y+pos[i].h)
            {
              for(int j = 0; j < NUMMENU; j++)
                SDL_FreeSurface(menus[j]);
              return i;
            }
          }
          break;
        case SDL_KEYDOWN:
          if(event.key.keysym.sym == SDLK_ESCAPE)
          {
            for(int j = 0; j < NUMMENU; j++)
              SDL_FreeSurface(menus[j]);

            return 0;
          }
          break;
      }
    }
    for(int i=0; i < NUMMENU; i++)
    {
      SDL_Texture * tmpTxt = SDL_CreateTextureFromSurface(screen, menus[i]);
      SDL_RenderCopy(gRenderer, tmpTxt, NULL, &pos[i]);
    }
    SDL_RenderPresent(screen);
    if(1000/30 > (SDL_GetTicks() - time))
      SDL_Delay(1000/30 - (SDL_GetTicks() - time));
  }
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
    gWindow = SDL_CreateWindow("menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
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
      }
    }
  }
  return success;
}

void close()
{
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;
  SDL_Quit();
}

int main(int argc, char * argv[])
{
  if(!init())
  {
    printf("Failded\n");
  }
  else
  {
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("virgo.ttf", 20);

    showMenu(gRenderer, font);
  }
  close();
  return 0;
}
