#include <iostream>
#include <string>
#include "carta.h"

using namespace std;

Carta::Carta(char type, string deck)
{
    tipo = type;
    baraja = deck;
}

int Carta::mostrar_info()
{
    cout << "Carta es Tipo " << tipo;
    cout << " y su baraja es " << baraja << endl;
    return 0;
}