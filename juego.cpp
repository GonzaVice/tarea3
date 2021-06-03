#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "juego.h"
#include "carta.h"
#include "jugador.h"

using namespace std;

Juego::Juego(string archive, string save, vector<Jugador> players, Jugador dealer, vector<Carta> deck)
{
    //Nombre de archivo de la interfaz
    archivo = archive;

    //Nombre de archivo de guardado
    guardado = save;

    //Vector de jugadores
    jugadores = players;

    //Jugador dealer
    distribuidor = dealer;

    //Vector de cartas
    baraja = deck;
}

void Juego::interfaz()
{
    int tabs = 0;
    string printer;
    ifstream inter;

    inter.open("interfaz.txt");

    tabs++;
    getline(inter, printer);
	while(inter)
    {
        if(tabs == 17)
        {
            cout << "│        │                   │ ";
            cout << distribuidor.mazo[0].print_value();
            cout << "│  │                  │         │\n";
        }
        else
        {
            cout << printer << endl;
        }

        tabs++;
        getline(inter, printer);
	}
	inter.close();

    return;
}

void Juego::mostrar_jugadores()
{
    for(int i = 0; i < jugadores.size(); i++)
    {
        cout << i+1 << ") " << jugadores[i].nombre << " y $" << jugadores[i].dinero << endl;
    }
    return;
}

void Juego::crear_jugador()
{
    //Definición
    string name;
    int money;
    vector<Carta> mazo = vector<Carta>();

    //I/0
    cout << "Escribe su nombre: ";
    cin >> name;
    cout << "¿Cuanto dinero quieres usar?: ";
    cin >> money;

    //Creación jugador
    Jugador player = Jugador(name, money, mazo);
    
    //Dentro de vector<Jugador> jugadores
    jugadores.push_back(player);

    //Retornar
    return;
}

void Juego::eliminar_jugador()
{
    if(jugadores.size() <= 0)
    {
        cout << "No hay jugadores que eliminar\n";
    }
    else
    {
        int eleccion;

        cout << "Jugadores:\n";
        for(int i = 0; i < jugadores.size(); i++)
        {
            cout << i+1 << ") " << jugadores[i].nombre << " y $" << jugadores[i].dinero << endl;
        }
        cout << "Escoge que jugador quieres eliminar: (1 a " << jugadores.size() << ") ";
        cin >> eleccion;
        while(eleccion < 1 || eleccion > jugadores.size())
        {
            cout << "Dato erroneo, escoge nuevamente.\n";
            cout << "Escoge que jugador quieres eliminar: (1 a " << jugadores.size() << ") ";
            cin >> eleccion;
        }
        jugadores.erase(jugadores.begin()+(eleccion-1));
    }
    return;
}

void Juego::repartir_cartas()
{
    Carta first_card;
    Carta second_card;

    for(int i = 0; i < jugadores.size(); i++)
    {
        first_card = baraja.back();
        baraja.pop_back();
        jugadores[i].mazo.push_back(first_card);

        second_card = baraja.back();
        baraja.pop_back();
        jugadores[i].mazo.push_back(second_card);

        cout << " Jugador " << jugadores[i].nombre << endl;
        jugadores[i].mazo[0].mostrar_info();
        jugadores[i].mazo[1].mostrar_info();
    }

    return;
}

void Juego::repartir_dealer()
{
    // Definición
    Carta first_card;
    Carta second_card;

    // Saca baraja y entrega a Dealer
    first_card = baraja.back();
    baraja.pop_back();
    distribuidor.mazo.push_back(first_card);

    second_card = baraja.back();
    baraja.pop_back();
    distribuidor.mazo.push_back(second_card);

    cout << " Jugador " << distribuidor.nombre << endl;
    distribuidor.mazo[0].mostrar_info();
    distribuidor.mazo[1].mostrar_info();

    // Si ambos valores posibles no suman mayor que 17
    while(distribuidor.mazo[0].value_1 + distribuidor.mazo[1].value_1 < 17 &&
        distribuidor.mazo[0].value_2 + distribuidor.mazo[1].value_2 < 17)
        {
            cout << "AGAIN\n";

            // Retorno de cartas al mazo
            first_card = distribuidor.mazo.back();
            distribuidor.mazo.pop_back();
            baraja.push_back(first_card);

            second_card = distribuidor.mazo.back();
            distribuidor.mazo.pop_back();
            baraja.push_back(second_card);

            // Revuelve baraja
            random_shuffle(baraja.begin(), baraja.end());

            // Saca baraja de nuevo
            first_card = baraja.back();
            baraja.pop_back();
            distribuidor.mazo.push_back(first_card);

            second_card = baraja.back();
            baraja.pop_back();
            distribuidor.mazo.push_back(second_card);

            cout << " Jugador " << distribuidor.nombre << endl;
            distribuidor.mazo[0].mostrar_info();
            distribuidor.mazo[1].mostrar_info();
        }
    cout << "NO PROBLEMO\n";

    return;

}

void Juego::begin_game()
{
    interfaz();
    return;
}

void Juego::table_init()
{
    int i;
    if(jugadores.size() <= 0)
    {
        cout << "No hay jugadores disponibles, agrega uno.\n";
        return;
    }
    else
    {
        repartir_cartas();
        repartir_dealer();
        begin_game();
        cout << "Presiona 0 para continuar.";
        cin >> i;
    }
    return;
}