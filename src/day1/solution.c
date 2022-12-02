#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leaderboard.h"

#define DEBUG 0
#if DEBUG
void printCurrentLeaderboard(Leaderboard* leaderboard) {
    printf("Leaderboard: ");
    for (int i = 0; i < leaderboard->count; i++) {
        printf("%d  ", leaderboard->values[i]);
    }
    printf("\n");
}
#endif 

int getHighestCombinedCalories(int* inputData, int length, int count) {

    Leaderboard* leaderboard = (Leaderboard*)malloc(sizeof(Leaderboard));
    leaderboard->values = (int*)calloc(sizeof(int), count);
    leaderboard->count = count;

    int total = 0;

    int index = 0;
    while (index < length) {

        int value = inputData[index];
        if (value > 0) {
            total += value;
        }
        else {
            add(leaderboard, total);

#if DEBUG
            printf("Added: %d\n", total);
            printCurrentLeaderboard(leaderboard);
#endif

            total = 0;
        }

        index++;
    }

    add(leaderboard, total);

#if DEBUG
    printf("Added: %d\n", total);
    printCurrentLeaderboard(leaderboard);
#endif

    int result = sum(leaderboard);

    free(leaderboard);

    return result;
}

int getHighestCalories(int* inputData, int length) {
    int current_total = 0;
    int highest_total = 0;

    int current_value;

    int index = 0;
    while (index < length) {
        current_value = *inputData;

        if (current_value > 0) {
            current_total += current_value;
        }
        else {
            if (current_total > highest_total) {
                highest_total = current_total;
            }
            current_total = 0;
        }

        index++;
        inputData++;
    }

    return highest_total;
}