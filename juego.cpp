#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    distruibidor = dealer;

    //Vector de cartas
    baraja = deck;
}

void Juego::interfaz()
{
    string printer;
    ifstream inter;

    inter.open("interfaz.txt");

    getline(inter, printer);
	while(inter)
    {
        cout << printer << endl;
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
    for(int i = 0; i < jugadores.size(); i++)
    {
        Carta first_card = baraja.back();
        baraja.pop_back();
        jugadores[i].mazo.push_back(first_card);

        Carta second_card = baraja.back();
        baraja.pop_back();
        jugadores[i].mazo.push_back(second_card);

        cout << " Jugador " << jugadores[i].nombre << endl;
        cout << jugadores[i].mazo[0].mostrar_info();
        cout << jugadores[i].mazo[1].mostrar_info() << endl;
    }
    return;
}

void Juego::table_init()
{
    if(jugadores.size() <= 0)
    {
        cout << "No hay jugadores disponibles, agrega uno.\n";
        return;
    }
    else
    {
        repartir_cartas();
    }
    return;
}