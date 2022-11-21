#include <stdio.h>
#include "SDL2/SDL.h"

float px = 200, py = 200;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;

void
player(SDL_Renderer * renderer){
  SDL_Rect position;

  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
   position.w = 32;
   position.h = 32;
   position.x = 200;
   position.y = 200;

  SDL_RenderFillRect(renderer, &position);
}

int main(int argc, char *argv[]){

  SDL_Surface *surface;

    /* Enable standard application logging */
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
        return 1;
    }

    /* Create window and renderer for given surface */
    window = SDL_CreateWindow("rec", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation fail : %s\n",SDL_GetError());
        return 1;
    }
    // surface = SDL_GetWindowSurface(window);
    // renderer = SDL_CreateSoftwareRenderer(surface);
    // if (!renderer) {
    //     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Render creation for surface fail : %s\n",SDL_GetError());
    //     return 1;
    // }

    /* Clear the rendering surface with the specified color */
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    

  int thi = 1;

  while(thi){
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE); // red line
    SDL_RenderDrawPoint(renderer, 100, 100);

    SDL_RenderPresent(renderer);
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT ){
        thi = 0;
      }

    }
  }

  // SDL_Delay(5000);
  SDL_Quit();
    return 0;
}
