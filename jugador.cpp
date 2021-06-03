#include <iostream>
#include <string>
#include <vector>
#include "jugador.h"
#include "carta.h"

Jugador::Jugador(std::string name, int money, std::vector<Carta> cards)
{
	nombre = name;
	dinero = money;
    mazo = cards;
}

void Jugador::mostrar_info()
{
    std::cout << "Se llama " << nombre;
    std::cout << " y tiene $" << dinero;
    std::cout << " de dinero." << std::endl;
    return;
}