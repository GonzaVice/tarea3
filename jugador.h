#ifndef _PLYR
#define _PLYR

#include <string>

class Jugador
{
    private:
        std::string nombre;
        int dinero;
    public:
        Jugador() {};
        Jugador(std::string, int);
        int mostrar_info();
};

#endif