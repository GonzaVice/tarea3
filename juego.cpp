#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "juego.h"
#include "carta.h"
#include "jugador.h"

Juego::Juego(std::string archive, std::string save, std::vector<Jugador> players, Jugador dealer, std::vector<Carta> deck)
{
    archivo = archive;
    guardado = save;
    jugadores = players;
    distruibidor = dealer;
    baraja = deck;
}

int Juego::interfaz()
{
    std::string printer;
    std::ifstream inter;

    inter.open("interfaz.txt");

    getline(inter, printer);
	while(inter)
    {
        std::cout << printer << std::endl;
        getline(inter, printer);
	}
	inter.close();

    return 0;
}