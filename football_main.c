#include <stdio.h>
#include <stdlib.h>
#include "football.h"

int main(int argc, char *argv[]) {
    int targetScore;

    // If a command-line argument is provided, use it.
    if (argc >= 2) {
        targetScore = atoi(argv[1]);
    } else {
        printf("Enter the NFL score (enter 0 or 1 to exit): ");
        if (scanf("%d", &targetScore) != 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }

    // Continue looping until the user enters 0 or 1.
    while (targetScore != 0 && targetScore != 1) {
        printf("\nPossible combinations of scoring plays if a team's score is %d:\n", targetScore);
        print_combinations(targetScore);
        int total = count_combinations(targetScore);
        printf("\nTotal number of combinations: %d\n", total);
        printf("\nEnter the NFL score (enter 0 or 1 to exit): ");
        if (scanf("%d", &targetScore) != 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }
    return 0;
}