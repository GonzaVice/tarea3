#include <iostream>
#include "jugador.h"

Jugador::Jugador(std::string name, int money)
{
	nombre = name;
	dinero = money;
}

int Jugador::mostrar_info()
{
    std::cout << "Se llama " << nombre;
    std::cout << " y tiene $" << dinero;
    std::cout << " de dinero." << std::endl;
    return 0;
}