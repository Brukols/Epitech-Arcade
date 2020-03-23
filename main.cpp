#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cout << SDL_GetError() << std::endl;
    }
    atexit(SDL_Quit);

    SDL_Window *window = SDL_CreateWindow("Coucou", 0, 0, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                return (0);
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    return (0);
            }
        }
        SDL_Surface *screenSurface = SDL_GetWindowSurface( window );

        //Fill the surface white
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
        
        //Update the surface
        SDL_UpdateWindowSurface( window );
    }
    SDL_DestroyWindow(window);
    return 0;
}
