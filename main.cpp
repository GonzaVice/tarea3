#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <list>
#include <algorithm>

#include "jugador.h"
#include "juego.h"
#include "carta.h"

using namespace std;

vector<Carta> deck_setup()
{
    vector<Carta> baraja = vector<Carta>();

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(j == 0) baraja.push_back(Carta(i+1, 'C'));
            else if(j == 1) baraja.push_back(Carta(i+1, 'D'));
            else if(j == 2) baraja.push_back(Carta(i+1, 'P'));
            else baraja.push_back(Carta(i+1, 'T'));
        }
    }

    random_shuffle(baraja.begin(), baraja.end());
    return baraja;
}

int main()
{
    Juego game = Juego("interfaz.txt");
    //game.interfaz();

    vector<Carta> mazo = vector<Carta>();
    vector<Jugador> players = vector<Jugador>();
    players.push_back(Jugador("Clark", 1000, mazo));
    players[0].mostrar_info();

    vector<Carta> baraja = deck_setup();

    for(int i = 0; i < 52; i++)
    {
        baraja[i].mostrar_info();
    }

    return 0;
}