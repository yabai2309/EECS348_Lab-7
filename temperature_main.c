#include "temperature.h"//Include the necessary libraries
#include <stdio.h>

int main(int argc, char *argv[]) {//Declare main function
    float userInput; //Declare initial variables: user temperature input, current unit and target unit
    int currentScale; 
    int targetScale;
    printf("Enter the temperature: ");//Prompt user to input the temperature
    int temp1 = scanf("%f", &userInput);//Write it to the userInput if it's the correct format
    while (temp1 != 1){//If not, make user try again
        printf("Invalid number. Please try again: ");//Print out the message so user know
        clearInputBuffer();//Clear the current input buffer to avoid internal loop
        temp1 = scanf("%f", &userInput);// Read user input again
    }
    printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); // Prompt user to input the current unit
    int temp2 = scanf("%d", &currentScale);// Listen to user input
    while(temp2 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){ //If user input is not in the correct format or correct range of value, make them do it again
        printf("Invalid input. Please try again:");//Print out the message to reprompt user
        clearInputBuffer();//Clear the current input buffer to avoid internal loop
        temp2 = scanf("%d", &currentScale);// Listen to the user input again 
    }
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");//Prompt user to input the targer unit
    int temp3 = scanf("%d", &targetScale);//Listen to user input
    while(currentScale == targetScale || temp3 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){//If user input is not in the correct format or correct range of value, make them do it again
        printf("Invalid input. Please choose the convert unit again:");//Print out the message to reprompt user
        clearInputBuffer();//Clear the current input buffer to avoid internal loop
        temp3 = scanf("%d", &targetScale);// Listen to the user input again 
    }

    while( currentScale == 3 && userInput < 0){//If the current unit is Kelvin and it's a negative number, go through all of the input once again to reprompt user
        printf("Invalid Kelvin number to convert. Temperature cannot be negative.\n");//Print out the message to user
        printf("Enter the temperature: ");//Prompt user to enter another temperaturer
        temp1 = scanf("%f", &userInput);//Listen to the user input
        while (temp1 != 1){//Verify the user input like the block of code above
            printf("Invalid number. Please try again: ");
            clearInputBuffer();
            temp1 = scanf("%f", &userInput);
        }
        printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");//Print the prompt for the second input 
        temp2 = scanf("%d", &currentScale);//Listen from user
        while(temp2 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){//Verify and reprompt like above if needed
            printf("Invalid input. Please try again:");
            clearInputBuffer();
            temp2 = scanf("%d", &currentScale);
        }
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");//Print the prompt for the third input
        temp3 = scanf("%d", &targetScale);//Listem from user
        while(currentScale == targetScale || temp3 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){//Verify and reprompt like above until found the correct data
            printf("Invalid input. Please choose the convert unit again:");
            clearInputBuffer();
            temp3 = scanf("%d", &targetScale);
        }
    }
        switch (currentScale){//Switch-case to handle different program flow
            case 1://Current unit is celsius
                switch(targetScale){//Switch case to handle target unit
                    case 2://If target unit is farenheit
                        {float temp = celsius_to_fahrenheit(userInput);//Caculate the value
                        printf("Converted temperature: %.2f F", temp);//Print the value to user
                        break;}//Break the case
                    case 3://If the targer unit is kelvin
                        {float temp = celsius_to_kelvin(userInput);//Calculate the value
                        printf("Converted temperature: %.2f K", temp);//Print the value to user
                        break;}//Break the current case
                }
                categorizeTemp(userInput);//Print out the weather advisory
                break;//Break the current case
            case 2://Current unit is farenheit
                switch(targetScale){//Switch case to handle target unit
                    case 1://Target unit is celsius
                        {float temp = fahrenheit_to_celsius(userInput);//Calculate the value
                        printf("Converted temperature: %.2f C", temp);//Print the value to user
                        break;}//Break the current case
                    case 3://Target unit is kelvin
                        {float temp = celsius_to_kelvin(fahrenheit_to_celsius(userInput));//Calculate the value
                        printf("Converted temperature: %.2f K", temp);//Print the value to user
                        break;}//Break the current case
                }
                categorizeTemp(fahrenheit_to_celsius(userInput));//Print out the weather advisory
                break;//Break the current case
            case 3://Current unit is kelvin
                switch(targetScale){//Switch case to handle target unit
                    case 1://Target unit is celsius
                        {float temp = kelvin_to_celsius(userInput);//Calculate the value
                        printf("Converted temperature: %.2f C", temp);//Print the value to user
                        break;}//Break the current case
                    case 2://Target unit is farenheit
                        {float temp = celsius_to_fahrenheit(kelvin_to_celsius(userInput));
                        printf("Converted temperature: %.2f F", temp);//Print the value to user
                        break;}//Break the current case
                }
                categorizeTemp(kelvin_to_celsius(userInput));//Print out the weather advisory
                break;//Break the current case
    }
    
    return 0;//End the main program and return 0
}
