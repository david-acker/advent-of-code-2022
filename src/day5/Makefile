CC=clang
CFLAGS=-I.

main: main.o solution.o stack.o utils.o
	$(CC) main.o solution.o stack.o utils.o -o main


main.o: main.c
	$(CC) -c main.c -o main.o

solution.o: solution.c
	$(CC) -c solution.c -o solution.o

stack.o: stack.c
	$(CC) -c stack.c -o stack.o

utils.o: utils.c
	$(CC) -c utils.c -o utils.o


clean:
	rm main main.o solution.o stack.o utils.o