#ifndef LEADERBOARD
#define LEADERBOARD

typedef struct leaderboard {
    int* values;
    int count;
} 
Leaderboard;

void add(Leaderboard* leaderboard, int value);
int sum(Leaderboard* leaderboard);

#endif