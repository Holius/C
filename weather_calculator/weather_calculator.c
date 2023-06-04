#include "weather_calculator.h"
#include <stdio.h>
#include <stdlib.h>
#define MONTHS_IN_YEAR 12
/*
input: 
- 2D array where each row should have 12 columns (each month)
- floats
output:
- total rainfall for each year 
- average yearly rainfall
- average rainfall for each month
*/

struct Rainfall calculate_rainfall_metadata(float rainfall_years[][MONTHS_IN_YEAR], int size) {
    float yearly_totals[size]; 
    float yearly_average = 0;
    // important that this is staic, so it's not deallocated after function exit
    float* monthly_average = (float*)calloc(MONTHS_IN_YEAR, sizeof(float));
    if (monthly_average == NULL) {
        printf("malloc failed");
        exit(1);
    }
    //static float monthly_average[MONTHS_IN_YEAR] = {0};
    struct Rainfall rainfall;
    rainfall.yearly_totals = yearly_totals;
    rainfall.monthly_average = monthly_average;
    rainfall.size = size;
    rainfall.rainfall = rainfall_years;

    for(int i = 0; i < size; i++) {
        float* year = rainfall_years[i]; 
        float year_total = 0;
        for(int j = 0; j < MONTHS_IN_YEAR; j++) {
            float month = year[j];
            year_total += month; 
            monthly_average[j] += month;        
        }
        yearly_totals[i] = year_total;        
    }


    printf("\n BEFORE avg %f" ,yearly_average);
    for(int i = 0; i < size; i++) {
        yearly_average += yearly_totals[i];
    }
    yearly_average /= size;
    // monthly_average has been totaled, so apply the divisor to get average
    for(int i = 0; i < MONTHS_IN_YEAR; i++) {
        monthly_average[i] /= size;
    }

    rainfall.yearly_average = yearly_average;
    return rainfall;
}
