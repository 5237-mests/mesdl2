#include <stdio.h>
#include "SDL2/SDL.h"
#define mapWidth 24
#define mapHeight 24

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;
int done;
float px = 300, py = 300;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void
DrawWorld(SDL_Renderer * renderer)
{
    int x = 0;
    SDL_Rect rect, darea;

    /* Get the Size of drawing surface */
    SDL_RenderGetViewport(renderer, &darea);

    for (int row = 0 ; row < 24; row++) {
        // column = row%2;
        for (int column = 0 ; column < 24; column++) {
            if(worldMap[row][column] != 0 ){
              x = column;
              SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); //wall 

              rect.w = 600/24;
              rect.h = 600/24;
              rect.x = x * rect.w;
              rect.y = row * rect.h;
              
              SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
        for (int i = 1; i <= 24; i++){
            int j = 25*i;
            int s = 25*i;
            SDL_RenderDrawLine(renderer, j, 0, j,600);
            SDL_RenderDrawLine(renderer, 0, s, 600,s);
            SDL_RenderPresent(renderer);

        }
}

void
PlayerPosition()
{
  //Player position
  if (SDL_KEYDOWN == e.type)
  {  
      if (SDLK_LEFT == e.key.keysym.sym)
      {
          px -= 10;
      }
      else if (SDLK_RIGHT == e.key.keysym.sym)
      {
          px += 10;
      }
      else if (SDLK_DOWN == e.key.keysym.sym)
      {
          py += 10;
      }
      else if (SDLK_UP == e.key.keysym.sym)
      {
          py -= 10;
      }
  }
  if (px < 0) px = 30;
  if (py < 0) py = 30;
  if (px >= 575) px = 575;
  if (py >= 575) py = 575;
}

void
player(SDL_Renderer * renderer){
  SDL_Rect position;
  if (SDL_KEYDOWN == e.type)
  {  
      if (SDLK_LEFT == e.key.keysym.sym)
      {
          px -= 10;
      }
      else if (SDLK_RIGHT == e.key.keysym.sym)
      {
          px += 10;
      }
      else if (SDLK_DOWN == e.key.keysym.sym)
      {
          py += 10;
      }
      else if (SDLK_UP == e.key.keysym.sym)
      {
          py -= 10;
      }
  }
  if (px <= 25) px = 26;
  if (py <= 25) py = 26;
  if (px >= 575) px = 569;
  if (py >= 575) py = 569;
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
   position.w = 8;
   position.h = 8;
   position.x = px;
   position.y = py;

  SDL_RenderFillRect(renderer, &position);
}

void
loop()
{
    // SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            done = 1;
            return;
        }

        if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_ESCAPE)) {
            done = 1;
            return;
        }
                 //start
        if (SDL_KEYDOWN == e.type)
        {  
            if (SDLK_LEFT == e.key.keysym.sym)
            {
                px -= 10;
            }
            else if (SDLK_RIGHT == e.key.keysym.sym)
            {
                px += 10;
            }
            else if (SDLK_DOWN == e.key.keysym.sym)
            {
                py += 10;
            }
            else if (SDLK_UP == e.key.keysym.sym)
            {
                py -= 10;
            }
        }
        //end

        DrawWorld(renderer);
        // player(renderer);


    /* Got everything on rendering surface,
       now Update the drawing image on window screen */
      SDL_UpdateWindowSurface(window);

    }
    
}

int
main(int argc, char *argv[])
{
    SDL_Surface *surface;

    /* Enable standard application logging */
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
        return 1;
    }

    /* Create window and renderer for given surface */
    window = SDL_CreateWindow("Chess Board", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation fail : %s\n",SDL_GetError());
        return 1;
    }
    surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateSoftwareRenderer(surface);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Render creation for surface fail : %s\n",SDL_GetError());
        return 1;
    }

    /* Clear the rendering surface with the specified color */
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    /* Draw the Image on rendering surface */

    done = 0;

    while (!done) {
        loop();
        player(renderer);
        
    }

    SDL_Quit();
    return 0;
}