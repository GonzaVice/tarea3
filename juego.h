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
        Jugador distribuidor;
        std::vector<Carta> baraja;

        //Métodos
        Juego() {};
        Juego(std::string, std::string, std::vector<Jugador>, Jugador, std::vector<Carta>);
        void interfaz();
        void mostrar_jugadores();

        //Opción 1:
        void crear_jugador();

        //Opción 2:
        void eliminar_jugador();

        //Opción 3:
        void table_init();
        void repartir_cartas();
        void repartir_dealer();
        void begin_game();
        void ask_card(int);
};

#endif