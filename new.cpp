#include <iostream>
#include <SDL3/SDL.h>

int main(int, char**)
{
    std::cout << "Starting program...\n";

int ret =     SDL_Init(SDL_INIT_VIDEO); 
        
    std::cout << "SDL_Init OK\n" << ret <<"\n";

    SDL_Window* window = SDL_CreateWindow("SDL debug", 800, 600, 0);
if(!window){
	std::cerr <<" CreateWindow failed:"  << SDL_GetError() << "\n";
        return 1;
    }
    std::cout << "Window OK\n";

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
if(!renderer){ 
 	std::cerr <<" CreateRenderer failed:"  << SDL_GetError() << "\n";
        return 1;
    }
    std::cout << "Renderer OK\n";

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT)
                running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    std::cout << "Exiting cleanly...n";

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0 ; 
}
