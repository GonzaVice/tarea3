#ifndef _CARD
#define _CARD

#include <string>

class Carta
{
    public:
        //Atributos
        int numero;
        char tipo;
        int value_1;
        int value_2;
        
        //Métodos
        Carta() {};
        Carta(int, char);
        void mostrar_info();
        void blackjack_value();
        void print_sign();
        char print_value();
};

#endif