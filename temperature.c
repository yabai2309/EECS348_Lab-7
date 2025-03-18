#include <stdio.h>
#include "temperature.h"

float celsius_to_fahrenheit(float celsius){
    return (9.0/5.0)*celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (5.0/9.0)*(fahrenheit-32);
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

void categorizeTemp(float C){
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
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}