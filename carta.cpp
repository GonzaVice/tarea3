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

void Carta::mostrar_info()
{
    cout << "Carta es número " << numero;
    cout << " y es tipo " << tipo << endl;
    return;
}

void Carta::blackjack_value()
{
    if(numero == 1)
    {
        value_1 = 1;
        value_2 = 11;
    }
    else if(numero > 10)
    {
        value_1 = 10;
        value_2 = 10;
    }
    else
    {
        value_1 = numero;
        value_2 = numero;
    }
    return;
}