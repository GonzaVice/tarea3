#ifndef _CARD
#define _CARD

#include <string>

class Carta
{
    private:
        char tipo;
        std::string baraja;
    public:
        Carta() {};
        Carta(char, std::string);
        int mostrar_info();
};

#endif