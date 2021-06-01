#ifndef _PLYR
#define _PLYR

#include <string>
#include <vector>
#include "carta.h"

class Jugador
{
    private:
        std::string nombre;
        int dinero;
        std::vector<Carta> mazo;
    public:
        Jugador() {};
        Jugador(std::string, int, std::vector<Carta>);
        int mostrar_info();
};

#endif