#ifndef _CARD
#define _CARD

class Carta
{
    private:
        char tipo;
        char baraja;
    public:
        Carta() {};
        Carta(char, char);
        int mostrar_info();
};

#endif