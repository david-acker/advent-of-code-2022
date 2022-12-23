#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_QUEUE 0
#define DEBUG_REMOVAL 0
#define DEBUG_SET 0

static inline int get_char_index(char character) {
    return (int)(character - 'a');
}

int get_signal_marker_index(FILE* fp, int char_queue_size) {
    fseek(fp, 0, SEEK_SET);

    int CHAR_SET_SIZE = 26;

    char* char_queue = (char*)calloc(char_queue_size, sizeof(char));
    int* char_set = (int*)calloc(CHAR_SET_SIZE, sizeof(int));

    int marker_index = -1;

    int character;
    int character_index = 0;
    while ((character = fgetc(fp)) != EOF) {

        if (character_index >= char_queue_size) {
            int removal_index = character_index % char_queue_size;
            char removed_char = char_queue[removal_index];
            
            int instance_count = 0;
            for (int j = 0; j < char_queue_size; j++) {
                if (char_queue[j] == removed_char) {
                    instance_count++;
                }
            }

            if (instance_count == 1) {
                char_set[get_char_index(removed_char)] = 0; 
            }

            #if DEBUG_REMOVAL
            printf("%d %c %d\n", removal_index, removed_char, instance_count);
            #endif
        }

        char_queue[(character_index % char_queue_size)] = (char)character;
        char_set[get_char_index((char)character)] = 1;

        #if DEBUG_QUEUE
        printf("Queue | ");
        for (int j = 0; j < char_queue_size; j++) {
            printf("%c", char_queue[j]);
        }
        printf("\n");
        #endif

        #if DEBUG_SET
        printf("Set   | ");
        int count = 0;
        for (int j = 0; j < CHAR_SET_SIZE; j++) {
            if (char_set[j] == 0) {
                printf("-");
            }
            else {
                count++;
                printf("%c", (char)(j + 'a'));
            }
        }
        printf(" Count: %d Last Index: %d", count, character_index);
        printf("\n");
        #endif

        if (character_index >= char_queue_size) {
            int total = 0;
            for (int j = 0; j < CHAR_SET_SIZE; j++) {
                int value = char_set[j];
                total += value;
            }

            if (total == char_queue_size) {
                marker_index = character_index;
                break;
            }
        }

        character_index++;
    }

    free(char_queue);
    free(char_set);

    return marker_index;
}