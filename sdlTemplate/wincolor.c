#include <stdio.h>
#include <SDL2/SDL.h>


int main(int argc, char* argv[])
{
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event e;
        /* Initialize SDL. */
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
                return 1;

        /* Create the window where we will draw. */
        window = SDL_CreateWindow("SDL2 window",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        640, 512,
                        0);

        /* We must call SDL_CreateRenderer in order for draw calls to affect this window. */
        renderer = SDL_CreateRenderer(window, -1, 0);

        int r = 1;
        while(r){
                while (SDL_PollEvent(&e))
                {
                        if(e.type == SDL_QUIT){
                                r = 0;
                        }
                }
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	        for (int z = 0; z < 640; z++ ){
	        SDL_RenderDrawLine(renderer, z, 156, z, 256);
                }
                
	        SDL_RenderPresent(renderer);
                
        }

        // SDL_Delay(5000);
        SDL_Quit();
        return 0;
}