#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "jugador.h"
#include "juego.h"
#include "carta.h"

using namespace std;

Carta * deck_setup()
{
    Carta * baraja = new Carta[52];

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(j == 0) baraja[i*4 + j] = Carta(i+1, 'C');
            else if(j == 1) baraja[i*4 + j] = Carta(i+1, 'D');
            else if(j == 2) baraja[i*4 + j] = Carta(i+1, 'P');
            else baraja[i*4 + j] = Carta(i+1, 'T');
        }
    }
    return baraja;
}

int main()
{
    Juego game = Juego("interfaz.txt");
    //game.interfaz();

    Jugador player1 = Jugador("Clark", 1000);
    //player1.mostrar_info();

    Carta * baraja = deck_setup();
    for(int i = 0; i < 52; i++)
    {
        baraja[i].mostrar_info();
    }

    delete baraja;

    return 0;
}