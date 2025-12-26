#include <SDL3/SDL.h>
#include <iostream>

int main() {
    std::cout << "Program started\n";

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "SDL init OK\n";

    SDL_Quit();
    std::cout << "Quit OK\n";

    return 0;
}
