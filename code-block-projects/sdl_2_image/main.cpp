#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL.h>
void pause()
{
    int continuer = 1;
    SDL_Event event;

    while(continuer)
        {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main ( int argc, char** argv )
{

    SDL_Surface *ecran = NULL, *background = NULL;
    SDL_Rect pos;

    pos.x = 0;
    pos.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"),NULL);

    ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("IMAGE", NULL);

    background = SDL_LoadBMP("lac_en_montagne.bmp");

    SDL_BlitSurface(background, NULL, ecran, &pos);

    SDL_Flip(ecran);

    pause();

    SDL_FreeSurface(background);
    SDL_Quit();

    return 0;
}
