CC=clang
CFLAGS=-I.

main: main.o solution.o
	$(CC) main.o solution.o -o main


main.o: main.c
	$(CC) -c main.c -o main.o

solution.o: solution.c
	$(CC) -c solution.c -o solution.o


clean:
	rm main main.o solution.o