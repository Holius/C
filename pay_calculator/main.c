#include <stdio.h>
//https://cplusplus.com/reference/cstdlib/strtol/
#include <stdlib.h> // for strtol
#include "pay.h"

/*
    HOUR_RATE = 12 dollars
    OVERTIME = over 40 hours
    TAX_RATE = 
        15% of first $300
        20% of next $150
        25% of remainder
*/

int _main(int argc, char* argv[]) {

    char* hours_of_work_str = argv[1];
    char* p;
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

#ifndef TEST
int main(int argc, char* argv[]) {
    _main(argc, argv);
}
#endif

/*
300 * 0.15 = 45
150 * 0.2  = 30
_________  = 75
*/