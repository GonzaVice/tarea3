#ifndef _CARD
#define _CARD

#include <string>

class Carta
{
    private:
        int tipo;
        std::string baraja;
    public:
        Carta() {};
        Carta(int, char);
        int mostrar_info();
};

#endif