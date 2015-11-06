#include "Devil.h"

Devil::Devil(SDL_Renderer* renderer, Jugador* jugador)
{
    this->renderer = renderer;
    this->jugador = jugador;
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvldown1.png"));
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvldown2.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvlup1.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvlup2.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvlleft1.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvlleft2.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvlright1.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/dvlright2.png"));

    SDL_QueryTexture(this->textures["down"][0], NULL, NULL, &rect.w, &rect.h);
    x = rand()%100;
    y = rand()%100;

    velocity=0.5;
    animation_velocity=20;

    current_texture=0;

    state="down";
}

Devil::~Devil()
{
    //dtor
}

void Devil::logica()
{
    if(jugador->x-10>x)
    {
        state="right";
    }
    if(jugador->x+10<x)
    {
        state="left";
    }

    if(state=="right")
    {
        x+=velocity;
    }
    if(state=="left")
    {
        x-=velocity;
    }

    if(jugador->x == x && jugador->y == y)
    {
        state="down";
    }

    if(frames%animation_velocity==0)
    {
        current_texture++;
        if(current_texture>=textures[state].size())
            current_texture=0;
    }

    frames++;
}
