#ifndef _GAME
#define _GAME

#include <string>

class Juego
{
    private:
        std::string archivo;
    public:
        Juego() {};
        Juego(std::string);
        int interfaz();
};

#endif