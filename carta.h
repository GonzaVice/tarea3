#ifndef _CARD
#define _CARD

#include <string>

class Carta
{
    private:
        int numero;
        char tipo;
    public:
        Carta() {};
        Carta(int, char);
        int mostrar_info();
};

#endif