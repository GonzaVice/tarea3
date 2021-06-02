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

//Crea y revuelve las cartas
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

//Elección
int choose(Juego game)
{
    int choosed = 0;

    while(choosed != 4)
    {
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
            game.crear_jugador();
        }
        else if(choosed == 2)
        {
            game.eliminar_jugador();
        }
    }

    cout << "La cantidad de jugadores son: ";
    cout << game.jugadores.size() << endl;

    game.mostrar_jugadores();

    return choosed;
}

int main()
{
    //Atributo jugadores
    vector<Jugador> players = vector<Jugador>();

    //Atributo distribuidor
    vector<Carta> mazo_dealer = vector<Carta>();
    Jugador dealer = Jugador("CPU", 0, mazo_dealer);

    //Atributo baraja
    vector<Carta> baraja = deck_setup();

    /*
    for(int i = 0; i < 52; i++)
    {
        baraja[i].mostrar_info();
    }
    */

    //Creación clase juego
    Juego game = Juego("interfaz.txt", "save.txt", players, dealer, baraja);

    //Comienza elección
    int eleccion = choose(game);

    return 0;
}