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

char Carta::print_value()
{
    if(numero == 1)
    {
        return 'A';
    }
    else if(numero == 2)
    {
        return '2';
    }
    else if(numero == 3)
    {
        return '3';
    }
    else if(numero == 4)
    {
        return '4';
    }
    else if(numero == 5)
    {
        return '5';
    }
    else if(numero == 6)
    {
        return '6';
    }
    else if(numero == 7)
    {
        return '7';
    }
    else if(numero == 8)
    {
        return '8';
    }
    else if(numero == 9)
    {
        return '9';
    }
    else if(numero == 10)
    {
        return 'T';
    }
    else if(numero == 11)
    {
        return 'J';
    }
    else if(numero == 12)
    {
        return 'Q';
    }
    else if(numero == 13)
    {
        return 'K';
    }
    else
    {
        return 'X';
    }
    return 'Y';
}

