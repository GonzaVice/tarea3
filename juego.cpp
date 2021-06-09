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

void Juego::load()
{
    ifstream loading;
    loading.open(guardado);

    int size;
    string name;
    int money;

    loading >> size;
    for(int i = 0; i < size; i++)
    {
        loading >> name;
        loading >> money;

        vector<Carta> mazo = vector<Carta>();
        Jugador player = Jugador(name, money, mazo);

        jugadores.push_back(player);
    }

    loading.close();

    return;
}

void Juego::save()
{
    ofstream saving;
    saving.open(guardado);

    saving << jugadores.size() << endl;

    for(int i = 0; i < (int)jugadores.size(); i++)
    {
        saving << jugadores[i].nombre << endl;
        saving << jugadores[i].dinero << endl;
    }

    saving.close();

    return;
}

void Juego::interfaz(int results)
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
            if(results == 0)
            {
                cout << "│        │                   │";
                cout << distribuidor.mazo[0].print_value();
                cout << " │  │                  │         │\n";
            }
            else
            {
                cout << "│        │                   │";
                cout << distribuidor.mazo[0].print_value();
                cout << " │";
                cout << distribuidor.mazo[1].print_value();
                cout << " │                  │         │\n"; 
            }
        }
        else if(tabs == 18)
        {
            if(results == 0)
            {
                cout << "│        │                   │ ";
                cout << distribuidor.mazo[0].print_sign();
                cout << "│  │                  │         │\n";
            }
            else
            {
                cout << "│        │                   │ ";
                cout << distribuidor.mazo[0].print_sign();
                cout << "│ ";
                cout << distribuidor.mazo[1].print_sign();
                cout << "│                  │         │\n";
            }
        }
        else if(tabs == 26)
        {
            cout << "│     ";
            for(int i = 0; i < (int)jugadores.size(); i++)
            {
                cout << "|";
                cout << jugadores[i].mazo[0].print_value();
                cout << " │";
                cout << jugadores[i].mazo[1].print_value();
                cout << " │ ";
            }
            for(int j = 0; j < (int)(7 - jugadores.size()); j++)
            {
                cout << "│  │  │ ";
            }
            cout << "  │\n";
        }
        else if(tabs == 27)
        {
            cout << "│     ";
            for(int i = 0; i < (int)jugadores.size(); i++)
            {
                cout << "| ";
                cout << jugadores[i].mazo[0].print_sign();
                cout << "│ ";
                cout << jugadores[i].mazo[1].print_sign();
                cout << "│ ";
            }
            for(int j = 0; j < (int)(7 - jugadores.size()); j++)
            {
                cout << "│  │  │ ";
            }
            cout << "  │\n";
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
    for(int i = 0; i < (int)jugadores.size(); i++)
    {
        cout << i+1 << ") " << jugadores[i].nombre << " y $" << jugadores[i].dinero << endl;
    }
    return;
}

void Juego::crear_jugador()
{
    if((int)jugadores.size() >= 0 && (int)jugadores.size() < 7)
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
    else
    {
        cout << "Ya hay demasiados jugadores.\n";
    }
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
        for(int i = 0; i < (int)jugadores.size(); i++)
        {
            cout << i+1 << ") " << jugadores[i].nombre << " y $" << jugadores[i].dinero << endl;
        }
        cout << "Escoge que jugador quieres eliminar: (1 a " << jugadores.size() << ") ";
        cin >> eleccion;
        while(eleccion < 1 || eleccion > (int)jugadores.size())
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
    random_shuffle(baraja.begin(), baraja.end());

    Carta first_card;
    Carta second_card;

    for(int i = 0; i < (int)jugadores.size(); i++)
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

    cout << distribuidor.mazo[0].value_1 + distribuidor.mazo[1].value_1 << " < 17\n";
    cout << distribuidor.mazo[0].value_2 + distribuidor.mazo[1].value_2 << " < 17\n";

    // Si ambos valores posibles no suman mayor que 17
    while(distribuidor.mazo[0].value_1 + distribuidor.mazo[1].value_1 < 17 && distribuidor.mazo[0].value_2 + distribuidor.mazo[1].value_2 < 17)
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

            cout << distribuidor.mazo[0].value_1 + distribuidor.mazo[1].value_1 << " < 17\n";
            cout << distribuidor.mazo[0].value_2 + distribuidor.mazo[1].value_2 << " < 17\n";
        }
    cout << "NO PROBLEMO\n";

    distribuidor.mazo[0].blackjack_value();
    distribuidor.mazo[1].blackjack_value();

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
        random_shuffle(baraja.begin(), baraja.end());
        repartir_cartas();
        repartir_dealer();
        begin_game();
        cout << "Presiona 0 para continuar.";
        cin >> i;
    }
    return;
}

void Juego::begin_game()
{
    
    int choosed;

    for(int i = 0; i < (int)jugadores.size(); i++)
    {
        Carta first_card = jugadores[i].mazo[0];
        Carta second_card = jugadores[i].mazo[1];

        baraja.push_back(first_card);
        baraja.push_back(second_card);

        jugadores[i].mazo.pop_back();
        jugadores[i].mazo.pop_back();

        random_shuffle(baraja.begin(), baraja.end());

        first_card = baraja.back();
        baraja.pop_back();
        second_card = baraja.back();
        baraja.pop_back();

        jugadores[i].mazo.push_back(first_card);
        jugadores[i].mazo.push_back(second_card);

        random_shuffle(baraja.begin(), baraja.end());
    }

    repartir_dealer();

    system("clear");
    for(int i = 0; i < (int)jugadores.size(); i++)
    {
        //system("clear");
        interfaz(0);

        int apuesta;

        cout << "\nJugador " << i+1 << ": " << jugadores[i].nombre << endl;
        cout << "\nDinero: " << jugadores[i].dinero << endl;

        cout << "\nCon cuanto quiere apostar:\n $";
        cin >> apuesta;

        while(apuesta > jugadores[i].dinero)
        {
            cout << "\nEstás apostando una cantidad más grande de la que tiene.\n";
            cout << "\nCon cuanto quiere apostar:\n $";
            cin >> apuesta;
        }
        jugadores[i].apuesta = apuesta;
        jugadores[i].dinero -= jugadores[i].apuesta;

        cout << "\n Selecciona acción:\n";
        cout << "  1) Pedir\n";
        cout << "  2) Plantarse\n";
        cout << "  3) Dividir\n";
        cout << "  4) Retirarse\n";

        cout << "\nElige del 1 al 4: ";
        cin >> choosed;
        while(choosed < 1 || choosed > 4)
        {
            cout << "\nEscoge bien tu opción\n";
            cout << "\nElige del 1 al 4: ";
            cin >> choosed;
        }

        if(choosed == 1)
        {
            ask_card(i);
        }
        else if(choosed == 3)
        {
            cout << "Funcionalidad aun no hecha\n";
        }
        else if(choosed == 4)
        {
            retirar_jugador(i);
        }
    }

    interfaz(1);
    results();

    return;
}

void Juego::ask_card(int pos)
{
    int choosed = 0;

    cout << "Escoge cual de las dos cartas que tienes quieres cambiar:\n";
    cout << " 1) ";
    jugadores[pos].mazo[0].mostrar_info();
    cout << " 2) ";
    jugadores[pos].mazo[1].mostrar_info();
    
    cout << "(1 o 2): ";
    cin >> choosed;

    while(choosed < 1 || choosed > 2)
    {
        cout << "Escoge bien la opción\n";
        cout << "(1 o 2): ";
        cin >> choosed;
    }

    Carta cardJ;
    Carta cardB;

    if(choosed == 1)
    {
        cardJ = jugadores[pos].mazo[0];
        jugadores[pos].mazo[0] = jugadores[pos].mazo[1];
        jugadores[pos].mazo[1] = cardJ;
    }

    cardB = baraja.back();
    baraja.pop_back();
    cardJ = jugadores[pos].mazo.back();
    jugadores[pos].mazo.pop_back();

    baraja.push_back(cardJ);
    jugadores[pos].mazo.push_back(cardB);
    
    random_shuffle(baraja.begin(), baraja.end());

    return;
}

void Juego::results()
{
    for(int i = 0; i < (int)jugadores.size(); i++)
    {
        int resultado_j = jugadores[i].mazo[0].value_2 + jugadores[i].mazo[1].value_2;
        int resultado_d = distribuidor.mazo[0].value_2 + distribuidor.mazo[1].value_2;

        cout << "\nResultado del Jugador " << i+1 << ": " << jugadores[i].nombre << endl;
        if(resultado_j > resultado_d)
        {
            if(resultado_j == 21)
            {
                jugadores[i].apuesta += (jugadores[i].apuesta*1.5);
                cout << "Hiciste Black Jack y ganaste contra el dealer.\nGanas tres dobles de lo que apostaste!\n";
            }
            else
            {
                if(jugadores[i].apuesta >= 10)
                {
                    jugadores[i].apuesta += (jugadores[i].apuesta*2);
                    cout << "Ganaste contra el dealer y apostaste mas de $10.\nGanas el doble de lo que apostaste!\n";
                }
                else
                {
                    jugadores[i].apuesta += jugadores[i].apuesta;
                    cout << "Ganaste contra el dealer.\nGanas lo mismo que apostaste!\n";
                }
            }
        }
        else if(resultado_j < resultado_d)
        {
            jugadores[i].apuesta = 0;
            cout << "Perdiste contra dealer.\nPierdes la apuesta!";
        }
        else
        {
            if(resultado_j == 21)
            {
                cout << "Igualaste al dealer con Black Jack.\nNo ganaste ni perdiste.\n";
            }
            else
            {
                cout << "Igualaste al dealer.\nNo ganaste ni perdiste.\n";
            }
        }
        jugadores[i].dinero += jugadores[i].apuesta;
        
        cout << "Dinero del Jugador " << i+1 << ": " << jugadores[i].nombre << endl;
        cout << " $" << jugadores[i].dinero << endl << endl;

    }
    return;
}

void Juego::retirar_jugador(int pos)
{
    Carta first_card = jugadores[pos].mazo[0];
    Carta second_card = jugadores[pos].mazo[1];

    baraja.push_back(first_card);
    baraja.push_back(second_card);

    jugadores[pos].mazo.pop_back();
    jugadores[pos].mazo.pop_back();

    random_shuffle(baraja.begin(), baraja.end());

    jugadores.erase(jugadores.begin()+(pos));
}