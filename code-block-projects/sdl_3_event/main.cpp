#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL.h>

void loop(SDL_Surface *ecran,SDL_Rect *position,SDL_Surface *zozor){
    int running = 1;
    SDL_Event event;


    while(running){
        SDL_WaitEvent(&event);

        switch(event.type){
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_UP:
                        position->y-=5;
                        break;
                    case SDLK_DOWN:
                        position->y+=5;
                        break;
                    case SDLK_RIGHT:
                        position->x+=5;
                        break;
                    case SDLK_LEFT:
                        position->x-=5;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                switch(event.button.button){
                    case SDL_BUTTON_LEFT:
                    position->x = event.button.x;
                    position->y = event.button.y;
                }
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255,255,255));
        SDL_BlitSurface(zozor, NULL, ecran, position);
        SDL_Flip(ecran);
    }
}

int main ( int argc, char** argv )
{
    SDL_Surface *ecran = NULL, *zozor = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_EnableKeyRepeat(10,10);

    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_Rect pos;

    pos.x = 0;
    pos.y = 0;

    SDL_SetColorKey(zozor,SDL_SRCCOLORKEY,SDL_MapRGB(zozor->format,0,0,255));

    ecran = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("EVENT",NULL);

    loop(ecran,&pos,zozor);

    SDL_FreeSurface(zozor);

    SDL_Quit();
    return 0;
}
