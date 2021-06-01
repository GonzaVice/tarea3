#include <iostream>
#include <string>
#include <fstream>
#include "juego.h"

Juego::Juego(std::string archive)
{
    archivo = archive;
}

int Juego::interfaz()
{
    std::string printer;
    std::ifstream inter;

    inter.open("interfaz.txt");

    //inter >> printer;
    getline(inter, printer);
	while(inter)
    {
        std::cout << printer << std::endl;
		//inter >> printer;
        getline(inter, printer);
	}
	inter.close();

    return 0;
}