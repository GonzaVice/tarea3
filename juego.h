#ifndef _GAME
#define _GAME

#include <string>
#include <vector>
#include "jugador.h"
#include "carta.h"

class Juego
{
    private:
        std::string archivo;
        std::string guardado;
        std::vector<Jugador> jugadores;
        Jugador distruibidor;
        std::vector<Carta> baraja;

    public:
        Juego() {};
        Juego(std::string, std::string, std::vector<Jugador>, Jugador, std::vector<Carta>);
        int interfaz();
};

#endif