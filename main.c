#include <stdio.h>
//https://cplusplus.com/reference/cstdlib/strtol/
#include <stdlib.h> // for strtol

#define FULLTIME 40
#define HOUR_RATE 12.00

/*
    HOUR_RATE = 12 dollars
    OVERTIME = over 40 hours
    TAX_RATE = 
        15% of first $300
        20% of next $150
        25% of remainder
*/
float gross_pay_calculator(float* base_rate, float* overtime_multipler, float* hours_of_work) {
    // to avoid unnecessary calculations when overtime is not met an if/else would be better for speed
    // GET hours worked
    float overtime_hours = *hours_of_work > 40 ? *hours_of_work - 40 : 0;
    float normal_hours = *hours_of_work > 40 ? 40 : *hours_of_work;

    // GET rate
    float overtime_rate = *base_rate * *overtime_multipler; 
    
    // GET pay
    float normal_pay = normal_hours * *base_rate;
    float overtime_pay = overtime_hours * overtime_rate; 
    
    // AGGREGATE pay
    return normal_pay + overtime_pay;

}

float tax_calculator(float gross_pay) {
    float FIRST_TAX_BRACKET = 0.15, SECOND_TAX_BRACKET = 0.2, THIRD_TAX_BRACKET = 0.25;
    if (gross_pay <= 300)
        return gross_pay * FIRST_TAX_BRACKET;
    else if (gross_pay <= 450)
        return (300 * FIRST_TAX_BRACKET) + ( (300 - gross_pay) * SECOND_TAX_BRACKET );
    else 
        return (300 * FIRST_TAX_BRACKET) + ( 150 * SECOND_TAX_BRACKET ) + ( (gross_pay - 450) * THIRD_TAX_BRACKET);
}

int main(int argc, char *argv[]) {
    
    char* hours_of_work_str = argv[1];
    char *p;
    float hours_of_work = (float)strtol(hours_of_work_str, &p, 10);
    // just as efficient as hardcoding since pre-compilation preprocessor will string replace the DEFINE value
    float hour_rate = HOUR_RATE;
    float overtime_multipler = 1.5;
    float gross_pay = gross_pay_calculator(&hour_rate, &overtime_multipler, &hours_of_work);
    float tax = tax_calculator(gross_pay);
    float net_pay = gross_pay - tax;
    printf("Gross pay is %.2f\n", gross_pay);
    printf("Tax deductions is %.2f\n", tax);
    printf("Net pay is %.2f\n", net_pay);
    return 0;    
}

/*
300 * 0.15 = 45
150 * 0.2  = 30
_________  = 75
*/