#ifndef _GAME
#define _GAME

#include <string>
#include <vector>
#include "jugador.h"
#include "carta.h"

class Juego
{
    public:
        //Atributos
        std::string archivo;
        std::string guardado;
        std::vector<Jugador> jugadores;
        Jugador distruibidor;
        std::vector<Carta> baraja;

        //Métodos
        Juego() {};
        Juego(std::string, std::string, std::vector<Jugador>, Jugador, std::vector<Carta>);
        int interfaz();
        int mostrar_jugadores();

        //Opción 1:
        int crear_jugador();

        //Opción 2:
        int eliminar_jugador();

        //Opción 3:
        int table_init();
};

#endif