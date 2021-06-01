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

    Carta card1 = Carta('K', "Corazón");
    Carta card2 = Carta('T', "Diamante");
    Carta card3 = Carta('9', "Pica");
    Carta card4 = Carta('6', "Trébol");

    card1.mostrar_info();
    card2.mostrar_info();
    card3.mostrar_info();
    card4.mostrar_info();

    Jugador player1 = Jugador("Clark", 1000);
    player1.mostrar_info();

    return 0;
}