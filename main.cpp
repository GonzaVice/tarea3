#include <iostream>
#include <fstream>
#include <string>

#include "jugador.h"
#include "juego.h"
#include "carta.h"

using namespace std;

int main()
{
    Juego game = Juego("interfaz.txt");
    game.interfaz();

    Jugador player1 = Jugador("Clark", 1000);
    player1.mostrar_info();

    return 0;
}