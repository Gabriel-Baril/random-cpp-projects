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
    SDL_Init(SDL_INIT_VIDEO);

    int i = 0,j = 0;

    SDL_Surface *ecran = NULL;
    ecran = SDL_SetVideoMode(720, 256, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Fenetre SDL",NULL);

    SDL_Surface *rectangles[256] = {NULL};

    for(i = 255;i > 0;i--){
        SDL_Rect pos;
        rectangles[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,720,1,32,0,0,0,0);
        pos.x = 0;
        pos.y = i;
        SDL_FillRect(rectangles[i],NULL, SDL_MapRGB(ecran->format,i,i,i));
        SDL_BlitSurface(rectangles[i], NULL, ecran, &pos);
        SDL_Flip(ecran);
    }

    SDL_Flip(ecran);

    for(j = 0;j < 255;j++){
        SDL_FreeSurface(rectangles[j]);
    }

    pause();



    SDL_Quit();
    return EXIT_SUCCESS;
}
