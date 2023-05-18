
#include "pay.h"

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