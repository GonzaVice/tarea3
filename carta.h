#ifndef _CARD
#define _CARD

#include <string>

class Carta
{
    public:
        //Atributos
        int numero;
        char tipo;
        
        //Métodos
        Carta() {};
        Carta(int, char);
        int mostrar_info();
};

#endif