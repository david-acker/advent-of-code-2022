CC=clang
CFLAGS=-I.

main: main.o solution.o utils.o
	$(CC) main.o solution.o utils.o -o main

test: test.o solution.o utils.o
	$(CC) test.o solution.o utils.o -o test


main.o: main.c
	$(CC) -c main.c -o main.o

solution.o: solution.c
	$(CC) -c solution.c -o solution.o

test.o: test.c
	$(CC) -c test.c -o test.o

utils.o: utils.c
	$(CC) -c utils.c -o utils.o


clean:
	rm main main.o solution.o utils.o