#ifndef __REPORT_H__
#define __REPORT_H__

/* Add any function signatures you need here but do not modify the existing ones */

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 * 
 * @param celsius
 * @return float
 */
float celsius_to_fahrenheit(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 * 
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_celsius(float fahrenheit);

/**
 * @brief Convert temperature in Celsius to Kelvin
 * 
 * @param celsius
 * @return float
 */
float celsius_to_kelvin(float celsius);

/**
 * @brief Convert temperature in Kelvin to Celsius
 * 
 * @param celsius
 * @return float
 */
float kelvin_to_celsius(float celsius);

/**
 * @brief Categorize temperature and print out the corresponding advisory info
 * 
 * @param celsius
 * @return none
 */
void categorizeTemp(float C);

/**
 * @brief Clear the input buffer to handle mistyped user input
 * 
 * @param none
 * @return none
 */
void clearInputBuffer();
#endif /* __REPORT_H__ */
