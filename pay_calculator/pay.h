#ifndef FULLTIME
#define FULLTIME 40
#endif

#ifndef HOUR_RATE
#define HOUR_RATE 12.00
#endif

#ifndef PAY

float gross_pay_calculator(float* base_rate, float* overtime_multipler, float* hours_of_work);

float tax_calculator(float gross_pay);
#endif 