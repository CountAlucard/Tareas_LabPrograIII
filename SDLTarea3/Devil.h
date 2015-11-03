#ifndef DEVIL_H
#define DEVIL_H
#include "Enemigo.h"

class Devil : public Enemigo
{
    public:
        Devil(SDL_Renderer* renderer, Jugador* Jugador);
        virtual ~Devil();
        void logica();
    protected:
    private:
};

#endif // DEVIL_H
