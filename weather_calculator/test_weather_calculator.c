#include "unity.h"
#include "weather_calculator.h"
#include <stdlib.h>

#define MONTHS_IN_YEAR 12
void one_year(void) {
    float one_year[1][12] = {
        {4.3, 5.1, 8.9, 6.7, 9.8, 3, 7.24, 10.1, 12, 10.3, 4.01, 5.6}
    };
    int size = 1;
    struct Rainfall rainfall = calculate_rainfall_metadata(one_year, size);
    float yearly_totals[1] = { 87.05 };
    float monthly_average[12] = {4.3, 5.1, 8.9, 6.7, 9.8, 3, 7.24, 10.1, 12, 10.3, 4.01, 5.6};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(yearly_totals, rainfall.yearly_totals, size, "YEARLY TOTALS");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(87.05, rainfall.yearly_average, "YEARLY AVERAGE");

    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(monthly_average, rainfall.monthly_average, MONTHS_IN_YEAR, "MONTHLY AVERAGE");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(one_year, rainfall.rainfall, "RAINFALL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(size, rainfall.size, "RAINFALL SIZE");
    free(rainfall.monthly_average);
}

void two_year(void) {
    float two_year[2][12] = {
        {4.3, 5.1, 8.9, 6.7, 9.8, 3, 7.24, 10.1, 12, 10.3, 4.01, 5.6},
        {2.4, 4.8, 3.7, 5.9, 8.0, 6, 8.99, 8.3, 8, 4.2, 8.23, 2.7}
    };
    int size = 2;
    struct Rainfall rainfall = calculate_rainfall_metadata(two_year, size);
    float yearly_totals[2] = { 87.05, 71.22 };

    float monthly_average[12] = {3.35, 4.95, 6.3, 6.3, 8.9, 4.5, 8.115, 9.2, 10, 7.25, 6.12, 4.15};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(yearly_totals, rainfall.yearly_totals, size, "YEARLY TOTALS");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(79.135, rainfall.yearly_average, "YEARLY AVERAGE");
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(monthly_average, rainfall.monthly_average, MONTHS_IN_YEAR, "MONTHLY AVERAGE");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(two_year, rainfall.rainfall, "RAINFALL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(size, rainfall.size, "RAINFALL SIZE");
    free(rainfall.monthly_average);
}

void three_year(void) {
    float three_year[3][12] = {
        {4.3, 5.1, 8.9, 6.7, 9.8, 3, 7.24, 10.1, 12, 10.3, 4.01, 5.6},
        {2.4, 4.8, 3.7, 5.9, 8.0, 6, 8.99, 8.3, 8, 4.2, 8.23, 2.7},
        {5, 3.22, 9.2, 1.7, 5.7, 7.8, 6.77, 5.9, 3, 6.7, 6.88, 3.9}
    };
    
    int size = 3;
    struct Rainfall rainfall = calculate_rainfall_metadata(three_year, size);
    float yearly_totals[3] = { 87.05, 71.22, 65.77 };
    
    float monthly_average[12] = {3.9, 4.373333, 7.26666, 4.76666, 7.83333, 5.6, 7.666666, 8.1, 7.666666, 7.066666, 6.373333, 4.066666 };
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(yearly_totals, rainfall.yearly_totals, size, "YEARLY TOTALS");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(74.68, rainfall.yearly_average, "YEARLY AVERAGE");
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(monthly_average, rainfall.monthly_average, MONTHS_IN_YEAR, "MONTHLY AVERAGE");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(three_year, rainfall.rainfall, "RAINFALL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(size, rainfall.size, "RAINFALL SIZE");
    free(rainfall.monthly_average);
}

void four_year(void) {
    float four_year[4][12] = {
        {4.3, 5.1, 8.9, 6.7, 9.8, 3, 7.24, 10.1, 12, 10.3, 4.01, 5.6},
        {2.4, 4.8, 3.7, 5.9, 8.0, 6, 8.99, 8.3, 8, 4.2, 8.23, 2.7},
        {5, 3.22, 9.2, 1.7, 5.7, 7.8, 6.77, 5.9, 3, 6.7, 6.88, 3.9},
        {8, 3.82, 3.3, 3.7, 8.3, 7.9, 1.02, 1.3, 4, 9.6, 5.81, 3.8}
    };
    
    int size = 4;
    struct Rainfall rainfall = calculate_rainfall_metadata(four_year, size);
    float yearly_totals[4] = { 87.05, 71.22, 65.77, 60.55 };

    float monthly_average[12] = {4.925, 4.235, 6.275, 4.5, 7.95, 6.175, 6.005, 6.4, 6.75, 7.7, 6.2325, 4 };
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(yearly_totals, rainfall.yearly_totals, size, "YEARLY TOTALS");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(71.1475, rainfall.yearly_average, "YEARLY AVERAGE");
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(monthly_average, rainfall.monthly_average, MONTHS_IN_YEAR, "MONTHLY AVERAGE");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(four_year, rainfall.rainfall, "RAINFALL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(size, rainfall.size, "RAINFALL SIZE");
    free(rainfall.monthly_average);
}

void five_year(void) {
    float five_year[5][12] = {
        {4.3, 5.1, 8.9, 6.7, 9.8, 3, 7.24, 10.1, 12, 10.3, 4.01, 5.6},
        {2.4, 4.8, 3.7, 5.9, 8.0, 6, 8.99, 8.3, 8, 4.2, 8.23, 2.7},
        {5, 3.22, 9.2, 1.7, 5.7, 7.8, 6.77, 5.9, 3, 6.7, 6.88, 3.9},
        {8, 3.82, 3.3, 3.7, 8.3, 7.9, 1.02, 1.3, 4, 9.6, 5.81, 3.8},
        {6, 5.13, 3.8, 9.3, 3.6, 1.3, 1.72, 3.1, 3, 3.7, 6.7, 7.8}
    };
    
    int size = 5;
    struct Rainfall rainfall = calculate_rainfall_metadata(five_year, size);
    float yearly_totals[5] = { 87.05, 71.22, 65.77, 60.55, 55.15 };

    float monthly_average[12] = { 5.14, 4.414, 5.78, 5.46, 7.08, 5.2, 5.148, 5.74, 6, 6.9, 6.326, 4.76};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(yearly_totals, rainfall.yearly_totals, size, "YEARLY TOTALS");
    TEST_ASSERT_EQUAL_FLOAT_MESSAGE(67.948, rainfall.yearly_average, "YEARLY AVERAGE");
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(monthly_average, rainfall.monthly_average, MONTHS_IN_YEAR, "MONTHLY AVERAGE");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(five_year, rainfall.rainfall, "RAINFALL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(size, rainfall.size, "RAINFALL SIZE");
    free(rainfall.monthly_average);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(one_year);
    RUN_TEST(two_year);
    RUN_TEST(three_year);
    RUN_TEST(four_year);
    RUN_TEST(five_year);
    return UNITY_END();
}