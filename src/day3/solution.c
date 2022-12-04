#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int get_priority(char character);
int get_priority_sum(InputRow* row);
int get_badge_priority(InputRow** rows, int start, int length);

int get_sum_of_priorities(Input* input) {

    int total_priority_sum = 0;

    for (int i = 0; i < input->length; i++) {
        total_priority_sum += get_priority_sum(input->rows[i]);
    }

    return total_priority_sum;
}

int get_priority_sum(InputRow* row) {

    int prioritySum = 0;

    int* priority_record = calloc(52, sizeof(int));

    int midpoint = row->length / 2;

    for (int i = 0; i < midpoint; i++) {
        char character = row->data[i];
        int priority = get_priority(character);

        priority_record[priority - 1] = 1;
    }

    for (int i = midpoint; i < row->length; i++) {
        char character = row->data[i];
        if (character == '\n' || character == '\0') {
            break;
        }

        int priority = get_priority(character);

        if (priority_record[priority - 1] == 1) {

            prioritySum += priority;
            priority_record[priority - 1] = 0;
        }
    }

    free(priority_record);

    return prioritySum;
}

int get_priority(char character) {
    int value = (int)character;

    // Lowercase characters
    if (value >= 97) {
        return value - (int)'a' + 1;
    }

    // Uppercase characters
    return value - (int)'A' + 27;
}

int get_sum_of_badge_priorities(Input* input) {

    int group_size = 3;
    int group_count = input->length / group_size;

    int priority_sum = 0;

    for (int i = 0; i < group_count; i++) {

        int start = i * group_size;
        int length = group_size;
        priority_sum += get_badge_priority(input->rows, start, length);
    }

    return priority_sum;
}

int get_badge_priority(InputRow** rows, int start, int length) {

    int priority_record_size = 52;
    int* total_priority_record = calloc(priority_record_size, sizeof(int));

    for (int i = start; i < (start + length); i++) {

        InputRow* row = rows[i];

        int* priority_record = calloc(priority_record_size, sizeof(int));

        for (int j = 0; j < row->length; j++) {
            char character = row->data[j];
            int priority = get_priority(character);

            if (priority_record[priority - 1] == 0) {
                priority_record[priority - 1] = 1;

                total_priority_record[priority - 1]++;
            }
        }

        free(priority_record);
    }

    int badge_priority_sum = 0;

    int match_count = 0;
    for (int i = 0; i < priority_record_size; i++) {
        if (total_priority_record[i] == length) {
            badge_priority_sum += i + 1;
            match_count++;
        }
    }

    free(total_priority_record);

    return badge_priority_sum;
}
