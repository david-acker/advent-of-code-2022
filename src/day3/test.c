#include "solution.h"

void test_get_priority_lowercase();
void test_get_priority_uppercase();

int main() {
    test_get_priority_lowercase();
    test_get_priority_uppercase();
}

void test_get_priority_lowercase() {
    char* message_template = "Lowercase priority was incorrect for %c. Expected %d, but was actually %d.\n";

    char current_character = 'a';
    int expected_priority = 1;

    int failure_count = 0;
    while (current_character <= 'z') {

        int actual_priority = get_priority(current_character);

        if (actual_priority != expected_priority) {
            printf(message_template, current_character, expected_priority, actual_priority);
            failure_count++;
        }

        current_character++;
        expected_priority++;
    }

    if (failure_count > 0) {
        printf("Failed: test_get_priority_lowercase [%d failures]\n", failure_count);
    }
    else {
        printf("Passed: test_get_priority_lowercase\n");
    }
}

void test_get_priority_uppercase() {
    char* message_template = "Uppercase priority was incorrect for %c. Expected %d, but was actually %d.\n";

    char current_character = 'A';
    int expected_priority = 27;

    int failure_count = 0;
    while (current_character <= 'Z') {

        int actual_priority = get_priority(current_character);

        if (actual_priority != expected_priority) {
            printf(message_template, current_character, expected_priority, actual_priority);
            failure_count++;
        }

        current_character++;
        expected_priority++;
    }

    if (failure_count > 0) {
        printf("Failed: test_get_priority_uppercase [%d failures]\n", failure_count);
    }
    else {
        printf("Passed: test_get_priority_uppercase\n");
    }
}
