#include <iostream>
#include <string>
#include "carta.h"

using namespace std;

Carta::Carta(int type, char deck)
{
    tipo = type;
    baraja = deck;
    // C: Corazón
    // P: Pica
    // D: Diamante
    // T: Trébol
}

int Carta::mostrar_info()
{
    cout << "Carta es Tipo " << tipo;
    cout << " y su baraja es " << baraja << endl;
    return 0;
}