#include <iostream>
#include <string>
#include "carta.h"

using namespace std;

Carta::Carta(int number, char type)
{
    numero = number;
    tipo = type;
    // C: Corazón
    // P: Pica
    // D: Diamante
    // T: Trébol
}

int Carta::mostrar_info()
{
    cout << "Carta es número " << numero;
    cout << " y es tipo " << tipo << endl;
    return 0;
}