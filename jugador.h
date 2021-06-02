#ifndef _PLYR
#define _PLYR

#include <string>
#include <vector>
#include "carta.h"

class Jugador
{
    public:
        //Atributos
        std::string nombre;
        int dinero;
        std::vector<Carta> mazo;
        
        //Métodos
        Jugador() {};
        Jugador(std::string, int, std::vector<Carta>);
        int mostrar_info();
};

#endif