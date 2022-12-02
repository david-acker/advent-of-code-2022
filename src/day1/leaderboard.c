#include <stdio.h>

typedef struct leaderboard {
    int* values;
    int count;
} 
Leaderboard;

void add(Leaderboard* leaderboard, int value) {

    if (value <= leaderboard->values[0]) {
        return;
    }

    for (int i = 1; i < leaderboard->count; i++) {

        if (value <= leaderboard->values[i]) {
            leaderboard->values[i - 1] = value;
            return;
        }
    }

    for (int i = 0; i < leaderboard->count - 1; i++) {
        leaderboard->values[i] = leaderboard->values[i + 1];
    }

    leaderboard->values[leaderboard->count - 1] = value;
}

int sum(Leaderboard* leaderboard) {
    int sum = 0;

    for (int i = 0; i < leaderboard->count; i++) {
        sum += leaderboard->values[i];
    }

    return sum;
}