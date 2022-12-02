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

    int index = leaderboard->count - 1;
    for (int i = 1; i < leaderboard->count; i++) {

        if (value <= leaderboard->values[i]) {
            index = i - 1;
            break;
        }
    }

    for (int i = 0; i < index; i++) {
        leaderboard->values[i] = leaderboard->values[i + 1];
    }

    leaderboard->values[index] = value;
}

int sum(Leaderboard* leaderboard) {
    int sum = 0;

    for (int i = 0; i < leaderboard->count; i++) {
        sum += leaderboard->values[i];
    }

    return sum;
}