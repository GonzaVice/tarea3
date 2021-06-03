CC = g++
exe = blackjack
flags = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

ver:
	$(CC) $(flags) -o main.o main.cpp -c
	$(CC) $(flags) -o jugador.o jugador.cpp -c
	$(CC) $(flags) -o juego.o juego.cpp -c
	$(CC) $(flags) -o carta.o carta.cpp -c
	$(CC) $(flags) -o $(exe) main.o jugador.o carta.o juego.o

run:
	./$(exe)

clear:
	rm -f *.o $(exe)