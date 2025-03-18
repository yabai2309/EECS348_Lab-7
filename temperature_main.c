#include "temperature.h"

int main(int argc, char *argv[]) {
    float userInput;
    int currentScale;
    int targetScale;
    printf("Enter the temperature: ");
    int temp1 = scanf("%f", &userInput);
    while (temp1 != 1){
        printf("Invalid number. Please try again: ");
        clearInputBuffer();
        temp1 = scanf("%f", &userInput);
    }
    printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    int temp2 = scanf("%d", &currentScale);
    while(temp2 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){
        printf("Invalid input. Please try again:");
        clearInputBuffer();
        temp2 = scanf("%d", &currentScale);
    }
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    int temp3 = scanf("%d", &targetScale);
    while(currentScale == targetScale || temp3 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){
        printf("Invalid input. Please choose the convert unit again:");
        clearInputBuffer();
        temp3 = scanf("%d", &targetScale);
    }

    while( currentScale == 3 && userInput < 0){
        printf("Invalid Kelvin number to convert. Temperature cannot be negative.\n");
        printf("Enter the temperature: ");
        temp1 = scanf("%f", &userInput);
        while (temp1 != 1){
            printf("Invalid number. Please try again: ");
            clearInputBuffer();
            temp1 = scanf("%f", &userInput);
        }
        printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        temp2 = scanf("%d", &currentScale);
        while(temp2 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){
            printf("Invalid input. Please try again:");
            clearInputBuffer();
            temp2 = scanf("%d", &currentScale);
        }
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        temp3 = scanf("%d", &targetScale);
        while(currentScale == targetScale || temp3 != 1 || (currentScale != 1 && currentScale != 2 && currentScale != 3)){
            printf("Invalid input. Please choose the convert unit again:");
            clearInputBuffer();
            temp3 = scanf("%d", &targetScale);
        }
    }
        switch (currentScale){
            case 1:
                switch(targetScale){
                    case 2:
                        {float temp = celsius_to_fahrenheit(userInput);
                        printf("Converted temperature: %.2f F", temp);
                        break;}
                    case 3:
                        {float temp = celsius_to_kelvin(userInput);
                        printf("Converted temperature: %.2f K", temp);
                        break;}
                }
                categorizeTemp(userInput);
                break;
            case 2:
                switch(targetScale){
                    case 1:
                        {float temp = fahrenheit_to_celsius(userInput);
                        printf("Converted temperature: %.2f C", temp);
                        break;}
                    case 3:
                        {float temp = celsius_to_kelvin(fahrenheit_to_celsius(userInput));
                        printf("Converted temperature: %.2f K", temp);
                        break;}
                }
                categorizeTemp(fahrenheit_to_celsius(userInput));
                break;
            case 3:
                switch(targetScale){
                    case 1:
                        {float temp = kelvin_to_celsius(userInput);
                        printf("Converted temperature: %.2f C", temp);
                        break;}
                    case 2:
                        {float temp = celsius_to_fahrenheit(kelvin_to_celsius(userInput));
                        printf("Converted temperature: %.2f F", temp);
                        break;}
                }
                categorizeTemp(kelvin_to_celsius(userInput));
                break;
    }
    
    return 0;
}
