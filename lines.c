#include <stdio.h>
#include "SDL2/SDL.h"


// float px = 200, py = 200;
// SDL_Event event;


// int main(int argc, char *argv[])
// {
//     if (SDL_Init(SDL_INIT_VIDEO) == 0)
//     {
//         SDL_Window *window = NULL;
//         SDL_Renderer *renderer = NULL;

//         if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0)
//         {
//             SDL_bool done = SDL_FALSE;

//             while (!done)
//             {
//                 // SDL_Event event;

//                 // SDL_SetRenderDrawColor(renderer, 1, 1, 1, SDL_ALPHA_OPAQUE);
//                 // SDL_RenderClear(renderer)

//                 SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE); // red line
//                 SDL_RenderDrawPoint(renderer, px, py);

//                 SDL_RenderPresent(renderer);
//                 SDL_UpdateWindowSurface(window);

//                 while (SDL_PollEvent(&event))
//                 {
//                     if (event.type == SDL_QUIT)
//                     {
//                         done = SDL_TRUE;
//                     }
                   
//                     //Player position
//                     if (SDL_KEYDOWN == event.type)
//                     {  

//                         if (SDLK_LEFT == event.key.keysym.sym)
//                         {
//                             px -= 10;
//                         }
//                         else if (SDLK_RIGHT == event.key.keysym.sym)
//                         {
//                             px += 10;
//                         }
//                         else if (SDLK_DOWN == event.key.keysym.sym)
//                         {
//                             py += 10;
//                         }
//                         else if (SDLK_UP == event.key.keysym.sym)
//                         {
//                             py -= 10;
//                         }
//                     }
//                     if (px < 0) px = 0;
//                     if (py < 0) py = 0;
//                     if (px >= 640) px = 640-1;
//                     if (py >= 480) py = 480-1;
//                 }
//             }
//         }

//         if (renderer)
//         {
//             SDL_DestroyRenderer(renderer);
//         }
//         if (window)
//         {
//             SDL_DestroyWindow(window);
//         }
//     }
//     SDL_Quit();
//     return 0;
// }


#define POINTS_COUNT 4

static SDL_Point points[POINTS_COUNT] = {
    {200, 300},
    {500, 300},
    {200, 400},
    {600, 400}
};

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                for (int i = 1; i < 80; i++){
                    int j = 32*i;
                    SDL_RenderDrawLine(renderer, j, 0, j,480);
                    SDL_RenderDrawLine(renderer, 0, j, 640,j);
                    SDL_RenderPresent(renderer);

                }

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                // SDL_RenderDrawLines(renderer, points, POINTS_COUNT);
                // SDL_RenderPresent(renderer);
                // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                // for (int i = 1; i < 80; i++){
                //     int j = 32*i;
                //     SDL_RenderDrawLine(renderer, j, 0, j,480);
                //     // SDL_RenderDrawLine(renderer, 0, i, 640,i);
                //     SDL_RenderPresent(renderer);

                // }
                // SDL_RenderDrawLine(renderer, 300, 300, 500, 300);
                // SDL_RenderDrawLine(renderer, 100, 100, 100, 300);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}