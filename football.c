#include "football.h"
#include <stdio.h>


static int scores[5] = {2, 3, 6, 7, 8};// Array of available scoring plays

// Recursive helper function to count the number of combinations
static int countCombinationsHelper(int target, int index) {
    if (target == 0) //If the number is 0, stop and return the value 1
        return 1;
    if (target < 0)// If the number is smaller than 0, stop and return the value 0
        return 0;
    int count = 0;//Start declare the count variable to return it back to user
    for (int i = index; i < 5; i++) {// Loop through the available scoring plays to see the number of combination
        count += countCombinationsHelper(target - scores[i], i);//Recursive function to count
    }
    return count;//Return the value back to the user
}

int count_combinations(int points) {//Main count function that using both user input and start the loop from 0
    return countCombinationsHelper(points, 0);
}

// Recursive helper to print combinations
static void printCombinationsHelper(int target, int combination[5], int index) {
    if (target == 0) {// Target = 0 means we've already found the combination that works
        // Format: Safety, FG, TD, TD+2, TD+FG.
        printf("Safety: %d, FG: %d, TD: %d, TD+2: %d, TD+FG: %d\n", combination[0], combination[1], combination[2], combination[3], combination[4]); // Print out that combination
        return;//End the function
    }
    if (target < 0)//If target < 0, means that's a wrong combination, so discard it
        return;//End function without printing anything
    for (int i = index; i < 5; i++) {//Loop through each plays in the plays array
        combination[i] += 1;//Add that number to the combination array to mark it
        printCombinationsHelper(target - scores[i], combination, i);//Pass the new value after subtracting the plays value from target score, and do recursion
        combination[i] -= 1;//After the function return, just pop away the combination that we've just added
    }
}

void print_combinations(int points) {//Main print out function that take points as the input
    int combination[5] = {0, 0, 0, 0, 0};//Declare the points combination
    printCombinationsHelper(points, combination, 0);//Pass the blank combination in and start the recursion
}