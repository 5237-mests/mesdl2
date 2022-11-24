#include <stdio.h>
#include "SDL2/SDL.h"

float px = 200, py = 200;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0)
        {
            SDL_bool done = SDL_FALSE;

            while (!done)
            {
                SDL_Event event;
                SDL_Rect position;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // red line
                // SDL_RenderDrawPoint(renderer, px, py);
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
                position.w = 8;
                position.h = 8;
                position.x = px;
                position.y = py;
                SDL_RenderFillRect(renderer, &position);
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                    //Player position
                    if (SDL_KEYDOWN == event.type)
                    {  

                        if (SDLK_LEFT == event.key.keysym.sym)
                        {
                            px -= 10;
                        }
                        else if (SDLK_RIGHT == event.key.keysym.sym)
                        {
                            px += 10;
                        }
                        else if (SDLK_DOWN == event.key.keysym.sym)
                        {
                            py += 10;
                        }
                        else if (SDLK_UP == event.key.keysym.sym)
                        {
                            py -= 10;
                        }
                    }
                    if (px < 0) px = 0;
                    if (py < 0) py = 0;
                    if (px >= 640) px = 640-1;
                    if (py >= 480) py = 480-1;
                }
            }
        }

        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}