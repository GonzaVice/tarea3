#include <iostream>
#include "carta.h"

using namespace std;

Carta::Carta(char type, char deck)
{
    tipo = type;
    baraja = deck;
}

int Carta::mostrar_info()
{
    cout << "Carta es Tipo " << tipo;
    cout << " y su baraja es " << baraja << endl;
}