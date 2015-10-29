#ifndef JUGADOR_H
#define JUGADOR_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<vector>

using namespace std;

class Jugador
{
    public:
        SDL_Renderer* renderer;
        vector<SDL_Texture*>textures;
        SDL_Rect rect;
        int current_texture;
        int frames;
        Jugador(SDL_Renderer* renderer);
        virtual ~Jugador();
        void dibujar();
        void logica();
    protected:
    private:
};

#endif // JUGADOR_H
