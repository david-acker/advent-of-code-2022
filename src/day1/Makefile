CC=clang
CFLAGS=-I.

main: main.o leaderboard.o solution.o
	$(CC) main.o leaderboard.o solution.o -o main

main.o: main.c
	$(CC) -c main.c -o main.o

leaderboard.o: leaderboard.c
	$(CC) -c leaderboard.c -o leaderboard.o

solution.o: solution.c
	$(CC) -c solution.c -o solution.o

clean:
	rm main main.o leaderboard.o solution.o