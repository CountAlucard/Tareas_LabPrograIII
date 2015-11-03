#ifndef HUMUNCULUS_H
#define HUMUNCULUS_H
#include "Enemigo.h"

class Humunculus : public Enemigo
{
    public:
        Humunculus(SDL_Renderer* renderer,Jugador* jugador);
        virtual ~Humunculus();
        void logica();
    protected:
    private:
};

#endif // HUMUNCULUS_H
