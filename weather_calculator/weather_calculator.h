#define MONTHS_IN_YEAR 12
typedef struct Rainfall {
    float *yearly_totals;
    float yearly_average;
    float *monthly_average;
    void* rainfall; // float [][12]
    int size;
} Rainfall;
struct Rainfall calculate_rainfall_metadata(float rainfall_years[][MONTHS_IN_YEAR], int size);