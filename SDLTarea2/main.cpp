
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<SDL2/SDL_mixer.h>

#include "Jugador.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;
Mix_Music *gMusic = NULL;

using namespace std;

int main( int argc, char* args[] )
{

    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    character = IMG_LoadTexture(renderer, "sprites/mfron1.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    Jugador jugador(renderer);

    //Init Music
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return 40;
    }

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            gMusic = Mix_LoadMUS("Most Wanted (Original).wav");

            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                switch(Event.key.keysym.sym)
                {
                    case SDLK_d:
                    rect_character.x++;
                    break;

                    case SDLK_9:
                    if( Mix_PlayingMusic() == 0)
                    {
                        Mix_PlayMusic(gMusic, -1);
                    } else
                    {
                        if(Mix_PausedMusic() == 1)
                        {
                            Mix_ResumeMusic();
                        }
                        else
                        {
                            Mix_PauseMusic();
                        }
                    }
                    break;

                    case SDLK_0:
                    Mix_HaltMusic();
                    break;
                }
            }
        }

        //
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( currentKeyStates[ SDL_SCANCODE_D ] )
        {
            rect_character.x+=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_A ] )
        {
            rect_character.x-=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_W ] )
        {
            rect_character.y-=1;
        }
        if( currentKeyStates[ SDL_SCANCODE_S ] )
        {
            rect_character.y+=1;
        }


        jugador.logica();

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        jugador.dibujar();
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

	return 0;
}
