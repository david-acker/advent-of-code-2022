CC=clang
CFLAGS=-I.

main: main.o leaderboard.o solution.o utils.o
	$(CC) main.o leaderboard.o solution.o utils.o -o main

main.o: main.c
	$(CC) -c main.c -o main.o

leaderboard.o: leaderboard.c
	$(CC) -c leaderboard.c -o leaderboard.o

solution.o: solution.c
	$(CC) -c solution.c -o solution.o

utils.o: utils.c
	$(CC) -c utils.c -o utils.o

clean:
	rm main main.o leaderboard.o solution.o utils.o