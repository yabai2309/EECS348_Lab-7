#include "football.h"

// Array of available scoring plays.
static int scores[5] = {2, 3, 6, 7, 8};

// Recursive helper to count combinations.
static int countCombinationsHelper(int target, int index) {
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    int count = 0;
    // Only consider scoring plays from the current index onward to avoid duplicate combinations.
    for (int i = index; i < 5; i++) {
        count += countCombinationsHelper(target - scores[i], i);
    }
    return count;
}

int count_combinations(int points) {
    return countCombinationsHelper(points, 0);
}

// Recursive helper to print combinations.
// 'combination' array holds how many times each scoring play is used.
static void printCombinationsHelper(int target, int combination[5], int index) {
    if (target == 0) {
        // Format: Safety, FG, TD, TD+2, TD+FG.
        printf("Safety: %d, FG: %d, TD: %d, TD+2: %d, TD+FG: %d\n",
               combination[0], combination[1], combination[2], combination[3], combination[4]);
        return;
    }
    if (target < 0)
        return;
    for (int i = index; i < 5; i++) {
        combination[i] += 1;
        printCombinationsHelper(target - scores[i], combination, i);
        combination[i] -= 1;
    }
}

void print_combinations(int points) {
    int combination[5] = {0, 0, 0, 0, 0};
    printCombinationsHelper(points, combination, 0);
}