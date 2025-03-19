#include <stdio.h> // Include the necessary library
#include <stdlib.h>
#include "football.h"

int main(int argc, char *argv[]) { //Main function start
    int targetScore;//Declare variable for user input

    // If a command-line argument is provided, use it
    if (argc >= 2) {
        targetScore = atoi(argv[1]);//Extract info from the command line
    } else { //Else, prompt user to input the number
        printf("Enter the NFL score (enter 0 or 1 to exit): ");
        if (scanf("%d", &targetScore) != 1) {//Read user input and raise error if needed
            fprintf(stderr, "Invalid input.\n");//Print out the error
            return 1;//End main and return a number
        }
    }

    // Continue looping until the user enters 0 or 1.
    while (targetScore != 0 && targetScore != 1) {//While the input is not 0 or 1, keep asking user
        printf("\nPossible combinations of scoring plays if a team's score is %d:\n", targetScore);//Print out the output for the current target score
        print_combinations(targetScore);//Call function that print the combinations
        int total = count_combinations(targetScore);//Call function that return the number of combination
        printf("\nTotal number of combinations: %d\n", total);//Print that out to user
        printf("\nEnter the NFL score (enter 0 or 1 to exit): ");//Prompt user again
        if (scanf("%d", &targetScore) != 1) {//Handle the error case
            fprintf(stderr, "Invalid input.\n");//Print out the error to user
            return 1;//End main and return a number
        }
    }
    return 0;//End main after program done executed
}