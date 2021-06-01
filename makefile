CC = g++
exe = blackjack

ver:
	$(CC) -o main.o main.cpp -c
	$(CC) -o jugador.o jugador.cpp -c
	$(CC) -o juego.o juego.cpp -c
	$(CC) -o carta.o carta.cpp -c
	$(CC) -o $(exe) main.o jugador.o carta.o juego.o

run:
	./$(exe)

clear:
	rm -f *.o $(exe)