#include <stdio.h>//Include necessary library
#include "temperature.h"

float celsius_to_fahrenheit(float celsius) {//Convert celsius to fahrenheit
    return (9.0/5.0)*celsius + 32;//Return the value directly
}

float fahrenheit_to_celsius(float fahrenheit){//Convert fahrenheit to celsius
    return (5.0/9.0)*(fahrenheit-32);//Return the value directly
}

float celsius_to_kelvin(float celsius){//Convert celsius to kelvin
    return celsius + 273.15;//Return the value directly
}

float kelvin_to_celsius(float kelvin){//Convert kelvin to celsius
    return kelvin - 273.15;//Return the value directly
}

void categorizeTemp(float C){//Function to print out appropriate weather advisory based on the requirement
    if (C < 0){
        printf("\nTemperature category: Freezing");
        printf("\nWeather advisory: Bring gloves and dress warm");
    } else if (C > 0 && C < 10){
        printf("\nTemperature category: Cold");
        printf("\nWeather advisory: Wear a jacket");
    } else if (C > 10 && C < 15){
        printf("\nTemperature category: Comfortable");
        printf("\nWeather advisory: Nice weather for outdoor activities");
    } else if (C > 25 && C < 35){
        printf("\nTemperature category: Hot");
        printf("\nWeather advisory: Remember your sunscreen!");
    } else {
        printf("\nTemperature category: Extreme Heat");
        printf("\nWeather advisory: Avoid going out middle of the day");
    }
}
void clearInputBuffer(void) {//Function to clear out the input buffer when user input the wrong data
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}