#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "./header.h"


int worldMap[16][16] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

map rayLenght1(int *worldmap, double px, double py, double teta){
  /*FIRST QUADRANT*/
  int R, dx, dy, xo, yo, r;

  if (teta <= 90 && teta >= 0){
   R = (640-1-px)/cos(teta); //640 = width of screen - 1 
   
   while (r < R){
    //case 1
    dx = px - int px;

    // case 2

   }

  }else if (teta > 90 && teta <= 180){

  } else if (teta > 180 && teta <= 270 ){

  }else if (teta > 270 && teta < 360){
    
  }

}





int main(int argc, char* argv[])
{
        // SDL_Window* window;
        // SDL_Renderer* renderer;
        // SDL_Event e;
        // /* Initialize SDL. */
        // if (SDL_Init(SDL_INIT_VIDEO) < 0)
        //         return 1;

        /* Create the window where we will draw. */
        //window = SDL_CreateWindow("SDL2 window raydistance",
                        // SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        // 640, 512,
                        // 0);

        /* We must call SDL_CreateRenderer in order for draw calls to affect this window. */
        // renderer = SDL_CreateRenderer(window, -1, 0);

        // int r = 1;
        // while(r){
        //         while (SDL_PollEvent(&e))
        //         {
        //                 if(e.type == SDL_QUIT){
        //                         r = 0;
        //                 }
        //         }
        //         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                
        //         SDL_RenderClear(renderer);
        //           //DRAWING WALL
        //         // SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	      //         // for (int z = 0; z < 640; z++ ){
	      //         //   SDL_RenderDrawLine(renderer, z, 156, z, 256);
        //         // }
	      //         SDL_RenderPresent(renderer);       
        //         }

        // SDL_Quit();
        printf("%s", "Hello.");
        return 0;
}