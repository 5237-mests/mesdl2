#include <stdio.h>
#include "SDL2/SDL.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;
SDL_Surface *surface;

//start functions

//End functions

int main(int argc, char *argv[])
{
  /* Enable standard application logging */
  SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

  /* Initialize SDL */
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
      return 1;
  }

  window = SDL_CreateWindow("maze!",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,0);
 
  renderer = SDL_CreateRenderer(window, -1, 0);

  /* Select the color for drawing. It is set to red here. */
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  //end window



  int cont = 1;

  while(cont){
    while(SDL_PollEvent(&event)){
      if (event.type == SDL_QUIT){
        cont = 0;
        return -1;
      }
      
    }

  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}