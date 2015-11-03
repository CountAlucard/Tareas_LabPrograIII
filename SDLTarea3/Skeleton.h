#ifndef SKELETON_H
#define SKELETON_H
#include "Enemigo.h"

class Skeleton : public Enemigo
{
    public:
        Skeleton(SDL_Renderer* renderer,Jugador* jugador);
        virtual ~Skeleton();
        void logica();
    protected:
    private:
};

#endif // SKELETON_H
