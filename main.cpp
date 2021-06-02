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

int crear_jugador()
{
    string name;
    cout << "Escribe su nombre: ";
    cin >> name;
    return 0;
}

int choose()
{
    int choosed;
    cout << "Selecciona acción (1 a 4)\n";
    cout << "  1) Crear jugador nuevo\n";
    cout << "  2) Eliminar jugador\n";
    cout << "  3) Iniciar mesa\n";
    cout << "  4) Salir del Juego\n";

    cin >> choosed;
    while(choosed < 1 || choosed > 4)
    {
        cout << "\nEscoge bien tu opción\n";
        cin >> choosed;
    }

    if(choosed == 1)
    {
        crear_jugador();
    }

    return choosed;
}

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
    vector<Carta> mazo = vector<Carta>();
    vector<Jugador> players = vector<Jugador>();
    players.push_back(Jugador("Clark", 1000, mazo));
    //players[0].mostrar_info();

    vector<Carta> mazo_dealer = vector<Carta>();
    Jugador dealer = Jugador("CPU", 1000, mazo_dealer);

    vector<Carta> baraja = deck_setup();

    for(int i = 0; i < 52; i++)
    {
        baraja[i].mostrar_info();
    }

    Juego game = Juego("interfaz.txt", "save.txt", players, dealer, mazo);
    //game.interfaz();

    int eleccion = choose();

    return 0;
}